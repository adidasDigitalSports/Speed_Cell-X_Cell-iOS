
@class ADIXCellSessionStartEvent;
@class ADIXCellSessionEndEvent;

#import <Foundation/Foundation.h>

/**
 *  @brief XCell business rules session.
 *  @defgroup XCELL_BUSINESS_RULES_SESSION XCellBusinessRulesSession
 *  @ingroup XCELL_BUSINESS_RULES_BINDING_LAYER_GROUP
 *  @{
 */

/**
 This simple, serializable value holder class describes a session.
 Session is an array of events. See ADIXCellEvent class and it's subclasses
 for more details. 
 */
@interface ADIXCellSession : NSObject

/** The array of events. */
//@property (strong, nonatomic) NSArray *events;
@property (strong, nonatomic) NSArray *jumpEvents;
@property (strong, nonatomic) NSArray *cutEvents;
@property (strong, nonatomic) NSArray *sprintEvents;
@property (strong, nonatomic) NSArray *heartRateEvents;
@property (strong, nonatomic) NSArray *buttonPressEvents;

/** Hustle values for the whole session as instances of ADIXCellHustleEntry objects. */
@property (strong, nonatomic) NSArray *intervalHustles;

/** The start event of the session. */
@property (strong, nonatomic) ADIXCellSessionStartEvent *startEvent;

/** The end event of the session. */
@property (strong, nonatomic) ADIXCellSessionEndEvent *endEvent;

/** The length of the session, actually this is the difference between the session end and start events timestamp. */
@property (readonly, nonatomic) NSTimeInterval length;

@property (readonly, nonatomic) NSDate *startDate;

/// This method can dump the content to csv format, which can be imported to a spreadsheet
- (NSString *)toCommaSeparatedValues;

@end

/** @} */
