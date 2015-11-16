#import <Foundation/Foundation.h>

/**
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  An enum type to represent the color of the FitSmart device.
 */
typedef enum : NSUInteger {

    ADIFitSmartColorUnknown = 0,
    ADIFitSmartColorBlack = 1,
    ADIFitSmartColorMilkyWhite = 2
} ADIFitSmartColor;

/** @}
 *  @ingroup FITSMART_DEVICE FitSmart Device
 *  @{
 */

/**
 *  @brief  This class represents general information about a FitSmart device.
 *
 *  FitSmart device info holds information about the FitSmartDevice.
 */
@interface ADIFitSmartDeviceInfo : NSObject

/**
 *  @brief  The manufacturer's name of the device.
 */
@property (strong, nonatomic) NSString *manufacturerName;

/**
 *  @brief  The model number of the device.
 */
@property (strong, nonatomic) NSString *modelNumber;

/**
 *  @brief  The serial number of the device.
 */
@property (strong, nonatomic) NSString *serialNumber;

/**
 *  @brief  The hardware revision number of the device.
 */
@property (strong, nonatomic) NSString *hardwareRevision;

/**
 *  @brief  The firmware revision number of the device.
 */
@property (strong, nonatomic) NSString *firmwareRevision;

/**
 *  @brief  The software revision number of the device.
 */
@property (strong, nonatomic) NSString *softwareRevision;

/**
 *  @brief  The system ID of the device.
 */
@property (strong, nonatomic) NSString *systemId;

/**
 *  @brief  The physical color of the device.
 */
@property (assign, nonatomic) ADIFitSmartColor color;

@end

/** @} */
