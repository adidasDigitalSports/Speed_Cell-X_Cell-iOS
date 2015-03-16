#import <Foundation/Foundation.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Protocol for setting and getting time from a device.
 */
@protocol ADISensorTimeProtocol <NSObject>

/**
 *  @brief Reads the time set on the device.
 *
 *  @param completion Block object to be executed on completion of acquiring device time.This block has no return value and takes a single NSDate argument, which holds the time on the device.
 */
- (void)getDeviceTime:(void (^)(NSDate *dateTime))completion;

/**
 *  @brief Sets the date and time on the device to the given date and time.
 *
 *  @param deviceTime A valid timestamp.
 *  @param completion Block object to be executed on completion of setting device time. This block has no return value and takes a Boolean value, which is YES if the time is set successfully, otherwise NO.
 */
- (void)setDeviceTime:(NSDate *)deviceTime success:(void (^)(BOOL success))completion;

@end

/** @} */
