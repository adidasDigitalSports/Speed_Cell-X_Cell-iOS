
#import <Foundation/Foundation.h>
#import "ADISpeedCellSessionRecord.h"
#import "ADISpeedCellGender.h"
#import "ADISpeedCellZoneInfo.h"


/**
 Public facade for SPEED_CELL business rules - DLE implementation.
 */
@interface ADISpeedCellBusinessRules : NSObject

/**
 Initializer, calling it will initialize this object to be able to provide calculated metrics.
 Input is parsed first, then general calculations applied.
 Call calculateInfoForBasketball method to calculate basketball game specific metrics.
 
 @param session Raw binary file downloaded from SPEED_CELL.
*/
- (id)initWithSpeedCellRawSession:(NSData *)session;

/**
 
 Designed initializer with time-correction calculation.
 
 @param session     Raw binary file downloaded from SPEED_CELL.
 @param sensorTime  Time from sensor's internal clock
 @param currentTime Time provided by operating system.
 
 @return self
 */
- (id)initWithSpeedCellRawSession:(NSData *)session withSensorTime:(NSDate *)sensorTime withCurrentTime:(NSDate *)currentTime;

/**
 Initialize object with session record array.
 
 @param sessionRecordArray Array returned by self.sessionRecordArray method.
 */
- (id)initWithSessionRecordArray:(NSArray *)sessionRecordArray;

/**
 This method must be called before zone related calls to use correct zone threshold settings.
 
 @param ageInYears User's age in years.
 @param gender User's gender: 0 = male, 1 = female.
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

// array of DLESessionRecord
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
