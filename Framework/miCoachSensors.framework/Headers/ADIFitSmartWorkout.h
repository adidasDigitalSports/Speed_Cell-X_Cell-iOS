#import <Foundation/Foundation.h>

/**
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  Workout definition class.
 *
 *  This workout can be uploaded to the FitSmart device.
 */
@interface ADIFitSmartWorkout : NSObject

/**
 *  @brief  Unique workout internal ID.
 */
@property (nonatomic, copy) NSNumber *uniqueId;

/**
 *  @brief  Workout index (from 1 to 15).
 */
@property (nonatomic, assign) NSUInteger workoutIndex;

/**
 *  @brief  Workout excercise time.
 */
@property (nonatomic, copy) NSDate *date;

/**
 *  @brief  Array holding workout intervals.
 */
@property (nonatomic, copy) NSArray *intervals;

/**
 *  @brief  Workout description. 
 *
 *  50 characters maximum, 4 characters minimum. This is optional.
 */
@property (nonatomic, copy) NSString *workoutDescription;

@end

/** @} */