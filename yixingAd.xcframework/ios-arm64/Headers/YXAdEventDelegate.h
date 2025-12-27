#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class YXBannerAd;
@class YXBannerView;

/// 统一广告事件回调协议（阶段 B 首先用于 Banner）
@protocol YXAdEventDelegate <NSObject>
@optional
- (void)adDidLoad:(id)ad;                    // 广告加载成功
- (void)adDidFail:(id)ad error:(NSError *)error; // 广告加载失败
- (void)adDidShow:(id)ad;                    // 广告展示/曝光
- (void)adDidClick:(id)ad;                   // 广告被点击
- (void)adDidClose:(id)ad;                   // 广告关闭
- (void)adDidReward:(id)ad info:(NSDictionary *)rewardInfo; // 激励发放（激励视频）
@end

NS_ASSUME_NONNULL_END