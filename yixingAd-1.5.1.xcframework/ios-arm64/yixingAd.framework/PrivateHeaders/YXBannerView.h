#import <Foundation/Foundation.h>

#if __has_include(<UIKit/UIKit.h>)
#import <UIKit/UIKit.h>
#endif

@class YXBannerAd;

#if __has_include(<UIKit/UIKit.h>)
@interface YXBannerView : UIView
#else
@interface YXBannerView : NSObject
#endif

@property (nonatomic, assign) YXBannerAd *ownerAd; // MRC 环境下使用 assign
@property (nonatomic, copy) void (^onAdImpression)(void);
@property (nonatomic, copy) void (^onAdClick)(void);

- (instancetype)initWithFrame:(CGRect)frame;

@end