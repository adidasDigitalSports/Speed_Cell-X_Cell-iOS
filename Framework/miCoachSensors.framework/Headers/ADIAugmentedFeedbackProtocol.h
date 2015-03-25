#import <Foundation/Foundation.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Protocol for acquiring augmented feedbacks.
 *
 *  Augmented feedbacks are interactions, both the application and the device is part of the action.
 */
@protocol ADIAugmentedFeedbackProtocol <NSObject>

/**
 *  @brief Switching the remote device to the given augmented feedback state.
 *
 *  @param state      The state in which the device should switch.
 *  @param completion Block object to be executed on completion of the state change. This block has no return value takes a Boolean value, which is YES on succesfull state change, otherwise NO.
 */
- (void)switchToAugmentedFeedbackState:(ADIXCellDeviceStatus)state completion:(void (^)(BOOL success))completion;

/**
 *  @brief Starts augmented jump on remote device.
 *
 *  @param completion Block object to be executed on completion of capturing the jump event. This block has no return value and takes two arguments: the captured raw binary jump event data and an NSError containing the error. On success the error is nil.
 */
- (void)startAugmentedFeedbackJump:(void (^)(NSData *data, NSError *error))completion;

/**
 *  @brief Starts augmented shuttle on remote device.
 *
 *  @param completion Block object to be executed on completion of capturing the shuttle event. This block has no return value and takes two arguments: the captured raw binary shuttle event data and an NSError containing the error. On success the error is nil.
 */
- (void)startAugmentedFeedbackShuttle:(void (^)(NSData *data, NSError *error))completion;

/**
 *  @brief Starts augmented reaction on remote device.
 *
 *  @param completion Block object to be executed on completion of capturing the reaction event. This block has no return value and takes two arguments: the captured raw binary reaction event data and an NSError containing the error. On success the error is nil.
 */
- (void)startAugmentedFeedbackReaction:(void (^)(NSData *data, NSError *error))completion;

@end

/** @} */
