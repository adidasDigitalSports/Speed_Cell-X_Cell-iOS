#import <Foundation/Foundation.h>

extern NSString *const ADIBluetoothErrorDomain;

typedef enum : NSUInteger {
    ADIBluetoothDiscoveryTimeout = 100,
    ADIBluetoothInvalidDeviceSerialNumber,
    ADIBluetoothUnsatisfiedRequiredCharacteristic,
} ADIBluetoothError;