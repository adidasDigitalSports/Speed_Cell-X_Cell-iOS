#import <Foundation/Foundation.h>
#import <miCoachSensors/ADIFitSmartRelatedTypes.h>

@class ADIFitSmartUserConfiguration;
@class ADIFitSmartActivityRecord;
@class ADIFitSmartDeviceInfo;
@class ADIFitSmartWorkout;
/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Protocol containing FitSmart specific methods.
 */
@protocol ADIFitSmartSensorSpecificProtocol <NSObject>

/**
 *  @brief Switches the device to communication state.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart startSync example
 */
- (void)startSync;

/**
 *  @brief Switches the device back to active state.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart endSync example
 */
- (void)endSync:(void (^)(BOOL success))completion;

/**
 *  @brief Pairs the device.
 *  This function must be called after each connection.
 *  @param userID User identification number.
 *  @param completion Block object to be executed on completion of pairing. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 */
- (void)pair:(NSNumber *)userID completion:(void (^)(BOOL success))completion;

/**
 *  @brief Pairs the device and uploads user configuration and sets time to the operating systems time.
 *  This is a convinient method to connect to a device which is in factory reset state, where user configuration must be uploaded. Can be used for already configured FitSmart.
 *  The FitSmart will be associated with the userConfiguration parameters uniqueUserIdentifier field.
 *  @param userConfiguration User configuration with at least the uniqueUserIdentifier field set properly.
 *  @param completion Block object to be executed on completion of pairing. This error instance set to nil if the operation was successful, or contain error details in case of failure.
 */
- (void)pairWithUserConfiguration:(ADIFitSmartUserConfiguration *)userConfiguration completion:(void (^)(NSError *error))completion;

/**
 *  @brief Deletes every session on the device.
 *  @param completion Block object to be executed when deletion is complete.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart delete all sessions example
 */
- (void)deleteAllSessions:(void (^)(BOOL success))completion;

/**
 *  @brief Downloads every activity record from the device.
 *
 *  @param completion Block object to be executed on completion of download. This block has no return value and takes two arguments: an ActivityRecord and an NSError containing the error. On success the error is nil.
 * 
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart download activity records example
 */
- (void)downloadActivityRecords:(void (^)(ADIFitSmartActivityRecord *record, NSError *error))completion;

/**
 *  @brief Deletes every activity record on the device.
 *  @param completion Block object to be executed when deletion is complete. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 *
*  \snippet ADIFitSmartFeatureExamples.m FitSmart delete activity records example
 */
- (void)deleteActivityRecords:(void (^)(BOOL success))completion;

/**
 *  @brief Writes the new calibration factor to the device.
 *  @param calibrationFactor New value of the calibration factor.
 *  @param completion Block object to be executed when write is complete. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart write calibration factor example
 */
- (void)writeCalibrationFactor:(float)calibrationFactor completion:(void (^)(BOOL success))completion;

/**
 *  @brief Reads the new calibration factor to the device.
 *  @param completion Block object to be executed when deletion is complete. This block has no return value and takes two arguments: a float value of the read calibrationFactor and a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart read calibration factor example
 */
- (void)readCalibrationFactor:(void (^)(float calibrationFactor, BOOL success))completion;

/**
 *  @brief  Writes the new user configuration to the device.
 *
 *  @param userConfiguration New user configuration to be uploaded.
 *  @param completion        Block object to be executed when write is complete. The block has no return value and takes one argument: a boolean value being true if the operation was successful, flase otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart write user configuration example
 */
- (void)writeUserConfiguration:(ADIFitSmartUserConfiguration *)userConfiguration completion:(void (^)(BOOL success))completion;

/**
 *  @brief Reads the battery level of the device.
 *  @param completion Block object to be executed when read is complete. This block has no return value and takes one argument: an integer value of the battery level.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart read battery level example
 */
- (void)readBatteryLevel:(void (^)(NSUInteger batteryLevel))completion;

