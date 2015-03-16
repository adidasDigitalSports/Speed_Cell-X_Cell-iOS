#import <Foundation/Foundation.h>

/**
 *  @brief XCell business rules start event.
 *  @defgroup XCELL_BUSINESS_RULES_START_EVENT XCellBusinessRulesStartEvent
 *  @ingroup XCELL_BUSINESS_RULES_EVENTS_GROUP
 *  @{
 */

/**
 This simple, serializable value holder class describes an event for
 mark the end of the session. Every session must contain this event and only as the last event.
 */
@interface ADIXCellSessionStartEvent : NSObject

/** This property contains the absolute time when the session started. */
@property (strong, nonatomic) NSDate *timeStamp;

@end

/** @} */
