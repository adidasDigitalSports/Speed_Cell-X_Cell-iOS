#import <Foundation/Foundation.h>

/**
 *  @brief XCell business rules cut event.
 *  @defgroup XCELL_BUSINESS_RULES_CUT_EVENT XCellBusinessRulesCutEvent
 *  @ingroup XCELL_BUSINESS_RULES_EVENTS_GROUP
 *  @{
 */

/**
 This simple, serializable value holder class describes an event when
 X_CELL detects a cut movement, by interpreting the readings from the accelerometer.
 */
@interface ADIXCellCutEvent : NSObject

/** This property contains the elapsed seconds since the session recording started, when the event occured. */
@property (strong, nonatomic) NSNumber *elapsedSeconds;

/** Angle value. */
@property (strong, nonatomic) NSNumber *angle;

/** Count value. */
@property (strong, nonatomic) NSNumber *count;

/** Sum of the rez. accelerations. */
@property (strong, nonatomic) NSNumber *sumRezAcceleration;

/** Maximum rez. acceleration. */
@property (strong, nonatomic) NSNumber *maxRezAcceleration;

/** Computed values */
@property (assign, nonatomic) float quickness;

/** Computed values */
@property (assign, nonatomic) float acceleration;

@end

/** @} */
