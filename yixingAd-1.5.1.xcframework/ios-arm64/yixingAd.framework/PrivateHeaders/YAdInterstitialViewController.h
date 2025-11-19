//
//  YAdInterstitialViewController.h
//  yixingAd
//
//  Created by YixingAd SDK on 2024/01/01.
//  Copyright © 2024 YixingAd. All rights reserved.
//

#import <Foundation/Foundation.h>

// 事件类型枚举
typedef NS_ENUM(NSInteger, YAdEventType) {
    YAdEventTypeImpression = 1,
    YAdEventTypeClick = 2,
    YAdEventTypeClose = 3,
    YAdEventTypeShow = 4
};

// 广告类型枚举
typedef NS_ENUM(NSInteger, YAdUIAdType) {
    YAdUIAdTypeInterstitial = 1,
    YAdUIAdTypeBanner = 2,
    YAdUIAdTypeNative = 3
};

@interface YAdInterstitialViewController : NSObject

// 广告数据
@property (nonatomic, strong) NSDictionary *adData;

// 回调块
@property (nonatomic, copy) void (^onAdShown)(void);
@property (nonatomic, copy) void (^onAdClicked)(void);
@property (nonatomic, copy) void (^onAdClosed)(void);

// 显示和隐藏方法
- (void)show;
- (void)hide;

@end