//  ----------------------------------------------------------------------
//  Copyright (C) 2015 Jack Jiang The MobileIMSDK Project.
//  All rights reserved.
//  Project URL:  https://github.com/JackJiang2011/MobileIMSDK
//
//  openmob.net PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
//
//  You can contact author with jack.jiang@openmob.net or jb2011@163.com.
//  ----------------------------------------------------------------------
//
//  PLoginInfoResponse.h
//  MobileIMSDK4i
//
//  Created by JackJiang on 14/10/22.
//  Copyright (c) 2014年 openmob.net. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 * 服务端反馈的用户登陆结果数据封装类。
 *
 * @author Jack Jiang,2014-10-29
 * @version 1.0
 * @since 2.1
 */
@interface PLoginInfoResponse : NSObject

/*! 错误码：0表示认证成功，否则是用户自定的错误码（该码应该是>1024的整数） */
@property (nonatomic, assign) int code;

/*! 用户登陆路成功后分配给客户的唯一id：此值只在code==0时才有意义 */
@property (nonatomic, assign) int user_id;

@end
