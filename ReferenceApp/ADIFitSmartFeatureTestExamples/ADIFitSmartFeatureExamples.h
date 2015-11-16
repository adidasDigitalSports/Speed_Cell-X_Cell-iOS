
#import <Foundation/Foundation.h>
#import <miCoachSensors/miCoachSensors.h>

// callback block for logging
typedef void (^ADIFitSmartFeatureTestsLogging)(NSString *log);

/**
 *  This class contains example codes for FitSmart use cases.
 */
@interface ADIFitSmartFeatureExamples : NSObject

// Should be set to an already connected FitSmart device.
@property (strong, nonatomic) ADIFitSmartDevice *fitSmart;

// This callback will be called for logging results of the examples.
@property (copy, nonatomic) ADIFitSmartFeatureTestsLogging log;

// This method starts running the examples.
- (void)runAllExamples;

@end
