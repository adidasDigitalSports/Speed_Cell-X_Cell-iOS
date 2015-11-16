#import <Foundation/Foundation.h>

/**
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  This class represents a Session Data point, holding session related values.
 */
@interface ADIFitSmartSessionDataPoint : NSObject

/**
*   @brief  In which second (relative to workout start) the data point recorded.
*/
@property (assign, nonatomic) NSUInteger timestamp;

/**
 *  @brief  Offset for each second, distance (meter).
 */
@property (assign, nonatomic) NSUInteger distance;

/**
 *  @brief  HR rate 30..220 beats/minute.
 */
@property (assign, nonatomic) NSUInteger heartRate;

/**
 *  @brief  Speed in meters/seconds.
 */
@property (assign, nonatomic) float speed;

/**
 *  @brief  Stride Rate, 0..255, steps/minute.
 */
@property (assign, nonatomic) NSUInteger strideRate;

/**
 *  @brief  Burned calories at the end of interval.
 */
@property (assign, nonatomic) NSUInteger calories;

@end

/** @}
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  This class contains details for a session marker event.
 */
@interface ADIFitSmartSessionMarker : NSObject

/**
 *  @brief  Type of the marker.
 *
 *  The types are the following:
 *  0 - Empty
 *  1 - Manual Split by Time
 *  2 - Manual Split by Distance
 *  3 - Auto split by time
 *  4 - Auto split by distance
 *  10 – Pause Workout
 *  11 - Resume Workout (.value = Time is pause duration in seconds)
 *  20 - Narration SpeedUp
 *  21 - Narration SlowDown
 *  22 - Narration MaintainZone
 *  23 - ZoneChangeUp
 *  24 - ZoneChangeDown
 *  25 - ZoneMaintain
 *  70 – HR lost
 *  71 - HR found
 *  240 - BLE connect event
 *  241 - BLE disconnect event
 *  252 - Total time when Vibra On is ON during workout (.value = in seconds)
 *  253 – Workout end
 *  254 - Disk Full
 */
@property (assign, nonatomic) NSUInteger type;

/**
 *  @brief  Marker value, for example: if type is ResumeWorkout, value is length of the pause in seconds.
 */
@property (assign, nonatomic) NSUInteger value;

/**
 *  @brief  In which second (relative to workout start) the marker recorded.
 */
@property (assign, nonatomic) NSUInteger timestamp;

@end

/** @}
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  An enum type to represent the workout type.
 */
typedef enum {

    ADIFitSmartWorkoutType_Free = 0,
    ADIFitSmartWorkoutType_Assessment = 1,
    ADIFitSmartWorkoutType_Planned = 2,
    ADIFitSmartWorkoutType_Gym = 3,

} ADIFitSmartWorkoutType;

/** @}
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  This class stores all information for a recorded workout.
 */
@interface ADIFitSmartSession : NSObject

/**
 *  @brief  Unique workout internal ID (from Mobile).
 */
@property (copy, nonatomic) NSNumber *workoutId;

/**
 *  @brief  Workout can be free workout, planned or assessment.
 */
@property (assign, nonatomic) ADIFitSmartWorkoutType type;

/**
 *  @brief  UTC time at the start of workout.
 */
@property (copy, nonatomic) NSNumber *startWorkoutTimestamp;

/**
 *  @brief  UTC time at the end of workout.
 */
@property (copy, nonatomic) NSNumber *endWorkoutTimestamp;

/**
 *  @brief  Average heart rate measured during heart rate.
 */
@property (assign, nonatomic) NSUInteger avgHeartRate;

/**
 *  @brief  Average pace in seconds.
 */
@property (assign, nonatomic) NSUInteger avgPace;

/**
 *  @brief  Average stride rate, step count in minutes.
 */
@property (assign, nonatomic) NSUInteger avgStrideRate;

/**
 *  @brief  Run score.
 */
@property (assign, nonatomic) NSUInteger runScore;

/**
 *  @brief  Array of ADIFitSmartSessionDataPoint instances.
 */
@property (copy, nonatomic) NSArray *dataPoints;

/**
 *  @brief  Total distance in meters.
 */
@property (assign, nonatomic) NSUInteger totalDistance;

/**
 *  @brief  Total calories in kilocalories.
 */
@property (assign, nonatomic) NSUInteger totalCalories;

/**
 *  @brief  Array of ADIFitSmartSessionMarker instances.
 */
@property (copy, nonatomic) NSArray *markers;

/**
 *  @brief  Determine wether session signed as valid during session parsing CRC calculation.
 */
@property (copy, nonatomic) NSNumber *isSessionValid;

/**
 *  @brief  This method can dump the content to csv format, which can be imported to a spreadsheet.
 *
 *  @return CSV representation
 */
- (NSString *)toCommaSeparatedValues;

@end

/** @} */