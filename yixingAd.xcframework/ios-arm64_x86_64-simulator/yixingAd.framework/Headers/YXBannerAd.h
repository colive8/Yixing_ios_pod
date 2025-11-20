#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "YXAdCommon.h"
#import "YXAdEventDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class YAdRequest;
@class YXBannerView;

/// Banner 广告类（阶段 B）：负责加载、状态管理与视图创建
@interface YXBannerAd : NSObject

@property (nonatomic, copy, readonly) NSString *adUnitId;
@property (nonatomic, assign, readonly) CGSize adSize;
@property (nonatomic, assign, nullable) id<YXAdEventDelegate> delegate;
@property (nonatomic, assign, readonly) YXAdState state;

// Block 回调（与协议兼容，并存触发）
@property (nonatomic, copy, nullable) void (^onLoad)(YXBannerAd *ad);
@property (nonatomic, copy, nullable) void (^onFail)(YXBannerAd *ad, NSError *error);
@property (nonatomic, copy, nullable) void (^onShow)(YXBannerAd *ad);
@property (nonatomic, copy, nullable) void (^onClick)(YXBannerAd *ad);
@property (nonatomic, copy, nullable) void (^onClose)(YXBannerAd *ad);

- (instancetype)initWithAdUnitId:(NSString *)adUnitId size:(CGSize)size;

/// 加载广告（内部桥接到旧版 YAdManager）
- (void)loadAd;
/// 统一命名：带请求对象加载（当前版本占位，不消费额外参数）
- (void)loadAd:(YAdRequest *)request;
/// 统一命名：默认展示（Banner无默认容器，返回错误）
- (void)showAd;
/// 统一命名：在指定上下文展示（UIView 容器）
- (void)showAdIn:(id)context;

/// 就绪状态
- (BOOL)isReady;



@end

NS_ASSUME_NONNULL_END