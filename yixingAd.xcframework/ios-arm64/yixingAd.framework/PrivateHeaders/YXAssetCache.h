#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, YXAssetKind) {
    YXAssetKindImage = 0,
    YXAssetKindVideo = 1,
    YXAssetKindJSON  = 2,
};

@class YXAssetCacheConfig;

@interface YXAssetContext : NSObject
@property (nonatomic, copy) NSString *adType;        // e.g. splash/interstitial/rewarded/feed/banner
@property (nonatomic, copy) NSString *placementId;   // ad placement id
@property (nonatomic, copy) NSString *requestId;     // per-request UUID
@property (nonatomic, copy) NSString *variant;       // size/crop/density variant hint
@end

@interface YXAssetCacheConfig : NSObject
@property (nonatomic) NSUInteger memoryCapacityBytes;       // NSCache cap for decoded bytes
@property (nonatomic) NSUInteger diskCapacityBytesImages;   // total disk cap for images
@property (nonatomic) NSTimeInterval defaultTTLImage;       // fallback TTL for images
@property (nonatomic) BOOL enablePrefetch;                  // prefetch toggle
+ (instancetype)defaultConfig;
@end

typedef void(^YXAssetCompletion)(NSData * _Nullable data,
                                 NSString * _Nullable filePath,
                                 NSDictionary * _Nullable meta,
                                 NSError * _Nullable error);

@interface YXAssetCache : NSObject
+ (instancetype)shared;
- (void)configure:(YXAssetCacheConfig *)config;

// Primary entry: get from cache or fetch from network.
- (void)getOrFetchURL:(NSURL *)url
                 kind:(YXAssetKind)kind
              context:(YXAssetContext *)context
           completion:(YXAssetCompletion)completion;

// Optional prefetch (non-blocking, best-effort).
- (void)prefetchURLs:(NSArray<NSURL *> *)urls
                kind:(YXAssetKind)kind
             context:(YXAssetContext *)context;

// Debug helpers
- (void)pruneIfNeeded;                   // enforce capacity
- (NSDictionary *)indexSummary;          // brief stats for monitoring

// Utilities
- (NSString *)cacheKeyForURL:(NSURL *)url variant:(NSString *)variant;
- (NSString *)imagesDirectoryPath;
@end