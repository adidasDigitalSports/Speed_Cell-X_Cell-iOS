#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@protocol ADIBluetoothDeviceProtocol;

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief The delegate of a ADIBluetoothDevice object must adopt the ADIBluetoothDeviceDelegate protocol. The delegate uses this protocol's methods to monitor the connection and interactions with the remote device.
 */
@protocol ADIBluetoothDeviceDelegate <NSObject>

@required

/**
 *  @brief Invoked when you retrieve a specified characteristic's value, or when the peripheral device notifies your app that the characteristic’s value has changed.
 *
 *  @param device         The device providing this information.
 *  @param characteristic The characteristic whose value has been retrieved.
 *  @param error          If an error occurred, the cause of the failure.
 */
- (void)device:(id<ADIBluetoothDeviceProtocol>)device didUpdateValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;

/**
 *  @brief Invoked when you write data to a characteristic’s value.
 *
 *  @param device         The device providing this information.
 *  @param characteristic The characteristic whose value has been written.
 *  @param error          If an error occurred, the cause of the failure.
 */
- (void)device:(id<ADIBluetoothDeviceProtocol>)device didWriteValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;

@optional

/**
 *  @brief Invoked when a connection to the remote device is established.
 *
 *  @param device The device that has been connected to the system.
 */
- (void)deviceDidConnect:(id<ADIBluetoothDeviceProtocol>)device;

/**
 *  @brief Invoked when a connection to the remote device is canceled.
 *
 *  @param device The device that has been disconnected.
 */
- (void)deviceDidDisconnect:(id<ADIBluetoothDeviceProtocol>)device;

/**
 *  @brief Invoked when a connection to the remote device is failed.
 *
 *  @param device The device that failed to connect to the remote device.
 *  @param error  If an error occurred, the cause of the failure.
 */
- (void)deviceDidFailToConnect:(id<ADIBluetoothDeviceProtocol>)device error:(NSError *)error;

@end

/** @} */
