#import <Foundation/Foundation.h>

/**
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  An enum type to represent the ADIFitSmartScreenMetric types.
 */
typedef enum : NSUInteger {

    ADIFitSmartMetricViewTypeEmpty = 0,
    ADIFitSmartMetricViewTypeTime,
    ADIFitSmartMetricViewTypeHeartRate,
    ADIFitSmartMetricViewTypeCalories,
    ADIFitSmartMetricViewTypeDistance,
    ADIFitSmartMetricViewTypePace,
    ADIFitSmartMetricViewTypeSpeed,
    ADIFitSmartMetricViewTypeStrideRate,
    ADIFitSmartMetricViewTypeTimeOfDay,
    ADIFitSmartMetricViewTypeAvgPace,
    ADIFitSmartMetricViewTypeAvgSpeed
} ADIFitSmartScreenMetric;

/** @}
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  This class represents the screen of a FitSmart device.
 *
 */
@interface ADIFitSmartScreen : NSObject

/**
 *  @brief  The count of the metrics displayed.
 */
@property (readonly, nonatomic) NSInteger metricCount;

/**
 *  @brief  Class method initializer with two metrics parameters.
 *
 *  @param top    Top metric.
 *  @param bottom Bottom metric.
 *
 *  @return New instance.
 */
+ (instancetype)fitSmartScreenWithMetricOnTop:(ADIFitSmartScreenMetric)top metricOnBottom:(ADIFitSmartScreenMetric)bottom;

/**
 *  @brief  Class method initializer with one single parameter.
 *
 *  @param  metric Single metric.
 *
 *  @return New instance.
 */
+ (instancetype)fitSmartScreenWithSingleMetric:(ADIFitSmartScreenMetric)metric;

@end

/** @} */