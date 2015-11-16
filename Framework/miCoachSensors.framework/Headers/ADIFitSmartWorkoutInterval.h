#import <Foundation/Foundation.h>

/**
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  Zone colors for workouts.
 *
 * These zone colors are also visible on the FitSmart screen.
 */
typedef enum : NSUInteger {
    /**
     * Blue.
     */
    ADIFitSmartWorkoutIntervalZoneColor_Blue = 1,
    /**
     *  Green.
     */
    ADIFitSmartWorkoutIntervalZoneColor_Green = 2,
    /**
     *  Yellow.
     */
    ADIFitSmartWorkoutIntervalZoneColor_Yellow = 3,
    /**
     *  Red.
     */
    ADIFitSmartWorkoutIntervalZoneColor_Red = 4
}ADIFitSmartWorkoutIntervalZoneColor;

/** @}
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  Class holding a workout interval.
 */
@interface ADIFitSmartWorkoutInterval : NSObject

/**
 *  @brief  Color of the interval.
 */
@property (nonatomic, assign) ADIFitSmartWorkoutIntervalZoneColor zoneColor;

/**
 *  @brief  Duration of the interval in seconds.
 */
@property (nonatomic, assign) int intervalDurationInSeconds;

/**
 *  @brief  Initializer function.
 *
 *  @param zoneColor         Color of the interval.
 *  @param durationInSeconds Duration of the interval.
 *
 *  @return Instance of ADIFitSmartWorkoutInterval.
 */
- (instancetype)initWithZoneColor:(ADIFitSmartWorkoutIntervalZoneColor)zoneColor withIntervalDuration:(NSTimeInterval)durationInSeconds;

@end

/** @} */