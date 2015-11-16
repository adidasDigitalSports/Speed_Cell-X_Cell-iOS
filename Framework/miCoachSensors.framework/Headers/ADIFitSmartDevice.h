#import <Foundation/Foundation.h>
#import <miCoachSensors/miCoachInterfaces.h>
#import <miCoachSensors/ADIGeneralDevice.h>

/**
 *  @brief Here you can find the documentation of how to make interactions with a FitSmart device.
 *  @defgroup FITSMART_DEVICE FitSmart device
 *  @{
 */

/**
 *  @example ADIFitSmartFeatureExamples.m
 *  @include ADIFitSmartFeatureExamples.m
 */

#pragma mark - ADIFitSmartDevice

/**
 *  @brief The \b ADIFitSmartDevice class represents a remote FitSmart device.
 *
 *  Use this class to connect to and interact with the device. You can initialize an \b ADIFitSmartDevice from an \b ADIBluetoothDeviceFitSmart object, that holds the necessary \b CBPeripheral object for the bluetooth communication.
 *
 *
 */
@interface ADIFitSmartDevice : ADIGeneralDevice <ADIFitSmartSensorProtocol>

/**
 *  @brief Initializes and returns an ADIFitSmartDevice instance.
 *
 *  @param device   An ADIBluetoothDeviceFitSmart instance used for communicating with the real device on bluetooth.
 *
 *  @return Returns an initialized ADIFitSmartDevice object or nil if the object could not be succesfully initialized.
 */
- (instancetype)initWithDevice:(id<ADIBluetoothDeviceProtocol>)device;

/* @} */

/**
 *  @brief Downloads every session from the remote device.
 *
 *  @param completion Block object to be executed on completion of download. This block has no return value and takes two arguments: an NSArray of ADIFitSmartSession instances and an NSError containing the error. On success the error is nil.
 *
 *  \snippet ADIFitSmartFeatureExamples.m FitSmart download sessions example
 */
- (void)downloadSessions:(void (^)(NSArray *sessions, NSError *error))completion;

@end

/** @} */
