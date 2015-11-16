#import <Foundation/Foundation.h>
#import <miCoachSensors/ADIFitSmartRelatedTypes.h>

@class ADIFitSmartSensorReadings;
/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Protocol containing Dual Mode specific methods.
 */
@protocol ADIFitSmartDualModeProtocol <NSObject>

/**
 *  @brief Swithces the device to dual, free workout mode.
 *  @param completion Block object to be executed when mode change is complete. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart start dual mode for free workout example
 */
- (void)startDualModeForFreeWorkout:(void (^)(BOOL success))completion;

/**
 *  @brief Swithces the device to dual, assessment workout mode.
 *  @param completion Block object to be executed when mode change is complete. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart start dual mode for assessment workout example
 */
- (void)startDualModeForAssessmentWorkout:(void (^)(BOOL success))completion;

/**
 *  @brief Swithces the device to dual, coached workout mode.
 *  @param completion Block object to be executed when mode change is complete. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart start dual mode for coached workout example
 */
- (void)startDualModeForCoachedWorkout:(void (^)(BOOL success))completion;

/**
 *  @brief Swithces the device to dual, strength and flex workout mode.
 *  @param completion Block object to be executed when mode change is complete. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart start dual mode for strength and flex workout example
 */
- (void)startDualModeForStrengthAndFlexWorkout:(void (^)(BOOL success))completion;

/**
 *  @brief Checks if the device is in dual mode.
 *  @return YES if the device is in dual mode, NO otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart is in dual mode example
 */
- (BOOL)isInDualMode;

/**
 *  @brief Swithces the device back to normal, active mode.
 *  @param completion Block object to be executed when mode change is complete. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart end dual mode example
 */
- (void)endDualMode:(void (^)(BOOL success))completion;

/**
 *  @brief Sends a ready command. This should be done, after heart rate is acquired.
 *  @param completion Block object to be executed when command is responded. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart dual mode ready example
 */
- (void)dualModeReady:(void (^)(BOOL success))completion;

/**
 *  @brief Sends a start workout command.
 *  @param completion Block object to be executed when command is responded. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart dual mode start workout example
 */
- (void)dualModeStartWorkout:(void (^)(BOOL success))completion;

/**
 *  @brief Sends a stop workout command.
 *  @param completion Block object to be executed when command is responded. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart dual mode stop workout example
 */
- (void)dualModeStopWorkout:(void (^)(BOOL success))completion;

/**
 *  @brief Sends a pause workout command.
 *  @param completion Block object to be executed when command is responded. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart dual mode pause workout example
 */
- (void)dualModePauseWorkout:(void (^)(BOOL success))completion;

/**
 *  @brief Sends a resume workout command.
 *  @param completion Block object to be executed when command is responded. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart dual mode resume workout example
 */
- (void)dualModeResumeWorkout:(void (^)(BOOL success))completion;

/**
 * @brief Initiates a screen animation in assessment workout: Zone up.
 * @param color Color of the zone.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart dual mode scene AW zone up example
 */
- (void)dualModeSceneAWZoneUp:(ADIFitSmartDualModeZoneColor)color;

/**
 * @brief Initiates a screen animation in assessment workout: Zone up with vibration.
 * @param color Color of the zone.
 */
- (void)dualModeSceneAWZoneUpVibra:(ADIFitSmartDualModeZoneColor)color;

/**
 * @brief Initiates a screen animation in assessment workout: Zone down.
 * @param color Color of the zone.
 */
- (void)dualModeSceneAWZoneDown:(ADIFitSmartDualModeZoneColor)color;

/**
 * @brief Initiates a screen animation in assessment workout: Zone with time and percentage.
 * @param color Color of the zone.
 * @param timeInZone Time spent in zone.
 * @param zonePercentage Percentage spent in zone.
 */
- (void)dualModeSceneAWZone:(ADIFitSmartDualModeZoneColor)color timeInZone:(int)timeInZone zonePercentage:(int)zonePercentage;

/**
 * @brief Initiates a screen animation in assessment workout: countdown before workout end. 
 */
- (void)dualModeSceneAWEndCountdown;

/**
 * @brief Initiates a screen animation in a workout: Speed up.
 * @param color Color of the zone.
 */
- (void)dualModeSceneSpeedUp:(ADIFitSmartDualModeZoneColor)color;

/**
 * @brief Initiates a screen animation in a workout: Slow down.
 * @param color Color of the zone.
 */
