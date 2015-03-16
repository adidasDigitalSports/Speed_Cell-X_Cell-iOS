#import <Foundation/Foundation.h>
#import <miCoachSensors/ADISpeedCellBusinessRulesProtocol.h>

/**
 *  @brief This class represents a directory entry on the device.
 *  @ingroup SPEEDCELL_BINDING_LAYER
 *
 *  Directory entries are holding information about the stored session files.
 */
@interface ADISpeedCellDirectoryEntry : NSObject <ADISpeedCellDirectoryEntryProtocol>

/**
 *  @brief The corresponding index of the session file. The file can be downloaded by this index.
 */
@property (assign, nonatomic) int fileIndex;

/**
 *  @brief The size of the session file.
 */
@property (assign, nonatomic) int fileSize;

/**
 *  @brief The type of the file.
 */
@property (assign, nonatomic) int fileType;

/**
 *  @brief A Boolean value indicating whether the file can be downloaded.
 */
@property (assign, nonatomic) BOOL canDownload;

/**
 *  @brief A boolean value indicating whether the file can be uploaded.
 */
@property (assign, nonatomic) BOOL canUpload;

/**
 *  @brief A Boolean value indicating whether the file can be deleted.
 */
@property (assign, nonatomic) BOOL canErase;

/**
 *  @brief A Boolean value indicating whether the file has been ever downloaded. 
 */
@property (assign, nonatomic) BOOL alreadyDownloaded;

@end
