//
//  TKEduClassRoom.h
//  EduClassPad
//
//  Created by ifeng on 2017/5/10.
//  Copyright © 2017年 beijing. All rights reserved.
//

#import <Foundation/Foundation.h>
@import UIKit;

typedef NS_ENUM(NSInteger,EKickOutReason) {
    
    EKickOutReason_ChairmanKickout,		    //老师踢出
    EKickOutReason_Repeat                    //重复登录
};
static NSString*const sTKRoomViewControllerDisappear = @"sTKRoomViewControllerDisappear";
#pragma mark TKEduEnterClassRoomDelegate
@protocol TKEduRoomDelegate <NSObject>
@optional


- (void) onEnterRoomFailed:(int)result Description:(NSString*)desc;
- (void) onKitout:(EKickOutReason)reason;
- (void) joinRoomComplete;
- (void) leftRoomComplete;
- (void) onClassBegin;
- (void) onClassDismiss;
- (void) onCameraDidOpenError;

@end

@interface TKEduClassRoom : NSObject

+(int)joinRoomWithParamDic:(NSDictionary*)paramDic
           ViewController:(UIViewController*)controller
                 Delegate:(id<TKEduRoomDelegate>)delegate;
/**
 *  获取会议控制器
 *
 *  @return会议控制器对象
 */

+(UIViewController *)currentViewController;
+(void)leftRoom;
+(UIViewController *)currentRoomViewController;
@end
