#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface YAdFeedTracker : NSObject
- (void)startTrackingView:(UIView *)view impression:(void(^)(void))impressionBlock;
- (void)stop;
@end