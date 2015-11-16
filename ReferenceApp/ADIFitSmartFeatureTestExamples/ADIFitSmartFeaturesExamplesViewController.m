
#import "ADIFitSmartFeatureExamplesViewController.h"
#import "ADIFitSmartFeatureExamples.h"
 
@interface ADIFitSmartFeatureExamplesViewController () <ADIGeneralDeviceDelegate, UITextViewDelegate>

@end

@implementation ADIFitSmartFeatureExamplesViewController {
    
    ADIFitSmartFeatureExamples *_featuresTests;

    IBOutlet UITextView *_loggingTextView;
}

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    __weak typeof(self) weakSelf = self;
    
    _featuresTests = [[ADIFitSmartFeatureExamples alloc] init];
    _featuresTests.fitSmart = self.device;
    _featuresTests.log = ^(NSString *log) { [weakSelf appendTextToLoggingToTextView:log]; };
    
    [self startTests];
}

#pragma mark - ADIFitSmartSensorSpecificProtocol sync calls

- (void) startTests {

    if (self.device.isConnected) {
        [_featuresTests runAllExamples];
    }
    else {
        self.device.delegate = self;
        [self.device connect];
    }
}

#pragma mark - ADIGeneralDeviceDelegate methods

- (void)deviceDidConnect:(ADIGeneralDevice *)device {
    
    [self.device pair:self.userConfigForFitSmart.uniqueUserIdentifier completion:^(BOOL success) {
        if (success) {
            [self.device startSync];
            [self.device writeUserConfiguration:self.userConfigForFitSmart completion:^(BOOL success) {
                if (success) {
                    [_featuresTests runAllExamples];
                } else {
                    [self appendTextToLoggingToTextView:@"User configuration upload failed"];
                }
            }];
        }
        else {
            [self appendTextToLoggingToTextView:@"Pairing failed, please reset Fit Smart device!"];
            
        }
    }];
    
}

- (void)deviceDidFailToConnect:(ADIGeneralDevice *)device error:(NSError *)error {
        [self appendTextToLoggingToTextView:@"Device failed to connect"];
}

#pragma mark - Helpers

- (void)appendTextToLoggingToTextView:(NSString *)textToAppend {
//    _loggingTextView.text = [NSString stringWithFormat:@"%@\n%@", _loggingTextView.text, textToAppend];
    [_loggingTextView insertText:textToAppend];
    [_loggingTextView insertText:@"\n"];

    NSRange lastCharacter = NSMakeRange(_loggingTextView.text.length - 1, 1);
    [_loggingTextView scrollRangeToVisible:lastCharacter];
}

@end
