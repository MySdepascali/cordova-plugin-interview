//
//  AffTaskObject.h
//  Affidavit
//
//  Created by Eugine Korobovsky on 25.12.15.
//  Copyright © 2015 hintsolutions. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

typedef enum {
    AffSubtaskTypeDemo = 0,
    AffSubtaskTypeSMSRead,
    AffSubtaskTypeStatementRead,
    AffSubtaskTypePassport
} AffSubtaskType;

typedef enum : NSUInteger {
    AffSubtaskOverlayTypeVoid = 0,
    AffSubtaskOverlayTypePassport,
    AffSubtaskOverlayTypeFace
} AffSubtaskOverlayType;

typedef enum : NSUInteger {
    AffSubtaskWatermarkMaskNone        = 0,
    AffSubtaskWatermarkMaskDatetime    = 1,
    AffSubtaskWatermarkMaskGeo         = 1<<1
} AffSubtaskWatermarkMask;

typedef enum : NSUInteger {
    AffSubtaskPresentationStyleLandscape = 0,           // with left subtask view
    AffSubtaskPresentationStyleLandscapeFullscreen,     // for passport types
    AffSubtaskPresentationStylePortrait                 // portrait style
} AffSubtaskPresentationStyle;


@interface AffSubtaskObject : NSObject {
    
}

- (id)init;
- (id)initWithType:(AffSubtaskType)type;

@property (nonatomic) AffSubtaskType taskType;
@property (nonatomic) AffSubtaskOverlayType overlayType;
@property (nonatomic) AffSubtaskPresentationStyle presentationStyle;
@property (nonatomic) NSTimeInterval minVideoDuration;
@property (nonatomic) NSTimeInterval maxVideoDuration;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *subtitle;
@property (nonatomic) AffSubtaskWatermarkMask watermark;
@property (nonatomic) BOOL isAntimirror;
@property (nonatomic) BOOL isRear;
@property (nonatomic) BOOL isCatchScreenshots;
@property (nonatomic) NSInteger order;

- (UIImage *)getOverlayWithHighlight:(BOOL)isHighlight;
- (UIImage *)getTaskImage;
- (NSString *)mainButtonTextBeforeMinTime;
- (NSString *)reviewTitleForSubtask;
- (NSString *)reviewSubtitleForSubtask;

@end
