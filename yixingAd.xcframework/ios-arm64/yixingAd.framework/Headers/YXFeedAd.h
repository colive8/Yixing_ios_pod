//
//  YXFeedAd.h
//  yixingAd
//
//  Created by YixingAd SDK on 2024/01/01.
//  Copyright © 2024 YixingAd. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YXFeedAd;
@class YXFeedView;

NS_ASSUME_NONNULL_BEGIN

@class YAdRequest;

/**
 * 信息流广告加载回调
 */
typedef void (^YXFeedAdLoadBlock)(YXFeedAd *ad);
typedef void (^YXFeedAdFailBlock)(YXFeedAd *ad, NSError *error);

/**
 * 信息流广告类
 * 负责广告的加载和管理，遵循安卓SDK的Ad+View架构模式
 */
@interface YXFeedAd : NSObject

/**
 * 广告位ID
 */
@property (nonatomic, readonly) NSString *adUnitId;

/**
 * 广告是否已加载
 */
@property (nonatomic, readonly) BOOL isLoaded;

/**
 * 广告数据
 */
@property (nonatomic, readonly, nullable) NSDictionary *adData;

/**
 * 加载成功回调
 */
@property (nonatomic, copy, nullable) YXFeedAdLoadBlock onLoad;

/**
 * 加载失败回调
 */
@property (nonatomic, copy, nullable) YXFeedAdFailBlock onFail;

/**
 * 初始化信息流广告
 * @param adUnitId 广告位ID
 */
- (instancetype)initWithAdUnitId:(NSString *)adUnitId;

/**
 * 加载广告
 */
- (void)loadAd;
/** 统一命名：带请求对象加载（当前版本占位，不消费额外参数） */
- (void)loadAd:(YAdRequest *)request;
/** 统一命名：默认展示（信息流无默认容器，返回错误） */
- (void)showAd;
/** 统一命名：在指定上下文展示（UIView 容器） */
- (void)showAdIn:(id)context;
/** 就绪状态（与其他广告类一致） */
- (BOOL)isReady;

/**
 * 创建信息流广告视图
 * @param frame 视图框架
 * @return 信息流广告视图，如果广告未加载则返回nil
 */


/**
 * 销毁广告
 */
- (void)destroy;

@end

NS_ASSUME_NONNULL_END