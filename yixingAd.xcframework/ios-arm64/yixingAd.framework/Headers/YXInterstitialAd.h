#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "YXAdCommon.h"
#import "YXAdEventDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class YAdRequest;
@class YXInterstitialView;

/// Interstitial 插屏广告类：负责加载、状态管理与视图创建
@interface YXInterstitialAd : NSObject

@property (nonatomic, copy, readonly) NSString *adUnitId;
@property (nonatomic, assign, readonly) YXAdState state;
@property (nonatomic, assign, nullable) id<YXAdEventDelegate> delegate;

// Block 回调（与协议兼容，并存触发）
@property (nonatomic, copy, nullable) void (^onLoad)(YXInterstitialAd *ad);
@property (nonatomic, copy, nullable) void (^onFail)(YXInterstitialAd *ad, NSError *error);
@property (nonatomic, copy, nullable) void (^onShow)(YXInterstitialAd *ad);
@property (nonatomic, copy, nullable) void (^onClick)(YXInterstitialAd *ad);
@property (nonatomic, copy, nullable) void (^onClose)(YXInterstitialAd *ad);

- (instancetype)initWithAdUnitId:(NSString *)adUnitId;

/// 加载广告（内部桥接到旧版 YAdManager）
- (void)loadAd;
/// 统一命名：带请求对象加载（当前版本占位，不消费额外参数）
- (void)loadAd:(YAdRequest *)request;
/// 注入已获取的广告数据用于展示（测试/模拟/复用数据）
- (void)loadAdWithData:(NSDictionary *)data;
/// 统一命名：默认展示（插屏默认全屏展示到window）
- (void)showAd;
/// 统一命名：在指定上下文展示（UIViewController/UIView）
- (void)showAdIn:(id)context;

/// 就绪状态
- (BOOL)isReady;



@end

NS_ASSUME_NONNULL_END