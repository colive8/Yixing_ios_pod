//
//  YXLocationProvider.h
//  yixingAd
//
//  轻量定位提供器：仅在已授权时返回最近位置，不触发权限弹窗
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YXLocationProvider : NSObject

/// 是否已授权定位（WhenInUse/Always），不触发权限弹窗
+ (BOOL)isAuthorized;

/// 返回最近一次已知位置（需要已授权）。若不可用或无授权，返回 nil
+ (nullable CLLocation *)authorizedLastKnownLocation;

@end

NS_ASSUME_NONNULL_END