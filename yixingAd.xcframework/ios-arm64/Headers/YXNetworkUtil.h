#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YXNetworkUtil : NSObject
/// 是否有任何网络连接（蜂窝或 Wi‑Fi）
+ (BOOL)isConnected;
/// 是否为 Wi‑Fi 连接（接口 `en0` 存在且可达）
+ (BOOL)isWifi;
@end

NS_ASSUME_NONNULL_END