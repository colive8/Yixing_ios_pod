#import <Foundation/Foundation.h>
#if __has_include(<UIKit/UIKit.h>)
#import <UIKit/UIKit.h>
#endif
@class YAdBid;

#if __has_include(<UIKit/UIKit.h>)
@interface YAdSplashView : UIView
#else
@interface YAdSplashView : NSObject
#endif

@property (nonatomic, strong) NSDictionary *adData;
@property (nonatomic, strong) YAdBid *bid; // 直接传入服务端返回的bid
@property (nonatomic, copy) void (^onAdClicked)(void);
@property (nonatomic, copy) void (^onAdSkipped)(void);
@property (nonatomic, copy) void (^onAdTimeOver)(void);

- (void)loadAdContent;
- (void)showInView:(id)parentView;
- (void)removeFromParentView;

@end