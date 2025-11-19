//
//  YAdResponse.h
//  yixingAd
//
//  Created by YixingAd SDK on 2024/01/01.
//  Copyright © 2024 YixingAd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 前向声明 proto 生成的类
@class YAdBid;

/**
 * 广告响应
 */
@interface YAdResponse : NSObject

@property (nonatomic, assign) NSInteger code;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, copy) NSString *requestId;
@property (nonatomic, assign) NSInteger delayTime;
@property (nonatomic, strong) NSArray<YAdBid *> *bids;  // 使用 proto 生成的 YAdBid

@end

NS_ASSUME_NONNULL_END