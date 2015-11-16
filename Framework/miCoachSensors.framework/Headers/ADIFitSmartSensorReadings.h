#import <Foundation/Foundation.h>

/**
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  Class that holds a sensor reading.
 *
 *  This structure is used both for incoming sensory data and screen update value during dual mode workouts.
 */
@interface ADIFitSmartSensorReadings : NSObject

/**
 *  @brief  Heart rate in BPM.
 */
@property (strong, nonatomic) NSNumber *heartRate;

/**
 *  @brief  Workout time.
 */
@property (strong, nonatomic) NSNumber *workoutTime;

/**
 *  @brief  Distance in meters.
 */
@property (strong, nonatomic) NSNumber *distance;

/**
 *  @brief  Calories burnt in kCal.
 */
@property (strong, nonatomic) NSNumber *calories;

/**
 *  @brief  Pace in seconds.
 */
@property (strong, nonatomic) NSNumber *pace;

/**
 *  @brief  Average  pace in seconds.
 */
@property (strong, nonatomic) NSNumber *avgPace;

/**
 *  @brief  Speed in m/s.
 */
@property (strong, nonatomic) NSNumber *speed;

/**
 *  @brief  Average speed in m/s;
 */
@property (strong, nonatomic) NSNumber *avgSpeed;

/**
 *  @brief  Stride rate in steps/minute.
 */
@property (strong, nonatomic) NSNumber *strideRate;

/**
 *  @brief  Number of steps.
 */
@property (strong, nonatomic) NSNumber *steps;

/**
 *  @brief  Run score calculated.
 */
@property (strong, nonatomic) NSNumber *runScore;

/**
 *  @brief  Timestamp of the measurement if applicable.
 */
@property (strong, nonatomic) NSNumber *timestampUTC;

@end

/** @} */