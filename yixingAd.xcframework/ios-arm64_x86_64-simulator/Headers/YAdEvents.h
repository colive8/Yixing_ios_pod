#import <Foundation/Foundation.h>

// 统一的事件与广告类型枚举定义

typedef NS_ENUM(NSInteger, YAdEventType) {
    YAdEventTypeImpression = 1,
    YAdEventTypeClick = 2,
    YAdEventTypeClose = 3,
    YAdEventTypeShow = 4
};

typedef NS_ENUM(NSInteger, YAdUIAdType) {
    YAdUIAdTypeInterstitial = 1,
    YAdUIAdTypeBanner = 2,
    YAdUIAdTypeNative = 3
};