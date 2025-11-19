#import <Foundation/Foundation.h>

@interface YAdFeedAsset : NSObject

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *descText;
@property (nonatomic, copy) NSString *iconUrl;
@property (nonatomic, copy) NSString *imageUrl;
@property (nonatomic, copy) NSString *clickUrl;
@property (nonatomic, copy) NSString *ctaText;
@property (nonatomic, copy) NSString *source;
@property (nonatomic, copy) NSString *sourceLogo;

+ (instancetype)assetFromAdData:(NSDictionary *)adData;

@end