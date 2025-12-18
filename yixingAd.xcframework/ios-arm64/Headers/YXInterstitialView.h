 #import <Foundation/Foundation.h>

#if __has_include(<UIKit/UIKit.h>)
#import <UIKit/UIKit.h>
#endif

@class YXInterstitialAd;

/// 关闭按钮位置枚举（四个角）
typedef NS_ENUM(NSUInteger, YXCloseButtonCorner) {
    YXCloseButtonCornerTopLeft,
    YXCloseButtonCornerTopRight,
    YXCloseButtonCornerBottomLeft,
    YXCloseButtonCornerBottomRight,
};

/// 关闭按钮配置对象（与安卓 CloseButtonConfig 概念对齐）
@interface YXCloseButtonConfig : NSObject
@property (nonatomic, assign) CGFloat sizeDp;           /// 尺寸（pt，当作dp等效处理）
@property (nonatomic, assign) CGFloat marginLeftDp;     /// 左边距
@property (nonatomic, assign) CGFloat marginTopDp;      /// 上边距
@property (nonatomic, assign) CGFloat marginRightDp;    /// 右边距
@property (nonatomic, assign) CGFloat marginBottomDp;   /// 下边距
@property (nonatomic, assign) YXCloseButtonCorner corner; /// 位置（四角）
@property (nonatomic, assign) BOOL randomizeCornersEnabled; /// 是否启用随机角
@end

#if __has_include(<UIKit/UIKit.h>)
@interface YXInterstitialView : UIView
#else
@interface YXInterstitialView : NSObject
#endif

@property (nonatomic, assign) YXInterstitialAd *ownerAd; // MRC 环境下使用 assign
@property (nonatomic, copy) void (^onAdShown)(void);
@property (nonatomic, copy) void (^onAdClick)(void);
@property (nonatomic, copy) void (^onAdClose)(void);

- (instancetype)initWithFrame:(CGRect)frame;

/// 由 Ad 类传入数据进行配置
- (void)configureWithAdData:(NSDictionary *)adData;

/// 在指定容器视图中显示（全屏挂载）
- (void)presentInView:(id)parentView;

/// 设置关闭按钮配置（可在展示前或配置后调用）
- (void)setCloseButtonConfig:(YXCloseButtonConfig *)config;

@end
