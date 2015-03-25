#import <Foundation/Foundation.h>

/**
 *  @brief XCell business rules directory entry.
 *  @defgroup XCELL_BUSINESS_RULES_DIRECTORY_ENTRY XCellBusinessRulesDirectoryEntry
 *  @ingroup XCELL_BUSINESS_RULES_BINDING_LAYER_GROUP
 *  @{
 */

/**
 This class contains the details of a file entry in the X_CELL's filesystem.
 */
@interface ADIXCellDirectoryEntry : NSObject

/** The session length bytes. */
@property (assign, nonatomic) int sessionLength;

/** The date and time when the session was started. */
@property (strong, nonatomic) NSDate *sessionStartDate;

@end

/** @} */
