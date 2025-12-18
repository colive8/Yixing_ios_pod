#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YAdSDKConfig : NSObject

@property (nonatomic, copy, readonly) NSString *appId;
@property (nonatomic, copy) NSString *host;
@property (nonatomic, assign) int32_t port;
@property (nonatomic, assign) BOOL enableSSL; // default: NO

+ (instancetype)configWithAppId:(NSString *)appId host:(NSString *)host port:(int32_t)port;
- (instancetype)initWithAppId:(NSString *)appId host:(NSString *)host port:(int32_t)port;

@end

NS_ASSUME_NONNULL_END