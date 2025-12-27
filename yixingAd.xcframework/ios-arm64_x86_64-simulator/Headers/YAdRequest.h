//
//  YAdRequest.h
//  yixingAd
//
//  Created by YixingAd SDK on 2024/01/01.
//  Copyright © 2024 YixingAd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 广告请求类，封装广告请求的所有参数
 */
@interface YAdRequest : NSObject

// 基本请求信息
@property (nonatomic, copy) NSString *requestId;
@property (nonatomic, copy) NSString *slotId;
@property (nonatomic, assign) NSInteger adType;
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;
@property (nonatomic, assign) NSInteger creativeType;

// 应用信息
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *appBundle;
@property (nonatomic, copy) NSString *appVersion;

// 设备信息
@property (nonatomic, assign) NSInteger deviceType;
@property (nonatomic, copy) NSString *ip;
@property (nonatomic, copy) NSString *userAgent;
@property (nonatomic, copy) NSString *deviceMake;
@property (nonatomic, copy) NSString *deviceModel;
@property (nonatomic, assign) NSInteger osType;
@property (nonatomic, copy) NSString *osVersion;
@property (nonatomic, assign) NSInteger screenWidth;
@property (nonatomic, assign) NSInteger screenHeight;
@property (nonatomic, copy) NSString *carrier;
@property (nonatomic, assign) NSInteger connectionType;

// 设备标识符
@property (nonatomic, copy, nullable) NSString *idfa;
@property (nonatomic, copy, nullable) NSString *idfv;

// 地理位置信息
@property (nonatomic, assign) BOOL hasLocation;
@property (nonatomic, assign) float latitude;
@property (nonatomic, assign) float longitude;
@property (nonatomic, copy) NSString *city;
// 新增：省份与区县
@property (nonatomic, copy) NSString *province;
@property (nonatomic, copy) NSString *district;
@property (nonatomic, assign) NSInteger locationTimestamp;
@property (nonatomic, copy) NSString *country;

// 设备硬件信息
@property (nonatomic, assign) NSInteger orientation; // 设备方向：0=竖屏，1=横屏
@property (nonatomic, assign) NSInteger ppi; // 像素密度
@property (nonatomic, assign) NSInteger dpi; // 每英寸像素(dpi)
@property (nonatomic, assign) float density; // 屏幕密度
@property (nonatomic, copy) NSString *hwModel; // 硬件型号
@property (nonatomic, copy) NSString *hwMachine; // 硬件标识符
@property (nonatomic, copy) NSString *sysMemory; // 系统内存
@property (nonatomic, copy) NSString *sysDisksize; // 系统磁盘大小
@property (nonatomic, copy) NSString *hwName; // 硬件名称
@property (nonatomic, copy) NSString *deviceName; // 设备名称
@property (nonatomic, copy) NSString *paid; // 付费应用标识

// 系统启动相关
@property (nonatomic, copy) NSString *bootMark; // 启动标识
@property (nonatomic, copy) NSString *bootTimeSec; // 启动时间
@property (nonatomic, copy) NSString *updateMark; // 更新标识
@property (nonatomic, copy) NSString *osUpdateTimeSec; // 系统更新时间
@property (nonatomic, copy) NSString *deviceInitializeTime; // 设备初始化时间

// 应用商店相关
@property (nonatomic, copy) NSString *appStoreVer; // App Store版本（对应Android的hwagVer）

// 用户信息
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, assign) NSInteger userAge;
@property (nonatomic, copy) NSString *userGender;
@property (nonatomic, copy) NSString *userKeywords;
@property (nonatomic, strong, nullable) NSArray<NSString *> *userAppList; // 用户已安装应用列表

// 广告相关配置
@property (nonatomic, assign) NSInteger supportDeeplink; // 是否支持深度链接
@property (nonatomic, assign) NSInteger support302; // 是否支持302重定向
@property (nonatomic, assign) BOOL fullScreen; // 是否满屏显示
@property (nonatomic, assign) NSInteger minDuration; // 允许最小播放时长，单位秒
@property (nonatomic, assign) NSInteger maxDuration; // 允许最大播放时长，单位秒
@property (nonatomic, assign) NSInteger skip; // 是否允许跳过
@property (nonatomic, assign) NSInteger skipAfter; // 几秒后允许跳过
@property (nonatomic, assign) NSInteger videoType; // 视频类型，0-普通视频，1-激励视频
@property (nonatomic, assign) NSInteger bannerType; // Banner广告类型，0-JSON，1-HTML
@property (nonatomic, assign) NSInteger feedAdLayoutType; // 信息流广告布局类型

/**
 * 创建默认的广告请求对象
 */
+ (instancetype)defaultRequest;

/**
 * 使用广告位ID创建请求对象
 */
+ (instancetype)requestWithSlotId:(NSString *)slotId;

@end

NS_ASSUME_NONNULL_END