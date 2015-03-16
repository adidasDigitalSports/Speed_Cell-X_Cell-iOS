#import <Foundation/Foundation.h>

@class ADIGeneralDevice;

/**
 *  @brief The delegate of an ADIGeneralDevice object must adopt the ADIGeneralDeviceDelegate protocol. The delegate uses this protocol's methods to monitor the connection state of the remote device.
 */
@protocol ADIGeneralDeviceDelegate <NSObject>

@optional

/**
 *  @brief Invoked when a connection to the remote device is established.
 *
 *  @param device  The device that has been connected to the system.
 */
- (void)deviceDidConnect:(ADIGeneralDevice *)device;

/**
 *  @brief Invoked when a connection to the remote device is canceled.
 *
 *  @param device The device that has been disconnected.
 */
- (void)deviceDidDisconnect:(ADIGeneralDevice *)device;

/**
 *  @brief Invoked when a connection to the remote device is failed.
 *
 *  @param device The device that failed to connect to the remote device.
 *  @param error  Cause of the failure.
 */
- (void)deviceDidFailToConnect:(ADIGeneralDevice *)device error:(NSError *)error;

@end

/**
 *  @brief Superclass for specific devices.
 */
@interface ADIGeneralDevice : NSObject

/**
 *  @brief Object that acts as a delegate of the ADIGeneralDevice instance.
 */
@property (nonatomic, weak) id<ADIGeneralDeviceDelegate> delegate;

/**
 *  @brief Serial number of the remote device.
 */
@property (nonatomic, strong) NSString *serialNumber;

/**
 *  @brief Boolean value indicating if automatic reconnect to the remote device is active.
 *
 *  If set to YES, then after an unexpected disconnection a reconnect attempt is performed.
 */
@property (nonatomic, assign) BOOL autoReconnect;

/**
 *  @brief Establishes a connection to the remote device.
 */
- (void)connect;

/**
 *  @brief Disconnects from the remote device.
 *
 *  @param completion Block object to be executed on completion of disconnect. This block has no return value and does not takes arguments.
 */
- (void)disconnectWithCompletionHandler:(void (^)())completion;

/**
 *  @brief Connection state of the device.
 *  YES if device is connected, NO otherwise.
 */
- (BOOL)isConnected;

@end
