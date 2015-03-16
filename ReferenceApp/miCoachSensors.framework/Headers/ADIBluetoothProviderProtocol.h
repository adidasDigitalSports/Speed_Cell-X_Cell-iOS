#import <Foundation/Foundation.h>

@protocol ADIBluetoothDelegateProtocol;

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief This protocol contains bluetooth related methods that a binding layer should implement.
 */
@protocol ADIBluetoothProviderProtocol <NSObject>

@required

/**
 *  @brief Sets the bluetooth delegate.
 *
 *  @param delegate A valid object, conforming to ADIBluetoothDelegateProtocol protocol.
 */
- (void)setBluetoothDelegate:(id<ADIBluetoothDelegateProtocol>)delegate;

/**
 *  @brief Corresponding method for CBPeripheral's didUpdateValue:forCharacteristic: method.
 *
 *  When CBPeripheral's didUpdateValue:forCharacteristic: method is invoked this method should be called.
 *
 *  @param value              The value of the characteristic.
 *  @param characteristicUUID The unique identifier of the characteristic whose value is updated.
 */
- (void)didUpdateValue:(NSData *)value forCharacteristic:(NSString *)characteristicUUID;

/**
 *  @brief Corresponding method for CBPeripheral's didWriteValue:forCharacteristic: method.
 *
 *  When CBPeripheral's didWriteValue:forCharacteristic: method is invoked this method should be called.
 *
 *  @param value              The value written.
 *  @param characteristicUUID The unique identifier of the characteristic whose value was written.
 */
- (void)didWriteValue:(NSData *)value forCharacteristic:(NSString *)characteristicUUID;

/**
 *  @brief Should be invoked when device did disconnect.
 *
 *  After CBCentralManager's didDisconnectPeripheral:error: delegate method invoked.
 */
- (void)didDisconnectPeripheral;

@end

/** @} */
