
#import <miCoachSensors/miCoachSensors.h>
#import "ViewController.h"
#import "ADIDeviceTableViewCell.h"

/**
 *  Private part of the example view controller.
 */
@interface ViewController () <UITableViewDataSource, UITableViewDelegate, ADIGeneralDeviceDelegate>

@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (weak, nonatomic) IBOutlet UIButton *pairButton;
@property (weak, nonatomic) IBOutlet UIButton *syncButton;
@property (weak, nonatomic) IBOutlet UIButton *syncAllButton;

@property (strong, nonatomic) NSMutableArray *devices;
@property (strong, nonatomic) NSMutableDictionary *progressViews;

@end

/**
 *  Implementation of the view controller.
 */
@implementation ViewController {
    
    ADILicenseManager *_licenseManager;
}

/**
 *  After view loaded we fire up the licensing and subscribe to app did enter notification.
 */
- (void)viewDidLoad {
    
    // call super
    [super viewDidLoad];

    // alloc ivars
    _devices = [NSMutableArray array];
    _progressViews = [NSMutableDictionary dictionary];
    
    // licensing details
    NSString *clientId = @"<Your client id here>";
    NSString *clientSecret = @"<Your client secret here>";
    
    // weak self in closure block
    __weak typeof(self) weakSelf = self;
    
    // the licensing manager
    _licenseManager = [[ADILicenseManager alloc] init];
    
    // initiate async call
    [_licenseManager validateLicenseWithClientId:clientId clientSecret:clientSecret completion:^(BOOL success) {
    
        // log result
        NSLog(@"_licenseManager validateLicenseWithClientId %@", @(success));
        if (success) {
            
            // enable UI
            [weakSelf didFinishLicensingSuccessfully];
        }
    }];

    // subscribe to applicationDidEnterBackground
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(applicationDidEnterBackground:) name:UIApplicationDidEnterBackgroundNotification object:nil];
}

/**
 *  If licensing okay, restore previously found devices and enable UI
 */
- (void)didFinishLicensingSuccessfully {
    
    [self loadPersistedDevices];
    
    self.pairButton.enabled = YES;
    self.syncButton.enabled = YES;
    self.syncAllButton.enabled = YES;
}

/**
 *  In case application enters background we stop sensor communication.
 *  This is not necessary, sensors can work in background by default, but this is a bit more user friendly for this app.
 *
 *  @param sender The sender of the notification
 */
- (void)applicationDidEnterBackground:(id)sender {

    // if we have a modal view, close it
    if (self.presentedViewController) {
        
        [self dismissViewControllerAnimated:YES completion:nil];
    }

    // disconenct all connected devices
    for (ADIGeneralDevice<ADIDownloadSessionsProtocol> *device in _devices) {
        
        if (device.isConnected) {
            
            // stop download and disconnect
            [device abortDownloadAll];
            [device disconnectWithCompletionHandler:nil];
        }
    }

    // we don't need no more notification
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

/**
 *  This method will restore all previously paired devices. Persistency using type and serial number.
 */
- (void)loadPersistedDevices {

    // get devices in dictionary from user defaults
    NSDictionary *persistedDevices = [[NSUserDefaults standardUserDefaults] objectForKey:@"kPersistedDevices"];
    
    // iterate the devices by serial number
    for (NSString *serialNumber in persistedDevices) {
        
        // check by type
        if ([persistedDevices[serialNumber] isEqualToString:NSStringFromClass([ADIXCellDevice class])]) {

            // add X_CELL
            ADIGeneralDevice *device = [miCoachSensorsUI xcellDeviceWithSerialNumber:serialNumber];
            device.delegate = self;
            [_devices addObject:device];
        }
        else if ([persistedDevices[serialNumber] isEqualToString:NSStringFromClass([ADISpeedCellDevice class])]) {
            
            // add SPEED_CELL
            ADIGeneralDevice *device = [miCoachSensorsUI speedcellDeviceWithSerialNumber:serialNumber];
            device.delegate = self;
            [_devices addObject:device];
        }
    }
}

/**
 *  If user taps connect button for a row for a paired sensor, we do the connect.
 *
 *  @param button The Button sending the event.
 */
- (void)connectButtonClicked:(UIButton *)button {

    // get the device from button
    ADIGeneralDevice *device = _devices[button.tag];
    
    // disable button
    button.enabled = NO;
    
    // allow reconnect and initiate the connection
    device.autoReconnect = YES;
    [device connect];
}

/**
 *  This method is executed when user taps the sync button for a row for a paired sensor, we do the session download.
 *
 *  @param button The Button sending the event.
 */
- (void)syncButtonClicked:(UIButton *)button {

    // use weak self in block
    __weak typeof(self) weakSelf = self;

    // get the device from button
    ADIGeneralDevice *device = _devices[button.tag];

    // use miCoachSensorsUI to show built-in UI while downloading
    UIViewController *viewController = [miCoachSensorsUI downloadSessionFromDevice:device completion:^(NSArray *sessions, NSError *error) {
        
        // this closure called when async download finished, we just log the result
        [weakSelf showSessionDownloadedAlertView:sessions error:error];
    }];
    
    // show the UI
    [self presentViewController:viewController animated:YES completion:nil];
}

/**
 *  This helper method can show an alert view with a title and message, dismissable with an OK button
 *
 *  @param title   Title for the alert view.
 *  @param message Message of the alert.
 */
- (void)alertControllerWithTitle:(NSString *)title message:(NSString *)message {
    
    // create
    UIAlertController* alert = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
    
    // handle OK button - dismiss
    [alert addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleCancel handler:^(UIAlertAction *action) {
        [alert dismissViewControllerAnimated:YES completion:nil];
    }]];
    
    // show the alert
    [self presentViewController:alert animated:YES completion:nil];
}

