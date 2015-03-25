#import <Foundation/Foundation.h>
#import <miCoachSensors/ADIHeartRate.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Block handler type definition for handling heart rate updates.
 *
 *  @param heartRateData An acquired ADIHeartRate object.
 *  @param error         An NSError object if error happened while capturing heart rate, otherwise nil.
 */
typedef void (^ADIHeartRateHandler)(ADIHeartRate *heartRateData, NSError *error);

/**
 *  @brief Protocol for capturing heart rate updates.
 */
@protocol ADIHeartRateProtocol <NSObject>

/**
 *  @brief Starts heart rate updates with a specific handler.
 *
 *  @param handler A block that is invoked with each update to handle new heart rate data. The block must conform to the ADIHeartRateHandler type.
 */
- (void)startHeartRateUpdatesWithHandler:(ADIHeartRateHandler)handler;

@end

/** @} */
