#import <Foundation/Foundation.h>
#import <miCoachSensors/ADIXCellBusinessRulesProtocol.h>

#import <miCoachSensors/ADIXCellJumpEvent.h>
#import <miCoachSensors/ADIXCellShuttleEvent.h>
#import <miCoachSensors/ADIXCellSprintEvent.h>
#import <miCoachSensors/ADIXCellCutEvent.h>
#import <miCoachSensors/ADIXCellReactionTimeEvent.h>
#import <miCoachSensors/ADIXCellNewHeartRateEvent.h>
#import <miCoachSensors/ADIXCellSessionStartEvent.h>
#import <miCoachSensors/ADIXCellSessionEndEvent.h>
#import <miCoachSensors/ADIXCellButtonPressEvent.h>
#import <miCoachSensors/ADIXCellHustleEntry.h>

#import <miCoachSensors/ADIXCellDirectoryEntry.h>
#import <miCoachSensors/ADIXCellSession.h>

/**
 *  @brief XCell business rules events.
 *  @defgroup XCELL_BUSINESS_RULES_EVENTS_GROUP XCellBusinessRulesEvents
 */

/**
 *  @brief XCell business rules binding layer.
 *  @defgroup XCELL_BUSINESS_RULES_BINDING_LAYER_GROUP XCellBusinessRulesBindingLayer
 */

/**
 *  @brief XCell business rules binding layer.
 *  @defgroup XCELL_BUSINESS_RULES_BINDING_LAYER XCellBusinessRulesBindingLayer
 *  @ingroup XCELL_BUSINESS_RULES_BINDING_LAYER_GROUP
 *  @{
 */
@interface miCoachXCellBusinessRules : NSObject <ADIXCellBusinessRulesProtocol>

@end

/** @} */
