//
//  YXFeedView.h
//  yixingAd
//
//  Created by YixingAd SDK on 2024/01/01.
//  Copyright © 2024 YixingAd. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<UIKit/UIKit.h>)
#import <UIKit/UIKit.h>
#endif

@class YXFeedAd;

NS_ASSUME_NONNULL_BEGIN

/**
 * 信息流广告视图类
 * 负责广告的展示和交互，遵循安卓SDK的Ad+View架构模式
 */
#if __has_include(<UIKit/UIKit.h>)
@interface YXFeedView : UIView
#else
@interface YXFeedView : NSObject
#endif

/**
 * 获取共享实例
 */
+ (instancetype)sharedInstance;

/**
 * 获取共享实例（别名方法）
 */
+ (instancetype)shareInstance;

/**
 * 关联的广告对象
 */
@property (nonatomic, assign, nullable) YXFeedAd *ownerAd; // MRC 环境下使用 assign

/**
 * 广告数据
 */
@property (nonatomic, retain, nullable) NSDictionary *adData; // 使用 retain 持有对象

/**
 * 广告点击回调
 */
@property (nonatomic, copy, nullable) void (^onAdClicked)(void);

/**
 * 广告展示回调
 */
@property (nonatomic, copy, nullable) void (^onAdImpression)(void);

/**
 * 使用广告数据配置视图
 * @param adData 广告数据
 */
- (void)configureWithAdData:(NSDictionary *)adData;

/**
 * 手动触发广告展示事件
 */
- (void)notifyAdImpression;

/**
 * 销毁视图
 */
- (void)destroy;

@end

NS_ASSUME_NONNULL_END