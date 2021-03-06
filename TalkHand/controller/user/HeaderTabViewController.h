//
//  HeaderTabViewController.h
//  HJTabViewControllerDemo
//
//  Created by haijiao on 2017/3/18.
//  Copyright © 2017年 olinone. All rights reserved.
//

#import "HJTabViewController.h"

#import "UserInfoMenu.h"
@interface HeaderTabViewController : HJTabViewController<UIImagePickerControllerDelegate,UINavigationControllerDelegate>
@property (nonatomic, assign) BOOL menuIsVisible;
@property (nonatomic, strong) UserInfoMenu *sideMenu;
@property (nonatomic) UIView *baseView;
@end
