#import <Foundation/Foundation.h>

@interface YXAssetIndexEntry : NSObject <NSSecureCoding>
@property (nonatomic, copy) NSString *cacheKey;
@property (nonatomic, copy) NSString *urlString;
@property (nonatomic, copy) NSString *mime;
@property (nonatomic) NSUInteger sizeBytes;
@property (nonatomic) NSTimeInterval ttl;
@property (nonatomic) NSTimeInterval expireAt; // epoch seconds
@property (nonatomic, copy) NSString *etag;
@property (nonatomic, copy) NSString *lastModified;
@property (nonatomic, copy) NSString *adType;
@property (nonatomic, copy) NSString *placementId;
@property (nonatomic, copy) NSString *variant;
@property (nonatomic) NSTimeInterval lastAccessAt;
@end

@interface YXAssetIndex : NSObject
+ (instancetype)shared;
- (void)loadFromDiskIfNeeded;
- (void)saveToDisk;

- (YXAssetIndexEntry *)entryForKey:(NSString *)cacheKey;
- (void)upsertEntry:(YXAssetIndexEntry *)entry;
- (void)removeEntryForKey:(NSString *)cacheKey;
- (void)touchEntryForKey:(NSString *)cacheKey;

- (NSUInteger)totalSizeBytes;
- (NSDictionary *)summary; // entries count, total size

- (void)pruneToMaxBytes:(NSUInteger)maxBytes priorityHint:(NSDictionary<NSString*,NSNumber*> *)priority;

// Paths
- (NSString *)indexFilePath;
@end