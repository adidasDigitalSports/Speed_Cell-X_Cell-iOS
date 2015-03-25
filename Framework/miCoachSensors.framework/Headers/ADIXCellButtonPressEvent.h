#import <Foundation/Foundation.h>

/**
 *  @brief XCell business rules press event.
 *  @defgroup XCELL_BUSINESS_RULES_PRESS_EVENT XCellBusinessRulesPressEvent
 *  @ingroup XCELL_BUSINESS_RULES_EVENTS_GROUP
 *  @{
 */

/**
 This simple, serializable value holder class describes an event for
 physical button pressed by the user on the X_CELL device.
 */
@interface ADIXCellButtonPressEvent : NSObject

/** This property contains the elapsed seconds since the session recording started, when the event occured. */
@property (strong, nonatomic) NSNumber *elapsedSeconds;

@end

/** @} */
