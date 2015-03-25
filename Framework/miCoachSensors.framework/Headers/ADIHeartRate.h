#import <Foundation/Foundation.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief An instance of the ADIHeartRate class contains a single measurement of the heart rate.
 */
@interface ADIHeartRate : NSObject

/**
 *  @brief The heartrate measured.
 */
@property (nonatomic, assign) NSUInteger heartRate;

@end

/** @} */
