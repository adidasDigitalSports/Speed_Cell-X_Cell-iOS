#import <Foundation/Foundation.h>
#import <miCoachSensors/ADIBluetoothDeviceType.h>

/**
 *  @addtogroup MICOACH_BLUETOOTH
 *  @{
 */

/**
 *  @brief Class for filtering discovered remote devices by their type.
 */
@interface ADIDiscoveryFilter : NSObject

/**
 *  @brief The bluetooth device type to search for.
 */
@property (nonatomic, assign) ADIBluetoothDeviceType type;

/**
 *  @brief Initializes an ADIDiscoveryFilter object with the specified type.
 *
 *  @param type Type of the remote device to search for.
 *
 *  @return Returns an initialized ADIDiscoveryFilter object.
 */
- (instancetype)initWithDeviceType:(ADIBluetoothDeviceType)type;

/**
 *  @param advertisementData An NSDictionary of adverisement data belonging to a discovered remote device.
 *
 *  @return Returns YES if the advertisementData belongs to a device with same type as specified in the filter, otherwise NO.
 */
- (BOOL)filterUsingAdvertisementData:(NSDictionary *)advertisementData;

@end

/** @} */