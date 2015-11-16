@import Foundation;

#import <miCoachSensors/ADISensorTimeProtocol.h>
#import <miCoachSensors/ADIDownloadSessionsProtocol.h>
#import <miCoachSensors/ADIFitSmartSensorSpecificProtocol.h>
#import <miCoachSensors/ADIFitSmartDualModeProtocol.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Protocol for an FitSmart device.
 *
 *  This protocol is a composition of protocols, covering all FitSmart functionality.
 */
@protocol ADIFitSmartSensorProtocol <ADISensorTimeProtocol, ADIDownloadSessionsProtocol, ADIHeartRateProtocol, ADIFitSmartSensorSpecificProtocol, ADIFitSmartDualModeProtocol>

@end

/** @} */
