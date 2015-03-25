#import <Foundation/Foundation.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief This protocol contains bluetooth related methods that a binding layer delegate should implement.
 *
 *  A binding layer relies on these methods to be implemented by its delegate which is set by ADIBluetoothProviderProtocol's setBluetoothDelegate: method.
 */
@protocol ADIBluetoothDelegateProtocol <NSObject>

/**
 *  @brief Tells the delegate to write the given data to bluetooth with an expectation of a response.
 *
 *  @param uuid The unique identifier of the characteristic to write.
 *  @param data Value of the characteristic to be written.
 */
- (void)writeCharacteristics:(NSString *)uuid withData:(NSData *)data;

/**
 *  @brief Tells the delegate to write the given data to bluetooth without any expectiation of a response.
 *
 *  @param uuid The unique identifier of the characteristic to write.
 *  @param data Value of the characteristic to be written.
 */
- (void)writeCharacteristicsWithoutResponse:(NSString *)uuid withData:(NSData *)data;

/**
 *  @brief Tells the delegate to read the value of a given characteristic.
 *
 *  @param uuid The unique identifier of the characteristic to read.
 */
- (void)readValueForCharacteristicWithUUID:(NSString *)uuid;

@end

/** @} */
