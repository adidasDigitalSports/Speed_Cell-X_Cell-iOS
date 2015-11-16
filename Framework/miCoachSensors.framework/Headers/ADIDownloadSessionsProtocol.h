#import <Foundation/Foundation.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Protocol for downloading sessions.
 */
@protocol ADIDownloadSessionsProtocol <NSObject>

/**
 *  @brief This method acquires the number of available sessions to download from the device.
 *
 *  @param completion Block object to be executed on completion of acquiring session count. This block has no return value and takes two arguments: an NSInteger value and an NSError containing the error. On success the error is nil.
 */
- (void)getSessionCount:(void (^)(NSUInteger sessionCount, NSError *error))completion;

/**
 *  @brief Downloads every session from the device in a binary format.
 *
 *  @param completion Block object to be executed on completion of download. This block has no return value and takes two arguments: an NSArray, which holds NSData instances of the downloaded binary sessions and an NSError containing the error. On success the error is nil.
 */
- (void)downloadSessionsBinary:(void (^)(NSArray *rawSessions, NSError *error))completion;

@optional
/**
 *  @brief Sets up the progress change handler.
 *
 *  The progress will only change, when an all session download is initiated. Progress calculation is based on bytesizes, so in case of some communication error or data loss the progress could not reach 100.
 *
 *  @param handler  Block object to be executed when the progress changes. This block has no return value and takes an NSInteger value, between 0 and 100.
 */
- (void)setHandlerForDownloadProgressChange:(void (^)(NSInteger progress))handler; /* {
    [self setHandlerForDownloadProgressChange:handler withNotificationLimit:1];
}*/

/**
 *  @brief Sets up the progress change handler.
 *
 *  The progress will only change, when an all session download is initiated. Progress calculation is based on bytesizes, so in case of some communication error or data loss the progress could not reach 100.
 *
 *  @param handler  Block object to be executed when the progress changes. This block has no return value and takes an NSInteger value, between 0 and 100.
 *
 *  @param limit Notification limit, use values between 1 and 100 to make the notification more or less frequent.
 */
- (void)setHandlerForDownloadProgressChange:(void (^)(NSInteger progress))handler withNotificationLimit:(NSUInteger)limit;

/**
 *  @brief  Continues all session download.
 */
- (void)continueDownloadAll;

/**
 *  @brief  Aborts all session download.
 */
- (void)abortDownloadAll;

/**
 *  @brief Downloads every session from the remote device.
 *
 *  @param completion Block object to be executed on completion of download. This block has no return value and takes two arguments: an NSArray of parsed session instances and an NSError containing the error. On success the error is nil.
 */
- (void)downloadSessions:(void (^)(NSArray *sessions, NSError *error))completion;

@end

/** @} */