/**
 *  When the user taps Add Device button, this method is executed.
 *  We use built-in UI to select a sensor and pair it. If pair was successful, we persist the sensor.
 *
 *  @param sender The object initiated the event handler.
 */
- (IBAction)addDevice:(id)sender {

    // use weak self in block
    __weak typeof(self) weakSelf = self;
    
    // initiate built-in pairing screen
    UIViewController *vc = [miCoachSensorsUI viewControllerWithPairCompletionHandler:^(ADIGeneralDevice *device, NSError *error) {

        // handle error - pair failed - show alert
        if (error) {
            
            [weakSelf alertControllerWithTitle:@"Pair device failed!" message:error.description];
            
        // handle case when we selected an already paired sensor
        } else if ([weakSelf isDiscoveredSerialNumber:device.serialNumber]) {
            
            [weakSelf alertControllerWithTitle:@"Device pairing" message:@"Device already paired!"];

        // new sensor - add to UI and persist - setup sensor delegate to self
        } else {
            
            [weakSelf.devices addObject:device];
            [weakSelf persistDevice:device];
            [weakSelf.tableView reloadData];
            device.delegate = weakSelf;
        }
    }];
    
    // show the UI
    [self presentViewController:vc animated:YES completion:nil];
}

/**
 *  This method is responsible to persist a device using user defaults.
 *  For each device a dictionary is saved with type (sensor class name) and serial number.
 *
 *  @param device The sensor to be persisted.
 */
- (void)persistDevice:(ADIGeneralDevice *)device {

    // get the persisted dictionary
    NSMutableDictionary *persistedDevices = [NSMutableDictionary dictionaryWithDictionary:[[NSUserDefaults standardUserDefaults] objectForKey:@"kPersistedDevices"]];
    
    // if this is the first device, create the dictionary
    if (persistedDevices == nil) {
        persistedDevices = [NSMutableDictionary dictionary];
    }
    
    // store sensor info: key = serial-number, value = class-name
    persistedDevices[device.serialNumber] = NSStringFromClass([device class]);
    
    // save to user defaults
    [[NSUserDefaults standardUserDefaults] setObject:persistedDevices forKey:@"kPersistedDevices"];
}

/**
 *  Helper method to device if the specified sensor is already on the list.
 *
 *  @param serialNumber The serial number of the device.
 *  @return Returns true if the device is already on the UI.
 */
- (BOOL)isDiscoveredSerialNumber:(NSString *)serialNumber {

    // do a simple linear search, return YES if we found it
    for (ADIGeneralDevice *device in _devices) {
        
        if ([device.serialNumber isEqualToString:serialNumber]) {
            return YES;
        }
    }
    return NO;
}

- (void)showSessionDownloadedAlertView:(NSArray *)sessions error:(NSError *)error {
    
    NSLog(@"error: %@ sessions: %@", error, sessions);
    
    // display results
    if (error == nil) {
        
        [self alertControllerWithTitle:@"Sync successful" message:[NSString stringWithFormat:@"%d sessions downloaded.", (int)sessions.count]];
    }
    else {
        
        [self alertControllerWithTitle:@"Sync failed" message:[NSString stringWithFormat:@"Error: %@", error]];
    }
}

