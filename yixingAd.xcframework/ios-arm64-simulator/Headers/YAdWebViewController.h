//
//  YAdWebViewController.h
//  yixingAd
//
//  Lightweight in-app landing page presenter using WKWebView.
//

#import <Foundation/Foundation.h>

@class UIViewController;
@class NSURL;

@interface YAdWebViewController : NSObject

+ (void)presentFromViewController:(UIViewController *)presentingController withURL:(NSURL *)url;

@end