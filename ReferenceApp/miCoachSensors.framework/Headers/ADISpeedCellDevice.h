#import <Foundation/Foundation.h>
#import <miCoachSensors/miCoachInterfaces.h>
#import "ADIGeneralDevice.h"

typedef NSObject<ADIBluetoothProviderProtocol, ADISpeedCellSensorProtocol> ADISpeedCellBluetoothCommunicationProtocol;
typedef NSObject<ADIBluetoothDeviceProtocol> ADISpeedCellBluetoothDevice;

/**
 *  @brief Here you can find the documentation of how to make interactions with a SpeedCell device.
 *  @defgroup SPEEDCELL_DEVICE SpeedCell Device
 *  @{
 */

#pragma mark - ADISpeedCellDevice

/**
 *  @example downloadSessionsExample.txt
 *  @example manageDeviceTime.txt
 *  @example strideRateExample.txt
 */

/**
 *  @brief The \b ADISpeedCellDevice class represents a remote SpeedCell device.
 *
 *  Use this class to connect to and interact with the device. You can initialize an \b ADISpeedCellDevice from an \b ADIBluetoothDeviceSpeedCell object, that holds the necessary \b CBPeripheral object for the bluetooth communication.
 *
 *  You have the opportunity to subclass \b ADISpeedCellBindingLayer class and initialize an \b ADISpeedCellDevice object with it. In this case you can override the inner behaviour of \b ADISpeedCellBindingLayer.
 *
 * @include downloadSessionsExample.txt
 * @include manageDeviceTime.txt
 * @include strideRateExample.txt
 */
@interface ADISpeedCellDevice : ADIGeneralDevice <ADISpeedCellSensorProtocol>

/**
 *  @brief Initializes and returns an ADISpeedCellDevice instance with the given ADISpeedCellBluetoothDevice object and ADISpeedCellBluetoothCommunicationProtocol object.
 *
 *  @param device   An ADIBluetoothDeviceSpeedCell instance used for communicating with the real device on bluetooth.
 *  @param protocol An ADISpeedCellBindingLayer instance user for creating bluetooth masseges and handling response from the device.
 *
 *  @return Returns an initialized ADISpeedCellDevice object or nil if the object could not be succesfully initialized.
 */
- (instancetype)initWithDevice:(ADISpeedCellBluetoothDevice *)device bluetoothProtocol:(ADISpeedCellBluetoothCommunicationProtocol *)protocol;

/**
 *  @brief Downloads every session from the remote device.
 *
 *  @param completion Block object to be executed on completion of download. This block has no return value and takes two arguments: an NSArray of ADISpeedCellSession instances and an NSError containing the error. On success the error is nil.
 */
- (void)downloadSessions:(void (^)(NSArray *sessions, NSError *error))completion;

@end

/** @} */
