#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "YXAdCommon.h"
#import "YXAdEventDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class YAdRequest;
@class YXSplashView;

/// Splash 开屏广告类：负责加载、状态管理与视图创建
@interface YXSplashAd : NSObject

@property (nonatomic, copy, readonly) NSString *adUnitId;
@property (nonatomic, assign, readonly) YXAdState state;
@property (nonatomic, assign, nullable) id<YXAdEventDelegate> delegate;

// Block 回调（与协议兼容，并存触发）
@property (nonatomic, copy, nullable) void (^onLoad)(YXSplashAd *ad);
@property (nonatomic, copy, nullable) void (^onFail)(YXSplashAd *ad, NSError *error);
@property (nonatomic, copy, nullable) void (^onShow)(YXSplashAd *ad);
@property (nonatomic, copy, nullable) void (^onClick)(YXSplashAd *ad);
@property (nonatomic, copy, nullable) void (^onClose)(YXSplashAd *ad);
@property (nonatomic, copy, nullable) void (^onSkip)(YXSplashAd *ad);
@property (nonatomic, copy, nullable) void (^onTimeOver)(YXSplashAd *ad);

- (instancetype)initWithAdUnitId:(NSString *)adUnitId;

/// 加载广告（内部桥接到旧版 YAdManager）
- (void)loadAd;
/// 统一命名：带请求对象加载（当前版本占位，不消费额外参数）
- (void)loadAd:(YAdRequest *)request;
/// 统一命名：默认展示（开屏默认展示到keyWindow）
- (void)showAd;
/// 统一命名：在指定上下文展示（UIWindow/UIViewController/UIView）
- (void)showAdIn:(id)context;

/// 就绪状态
- (BOOL)isReady;



@end

NS_ASSUME_NONNULL_END