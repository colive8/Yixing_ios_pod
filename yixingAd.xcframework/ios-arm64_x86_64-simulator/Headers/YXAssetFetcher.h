#import <Foundation/Foundation.h>

typedef void(^YXFetcherCompletion)(NSData * _Nullable data,
                                   NSHTTPURLResponse * _Nullable response,
                                   NSError * _Nullable error);

@interface YXAssetFetcher : NSObject
+ (instancetype)shared;

// Basic GET with optional headers, simple retry for 5xx.
- (void)fetchURL:(NSURL *)url
         headers:(NSDictionary<NSString*,NSString*> * _Nullable)headers
          tries:(NSInteger)tries
     completion:(YXFetcherCompletion)completion;
@end