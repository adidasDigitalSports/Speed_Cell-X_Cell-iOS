#import <Foundation/Foundation.h>
#import "ADIBluetoothDeviceType.h"
#import "ADIBluetoothDevice.h"

@class ADIBluetooth;

/**
 *  @addtogroup MICOACH_BLUETOOTH
 *  @{
 */

/**
 *  @brief  The delegate of an ADIBluetooth object must adopt the ADIBluetoothDelegate protocol. The delegate uses this protocol's methods to catch device discovery and error events.
 */
@protocol ADIBluetoothDelegate <NSObject>

/**
 *  @brief Invoked when a remote device is discovered.
 *
 *  @param service The discovery service object providing the information.
 *  @param device  The found remote device represneted by an ADIBluetoothDevice object.
 *  @param type    The type of the ADIBluetoothDevice object, which is helpful for casting the object to a subclass.
 */
- (void)discoveryService:(ADIBluetooth *)service didFoundDevice:(ADIBluetoothDevice *)device OfType:(ADIBluetoothDeviceType)type;

/**
 *  @brief Invoked when an error occures during discovery.
 *
 *  @param service The discovery service object providing the information.
 *  @param error   The error happened during the discovery.
 */
- (void)discoveryService:(ADIBluetooth *)service occuredError:(NSError *)error;

@end

/** @} */