/**
 *  This method shows a built-in UI to select a sensor and initiate the sessions from it.
 *
 *  @param sender The object initiated the event handler.
 */
- (IBAction)syncDevice:(id)sender {
    
    // use weak self in blocks
    __weak typeof(self) weakSelf = self;

    // create the view controller
    UIViewController *viewController = [miCoachSensorsUI downloadSessionFromDevice:^(NSArray *sessions, NSError *error) {
        
        [weakSelf showSessionDownloadedAlertView:sessions error:error];
    }];
    
    // and display it
    [self presentViewController:viewController animated:YES completion:nil];
}

/**
 *  This method initiates sync for all paired devices in the list.
 *
 *  @param sender The object initiated the event handler.
 */
- (IBAction)syncAllConnected:(id)sender {

    // index of the row we are processing
    int row = 0;
    
    // go over all paired devices
    for (ADIGeneralDevice<ADIDownloadSessionsProtocol> *device in _devices) {
        
        // we process only rows that has connected devices
        if (device.isConnected) {

            // update UI
            [_progressViews[@(row)] setHidden:NO];
            [_progressViews[@(row)] setProgress:0 animated:NO];

            // weak self
            __weak typeof(self) weakSelf = self;
            
            // setup the handler for the download progress here
            [device setHandlerForDownloadProgressChange:^(NSInteger progress) {

                // if progressbar visible, update with percentage
                if (![weakSelf.progressViews[@(row)] isHidden]) {
                    [weakSelf.progressViews[@(row)] setProgress:progress / 100.0f animated:YES];
                }
            }];

            // intiate the download itself
            [device downloadSessions:^(NSArray *rawSessions, NSError *error) {
                
                // process downloaded sessions and handle error
                [weakSelf device:device didDownloadSessions:rawSessions error:error];
            }];
        }
        
        // increment row index
        row++;
    }
}

/**
 *  This method is called when a session download is finished
 *
 *  @param device   The sensor where the session is coming from.
 *  @param sessions The downloaded sessions.
 *  @param error    In case of error, the details stored here.
 */
- (void)device:(ADIGeneralDevice *)device didDownloadSessions:(NSArray *)sessions error:(NSError *)error {

    // hide progressbar
    NSUInteger index = [_devices indexOfObject:device];
    [_progressViews[@(index)] setHidden:YES];
    
    // log results
    NSLog(@"Device with serial number %@ has session count: %lu", device.serialNumber, (unsigned long)sessions.count);
    NSLog(@"Error: %@", error);
}

#pragma mark - UITableView DataSource

/**
 *  One sensor makes one row on the UI.
 *
 *  @param tableView The table view to be updated.
 *  @param section   The section index, in this example it's always 1.
 *
 *  @return We return the number of sensors paired.
 */
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return _devices.count;
}

