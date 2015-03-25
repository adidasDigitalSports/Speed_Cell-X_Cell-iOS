#import <Foundation/Foundation.h>
#import <miCoachSensors/ADISpeedCellBusinessRulesProtocol.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Block handler type definition for handling stride rate updates.
 *
 *  @param strideRateData An acquired stride rate object conforming to ADIRSCMeasurementProtocol.
 *  @param error          An NSError object if error happened while capturing stride rate, otherwise nil.
 */
typedef void (^ADIStrideRateHandler)(NSObject<ADIRSCMeasurementProtocol> *strideRateData, NSError *error);

/**
 *  @brief Protocol for capturing stride rate updates.
 */
@protocol ADIStrideRateProtocol <NSObject>

/**
 *  @brief Starts stride rate updates with a specific handler.
 *
 *  @param handler A block that is invoked with each update to handle new stride rate data. The block must conform to the ADIStrideRateHandler type.
 */
- (void)startStrideRateUpdatesWithHandler:(ADIStrideRateHandler)handler;

@end

/** @} */
