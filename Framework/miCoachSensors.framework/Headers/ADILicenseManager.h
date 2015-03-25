#import <Foundation/Foundation.h>

@interface ADILicenseManager : NSObject

- (void)validateLicenseWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret completion:(void (^)(BOOL))completion;

@end
