
#import <miCoachSensors/ADIXCellSensorSpecificProtocol.h>
#import <miCoachSensors/ADISensorTimeProtocol.h>
#import <miCoachSensors/ADIDownloadSessionsProtocol.h>
#import <miCoachSensors/ADIAugmentedFeedbackProtocol.h>
#import <miCoachSensors/ADIHeartRateProtocol.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Protocol for an XCell device.
 *
 *  This protocol is a composition of protocols, covering all XCell functionality.
 */
@protocol ADIXCellSensorProtocol <ADIXCellSensorSpecificProtocol, ADISensorTimeProtocol, ADIDownloadSessionsProtocol, ADIAugmentedFeedbackProtocol, ADIHeartRateProtocol>

@end

/** @} */