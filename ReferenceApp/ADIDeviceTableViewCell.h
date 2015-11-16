#import <UIKit/UIKit.h>

/**
 *  Re-useable identifier for the cell below.
 */
extern NSString *const kADIDeviceTableViewCellIdentifier;

/**
 *  Table view cell to display paired devices on main screen.
 */
@interface ADIDeviceTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *deviceIdLabel;
@property (weak, nonatomic) IBOutlet UIButton *connectButton;
@property (weak, nonatomic) IBOutlet UIButton *syncButton;
@property (weak, nonatomic) IBOutlet UIProgressView *progressView;

@end
