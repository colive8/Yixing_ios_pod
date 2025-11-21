#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 错误域
FOUNDATION_EXPORT NSString * const YXAdErrorDomain;

/// 广告状态
typedef NS_ENUM(NSInteger, YXAdState) {
    YXAdStateIdle = 0,
    YXAdStateLoading,
    YXAdStateReady,
    YXAdStateFailed,
    YXAdStateShowing,
    YXAdStateClosed,
};

/// 错误码
typedef NS_ENUM(NSInteger, YXAdErrorCode) {
    YXAdErrorCodeInvalidRequest = -1000,
    YXAdErrorCodeNoFill = -1001,
    YXAdErrorCodeNotReady = -1002,
    YXAdErrorCodeInternal = -1099,
};

/// 判断是否为 App Store 链接（支持 itms-apps/itms-services 以及 apps.apple.com/itunes.apple.com）
FOUNDATION_EXPORT BOOL YXIsAppStoreURL(NSURL * _Nullable url);
/// 从字符串判断是否为 App Store 链接
FOUNDATION_EXPORT BOOL YXIsAppStoreURLString(NSString * _Nullable urlString);

NS_ASSUME_NONNULL_END