#import <UIKit/UIKit.h>

//! Project version number for miCoachSensorsUIFramework.
FOUNDATION_EXPORT double miCoachSensorsUIVersionNumber;

//! Project version string for miCoachSensorsUIFramework.
FOUNDATION_EXPORT const unsigned char miCoachSensorsUIVersionString[];

/**
 *  @brief This class is used to access the public methods of the Framework.
 */
@interface miCoachSensorsUI : NSObject

/**
 *  @brief Instantiates a view controller sequence managed by a navigation view controller in order to discover a remote device selected by the user.
 *
 *  The remote device is an instance of an ADIGeneralDevice subclass.
 *
 *  @param completion Block object to be executed on completion of remote device discovery and selection. This block has no return value and takes two arguments: the initialized device and the error that occured during the process. If the process was successfull the error is nil, otherwise the device is nil and the error contains an instance of NSError.
 *
 *  @return Returns a UINavigationViewConroller instance that should be presented.
 */
+ (UINavigationController *)viewControllerWithPairCompletionHandler:(void (^)(id device, NSError *error))completion;

/**
 *  @brief Instantiates a view controller sequence managed by a navigation view controller in order to download sessions from a remote device selected by the user.
 *
 *  Depending on the selected device type an element of the array could be raw binary NSData or a parsed session instance.
 *
 *  @param userConfig   Optional user configuration, only needed for the FitSmart device.
 *  @param completion Block object to be executed on completion of download. This block has no return value and takes two arguments: the downloaded sessions and the error that occured during the process. If the process was successfull the error is nil, otherwise the sessions array is an empty instance of NSArray.
 *
 *  @return Returns a UINavigationViewConroller instance that should be presented.
 */
+ (UINavigationController *)downloadSessionFromDeviceWithUserConfiguration:(ADIFitSmartUserConfiguration *)userConfig withCompletionHandler:(void (^)(NSArray *sessions, NSError *error))completion;

/**
 *  @brief Instantiates a view controller with the given ADIGenerealDevice instance which manages to download sessions from the remote device while presenting progress.
 *
 *  @param device     Instance of an ADIGenerealDevice subclass which represents the remote device.
 *  @param userConfig   Optional user configuration, only needed for the FitSmart device
 *  @param completion Block object to be executed on completion of download. This block has no return value and takes two arguments: the downloaded sessions and the error that occured during the process. If the process was successfull the error is nil, otherwise the sessions array is an empty instance of NSArray.
 *
 *  @return Returns a UIViewConroller instance that should be presented.
 */
+ (UIViewController *)downloadSessionFromDevice:(id)device withUserConfiguration:(ADIFitSmartUserConfiguration *)userConfig withCompletionHandler:(void (^)(NSArray *sessions, NSError *error))completion;

/**
 *  @brief Creates an ADIXCellDevice instance from the given serial number.
 *
 *  @param serialNumber A valid non nil serial number of the remote device.
 *
 *  @return Returns an ADIXCellDevice instance identified with the given serial number.
 */
+ (id)xcellDeviceWithSerialNumber:(NSString *)serialNumber;

/**
 *  @brief Creates an ADISpeedCellDevice instance form the given serial number.
 *
 *  @param serialNumber A valid non nil serial number of the remote device.
 *
 *  @return Returns an ADISpeedCellDevice instance identified with the given serial number.
 */
+ (id)speedcellDeviceWithSerialNumber:(NSString *)serialNumber;

/**
 *  @brief Creates an ADIFitSmartDevice instance form the given serial number.
 *
 *  @param serialNumber A valid non nil serial number of the remote device.
 *
 *  @return Returns an ADIFitSmartDevice instance identified with the given serial number.
 */
+ (id)fitSmartDeviceWithSerialNumber:(NSString *)serialNumber;


@end
