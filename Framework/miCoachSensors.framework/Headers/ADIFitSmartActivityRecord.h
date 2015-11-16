#import <Foundation/Foundation.h>

/**
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  This class represents an activity record on the FitSmart device.
 *
 *  Activity Records are holding information about a workout at a given time.
 */
@interface ADIFitSmartActivityRecordDataPoint : NSObject

/**
 *  @brief  Timestamp of the recording.
 */
@property (assign, nonatomic) NSUInteger timestamp;

/**
 *  @brief  The value of burned calories.
 */
@property (assign, nonatomic) NSUInteger calories;

/**
 *  @brief  The number of steps done.
 */
@property (assign, nonatomic) NSUInteger steps;

/**
 *  @brief  The distance covered.
 */
@property (assign, nonatomic) NSUInteger distance;

/**
 *  @brief  The heart rate in BPM.
 */
@property (assign, nonatomic) NSUInteger heartRate;

/**
 *  @brief  The quality of heart rate.
 */
@property (assign, nonatomic) NSUInteger heartRateQuality;

@end

/** @}
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  An enum type to represent the ActivityRecordMarker.
 */
typedef enum : NSUInteger {

    ADIFitSmartActivityRecordMarker_start,
    ADIFitSmartActivityRecordMarker_stop

} ADIFitSmartActivityRecordMarkerType;

/** @}
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  Class holding an activity marker.
 */
@interface ADIFitSmartActivityRecordMarker : NSObject

/**
 *  @brief  The timestamp when the event occured.
 */
@property (assign, nonatomic) NSUInteger timestamp;

/**
 *  @brief  The type of the activity record marker.
 */
@property (assign, nonatomic) ADIFitSmartActivityRecordMarkerType type;

@end

/** @}
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  This class represents an acivity record of the FitSmart device.
 */
@interface ADIFitSmartActivityRecord : NSObject

/**
 *  @brief  An array of activity record data points.
 */
@property (copy, nonatomic) NSArray *dataPoints;
/**
 *  @brief  An array of marker type records.
 */
@property (copy, nonatomic) NSArray *markerRecords;
/**
 *  @brief  The validity of the activity record.
 */
@property (copy, nonatomic) NSNumber *isRecordValid;

/**
 *  @brief  This method can dump the content to csv format, which can be imported to a spreadsheet.
 *
 *  @return CSV representation
 */
- (NSString *)toCommaSeparatedValues;

@end

/** @} */