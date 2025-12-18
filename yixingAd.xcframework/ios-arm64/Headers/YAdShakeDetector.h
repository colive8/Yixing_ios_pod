#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YAdShakeDetector : NSObject

@property (nonatomic, copy, nullable) void (^onShake)(double xMaxAcc, double yMaxAcc, double zMaxAcc);

// sensitivity: 1..5；值越小越敏感
// 映射规则（与安卓一致，单位为 m/s²）：
// 1 -> 0.5, 2 -> 1.0, 3 -> 1.4, 4 -> 1.8, 5 -> 2.2
// 内部比较以 g 为单位，自动按 GRAVITY_EARTH 转换；当外部传入 <=0 时使用默认档位 2
- (instancetype)initWithSensitivity:(NSInteger)sensitivity;
- (void)updateSensitivity:(NSInteger)sensitivity;
// 控制加速度采样
- (void)start;
- (void)stop;

// 重置一次性触发的标记，使其可以再次触发一次（与安卓一次性触发行为对齐）
- (void)resetOneShot;

@end

NS_ASSUME_NONNULL_END
