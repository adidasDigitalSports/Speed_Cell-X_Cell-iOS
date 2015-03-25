#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <miCoachSensors/ADIBluetoothDeviceDelegate.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Protocol defining methods of ADIBluetoothDevice class.
 */
@protocol ADIBluetoothDeviceProtocol <NSObject>

/**
 *  @return Returns the serial number of the remote device.
 */
- (NSString *)serialNumber;

/**
 *  @param serialNumber Serial number of the remote device.
 */
- (void)setSerialNumber:(NSString *)serialNumber;

/**
 *  @return Bluetooth device name.
 */
- (NSString *)deviceLocalName;

/**
 *  @return CBPeripheral of the remote device.
 */
- (CBPeripheral *)peripheral;

/**
 *  @return Every CBCharacteristic of discovered services by UUIDString of the characteristic.
 */
- (NSDictionary *)characteristics;

/**
 *  @param delegate Delegate of the bluetooth device.
 */
- (void)setDelegate:(id<ADIBluetoothDeviceDelegate>)delegate;

/**
 *  @brief Connect to the remote device on bluetooth.
 */
- (void)connect;

/**
 *  @brief Boolean value indicating if automatic reconnect to the remote device is active.
 *
 *  If set to YES, then after an unexpected disconnection a reconnect attempt is performed.
 */
- (BOOL)autoReconnect;

/**
 *  @brief Boolean value indicating if automatic reconnect to the remote device is active.
 *
 *  @param autoReconnect If set to YES, then after an unexpected disconnection a reconnect attempt is performed.
 */
- (void)setAutoReconnect:(BOOL)autoReconnect;

/**
 *  @brief Disconnect from the remote device.
 *
 *  @param callback Block object to be executed on completion of disconnect. This block has no return value and does not takes arguments.
 */
- (void)disconnectWithCallback:(void (^)())callback;

/**
 *  @brief Method for notifying the ADIBluetoothDevice instance that a connection to the remote device has been established.
 *
 *  @param peripheral      The peripheral that has been connected to the system.
 *  @param characteristics A list of characteristics that have been discovered in the services of the remote device.
 */
- (void)didConnectPeripheral:(CBPeripheral *)peripheral withCharacteristics:(NSDictionary *)characteristics;

/**
 *  @brief Initailizes an ADIBluetoothDevice instance.
 *
 *  @param deviceLocalName Local name of the remote device.
 *  @param serialNumber    Serial number of the remote device.
 *
 *  @return Returns an initialized ADIBluetoothDevice object.
 */
- (instancetype)initWithName:(NSString *)deviceLocalName serialNumber:(NSString *)serialNumber;

/**
 *  @brief Allocates and initailizes an ADIBluetoothDevice instance.
 *
 *  @param deviceLocalName Local name of the remote device.
 *  @param serialNumber    Serial number of the remote device.
 *
 *  @return Returns an allocated and initialized ADIBluetoothDevice object.
 */
+ (instancetype)deviceWithName:(NSString *)deviceLocalName serialNumber:(NSString *)serialNumber;

@optional

/**
 *  @brief Method for ADIBluetoothDevice subclasses to implement providing required characteristic UUID strings.
 *
 *  After connecting to a peripheral it is filtered by these characteristics.
 *
 *  @return Returns array of NSString instances.
 */
+ (NSArray *)requiredCharacteristics;

/**
 *  @brief Method for ADIBluetoothDevice subclasses to implement providing notify characteristic UUID strings.
 *
 *  List of characteristic which notification value should be set to YES.
 *
 *  @return Retruns array of NSString instances.
 */
+ (NSArray *)notifyCharacteristics;

/**
 *  @brief Method for ADIBluetoothDevice subclasses to implement providing a serial number from bluetooth advertisement data.
 *
 *  @param advertisementData A dictionary containing any advertisement data.
 *
 *  @return Returns serial number from valid advertisement data, nil otherwise.
 */
+ (NSString *)serialNumberFromAdvertismentData:(NSDictionary *)advertisementData;

@end

/** @} */
