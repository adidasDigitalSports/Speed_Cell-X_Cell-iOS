#import <Foundation/Foundation.h>

/**
 *  @brief XCell business rules jump event.
 *  @defgroup XCELL_BUSINESS_RULES_JUMP_EVENT XCellBusinessRulesJumpEvent
 *  @ingroup XCELL_BUSINESS_RULES_EVENTS_GROUP
 *  @{
 */

/**
 This simple, serializable value holder class describes an event when
 X_CELL detects a vertical jump movement, by interpreting the readings from the accelerometer.
 */
@interface ADIXCellJumpEvent : NSObject

/** This property contains the elapsed seconds since the session recording started, when the event occured. */
@property (strong, nonatomic) NSNumber *elapsedSeconds;

/** Max rez. acceleration values. */
@property (strong, nonatomic) NSNumber *maxRezAcceleration;

/** Acceleration value on the vertical axis. */
@property (strong, nonatomic) NSNumber *sumAccelerationZ;

/** Calculated acceleration (based on raw acceleration values) */
@property (assign, nonatomic) float jumpMaxAcceleration;

/** Calculated jump height (based on acceleration values) measured in inches */
@property (assign, nonatomic) float jumpHeight;

@end

/** @} */
