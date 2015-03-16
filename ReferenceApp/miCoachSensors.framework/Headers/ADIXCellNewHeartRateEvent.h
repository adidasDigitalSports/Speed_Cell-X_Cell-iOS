#import <Foundation/Foundation.h>

/**
 *  @brief XCell business rules heart rate event.
 *  @defgroup XCELL_BUSINESS_RULES_HEARTRATE_EVENT XCellBusinessRulesHeartRateEvent
 *  @ingroup XCELL_BUSINESS_RULES_EVENTS_GROUP
 *  @{
 */

/**
 This simple, serializable value holder class describes an event for
 heart rate update.
 */
@interface ADIXCellNewHeartRateEvent : NSObject

/** This property contains the elapsed seconds since the session recording started, when the event occured. */
@property (strong, nonatomic) NSNumber *elapsedSeconds;

/** This property contains the most recent heart rate value. */
@property (strong, nonatomic) NSNumber *heartRate;

@end

/** @} */