/**
 *  We create a cell based on the sensor paired.
 *
 *  @param tableView The table view to be updated.
 *  @param indexPath IndexPath of the cell which interacts with the user.
 *
 *  @return We return the created cell, as expected by the delegate.
 */
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {

    // re-use or create
    ADIDeviceTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:kADIDeviceTableViewCellIdentifier];

    // text is the serial number
    cell.textLabel.text = [_devices[indexPath.row] serialNumber];
    
    // save row index in tags
    cell.connectButton.tag = indexPath.row;
    cell.syncButton.tag = indexPath.row;
    
    // button handlers
    [cell.connectButton addTarget:self action:@selector(connectButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
    [cell.syncButton addTarget:self action:@selector(syncButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
    
    // save progress bar for later, easier use
    _progressViews[[NSNumber numberWithInt:indexPath.row]] = cell.progressView;
    
    // hide progress bar by default
    cell.progressView.hidden = YES;

    // setup the cell differently if sensor is connected
    if ([_devices[indexPath.row] isConnected]) {
        
        // use checkmark and disable connect and enable sync button
        cell.accessoryType = UITableViewCellAccessoryCheckmark;
        cell.connectButton.enabled = NO;
        cell.syncButton.enabled = YES;
        
    } else {
        
        // no checkmark and enable connect and disable sync button
        cell.connectButton.enabled = YES;
        cell.syncButton.enabled = NO;
        cell.accessoryType = UITableViewCellAccessoryNone;
    }

    // return the updated cell
    return cell;
}

/**
 *  Handle edit on table view
 *
 *  @param tableView The table view to be updated.
 *  @param indexPath IndexPath of the cell which interacts with the user.
 *
 *  @return Returns the actions.
 */
- (NSArray *)tableView:(UITableView *)tableView editActionsForRowAtIndexPath:(NSIndexPath *)indexPath {

    // use weak self in blocks
    __weak typeof(self) weakSelf = self;

    // delete = unpair
    UITableViewRowAction *deleteAction = [UITableViewRowAction rowActionWithStyle:UITableViewRowActionStyleDestructive title:@"unpair" handler:^(UITableViewRowAction *action, NSIndexPath *indexPath) {

        // get the device from row
        ADIGeneralDevice *device = weakSelf.devices[indexPath.row];
        
        // disconnect
        if (device.isConnected) {
            [device disconnectWithCompletionHandler:nil];
        }

        // remove from persistency
        NSMutableDictionary *persistedDevices = [NSMutableDictionary dictionaryWithDictionary:[[NSUserDefaults standardUserDefaults] objectForKey:@"kPersistedDevices"]];
        [persistedDevices removeObjectForKey:device.serialNumber];
        [[NSUserDefaults standardUserDefaults] setObject:persistedDevices forKey:@"kPersistedDevices"];
        
        // remove from UI and internal array
        [weakSelf.devices removeObjectAtIndex:indexPath.row];
        [weakSelf.tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationAutomatic];
    }];

    // if action is delete, we are done
    if (![_devices[indexPath.row] isConnected]) {
        return @[deleteAction];
    }

    // disconnect action
    UITableViewRowAction *disconnectAction = [UITableViewRowAction rowActionWithStyle:UITableViewRowActionStyleNormal title:@"disconnect" handler:^(UITableViewRowAction *action, NSIndexPath *indexPath) {

        // get the device from row
        ADIGeneralDevice *device = weakSelf.devices[indexPath.row];
        
        // disconnect and update UI
        [device disconnectWithCompletionHandler:nil];
        [weakSelf.tableView setEditing:NO animated:YES];
    }];

    // return actions
    return @[disconnectAction, deleteAction];
}

/**
 *  Allow user to use edit gesture on cells.
 *
 *  @param tableView The table view to be updated.
 *  @param indexPath IndexPath of the cell which interacts with the user.
 *
 *  @return YES, we allow edit.
 */
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath {
    
    return YES;
}

/**
 *  We handle edit in a custom way.
 *
 *  @param tableView The table view to be updated.
 *  @param editingStyle Editing style.
 *  @param indexPath IndexPath of the cell which interacts with the user.
 */
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
    
}

#pragma mark - Device delegate methods

/**
 *  This method is a callback when the device initiated a connection. We update the table view in such case.
 *
 *  @param device The device which connected.
 */
- (void)deviceDidConnect:(ADIGeneralDevice *)device {

    NSUInteger index = [_devices indexOfObject:device];
    [self.tableView reloadRowsAtIndexPaths:@[[NSIndexPath indexPathForRow:index inSection:0]] withRowAnimation:UITableViewRowAnimationAutomatic];
}

/**
 *  This method is a callback when the device initiated a disconnection. We update the table view in such case.
 *
 *  @param device The device which disconnected.
 */
- (void)deviceDidDisconnect:(ADIGeneralDevice *)device {

    // index for the device
    NSUInteger index = [_devices indexOfObject:device];
    
    // if we know this device, then we update the table view
    if (index != NSNotFound) {
        [self.tableView reloadRowsAtIndexPaths:@[[NSIndexPath indexPathForRow:index inSection:0]] withRowAnimation:UITableViewRowAnimationAutomatic];
    }
}

/**
 *  This method is callback for a device that failed to be connected.
 *
 *  @param device The device failed to connect.
 *  @param error  Details of the error.
 */
- (void)deviceDidFailToConnectPeripheral:(ADIGeneralDevice *)device error:(NSError *)error {

    // show an alert view
    [self alertControllerWithTitle:@"Pair device failed!" message:@"Device did fail to connect!"];

    // index for the device
    NSUInteger index = [_devices indexOfObject:device];
    
    // update the table view
    [self.tableView reloadRowsAtIndexPaths:@[[NSIndexPath indexPathForRow:index inSection:0]] withRowAnimation:UITableViewRowAnimationAutomatic];
}

@end
