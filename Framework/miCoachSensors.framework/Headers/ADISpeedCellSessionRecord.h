
@interface ADISpeedCellSessionRecord : NSObject

/** The timestamp. The number of seconds from the reference date, 1 January 1970, GMT*/
@property (assign, nonatomic) uint32_t timestamp;

/** The current speed in meters/second */
@property (assign, nonatomic) float speed;

/** The current cadence in rpm (revolutions per minute) */
@property (assign, nonatomic) int cadence;

/** The current stride rate (double of cadence) */
@property (assign, nonatomic) int strideRate;

/** The current pace in seconds/meter */
@property (assign, nonatomic) float pace;

/** Cumulative step count */
@property (assign, nonatomic) int totalStepCount;

/** Total distance in meters */
@property (assign, nonatomic) float totalDistance;

/** Array of 5 actual speed samples */
@property (strong, nonatomic) NSArray *speedArray;

@end
