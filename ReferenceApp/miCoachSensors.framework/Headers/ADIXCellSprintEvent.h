#import <Foundation/Foundation.h>

/**
 *  @brief XCell business rules sprint event.
 *  @defgroup XCELL_BUSINESS_RULES_SPRINT_EVENT XCellBusinessRulesSprintEvent
 *  @ingroup XCELL_BUSINESS_RULES_EVENTS_GROUP
 *  @{
 */

/**
 This simple, serializable value holder class describes an event when
 X_CELL detects a sprint, by interpreting the readings from the accelerometer.
 */
@interface ADIXCellSprintEvent : NSObject

/** This property contains the elapsed seconds since the session recording started, when the event occured. */
@property (strong, nonatomic) NSNumber *elapsedSeconds;

/** */
@property (strong, nonatomic) NSNumber *maxRezAcceleration;

/** */
@property (strong, nonatomic) NSNumber *jerkDuration;

/** */
@property (strong, nonatomic) NSNumber *accStartJerk;

/** */
@property (strong, nonatomic) NSNumber *accEndJerk;

/** */
@property (assign, nonatomic) float acceleration;

/** */
@property (assign, nonatomic) float quickness;

@end

/** @} */
