#import <Foundation/Foundation.h>
FOUNDATION_EXPORT BOOL YXShouldLog(NSString * _Nullable tag, NSInteger level);
FOUNDATION_EXPORT void YXEmitLog(NSString * _Nullable tag, NSInteger level, NSString * _Nullable message);

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, YXLogLevel) {
    YXLogLevelOff = 0,
    YXLogLevelError = 1,
    YXLogLevelWarn = 2,
    YXLogLevelInfo = 3,
    YXLogLevelDebug = 4,
    YXLogLevelTrace = 5,
};

#define YXLogE(tag, fmt, ...) do { if (YXShouldLog((tag), YXLogLevelError)) { YXEmitLog((tag), YXLogLevelError, [NSString stringWithFormat:(fmt), ##__VA_ARGS__]); } } while(0)
#define YXLogW(tag, fmt, ...) do { if (YXShouldLog((tag), YXLogLevelWarn)) { YXEmitLog((tag), YXLogLevelWarn, [NSString stringWithFormat:(fmt), ##__VA_ARGS__]); } } while(0)
#define YXLogI(tag, fmt, ...) do { if (YXShouldLog((tag), YXLogLevelInfo)) { YXEmitLog((tag), YXLogLevelInfo, [NSString stringWithFormat:(fmt), ##__VA_ARGS__]); } } while(0)
#define YXLogD(tag, fmt, ...) do { if (YXShouldLog((tag), YXLogLevelDebug)) { YXEmitLog((tag), YXLogLevelDebug, [NSString stringWithFormat:(fmt), ##__VA_ARGS__]); } } while(0)
#define YXLogT(tag, fmt, ...) do { if (YXShouldLog((tag), YXLogLevelTrace)) { YXEmitLog((tag), YXLogLevelTrace, [NSString stringWithFormat:(fmt), ##__VA_ARGS__]); } } while(0)

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
