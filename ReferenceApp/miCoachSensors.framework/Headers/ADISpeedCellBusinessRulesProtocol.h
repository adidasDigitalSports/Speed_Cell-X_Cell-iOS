#import <Foundation/Foundation.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Protocol for a directory entry on a SpeedCell device.
 *  
 *  You can use this to take a look at the individual files and later download them.
 */
@protocol ADISpeedCellDirectoryEntryProtocol <NSObject>

/**
 *  @brief The corresponding index of the session file. The file can be downloaded by this index.
 */
- (int)fileIndex;

/**
 *  @brief The type of the file.
 */
- (int)fileType;

/**
 *  @brief A Boolean value indicating whether the file has been ever downloaded.
 */
- (BOOL)alreadyDownloaded;

@end

/**
 *  @brief Stride rate protocol containing striderate values.
 */
@protocol ADIRSCMeasurementProtocol <NSObject>

/**
 *  @brief Current speed.
 *
 *  @return Speed in meter per second.
 */
- (double)runningSpeed;

/**
 *  @brief Current cadence.
 *
 *  @return Strides per minute.
 */
- (int)cadence;

/**
 *  @brief Total distance so far.
 *
 *  This is reseted on battery change.
 *
 *  @return distance in meters.
 */
- (double)totalDistance;

@end

/** @} */