- (void)dualModeSceneSlowDown:(ADIFitSmartDualModeZoneColor)color;

/**
 * @brief Initiates a screen animation in a workout: Keep up.
 * @param color Color of the zone.
 */
- (void)dualModeSceneKeepUp:(ADIFitSmartDualModeZoneColor)color;

/**
 * @brief Initiates a screen animation in a workout: Change zone up.
 * @param color Color of the zone.
 * @param durationInSeconds Duration in seconds.
 */
- (void)dualModeSceneZoneChangeUp:(ADIFitSmartDualModeZoneColor)color duration:(NSTimeInterval)durationInSeconds;

/**
 * @brief Initiates a screen animation in a workout: Change zone down.
 * @param color Color of the zone.
 * @param durationInSeconds Duration in seconds.
 */
- (void)dualModeSceneZoneChangeDown:(ADIFitSmartDualModeZoneColor)color duration:(NSTimeInterval)durationInSeconds;

/**
 * @brief Initiates a screen animation in a workout: Keep up zone.
 * @param color Color of the zone.
 * @param durationInSeconds Duration in seconds.
 */
- (void)dualModeSceneZoneChangeKeepUp:(ADIFitSmartDualModeZoneColor)color duration:(NSTimeInterval)durationInSeconds;

/**
 * @brief Initiates a screen animation in a workout: Split time based on timestamps.
 * @param numberOfSplits Number of splits.
 * @param time1 First time.
 * @param time2 Second time.
 */
- (void)dualModeSceneSplitTime:(int)numberOfSplits time1:(int)time1 time2:(int)time2;

/**
 * @brief Initiates a screen animation in a workout: Split time based on distance.
 * @param numberOfSplits Number of splits.
 * @param distance1 First distance.
 * @param distance2 Second distance.
 */
- (void)dualModeSceneSplitDistance:(int)numberOfSplits distance1:(int)distance1 distance2:(int)distance2;

/**
 * @brief Initiates a screen animation in a workout: Auto lap based on time.
 * @param numberOfSplits Number of splits.
 * @param time1 First time.
 * @param time2 Second time.
 */
- (void)dualModeSceneAutoLapTime:(int)numberOfSplits time1:(int)time1 time2:(int)time2;

/**
 * @brief Initiates a screen animation in a workout: Auto lap based on distance.
 * @param numberOfSplits Number of splits.
 * @param distance1 First distance.
 * @param distance2 Second distance.
 */
- (void)dualModeSceneAutoLapDistance:(int)numberOfSplits distance1:(int)distance1 distance2:(int)distance2;

/**
 * @brief Initiates a screen animation in a workout: Display heart rate lost.
 */
- (void)dualModeDisplayHeartRateLost;

/**
 * @brief Initiates a screen animation in a workout: Display heart rate found.
 */
- (void)dualModeDisplayHeartRateFound;

/**
 * @brief Sets a handler for incoming notifications from the device.
 * @param handler This block has no return value and takes one argument: an eventType, which holds the type of the incoming event.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart set handler for dual mode event notification example
 */
- (void)setHandlerForDualModeEventNotification:(void (^)(ADIFitSmartDualModeEventType eventType))handler;

/**
 *  @brief  Sets a handler for incoming sensor reading from the device.
 *
 *  @param handler This block has no return value and takes one argument: a sensor readings, which holds the incoming sensor values.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart set handler for dual mode sensor readings example
 */
- (void)setHandlerForDualModeSensorReadings:(void (^)(ADIFitSmartSensorReadings *readings))handler;

/**
 *  @brief  Writes the new instant SensorReadings metrics to the device.
 *
 *  @param metrics    The new instant metrics passed to the device.
 *  @param completion Block object to be executed on completion of the metrics upgrade. This block has no return value and takes one arguments: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart dual mode update instant metrics example
 */
- (void)dualModeUpdateInstantMetrics:(ADIFitSmartSensorReadings *)metrics completion:(void (^)(BOOL success))completion;

/**
 *  @brief  Writes the new summary of SensorReadings metrics to the device.
 *
 *  @param metrics    The new summary metrics passed to the device.
 *  @param completion Block object to be executed on completion of the metrics upgrade. This block has no return value and takes one arguments: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart dual mode update summary metrics example
 */
- (void)dualModeUpdateSummaryMetrics:(ADIFitSmartSensorReadings *)metrics completion:(void (^)(BOOL success))completion;


@end

/** @} */


