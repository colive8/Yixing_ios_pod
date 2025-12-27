//
//  YXRewardedVideoAd.h
//  yixingAd
//
//  Created by YixingAd SDK on 2024/01/01.
//  Copyright © 2024 YixingAd. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<UIKit/UIKit.h>)
#import <UIKit/UIKit.h>
#endif

#import "YXAdEventDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class YAdRequest;

/**
 * 视频激励广告类
 * 负责广告的加载、状态管理，遵循安卓SDK的Ad+View架构模式
 */
@interface YXRewardedVideoAd : NSObject

/**
 * 获取共享实例（可选）
 */
+ (instancetype)sharedInstance;

/**
 * 广告位ID
 */
@property (nonatomic, copy, readonly) NSString *adUnitId;

/**
 * 广告是否已加载
 */
@property (nonatomic, assign, readonly) BOOL isLoaded;

/**
 * 广告数据
 */
@property (nonatomic, retain, readonly, nullable) NSDictionary *adData;

/**
 * 统一事件委托（与安卓回调风格对齐）
 */
@property (nonatomic, assign, nullable) id<YXAdEventDelegate> delegate;

/**
 * 广告加载成功回调
 */
@property (nonatomic, copy, nullable) void (^onLoad)(YXRewardedVideoAd *ad);

/**
 * 广告加载失败回调
 */
@property (nonatomic, copy, nullable) void (^onFail)(YXRewardedVideoAd *ad, NSError *error);

/**
 * 广告展示回调
 */
@property (nonatomic, copy, nullable) void (^onShow)(YXRewardedVideoAd *ad);

/**
 * 广告点击回调
 */
@property (nonatomic, copy, nullable) void (^onClick)(YXRewardedVideoAd *ad);

/**
 * 广告关闭回调
 */
@property (nonatomic, copy, nullable) void (^onClose)(YXRewardedVideoAd *ad);

/**
 * 激励发放回调
 */
@property (nonatomic, copy, nullable) void (^onReward)(YXRewardedVideoAd *ad, NSDictionary *rewardInfo);

/**
 * 初始化激励视频广告
 * @param adUnitId 广告位ID
 */
- (instancetype)initWithAdUnitId:(NSString *)adUnitId;

/**
 * 加载广告
 */
- (void)loadAd;
/** 统一命名：带请求对象加载（当前版本占位，不消费额外参数） */
- (void)loadAd:(YAdRequest *)request;
/** 统一命名：默认展示（自动寻找顶层UIViewController） */
- (void)showAd;
/** 统一命名：在指定上下文展示（UIViewController） */
- (void)showAdIn:(id)context;

/**
 * 展示广告
 * @param viewController 展示广告的视图控制器
 */

#if __has_include(<UIKit/UIKit.h>)
/**
 * 构建用于展示的视图控制器（不负责 present），两步式用法
 * 需在广告已加载后调用
 */
- (UIViewController *)buildViewController;
#endif

/**
 * 销毁广告
 */
- (void)destroy;

@end

NS_ASSUME_NONNULL_END