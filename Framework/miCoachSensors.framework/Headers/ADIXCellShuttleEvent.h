#import <Foundation/Foundation.h>

/**
 *  @brief XCell business rules shuttle event.
 *  @defgroup XCELL_BUSINESS_RULES_SHUTTLE_EVENT XCellBusinessRulesShuttleEvent
 *  @ingroup XCELL_BUSINESS_RULES_EVENTS_GROUP
 *  @{
 */

/**
 This simple, serializable value holder class describes an event when
 X_CELL detects a shuttle movement, by interpreting the readings from the accelerometer.
 */
@interface ADIXCellShuttleEvent : NSObject

/** */
@property (strong, nonatomic) NSNumber *turnTime;

/** */
@property (strong, nonatomic) NSNumber *totalCutTime;

@end

/** @} */
