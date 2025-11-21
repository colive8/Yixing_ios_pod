//
//  YAdGRPCClient.h
//  yixingAd
//
//  Created by YixingAd SDK on 2024/01/01.
//  Copyright © 2024 YixingAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YAdEvents.h"

NS_ASSUME_NONNULL_BEGIN

@class YAdRequest;
@class YAdResponse;
@class YAdAdResponse; // forward declare proto response to avoid heavy imports

/**
 * gRPC客户端回调协议
 */
@protocol YAdGRPCClientDelegate <NSObject>

@optional
/**
 * 广告请求开始
 */
- (void)adRequestDidStart;

/**
 * 广告请求成功
 * @param response 广告响应数据
 */
- (void)adRequestDidSucceedWithResponse:(YAdResponse *)response;

/**
 * 广告请求失败
 * @param error 错误信息
 */
- (void)adRequestDidFailWithError:(NSError *)error;

/**
 * 事件上报成功
 * @param success 是否成功
 */
- (void)eventReportDidCompleteWithSuccess:(BOOL)success;

@end

/**
 * YixingAd gRPC客户端
 * 负责与广告服务器进行gRPC通信
 */
@interface YAdGRPCClient : NSObject

/**
 * 服务器端口
 */
@property (nonatomic, assign) NSInteger serverPort;

/**
 * 单例实例
 */
+ (instancetype)sharedClient;

/**
 * 初始化客户端
 * @param host 服务器地址
 * @param port 服务器端口
 */
- (void)initializeWithHost:(NSString *)host port:(NSInteger)port;

/**
 * 请求广告（旧接口，返回自定义包装类型）
 */
- (void)requestAdWithRequest:(YAdRequest *)request completion:(void (^)(YAdResponse * _Nullable response, NSError * _Nullable error))completion;

/**
 * 请求广告（新接口，直接返回 proto 类型）
 */
- (void)requestProtoAdWithRequest:(YAdRequest *)request completion:(void (^)(YAdAdResponse * _Nullable response, NSError * _Nullable error))completion;

/**
 * 请求广告并返回已映射的通用字典数据（避免调用方直接依赖 proto）
 */
- (void)requestAdDataWithRequest:(YAdRequest *)request completion:(void (^)(NSDictionary * _Nullable adData, NSError * _Nullable error))completion;

/**
 * 上报事件
 * @param requestId 请求ID
 * @param eventType 事件类型
 * @param completion 完成回调
 */
- (void)logEventWithRequestId:(NSString *)requestId eventType:(YAdEventType)eventType completion:(void (^)(BOOL success, NSError * _Nullable error))completion;
- (void)logEventWithRequestId:(NSString *)requestId adId:(NSString *)adId eventType:(YAdEventType)eventType completion:(void (^)(BOOL success, NSError * _Nullable error))completion;

/**
 * 通过原始 gRPC 跟踪地址上报事件
 */
- (void)logEventWithLogUri:(NSString *)logUri;
- (void)logEventWithLogUri:(NSString *)logUri completion:(void (^)(BOOL success, NSError * _Nullable error))completion;

/**
 * 测试连接
 * @param completion 完成回调
 */
- (void)testConnectionWithCompletion:(void(^)(BOOL success, NSError * _Nullable error))completion;

/**
 * 关闭连接
 */
- (void)shutdown;

@end

NS_ASSUME_NONNULL_END