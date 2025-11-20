#import <Foundation/Foundation.h>
#if __has_include(<UIKit/UIKit.h>)
#import <UIKit/UIKit.h>
#endif

#if __has_include(<UIKit/UIKit.h>)
@interface YAdRewardedViewController : UIViewController
#else
@interface YAdRewardedViewController : NSObject
#endif

@property (nonatomic, strong) NSDictionary *adData;
@property (nonatomic, assign) NSInteger countdownSeconds;            // 总时长，默认 8s
@property (nonatomic, assign) NSInteger rewardThresholdSeconds;      // 获得奖励所需观看时长，默认 5s

@property (nonatomic, copy) void (^onAdShown)(void);
@property (nonatomic, copy) void (^onAdClicked)(void);
@property (nonatomic, copy) void (^onAdClosed)(void);
@property (nonatomic, copy) void (^onRewardEarned)(void);

- (instancetype)initWithAdData:(NSDictionary *)adData;

@end