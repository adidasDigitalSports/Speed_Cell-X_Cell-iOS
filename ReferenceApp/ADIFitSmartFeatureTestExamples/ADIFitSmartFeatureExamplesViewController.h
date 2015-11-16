@import  UIKit;

#import <miCoachSensors/miCoachSensors.h>
#import "ADIDeviceTableViewCell.h"

@interface ADIFitSmartFeatureExamplesViewController : UIViewController

@property (strong, nonatomic) ADIFitSmartDevice *device;
@property (strong, nonatomic) ADIFitSmartUserConfiguration *userConfigForFitSmart;

@end
