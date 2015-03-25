#import <CoreBluetooth/CoreBluetooth.h>

#import <miCoachSensors/miCoachInterfaces.h>
#import <miCoachSensors/ADIBluetoothDeviceType.h>

/**
 *  @addtogroup MICOACH_BLUETOOTH
 *  @{
 */

/**
 *  @brief ADIBluetoothDevice objects used for representing remote bluetooth compatible device's.
 *
 *  Instance methods allows to connect the remote device to the system.
 */
@interface ADIBluetoothDevice : NSObject <ADIBluetoothDeviceProtocol, CBPeripheralDelegate>

/**
 *  @brief The object that acts as a delegate of the bluetooth device.
 */
@property (nonatomic, weak) id<ADIBluetoothDeviceDelegate> delegate;

/**
 *  @brief Serial number of the remote device.
 */
@property (nonatomic, strong) NSString *serialNumber;

/**
 *  @brief Local name of the remote device same as bluetooth local name.
 */
@property (nonatomic, strong) NSString *deviceLocalName;

/**
 *  @brief Associated CBPeripheral object of the remote device.
 */
@property (nonatomic, strong) CBPeripheral *peripheral;

/**
 *  @brief All discovered CBCharacteristic objects of services by uuid string keys.
 */
@property (nonatomic, strong) NSDictionary *characteristics;

/**
 *  @brief Boolean value indicating if automatic reconnect to the remote device is active.
 *
 *  If set to YES, then after an unexpected disconnection a reconnect attempt is performed.
 */
@property (nonatomic) BOOL autoReconnect;

/**
 *  @brief Abstract instance method for subclasses to override.
 *
 *  @return Returns type of the bluetooth device.
 */
- (ADIBluetoothDeviceType)type;

@end

/** @} */
