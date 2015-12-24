//
//  TeadsSoundButton.h
//  TeadsSDK
//
//  Created by Bastien Lefrant on 16/07/2015.
//  Copyright (c) 2015 Teads. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TeadsContentSettings.h"

typedef enum {
    TeadsSoundButtonTypeVumeter,
    TeadsSoundButtonTypeMute
}TeadsSoundButtonType;

@interface TeadsSoundButton : NSObject <TeadsContentSettingsProtocol>

@property (nonatomic) BOOL display;
@property (nonatomic) int countdown;
@property (nonatomic) TeadsSoundButtonType type;

@end
