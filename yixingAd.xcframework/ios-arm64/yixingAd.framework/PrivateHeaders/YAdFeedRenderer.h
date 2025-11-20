#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class YAdFeedAsset;

@interface YAdFeedRenderer : NSObject
- (void)renderInView:(UIView *)container withAsset:(YAdFeedAsset *)asset layoutType:(NSInteger)layoutType;
@end