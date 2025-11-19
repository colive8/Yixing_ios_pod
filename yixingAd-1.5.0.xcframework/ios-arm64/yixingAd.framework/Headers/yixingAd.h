//
//  yixingAd.h
//  yixingAd
//
//  Created by colive on 2025/7/9.
//

#import <Foundation/Foundation.h>

//! Project version number for yixingAd.
FOUNDATION_EXPORT double yixingAdVersionNumber;

//! Project version string for yixingAd.
FOUNDATION_EXPORT const unsigned char yixingAdVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <yixingAd/PublicHeader.h>

// Removed legacy manager from public umbrella

#import "YixingAdSDK.h"
#import "YAdRequest.h"
#import "YAdResponse.h"
#import "YXAdCommon.h"
#import "YXAdEventDelegate.h"
#import "YXBannerAd.h"
#import "YXInterstitialAd.h"
#import "YXSplashAd.h"
#import "YXFeedAd.h"
#import "YXRewardedVideoAd.h"
#if __has_include(<UIKit/UIKit.h>)
#import "YXBannerView.h"
#import "YXSplashView.h"
#import "YXInterstitialView.h"
#import "YXFeedView.h"
#endif
// gRPC support is provided through Swift bridging header
