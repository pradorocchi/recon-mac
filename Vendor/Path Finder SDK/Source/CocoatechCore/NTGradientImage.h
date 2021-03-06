//
//  NTGradientImage.h
//  CocoatechCore
//
//  Created by Steve Gehrman on 9/15/05.
//  Copyright 2005 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class NTGradient;

// caches a gradient in an image for faster drawing

@interface NTGradientImage : NSObject {
	NTGradient *mv_gradient;
	NSColor* mv_color;
	NSColor* mBackColor;
	
	int mv_imageHeight;
	NSImage* mv_image;
}

+ (NTGradientImage*)gradientImage:(NTGradient*)gradient color:(NSColor*)color;
+ (NTGradientImage*)gradientImage:(NTGradient*)gradient color:(NSColor*)color backColor:(NSColor*)backColor;

- (void)drawInRect:(NSRect)rect;
- (void)drawInRect:(NSRect)rect rotation:(CGFloat)rotation;
- (void)drawInPath:(NSBezierPath*)path;
- (void)drawInPath:(NSBezierPath*)path inRect:(NSRect)inRect;
- (void)drawInPath:(NSBezierPath*)path inRect:(NSRect)inRect rotation:(CGFloat)rotation;

@property (nonatomic, retain) NTGradient *gradient;
@property (nonatomic, retain) NSColor *color;
@property (nonatomic, retain) NSColor *backColor;

@end
