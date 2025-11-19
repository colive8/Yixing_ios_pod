#import <Foundation/Foundation.h>

#if __has_include(<UIKit/UIKit.h>)
#import <UIKit/UIKit.h>
#endif

@class YXSplashAd;

#if __has_include(<UIKit/UIKit.h>)
@interface YXSplashView : UIView
#else
@interface YXSplashView : NSObject
#endif

@property (nonatomic, assign) YXSplashAd *ownerAd; // MRC 环境下使用 assign
@property (nonatomic, copy) void (^onAdShown)(void);
@property (nonatomic, copy) void (^onAdClick)(void);
@property (nonatomic, copy) void (^onAdSkip)(void);
@property (nonatomic, copy) void (^onAdTimeOver)(void);

- (instancetype)initWithFrame:(CGRect)frame;

/// 由 Ad 类传入数据进行配置
- (void)configureWithAdData:(NSDictionary *)adData;

/// 在指定容器视图中显示（全屏挂载）
- (void)presentInView:(id)parentView;

@end