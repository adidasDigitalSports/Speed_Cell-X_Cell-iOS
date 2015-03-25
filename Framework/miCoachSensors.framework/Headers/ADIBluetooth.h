#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import <miCoachSensors/ADIBluetoothDeviceType.h>
#import <miCoachSensors/ADIBluetoothDevices.h>
#import <miCoachSensors/ADIBluetoothDelegate.h>
#import <miCoachSensors/ADIDiscoveryFilter.h>

/**
 *  @example discoverDeviceExample.txt
 */

/**
 *  @defgroup MICOACH_BLUETOOTH miCoachBluetooth
 *  @include discoverDeviceExample.txt
 */

/**
 *  @addtogroup MICOACH_BLUETOOTH
 *  @{
 */

/**
 *  @brief Class for discovering bluetooth compatible remote devices.
 */
@interface ADIBluetooth : NSObject

/**
 *  @return Returns the shared bluetooth manager object.
 */
+ (instancetype)sharedInstance;

/**
 *  @brief The object that acts as a delegate of the class.
 */
@property (nonatomic, weak) id<ADIBluetoothDelegate> bluetoothDelegate;

/**
 *  @brief Time out limit of device discovery in seconds. If less then or equal to 0 then dicovery has no timout. Default is 60 seconds.
 */
@property (nonatomic) NSInteger discoveryTimeout;

/**
 *  @brief Start a remote bluetooth device discovery with the specified filter.
 *
 *  Invokes discoveryService:didFoundDevice:ofType: delegate method when a remote device is discovered.
 *  If the filter parameter is nil, all discovered device of supported type is returned.
 *
 *  @param filter An ADIDiscoveryFilter object for filtering discovered devices.
 *  @include discoverDeviceExample.txt
 */
- (void)startDiscoveryWithFilter:(ADIDiscoveryFilter *)filter;

/**
 *  @brief Asks the bluetooth manager to stop discovery for remote devices.
 */
- (void)stopDiscovery;

/**
 *  @brief Connects to the specified remote device represented by an ADIBluetoothDevice object.
 *
 *  The device parameter should be a discovered ADIBluetoothDevice object with valid CBPeripheral.
 *  @param device The device object to connect.
 */
- (void)connectDevice:(ADIBluetoothDevice *)device;

/**
 *  @brief Cancels the connection to a remote device represented by an ADIBluetoothDevice object.
 *
 *  @param device   The device object to disconnect from.
 *  @param callback Block object to be executed on completion of the disconnect. This block has no return value and does not takes arguments.
 */
- (void)disconnectDevice:(ADIBluetoothDevice *)device withCallback:(void (^)())callback;

@end

/** @} */
