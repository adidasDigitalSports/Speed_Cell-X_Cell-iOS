#import <Foundation/Foundation.h>

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Key for holding NSNumber error description in NSError userInfo dictionary.
 */
extern NSString *const ADIXCellErrorDescriptionKey;

/**
 *  @brief Key for holding NSString error description in NSError userInfo dictionary.
 */
extern NSString *const ADIXCellErrorTextDescriptionKey;

/**
 *  @brief Values representing the current working state of the XCell device.
 */
typedef enum : NSUInteger {
    ADIXCellDeviceStatusRadioHR,
    ADIXCellDeviceStatusAFJump,
    ADIXCellDeviceStatusAFShuttle,
    ADIXCellDeviceStatusAFReactionTime,
    ADIXCellDeviceStatusSleep,
    ADIXCellDeviceStatusUnknown
} ADIXCellDeviceStatus;

/**
 *  @brief Values representing the position of the XCell device.
 */
typedef enum : NSUInteger {
    ADIXCellDevicePositionChest,
    ADIXCellDevicePositionBelt,
    ADIXCellDevicePositionNeck,
    ADIXCellDevicePositionNone
} ADIXCellDevicePosition;

/**
 *  @brief Options to describe possible errors that can be raised by requests.
 */
typedef enum : NSUInteger {
    ADIXCellErrorNoDescription,
    ADIXCellErrorEraseFailure,
    ADIXCellErrorInvalidRequest,
    ADIXCellErrorNoDataAvailable,
    ADIXCellErrorNotImplementedYet,
    ADIXCellErrorSensorLost,
    ADIXCellErrorDownloadSessionResponseFailure,
    ADIXCellErrorEraseSessionResponseFailure,
    ADIXCellErrorInternalInconsistencyDownloadSessions,
    ADIXCEllErrorInvalidMode
} ADIXCellError;

/** @} */
