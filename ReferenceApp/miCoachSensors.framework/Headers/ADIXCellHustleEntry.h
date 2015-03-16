#import <Foundation/Foundation.h>

/**
 *  @brief XCell business rules hustle event.
 *  @defgroup XCELL_BUSINESS_RULES_HUSTLE_EVENT XCellBusinessRulesHustleEvent
 *  @ingroup XCELL_BUSINESS_RULES_EVENTS_GROUP
 *  @{
 */

/**
 Hustle object to store the G/min metric of the session.
 */
@interface ADIXCellHustleEntry : NSObject

/** This property contains the elapsed seconds since the session recording started, when the event occured. */
@property (strong, nonatomic) NSNumber *elapsedSeconds;

/** This property contains the hustle value measured from the latest hustle's time to this event's time. */
@property (strong, nonatomic) NSNumber *hustleValue;

@end

/** @} */
