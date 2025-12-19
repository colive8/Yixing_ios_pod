#import <Foundation/Foundation.h>
#import "YAdGRPCClient.h"
#import "YAdEventReporter.h"
#import "YAdEvents.h"

@interface YAdReportingAgent : NSObject

@property (nonatomic, strong, readonly) NSDictionary *adContext;
@property (nonatomic, strong, readonly) YAdGRPCClient *grpcClient;

- (instancetype)initWithAdContext:(NSDictionary *)adContext grpcClient:(YAdGRPCClient *)grpcClient;
- (void)updateAdContext:(NSDictionary *)adContext;

- (void)reportImpression;
- (void)reportClick;
- (void)reportClose;

// 新增：视频静音/取消静音埋点
- (void)reportVideoMute;
- (void)reportVideoUnmute;

// 新增：视频播放相关事件上报便捷方法
- (void)reportVideoPause;
- (void)reportVideoResume;
- (void)reportVideoStop;
- (void)reportVideoReady;
- (void)reportVideoLoadError;
// 可选：播放错误/重播/全屏切换（若有触发点可调用）
- (void)reportVideoError;
- (void)reportVideoReplay;
- (void)reportVideoFull;
- (void)reportVideoExitFull;

// 新增：跳过/停止上报
- (void)reportSkip;
- (void)reportStop;

// 新增：UC 点击与自动播放、进度四分位
- (void)reportUcClk;
- (void)reportAutoplay;
- (void)reportStart;
- (void)reportFirstQuartile;
- (void)reportMidPoint;
- (void)reportThirdQuartile;
- (void)reportComplete;

// 新增：与 Android 对齐的 deeplink/安装/下载等事件
- (void)reportAppUninstalled;
- (void)reportAppInstalled;
- (void)reportDplTry;
- (void)reportDplSuccess;
- (void)reportDplFailed;
- (void)reportFallbackTracks;
- (void)reportInstallStartTracks;
- (void)reportInstallTracks;
- (void)reportInstalledOpen;
- (void)reportInstallFailed;
- (void)reportDlStartTracks;
- (void)reportDlTracks;

@end