#import <Foundation/Foundation.h>

/**
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  Coaching method types.
 */
typedef enum : NSUInteger {
    ADIFitSmartCoachingMethodPreferenceHeartRate = 0,
    ADIFitSmartCoachingMethodPreferencePace

} ADIFitSmartCoachingMethodPreference;

/**
 *  @brief  Screen metric types.
 */
typedef enum : NSUInteger {
    ADIFitSmartWorkoutViewPreferenceSingleMetrics = 0,
    ADIFitSmartWorkoutViewPreferenceDoubleMetrics

} ADIFitSmartWorkoutViewPreference;

/**
 *  @brief  Unit types.
 */
typedef enum : NSUInteger {
    ADIFitSmartUnitPreferenceMetric = 0,
    ADIFitSmartUnitPreferenceImperial

} ADIFitSmartUnitPreference;

/**
 *  @brief  Time format types.
 */
typedef enum : NSUInteger {
    ADIFitSmartTimeFormatPreference24H = 0,
    ADIFitSmartTimeFormatPreference12H

} ADIFitSmartTimeFormatPreference;

/**
 *  @brief  Genders preferences.
 */
typedef enum : NSUInteger {
    ADIFitSmartGenderPreferenceFemale = 0,
    ADIFitSmartGenderPreferenceMale

} ADIFitSmartGenderPreference;

/**
 *  @brief  Split mode types.
 */
typedef enum : NSUInteger {
    ADIFitSmartSplitModePreferenceTime = 0,
    ADIFitSmartSplitModePreferenceDistance = 1

} ADIFitSmartSplitModePreference;

/**
 *  @brief  Auto split mode types.
 */
typedef enum : NSUInteger {
    ADIFitSmartAutoSplitModeNoSplit = 0,
    ADIFitSmartAutoSplitModeTime = 1,
    ADIFitSmartAutoSplitModeDistance = 2

} ADIFitSmartAutoSplitMode;

/**
 *  @brief  Activity tracker target types.
 */
typedef enum : NSUInteger {
    ADIFitSmartActivityTargetPreferenceSteps = 0,
    ADIFitSmartActivityTargetPreferenceDistance = 1,
    ADIFitSmartActivityTargetPreferenceCalories = 2

} ADIFitSmartActivityTargetPreference;

/** @}
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  Class that can be used to set user configuration, which later can be uploaded to the FitSmart device.
 */
@interface ADIFitSmartUserConfiguration : NSObject

/**
 *  @brief  User ID.
 */
@property (nonatomic, assign) NSNumber *uniqueUserIdentifier;

/**
 *  @brief  Top of red heart rate zone in BPM.
 */
@property (nonatomic, assign) int heartRateZoneRedTopInBPM;

/**
 *  @brief  Top of yellow heart rate zone in BPM.
 */
@property (nonatomic, assign) int heartRateZoneYellowTopInBPM;

/**
 *  @brief  Top of green heart rate zone in BPM.
 */
@property (nonatomic, assign) int heartRateZoneGreenTopInBPM;

/**
 *  @brief  Top of blue heart rate zone in BPM.
 */
@property (nonatomic, assign) int heartRateZoneBlueTopInBPM;

/**
 *  @brief  Bottom of blue heart rate zone in BPM.
 */
@property (nonatomic, assign) int heartRateZoneBlueMinInBPM;

/**
 *  @brief  Weight of the user in kg.
 */
@property (nonatomic, assign) int weightInKilograms;

/**
 *  @brief  Height of the user in cm.
 */
@property (nonatomic, assign) int heightInCentiMeters;

/**
 *  @brief  Age of the user in years.
 */
@property (nonatomic, assign) int ageInYears;

/**
 *  @brief  Top of red pace zone in s/km.
 */
@property (nonatomic, assign) int paceZoneRedTopInSecondsPerKM;

/**
 *  @brief  Top of yellow pace zone in s/km.
 */
@property (nonatomic, assign) int paceZoneYellowTopInSecondsPerKM;

/**
 *  @brief  Top of green pace zone in s/km.
 */
@property (nonatomic, assign) int paceZoneGreenTopInSecondsPerKM;

/**
 *  @brief  Top of blue pace zone in s/km.
 */
@property (nonatomic, assign) int paceZoneBlueTopInSecondsPerKM;

/**
 *  @brief  Bottom of blue pace zone in s/km.
 */
@property (nonatomic, assign) int paceZoneBlueMinInSecondsPerKM;

/**
 *  @brief  Property to set if the watch view is locked.
 */
@property (nonatomic, assign) BOOL enableLockOfWatchView;

/**
 *  @brief  Coaching method: HeartRate or time based.
 */
@property (nonatomic, assign) ADIFitSmartCoachingMethodPreference coachingMethod;

/**
 *  @brief  Workout view setting: single or double.
 */
@property (nonatomic, assign) ADIFitSmartWorkoutViewPreference workoutView;

/**
 *  @brief  Unit preference: metric or imperial.
 */
@property (nonatomic, assign) ADIFitSmartUnitPreference unit;

/**
 *  @brief  Timeformat preference: 12 or 24 hours.
 */
@property (nonatomic, assign) ADIFitSmartTimeFormatPreference timeFormat;

/**
 *  @brief  Gender of the user.
 */
@property (nonatomic, assign) ADIFitSmartGenderPreference gender;

/**
 *  @brief  Split mode preference.
 */
@property (nonatomic, assign) ADIFitSmartSplitModePreference splitMode;

/**
 *  @brief  Auto split mode preference.
 */
@property (nonatomic, assign) ADIFitSmartAutoSplitMode autoSplitMode;

/**
 *  @brief  Value of auto split.
 */
@property (nonatomic, assign) int autoSplitValue;

/**
 *  @brief  Array of metrics. These metrics are shown during a workout.
 */
@property (nonatomic, strong) NSArray *orderOfMetricViews;

/**
 *  @brief  Stores the value if double metrics names are shown or not.
 */
@property (nonatomic) BOOL showDoubleMetricNames;

/**
 *  @brief  Enables the activity tracking.
 */
@property (nonatomic, assign) BOOL enableActivityTracking;
/**
 *  @brief  Enables the Assessment workout.
 */
@property (nonatomic, assign) BOOL enableAWorkout;

/**
 *  @brief  Activity targer type preference.
 */
@property (nonatomic, assign) ADIFitSmartActivityTargetPreference activityTrackerTargetType;

/**
 *  @brief  Activity tracker goal. The goal correlates to the target type.
 */
@property (nonatomic, assign) int activityTrackerGoal;

/**
 *  @brief  Activity tracker reset time.
 *
 *  Daily time to reset the activity tracker.
 */
@property (nonatomic, assign) int activityTrackerResetTime;

@end

/** @} */
