
#import <Foundation/Foundation.h>
#import "ADISpeedCellSessionRecord.h"
#import "ADISpeedCellGender.h"
#import "ADISpeedCellZoneInfo.h"


/**
 * @brief This class can parse a session downloaded from SPEED_CELL sensor.
 * @discussion Besides parsing the binary data downloaded from the SPEED_CELL sensor and creating ADISpeedCellSession objects, this class
 * provides more metrics, derived from the parsed session. This metrics are sport type specific values, like "bursts" for basketball. 
 * If persistency is needed for these values, it is enough to persist only sessionRecordArray containing ADISpeedCellSessionRecord objects,
 * because you can initialize this class with sessionRecordArray and derived values can be recalculated on demand.
 */
@interface ADISpeedCellBusinessRules : NSObject

/**
 @brief Initializer, calling it will initialize this object to be able to provide calculated metrics.
 @discussion Input is parsed first, then general calculations applied.
 Call calculateInfoForBasketball, calculateInfoForTennis or calculateInfoForFootball method to calculate game specific metrics.
 
 @param session Raw binary file downloaded from SPEED_CELL.
*/
- (id)initWithSpeedCellRawSession:(NSData *)session;

/**
 @brief Designed initializer with time-correction calculation.
 @discussion This initializer is useful when the SPEED_CELL recorded a session after battery replacement. In such case, timestamp values
 for data points will be invalid (relative time elapsed in addition to factory default, which is unix epoch time). Using this initializer
 timestamps will be fixed, using time retrieved from sensor, and current local time.
 
 @param session     Raw binary file downloaded from SPEED_CELL.
 @param sensorTime  Time from sensor's internal clock
 @param currentTime Time provided by operating system.
 
 @return self
 */
- (id)initWithSpeedCellRawSession:(NSData *)session withSensorTime:(NSDate *)sensorTime withCurrentTime:(NSDate *)currentTime;

/**
 @brief Initialize object with session record array.
 @discussion This method can be used to initialize the object from a previously parsed session, provided by the sessionRecordArray method.
 The sessionRecordArray is sufficient to be persisted, so later all derived values can be recalculated.
 
 @param sessionRecordArray Array returned by sessionRecordArray method.
 */
- (id)initWithSessionRecordArray:(NSArray *)sessionRecordArray;

/**
 This method must be called before zone related calls in order to use correct zone threshold settings.
 
 @param ageInYears User's age in years.
 @param gender     User's gender: 0 = male, 1 = female.
 @param speedZones The user's speed zones.
 */
- (void)setupZonesWithAge:(int)ageInYears withGender:(ADISpeedCellGender)gender withSpeedZones:(ADISpeedCellZoneInfo *)speedZones;

/**
 This method has to be called to initiate calculations for Basketball and Handball specific metrics.
 */
- (void)calculateInfoForBasketball;

/**
 This method has to be called to initiate calculations for Tennis and American Football specific metrics.
 */
- (void)calculateInfoForTennis;

/**
 This method has to be called to initiate calculations for Football, Rugby and Hockey specific metrics.
 */
- (void)calculateInfoForFootball;

/**
 This method returns TRUE if the session does not contains valid data, or too short to be analysed.
 */
- (BOOL)isSessionJunk;

// Generic - for all sports

- (float)speedGameMax; // km/h
- (float)speedGameAvg; // km/h
- (int)secondsActiveGameLength;
- (int)secondsOverallGameLength;

// Basketball, Handball

- (float)speedBurstsMax; // km/h
- (float)speedBurstsAvg; // km/h
- (float)speedFastBreaksMax; // km/h
- (float)speedFastBreaksAvg; // km/h

- (float)distanceBurstsMax;
- (float)distanceBurstsAvg;
- (float)distanceFastBreaksMax;
- (float)distanceFastBreaksAvg;

- (float)distanceGameBursts;
- (float)distanceGameFastBreaks;
- (float)intensityBurstsTotal;
- (float)intensityFastBreaksTotal;


- (float)intensityBurstsMaxInFiveMinutes;
- (float)intensityBurstsAvgPerFiveMinutes;
- (float)intensityFastBreaksMaxInFiveMinutes;
- (float)intensityFastBreaksAvgPerFiveMinutes;

- (int)numberOfBursts;
- (int)numberOfFastBreaks;

// Tennis, American Football
// (for American Football, rallies are named as 'plays')

- (float)speedRallyMax;
- (float)speedRallyAvg;
- (float)distanceGameTotal;
- (float)distanceGameRallies;
- (float)distanceRalliesAvg;
- (float)distanceRalliesMax;
- (int)ralliesMaxInFiveMinutes;
- (int)ralliesAvgPerFiveMinutes;

- (int)ralliesMaxLengthInSeconds;
- (int)ralliesAvgLengthInSeconds;

- (int)numberOfRallies;

// Football, Rugby, Hockey
// (red: sprint, yellow: hi-speed, green: running, blue: jogging, gray: walking)
// (hi-intensity are sum of red and yellow zones)

- (float)distanceInHighIntensity;
- (float)distanceInRedZone;
- (float)distanceInYellowZone;
- (float)distanceInGreenZone;
- (float)distanceInBlueZone;
- (float)distanceInGrayZone;

- (float)minutesInHighIntensity;
- (float)minutesInRedZone;
- (float)minutesInYellowZone;
- (float)minutesInGreenZone;
- (float)minutesInBlueZone;
- (float)minutesInGrayZone;

- (float)secondsInHighIntensity;
- (float)secondsInRedZone;
- (float)secondsInYellowZone;
- (float)secondsInGreenZone;
- (float)secondsInBlueZone;
- (float)secondsInGrayZone;

- (int)numberOfSprints;

// array of ADISessionRecord
- (NSArray *)sessionRecordArray;

// array of NSNumbers ("@max.floatValue" should match self.maxGameSpeed)
- (NSArray *)speedArray;

- (NSArray *)distanceArray;

- (NSArray *)distanceArrayForGrayZone;
- (NSArray *)distanceArrayForGrayZonePadded;
- (NSArray *)distanceArrayForBlueZone;
- (NSArray *)distanceArrayForGreenZone;
- (NSArray *)distanceArrayForYellowZone;
- (NSArray *)distanceArrayForRedZone;


- (NSArray *)burstsDistances;

- (NSArray *)fastBreaksDistances;

- (NSArray *)ralliesDistances;

- (NSArray *)ralliesDurations;

- (NSArray *)burstsSpeeds;

- (NSArray *)fastBreakSpeeds;

- (float)speedGameMaxRunning;

@end
