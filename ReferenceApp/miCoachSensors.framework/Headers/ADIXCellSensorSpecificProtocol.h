#import <Foundation/Foundation.h>
#import <miCoachSensors/ADIXCellRelatedTypes.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Protocol containing XCell specific methods.
 */
@protocol ADIXCellSensorSpecificProtocol <NSObject>

/**
 *  @brief This function responsible for getting device status.
 *  @param completion Block object to be executed when device status is acquired.
 */
- (void)deviceStatus:(void (^)(ADIXCellDeviceStatus status, NSError *error))completion;

/**
 *  @brief Downloads the current session from the device.
 *  @param completion Block object to be executed on completion of current session download.
 */
- (void)downloadCurrentSessionBinary:(void (^)(NSData *session, NSError *error))completion;

/**
 *  @brief Removes the current session from the device.
 *  @param completion Block object to be executed on completion of current session delete.
 */
- (void)eraseCurrentSession:(void (^)(BOOL success))completion;

/**
 *  @brief Sends out a position set command with the desired position.
 *
 *  @param position A valid position enumareted type.
 */
- (void)setPosition:(ADIXCellDevicePosition)position;

@end

/** @} */
