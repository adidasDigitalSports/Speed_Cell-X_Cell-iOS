#import <Foundation/Foundation.h>

typedef enum : NSInteger {

    ADIXCellReactionTimeEventDirectionLeft,
    ADIXCellReactionTimeEventDirectionRight

} ADIXCellReactionTimeEventDirection;


/**
 *  @brief XCell business rules reaction event.
 *  @defgroup XCELL_BUSINESS_RULES_REACTION_EVENT XCellBusinessRulesReactionEvent
 *  @ingroup XCELL_BUSINESS_RULES_EVENTS_GROUP
 *  @{
 */

/**
 This simple, serializable value holder class describes an event when
 X_CELL detects a shuttle movement for reaction time augmented feedback mode.
 */
@interface ADIXCellReactionTimeEvent : NSObject

/** The raw event length returned by the sensor. */
@property (strong, nonatomic) NSNumber *milliSecondsElapsed;

/** The direction returned by the sensor. */
@property (strong, nonatomic) NSNumber *direction;

@end

/** @} */