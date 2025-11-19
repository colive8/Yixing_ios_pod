#import <Foundation/Foundation.h>
#if __has_include(<UIKit/UIKit.h>)
#import <UIKit/UIKit.h>
#endif

#if __has_include(<UIKit/UIKit.h>)
@interface YAdBannerView : UIView
#else
@interface YAdBannerView : NSObject
#endif

@property (nonatomic, strong) NSDictionary *adData;
@property (nonatomic, copy) void (^onAdClicked)(void);
@property (nonatomic, copy) void (^onAdImpression)(void);

- (void)configureWithAdData:(NSDictionary *)adData;

@end