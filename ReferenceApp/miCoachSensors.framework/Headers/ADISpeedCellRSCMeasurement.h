#import <Foundation/Foundation.h>
#import <miCoachSensors/ADISpeedCellBusinessRulesProtocol.h>

/**
 *  @brief This class holds stride rate data.
 *  @ingroup SPEEDCELL_BINDING_LAYER
 */
@interface ADISpeedCellRSCMeasurement : NSObject <ADIRSCMeasurementProtocol>

@property (assign, nonatomic) int flags;
/**
 *  @brief Running speed measured in meter per seconds.
 */
@property (assign, nonatomic) double runningSpeed;

/**
 *  @brief Cadence measured in strides per minute.
 */
@property (assign, nonatomic) int cadence;

/**
 *  @brief Total distance measured in meters.
 */
@property (assign, nonatomic) double totalDistance;

@end
