//
//  YixingAdSDK.h
//  yixingAd
//
//  Created by YixingAd on 2024/09/22.
//

#import <Foundation/Foundation.h>
#import "YAdRequest.h"

NS_ASSUME_NONNULL_BEGIN

@class UIViewController;
@class UIView;
@class YAdRequest; // 引入旧请求类型作为别名基础

/**
 * 广告类型
 */
typedef NS_ENUM(NSInteger, YixingAdType) {
    YixingAdTypeBanner = 1,        // 横幅广告
    YixingAdTypeInterstitial = 2,  // 插屏广告
    YixingAdTypeSplash = 3,        // 开屏广告
    YixingAdTypeNative = 4,        // 信息流/原生广告
    YixingAdTypePaster = 5,        // 贴片广告（视频贴片）
    YixingAdTypeRewardedVideo = 6, // 激励视频
    YixingAdTypeNativeOther = 7    // 其它原生广告
};

/**
 * 广告数据模型（可选保留）
 */
@interface YixingAdData : NSObject
@property (nonatomic, strong) NSString *adId;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *desc;
@property (nonatomic, strong) NSString *imageUrl;
@property (nonatomic, strong) NSString *clickUrl;
@property (nonatomic, assign) YixingAdType adType;
@end

/**
 * 广告请求参数（兼容旧版 YAdRequest）
 * 将 YixingAdRequest 别名为 YAdRequest，并通过分类补充缺失属性
 */
typedef YAdRequest YixingAdRequest;

@interface YAdRequest (YixingCompatibility)
@property (nonatomic, strong) NSString *adUnitId; // 映射到 slotId
@property (nonatomic, assign) CGSize adSize;      // 映射到 width/height
@end

/**
 * 易行广告SDK主类（仅初始化与版本信息）
 */
@interface YixingAdSDK : NSObject

+ (void)initializeWithAppId:(NSString *)appId;
+ (void)initializeWithAppId:(NSString *)appId host:(NSString *)host port:(NSInteger)port;
+ (NSString *)appId;
+ (NSString *)version;
+ (NSInteger)versionCode;
+ (NSString *)currentHost;
+ (NSInteger)currentPort;
+ (NSArray<NSString *> *)currentHosts; // 返回当前路由地址列表（含端口或主机）
+ (void)rotateToNextHost; // 服务器宕机时轮换到下一个地址
// 手动触发路由更新，返回是否成功与信息
+ (void)updateRoutingWithCompletion:(void(^)(BOOL success, NSString * _Nullable message))completion;

+ (void)setCacheDebugEnabled:(BOOL)enabled;
+ (BOOL)isCacheDebugEnabled;
+ (void)printCacheSummary;

// MARK: - App 信息覆盖（供请求构造时优先使用）
+ (void)setAppInfoWithName:(NSString *)name bundle:(NSString *)bundle version:(NSString *)version;
+ (nullable NSString *)appName;   // 返回覆盖值；若未设置则从 Info.plist 读取
+ (nullable NSString *)appBundle; // 返回覆盖值；若未设置则从 Info.plist 读取
+ (nullable NSString *)appVersion; // 返回覆盖值；若未设置则从 Info.plist 读取

// MARK: - 地理信息覆盖（供请求构造时优先使用）
+ (void)setGeoInfoWithLat:(float)lat lon:(float)lon city:(nullable NSString *)city province:(nullable NSString *)province district:(nullable NSString *)district timestamp:(NSInteger)timestamp;
+ (BOOL)hasGeoInfo;
+ (float)geoLatitude;
+ (float)geoLongitude;
+ (nullable NSString *)geoCity;
+ (nullable NSString *)geoProvince;
+ (nullable NSString *)geoDistrict;
+ (NSInteger)geoTimestamp;

// MARK: - IDFA 注入（由宿主控制）
+ (void)setIDFA:(nullable NSString *)idfa; // 宿主可在合适时机注入；为空则清除
+ (nullable NSString *)idfa;               // 请求构造时优先取此值

// MARK: - 自动采集开关（缺省时尝试自动获取；不触发权限弹窗）
+ (void)setAutoCollectIDFAEnabled:(BOOL)enabled;      // 默认 YES
+ (BOOL)isAutoCollectIDFAEnabled;
+ (void)setAutoCollectLocationEnabled:(BOOL)enabled;  // 默认 YES
+ (BOOL)isAutoCollectLocationEnabled;

@end

NS_ASSUME_NONNULL_END
