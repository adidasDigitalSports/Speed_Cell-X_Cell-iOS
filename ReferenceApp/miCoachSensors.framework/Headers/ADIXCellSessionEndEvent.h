#import <Foundation/Foundation.h>

/**
 *  @brief XCell business rules end event.
 *  @defgroup XCELL_BUSINESS_RULES_END_EVENT XCellBusinessRulesEndEvent
 *  @ingroup XCELL_BUSINESS_RULES_EVENTS_GROUP
 *  @{
 */

/**
 This simple, serializable value holder class describes an event for
 mark the start of the session. Every session must contain this event and only as the first event.
 */
@interface ADIXCellSessionEndEvent : NSObject

/** This property contains the absolute time when the session ended. */
@property (strong, nonatomic) NSDate *timeStamp;

@end

/** @} */
