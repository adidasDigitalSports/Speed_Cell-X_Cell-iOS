#import <Foundation/Foundation.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Values representing the current working state of the FitSmart device.
 */
typedef enum : NSUInteger {
    ADIFitSmartStateUnknown = 0,
    ADIFitSmartStateProductionTestMode = 2,
    ADIFitSmartStatActive = 3,
    ADIFitSmartStateWorkout = 4,
    ADIFitSmartStateCommunication = 6,
    ADIFitSmartStateFWUpdate = 7,
    ADIFitSmartStateDual = 8,
    ADIFitSmartStatePairing = 9

} ADIFitSmartState;

/**
 *  @brief Values representing the current working substate of the FitSmart device.
 */
typedef enum : NSUInteger {
    ADIFitSmartSubstateUknown = 0,
    ADIFitSmartSubStateWorkoutConfigured = 1,
    ADIFitSmartSubStateWorkoutOngoing = 2,
    ADIFitSmartSubStateWorkoutPaused = 3

} ADIFitSmartSubState;

/**
 *  @brief  Values representing the zone Colors available on the FitSmart device.
 */
typedef enum : NSUInteger {
    ADIFitSmartDualModeZoneColorBlue = 1,
    ADIFitSmartDualModeZoneColorGreen = 2,
    ADIFitSmartDualModeZoneColorYellow = 3,
    ADIFitSmartDualModeZoneColorRed = 4,
} ADIFitSmartDualModeZoneColor;

/**
 *  @brief  Values representing the dual mode event types on the FitSmart device.
 */
typedef enum : NSUInteger {

    ADIFitSmartDualModeEventTypeHeartRateFound = 0x01,
    ADIFitSmartDualModeEventTypeHeartRateNotDetected = 0x02,
    ADIFitSmartDualModeEventTypeHeartRateLost = 0x03,

    ADIFitSmartDualModeEventTypeCancel = 0x04,
    ADIFitSmartDualModeEventTypeStart = 0x05,
    ADIFitSmartDualModeEventTypePause = 0x06,
    ADIFitSmartDualModeEventTypeResume = 0x07,
    ADIFitSmartDualModeEventTypeStop = 0x08,
    ADIFitSmartDualModeEventTypeSceneComplete = 0x09,
    ADIFitSmartDualModeEventTypeSceneCancelled = 0x0A,
    ADIFitSmartDualModeEventTypeSplit = 0x0B,
    ADIFitSmartDualModeEventTypeBatteryBelow3 = 0x0C,
    ADIFitSmartDualModeEventTypeEndSummary = 0x0D,
} ADIFitSmartDualModeEventType;

/** @} */
