#import <Foundation/Foundation.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Protocol containing SpeedCell specific methods.
 */
@protocol ADISpeedCellSensorSpecificProtocol <NSObject>

/**
 *  This method is responsible for downloading the directory entries from the device.
 *
 *  @param completion A block object to be executed when the download ends.  This block has no return value and takes two arguments: an NSArray instance which holds the downloaded ADISpeedCellDirectoryEntry entries and an NSError containing the error. On success the error is nil.
 */
- (void)downloadDirectory:(void (^)(NSArray *directoryEntries, NSError *error))completion;

/**
 *  @brief This methods is responsible for start downloading the session file specified with the given index.
 *
 *  @param index The index of the session file to download.
 *  @param completion Block object to be executed on completion of file download.  This block has no return value and takes two arguments: the downloaded raw binary file data and an NSError containing the error. On success the error is nil.
 */
- (void)downloadFile:(NSUInteger)index completion:(void (^)(NSData *data, NSError *error))completion;

/**
 *  @brief Indicating already downloaded sessions will be downloaded again from remote device.
 *
 *  @return Returns YES if download all sessions will include already downloaded sessions.
 */
- (BOOL)downloadAlreadyDownloadedSessions;

/**
 *  @brief Setting to YES enables to download already downloaded sessions from remote device.
 *
 *  @param downloadAlreadyDownloadedSessions Boolean value indicating already downloaded sessions should be included in session download.
 */
- (void)setDownloadAlreadyDownloadedSessions:(BOOL)downloadAlreadyDownloadedSessions;

@end

/** @} */
