#import <Foundation/Foundation.h>
#import <miCoachSensors/miCoachInterfaces.h>
#import <miCoachSensors/ADIGeneralDevice.h>

/**
 *  @brief Here you can find the documentation of how to make actions with the physical XCell device.
 *  @defgroup XCELL_DEVICE XCell Device
 *  @{
 */

typedef NSObject<ADIXCellSensorProtocol, ADIBluetoothProviderProtocol> ADIXCellBluetoothCommunicationProtocol;
typedef NSObject<ADIBluetoothDeviceProtocol> ADIXCellBluetoothDevice;
typedef NSObject<ADIXCellBusinessRulesProtocol> ADIXCellBusinessRules;

#pragma mark - ADIXCellDevice

/**
 *  @example downloadAllSessionsExample.txt
 *  @example downloadSessionExample.txt
 *  @example manageDeviceTimeExample.txt
 *  @example heartRateExample.txt
 *  @example setDevicePositionExample.txt
 *  @example augmentedFeedbackJumpExample.txt
 *  @example augmentedFeedbackShuttleExample.txt
 *  @example augmentedFeedbackReactExample.txt
 */

/**
 *  @brief The \b ADIXCellDevice class represents a remote XCell device.
 *
 *  Use this class to connect to and interact with the device. You can initialize an \b ADIXCellDevice with an \b ADIBluetoothDeviceXCell instance, that holds the necessary \b CBPeripheral object for the bluetooth communication, and with an \b ADIXCellBindingLayer instance that is responsible for the communication logic with the remote device and an \b miCoachXCellBusinessRules instance which responsible for parsing raw binary data downloaded from the remote device.
 *
 *  @include manageDeviceTimeExample.txt
 *  @include heartRateExample.txt
 */
@interface ADIXCellDevice : ADIGeneralDevice <ADIXCellSensorProtocol>

/**
 *  @brief This property stores the position of the xcell device on the user.
 *  @include setDevicePositionExample.txt
 */
@property (nonatomic) ADIXCellDevicePosition devicePosition;

/**
 *  @brief Initializes and returns an ADIXCellDevice instance with the given ADIXCellBluetoothDevice object and ADIXCellBusinessRules object.
 *
 *  @param device   An ADIBluetoothDeviceXCell instance used for communicating with the real device on bluetooth.
 *  @param protocol An ADIXCellBindingLayer instance user for creating bluetooth masseges and handling response from the device.
 *  @param businessRules A miCoachXCellBusinessRules instance used for parsing raw binary data downloaded from the remote device.
 *
 *  @return Returns an initialized ADIXCellDevice object or nil if the object could not be succesfully initialized.
 */
- (instancetype)initWithDevice:(ADIXCellBluetoothDevice *)device bluetoothProtocol:(ADIXCellBluetoothCommunicationProtocol *)protocol businessRules:(ADIXCellBusinessRules *)businessRules;

/**
 *  @brief Recieve an augmented feedback jump event from the remote device after switching the the corresponding state with \b switchToAugmentedFeedbackState:.
 *
 *  @param completion Block object to be executed on completion of capturing the jump event. This block has no return value and takes two arguments: the captured ADIXCellJumpEvent and an NSError containing the error. On success the error is nil.
 *  @include augmentedFeedbackJumpExample.txt
 */
- (void)recieveJumpEvent:(void (^)(ADIXCellJumpEvent *jump, NSError *error))completion;

/**
 *  @brief Recieve an augmented feedback shuttle event from the remote device after switching the the corresponding state with \b switchToAugmentedFeedbackState:.
 *
 *  @param completion Block object to be executed on completion of capturing the shuttle event. This block has no return value and takes two arguments: the captured ADIXCellShuttleEvent and an NSError containing the error. On success the error is nil.
 *  @include augmentedFeedbackShuttleExample.txt
 */
- (void)recieveShuttleEvent:(void (^)(ADIXCellShuttleEvent *shuttle, NSError *error))completion;

/**
 *  @brief Recieve an augmented feedback reaction event from the remote device after switching the the corresponding state with \b switchToAugmentedFeedbackState:.
 *
 *  @param completion Block object to be executed on completion of capturing the reaction event. This block has no return value and takes two arguments: the captured ADIXCellReactionTimeEvent and an NSError containing the error. On success the error is nil.
 *  @include augmentedFeedbackReactExample.txt
 */
- (void)recieveReactionEvent:(void (^)(ADIXCellReactionTimeEvent *reaction, NSError *error))completion;

/**
 *  @brief Downloads every session from the remote device.
 *
 *  @param completion Block object to be executed on completion of download. This block has no return value and takes two arguments: an NSArray of ADIXCellSession instances and an NSError containing the error. On success the error is nil.
 *  @include downloadAllSessionsExample.txt
 */
- (void)downloadSessions:(void (^)(NSArray *sessions, NSError *error))completion;

/**
 *  @brief Downloads the current session from the remote device.
 *
 *  @param completion Block object to be executed on completion of download. This block has no return value and takes two arguments: an ADIXCellSession instance and an NSError containing the error. On success the error is nil.
 *  @include downloadSessionExample.txt
 */
- (void)downloadCurrentSession:(void (^)(ADIXCellSession *session, NSError *error))completion;

@end /** @} */
