#import <Foundation/Foundation.h>
#import "YAdSDKConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface YAdRouteManager : NSObject

@property (nonatomic, strong, readonly) YAdSDKConfig *config;
@property (nonatomic, copy, readonly) NSString *currentHost;
@property (nonatomic, assign, readonly) int32_t currentPort;
@property (nonatomic, strong, readonly) NSArray<NSString *> *adHosts;
@property (nonatomic, assign, readonly) NSInteger currentIndex;
@property (nonatomic, assign, readonly, getter=isUpdating) BOOL updating;
@property (nonatomic, assign, readonly) NSTimeInterval lastUpdateTime;

- (instancetype)initWithConfig:(YAdSDKConfig *)config;
- (void)updatePrimaryHost:(NSString *)host port:(int32_t)port;
// 公开路由更新方法，供 SDK 外部调用
- (void)updateRouteTableWithCompletion:(void(^)(BOOL success, NSString * _Nullable message))completion;
// 公开轮换当前主机的方法，供 SDK 在服务器宕机场景下调用
- (void)markCurrentHostFailedAndRotate;

@end

NS_ASSUME_NONNULL_END