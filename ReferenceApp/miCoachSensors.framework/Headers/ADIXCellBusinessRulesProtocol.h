#import <Foundation/Foundation.h>

@class ADIXCellSession;
@class ADIXCellJumpEvent;
@class ADIXCellShuttleEvent;
@class ADIXCellReactionTimeEvent;

/**
 *  @ingroup MICOACH_INTERFACES
 *  @{
 */

/**
 *  @brief Possible device positions.
 *
 *  This position is used as a correction factor when doing jumps.
 */
typedef NS_ENUM(NSUInteger, ADIXCellPosition) {
    /**
     *  Default.
     */
    ADIXCellPositionNone = 0,
    /**
     *  Chest position.
     */
    ADIXCellPositionChestStrap,
    /**
     *  Belt position.
     */
    ADIXCellPositionWaistClip,
};

/**
 *  @brief Protocol for a directory entry on an XCell device.
 *
 *  You can use this to take a look at the individual files and later download them.
 */
@protocol ADIXCellDirectoryEntryProtocol <NSObject>

/**
 *  @return Returns the length of the session in bytes.
 */
- (int)sessionLength;

@end

/**
 *  @brief Protocol defining methods for parsing raw data downloaded from a remote XCell device.
 */
@protocol ADIXCellBusinessRulesProtocol <NSObject>

/**
 *  @brief Parsing a raw session.
 *
 *  This function is used to jump a raw binary session, and fill it's every value. The parsed session will store individual events (jump, cut, etc), as well as start and length information.
 *
 *  @param rawBinarySession Raw session data coming from the XCell device.
 *
 *  @return Parsed session.
 */
- (ADIXCellSession *)parse:(NSData *)rawBinarySession;

/**
 *  @brief Parsing raw directory data.
 *
 *  This function parses raw directory data, and the result is an NSArray containing the directory entries (ADIXCellDirectoryEntry objects). It can be used to determine the count and size of the session on the XCell device.
 *
 *  @param rawBinaryDirectoryData Raw directory data coming from the XCell device.
 *
 *  @return Parsed directory data.
 */
- (NSArray *)parseDirectoryList:(NSData *)rawBinaryDirectoryData;

/**
 *  @brief Parsing a Jump event from the given data object and device position.
 *
 *  @param data     Binary jump event data object.
 *  @param position Position of the XCell device on the user.
 *
 *  @return Parsed jump event instance or nil if data is invalid.
 */
- (ADIXCellJumpEvent *)parseJumpEventFromData:(NSData *)data wearingPosition:(ADIXCellPosition)position;

/**
 *  @brief  Parsing a Shuttle event from the given data object.
 *
 *  @param data Binary shuttle event data object.
 *
 *  @return Returns parsed shuttle event instance or nil if data is invalid.
 */
- (ADIXCellShuttleEvent *)parseShuttleEventFromData:(NSData *)data;

/**
 *  @brief Parsing a Reaction event from the given data object.
 *
 *  @param data Binary reaction event data object.
 *
 *  @return Parsed reaction event instance or nil if data is invalid.
 */
- (ADIXCellReactionTimeEvent *)parseReactionTimeEventFromData:(NSData *)data;

@end

/** @} */
