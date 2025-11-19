#import <Foundation/Foundation.h>
#import "YAdGRPCClient.h"

@class YAdBid;

@interface YAdEventReporter : NSObject

+ (instancetype)sharedReporter;

// 通过字典上下文统一上报（字典包含 adId、requestId、可选 _bid）
- (void)reportEventWithAdContext:(NSDictionary *)adContext
                        eventType:(YAdEventType)eventType
                        grpcClient:(YAdGRPCClient *)grpcClient;

// 直接通过 adId/requestId/bid 上报（供需要时直接调用）
- (void)reportEventWithAdId:(NSString *)adId
                   requestId:(NSString *)requestId
                         bid:(YAdBid *)bid
                    eventType:(YAdEventType)eventType
                   grpcClient:(YAdGRPCClient *)grpcClient;

// 新增：按 eventTrack 的数组键上报（例如 videoMuteArray / videoUnmuteArray）
- (void)reportEventWithAdContext:(NSDictionary *)adContext
                         arrayKey:(NSString *)arrayKey
                        grpcClient:(YAdGRPCClient *)grpcClient;

@end