/**
 *  @brief  Writes the workout to the device.
 *
 *  @param workout    New workout to be uploaded to the device.
 *  @param completion Block object to be executed when write is complete. The block has no return value and takes one argument: a boolean value being true if the operation was successful, flase otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart upload workout example
 */
- (void)uploadWorkout:(ADIFitSmartWorkout*) workout completion:(void (^)(BOOL success))completion;

/**
 *  @brief  Writes the workout to the device eith US Dates.
 *
 *  @param workout    New workout to be uploaded to the device.
 *  @param completion Block object to be executed when write is complete. The block has no return value and takes one argument: a boolean value being true if the operation was successful, flase otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart upload workout with US dates example
 */
- (void)uploadWorkoutWithUSDates:(ADIFitSmartWorkout*) workout completion:(void (^)(BOOL success))completion;

/**
 *  @brief Reads the DeviceInfo of the device.
 *
 *  @param completion Block object to be executed when read is complete. This block has no return value and takes one argument: a deviceInfo containing the properties of the device.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart get device info example
 */
- (void)getDeviceInfo:(void (^)(ADIFitSmartDeviceInfo *deviceInfo))completion;

//- (BOOL)shouldUpdateToFirmwareWithVersion:(NSString*)version;

/**
 *  @brief Reads the state and substate of the device.
 *  @param completion Block object to be executed when read is complete. This block has no return value and takes two arguments: The state and substate of the device.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart get device state example
 */
- (void)getDeviceState:(void (^)(ADIFitSmartState state, ADIFitSmartSubState subState))completion;

/**
 *  @brief Reads the percentage of free space available for sessions on the device.
 *  @param completion Block object to be executed when read is complete. This block has no return value and takes one argument, an unsigned integer value of the result ranging from 0 to 100.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart get available space percent for sessions example
 */
- (void)getAvailableSpacePercentForSessions:(void (^)(NSUInteger percent))completion;

/**
 *  @brief Reads the percentage of free space available for activity records on the device.
 *  @param completion Block object to be executed when read is complete. This block has no return value and takes one argument, an unsigned integer value of the result ranging from 0 to 100.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart get available space percent for activity tracker example
 */
- (void)getAvailableSpacePercentForActivityTracker:(void (^)(NSUInteger percent))completion;

/**
 *  @brief Resets the device.
 *  @param completion Block object to be executed when reset is complete. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart user reset device example
 */
- (void)userResetDevice:(void (^)(BOOL success))completion;

/**
 *  @brief Reboots the device with factory reset. All data on the device will be lost.
 *  @param completion Block object to be executed when reset is complete. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart reboot device with factory reset example
 */
- (void)rebootDeviceWithFactoryReset:(void (^)(BOOL success))completion;

/**
 *  @brief Reboots the device.
 *  @param completion Block object to be executed when reset is complete. This block has no return value and takes one argument: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart reboot device without factory reset example
 */
- (void)rebootDeviceWithoutFactoryReset:(void (^)(BOOL success))completion;

/**
 *  @brief Updates the firmware on the device.
 *
 *  @param firmwareData Firmware data got from an official source.
 *  @param completion Block object to be executed on completion of the firmware upgrade. This block has no return value and takes one arguments: a boolean value being true if the operation was successful, false otherwise.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart update firmware example
 */
- (void)updateFirmware:(NSData*)firmwareData completion:(void (^)(BOOL success))completion;

@optional
/**
 *  @brief Sets up the progress change handler for firmware upgrade.
 *
 *  Progress calculation is based on bytesizes, so in case of some communication error or data loss the progress could not reach 100.
 *
 *  @param handler  Block object to be executed when the progress changes. This block has no return value and takes an NSInteger value, between 0 and 100.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart set handler for firmware progress change example
 */
- (void)setHandlerForFirmwareProgressChange:(void (^)(NSInteger progress))handler;

@end

/** @} */

