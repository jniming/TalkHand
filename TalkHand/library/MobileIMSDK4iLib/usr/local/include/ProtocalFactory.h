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
//  ProtocalFactory.h
//  MobileIMSDK4i
//
//  Created by JackJiang on 14/10/23.
//  Copyright (c) 2014年 openmob.net. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Protocal.h"
#import "PLoginInfoResponse.h"
#import "PErrorResponse.h"

/*!
 * MibileIMSDK框架的协议工厂类。
 * <p>
 * 理论上这些协议都是即时通讯框架内部要用到的，上层应用可以无需理解和理会之。
 *
 * @author Jack Jiang,2014-10-29
 * @version 1.0
 * @since 2.1
 */
@interface ProtocalFactory : NSObject


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - 协议解析相关方法
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*!
* 将JSON转换而来的byte数组反序列化成Protocal类的对象.
* <p>
* <b>本方法主要由MobileIMSDK框架内部使用。</b>
*
* @param fullProtocalJASOnBytes JSON转换而来的byte数组
* @return 如果返回列化成功则返回对象，否则返回nil
*/
+ (id) parse:(NSData *)fullProtocalJASOnBytes;

/*!
 * 将JSON转换而来的byte数组反序列化成指定类的对象.
 * <p>
 * <b>本方法主要由MobileIMSDK框架内部使用。</b>
 *
 * @param fullProtocalJASOnBytes JSON转换而来的byte数组
 * @param clazz 类
 * @return 如果返回列化成功则返回对象，否则返回nil
 */
+ (id) parse:(NSData *)fullProtocalJASOnBytes withClass:(Class)clazz;

/*!
 * 将指定的JSON字符串反序列化成指定类的对象.
 * <p>
 * <b>本方法主要由MobileIMSDK框架内部使用。</b>
 *
 * @param dataContentJSONOfProtocal json字符串
 * @param clazz 类
 * @return 如果返回列化成功则返回对象，否则返回nil
 *
 */
+ (id) parseObject:(NSString *)dataContentJSONOfProtocal withClass:(Class)clazz;

/*!
 * 接收用户登陆响应消息对象（该对象由客户端接收）.
 * <p>
 * <b>本方法主要由MobileIMSDK框架内部使用。</b>
 *
 * @param dataContentOfProtocal
 * @return
 */
+ (PLoginInfoResponse *) parsePLoginInfoResponse:(NSString *)dataContentOfProtocal;

/*!
 * 解析错误响应消息对象（该对象由客户端接收）.
 * <p>
 * <b>本方法主要由MobileIMSDK框架内部使用。</b>
 *
 * @param dataContentOfProtocal
 * @return
 */
+ (PErrorResponse *) parsePErrorResponse:(NSString *) dataContentOfProtocal;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - 协议组装相关方法
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*!
 * 创建用户注消登陆消息对象（该对象由客户端发出）.
 * <p>
 * <b>本方法主要由MobileIMSDK框架内部使用。</b>
 *
 * @param user_id
 * @param loginName
 * @return
 */
+ (Protocal *) createPLoginoutInfo:(int) user_id withLoginName:(NSString *)loginName;

/*!
 * 创建用户登陆消息对象（该对象由客户端发出）.
 * <p>
 * <b>本方法主要由MobileIMSDK框架内部使用。</b>
 *
 * @param loginName 登陆时提交的用户名：此用户名对框架来说可以随意，具体意义由上层逻辑决即可
 * @param loginPsw 登陆时提交的密码：此密码对框架来说可以随意，具体意义由上层逻辑决即可
 * @param extra 额外信息字符串。本字段目前为保留字段，供上层应用自行放置需要的内容
 * @return
 */
+ (Protocal *) createPLoginInfo:(NSString *)loginName withPsw:(NSString *)loginPsw andExtra:(NSString *)extra;

/*!
 * 创建用户心跳包对象（该对象由客户端发出）.
 * <p>
 * <b>本方法主要由MobileIMSDK框架内部使用。</b>
 *
 * @param from_user_id
 * @return
 */
+ (Protocal *) createPKeepAlive:(int)from_user_id;

/*!
 *  通用消息的Protocal对象新建方法（默认不需要Qos支持）。
 * <p>
 * <b>本方法主要由MobileIMSDK框架内部使用。</b>
 *
 *  @param dataContent  要发送的数据内容（字符串方式组织）
 *  @param from_user_id 发送人的user_id
 *  @param to_user_id   接收人的user_id
 *
 *  @return 新建的Protocal对象
 */
+ (Protocal *) createCommonData:(NSString *)dataContent fromUserId:(int)from_user_id toUserId:(int)to_user_id;

/*!
 *  通用消息的Protocal对象新建方法。
 * <p>
 * <b>本方法主要由MobileIMSDK框架内部使用。</b>
 *
 *  @param dataContent  要发送的数据内容（字符串方式组织）
 *  @param from_user_id 发送人的user_id
 *  @param to_user_id   接收人的user_id
 *  @param QoS          是否需要QoS支持，true表示需要，否则不需要
 *
 *  @return 新建的Protocal对象
 */
+ (Protocal *) createCommonData:(NSString *)dataContent fromUserId:(int)from_user_id toUserId:(int)to_user_id qos:(BOOL)QoS;

/*!
 *  通用消息的Protocal对象新建方法。
 * <p>
 * <b>本方法主要由MobileIMSDK框架内部使用。</b>
 *
 *  @param dataContent  要发送的数据内容（字符串方式组织）
 *  @param from_user_id 发送人的user_id
 *  @param to_user_id   接收人的user_id
 *  @param QoS          是否需要QoS支持，true表示需要，否则不需要
 *  @param fingerPrint  消息指纹特征码，为nil则表示由系统自动生成指纹码，否则使用本参数指明的指纹码
 *
 *  @return 新建的Protocal对象
 */
+ (Protocal *) createCommonData:(NSString *)dataContent fromUserId:(int)from_user_id toUserId:(int)to_user_id qos:(BOOL)QoS fp:(NSString *)fingerPrint;

/*!
 * 客户端from_user_id向to_user_id发送一个QoS机制中需要的“收到消息应答包”.
 * <p>
 * <b>本方法主要由MobileIMSDK框架内部使用。</b>
 *
 * @param from_user_id 发起方
 * @param to_user_id 接收方
 * @param recievedMessageFingerPrint 已收到的消息包指纹码
 * @return
 */
+ (Protocal *) createRecivedBack:(int)from_user_id toUserId:(int)to_user_id withFingerPrint:(NSString *)recievedMessageFingerPrint;

@end
