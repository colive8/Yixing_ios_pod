#import <UIKit/UIKit.h>

@interface YXRedEnvelopeRainView : UIView

@property (nonatomic, assign, readonly) BOOL raining;
@property (nonatomic, assign, readonly) BOOL paused;

- (void)startRainWithCount:(NSInteger)count;
- (void)pauseRain;
- (void)resumeRain;
- (void)stopRain;

@end