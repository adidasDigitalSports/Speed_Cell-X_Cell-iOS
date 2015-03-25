#import <Foundation/Foundation.h>

#import <miCoachSensors/ADISensorTimeProtocol.h>
#import <miCoachSensors/ADIDownloadSessionsProtocol.h>
#import <miCoachSensors/ADISpeedCellSensorSpecificProtocol.h>
#import <miCoachSensors/ADIStrideRateProtocol.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Protocol for an SpeedCell device.
 *
 *  This protocol is a composition of protocols, covering all SpeedCell functionality.
 */
@protocol ADISpeedCellSensorProtocol <ADISensorTimeProtocol, ADIDownloadSessionsProtocol, ADISpeedCellSensorSpecificProtocol, ADIStrideRateProtocol>

@end

/** @} */
