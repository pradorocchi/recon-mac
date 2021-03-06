//
//  NTImageButton.m
//  CocoatechCore
//
//  Created by Steve Gehrman on 7/23/04.
//  Copyright 2004 __MyCompanyName__. All rights reserved.
//

#import "NTImageButton.h"
#import "NSMenu-NTExtensions.h"
#import "NSWindow-NTExtensions.h"
#import "NSView-CoreExtensions.h"
#import "NTColorSet.h"
#import "NSImage-NTExtensions.h"

@interface NTImageButton ()
@property (nonatomic) BOOL mouseOver;
- (void)buildButton:(NSImage*)image
	 mouseOverImage:(NSImage*)mouseOverImage 
		dimmedImage:(NSImage*)dimmedImage;

@property (nonatomic, copy) NSImage *mouseOverImage;
- (void)installMouseTracker;

- (void)displayMenu;

- (void)windowStateChangedNotification:(NSNotification*)notification;
@end

@implementation NTImageButton

@synthesize menu, clickedImage, normalImage, dimmedImage;

- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
		
	[[NSNotificationCenter defaultCenter] addObserver:self
											 selector:@selector(windowStateChangedNotification:)
												 name:NSWindowDidResignMainNotification
											   object:nil];        
	[[NSNotificationCenter defaultCenter] addObserver:self
											 selector:@selector(windowStateChangedNotification:)
												 name:NSWindowDidBecomeMainNotification
											   object:nil];     
	
	[self installMouseTracker];
	
    return self;
}

- (void)dealloc
{
	[[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)windowStateChangedNotification:(NSNotification*)notification
{
    // make sure the window is our window
    if ([notification object] == [self contentWindow])        
        [self setNeedsDisplay:YES];
}

- (NSSize)size
{
    return [[self normalImage] size];
}

+ (NTImageButton*)button:(NSImage*)image 
		  mouseOverImage:(NSImage*)mouseOverImage
{
	return [self button:image mouseOverImage:mouseOverImage dimmedImage:nil];
}

+ (NTImageButton*)button:(NSImage*)image 
		  mouseOverImage:(NSImage*)mouseOverImage
			 dimmedImage:(NSImage*)dimmedImage
{
	NSRect buttonBounds = NSZeroRect;
	buttonBounds.size = [image size];
    NTImageButton *result = [[self alloc] initWithFrame:buttonBounds];
	
    [result buildButton:image mouseOverImage:mouseOverImage dimmedImage:dimmedImage];
    
    return result;
}

- (void)drawRect:(NSRect)rect
{
	[super drawRect:rect];  // subclass can draw background if needed
	
	NSImage* image = [self normalImage];
	if ([self isEnabled])
	{
		if ([self mouseOver] && ![[self cell] isHighlighted])
			image = [self mouseOverImage];
		else if ([[self cell] isHighlighted] && [self clickedImage])
			image = [self clickedImage];
	}

	[image drawInRect:[self bounds] inView:self highlighted:[[self cell] isHighlighted] backgroundStyle:NSBackgroundStyleRaised];
}

- (BOOL)acceptsFirstMouse:(NSEvent *)theEvent
{
    return YES;
}

- (void)mouseDown:(NSEvent*)event
{
	if ([self menu])
		[self displayMenu];
	else
		[super mouseDown:event];
	
	// reset this if the click moved the view
	[self setMouseOver:NO];
}

- (void)rightMouseDown:(NSEvent*)event
{
	if ([self menu])
		[self displayMenu];
	else
		[super rightMouseDown:event];
}

- (BOOL)mouseDownCanMoveWindow
{
	return NO;
}

- (void)displayMenu
{
	[[self cell] setHighlighted:YES];
	[[self menu] popupMenuBelowRect:[self bounds] inView:self];
	[[self cell] setHighlighted:NO];
}	

//---------------------------------------------------------- 
//  mouseOverImage 
//---------------------------------------------------------- 
@synthesize mouseOverImage=mMouseOverImage;

- (void)setMouseOverImage:(NSImage *)theMouseOverImage
{
    if (mMouseOverImage != theMouseOverImage) {
        mMouseOverImage = [theMouseOverImage copy];
		
		[mMouseOverImage setTemplate:NO];  // prevent from drawing black
    }
}

- (void)buildButton:(NSImage*)theImage
	 mouseOverImage:(NSImage*)theMouseOverImage
		dimmedImage:(NSImage*)theDimmedImage
{
	NTColorSet *colorSet = [NTColorSet standardSet];

    [self setImagePosition:NSImageOnly];
    [self setBordered:NO];
		
    [[self cell] setShowsStateBy:NSContentsCellMask];
    [[self cell] setHighlightsBy:NSPushInCellMask];

	[[self cell] setTitle:@""];
	[[self cell] setAlternateTitle:@""];

	[self setNormalImage:theImage];
	[self setMouseOverImage:theMouseOverImage];

	if (!theDimmedImage)
		theDimmedImage = [theImage coloredImage:[colorSet colorForKey:kNTCS_disabledText]];
	
	[self setDimmedImage:theDimmedImage];
}

@synthesize mouseOver=mv_mouseOver;

- (void)setMouseOver:(BOOL)newMouseOver
{
	if (newMouseOver != mv_mouseOver)
	{
		mv_mouseOver = newMouseOver;
		[self setNeedsDisplay:YES];
	}
}

- (void)installMouseTracker
{    
	NSTrackingAreaOptions options = NSTrackingMouseEnteredAndExited | NSTrackingActiveInActiveApp | NSTrackingActiveInKeyWindow | NSTrackingInVisibleRect;
		
	if ([self mouseInRectNow])
	{
		options |= NSTrackingAssumeInside;
		[self setMouseOver:YES];
	}
	
    NSTrackingArea *area = [[NSTrackingArea alloc] initWithRect:NSZeroRect 
														options:options
														  owner:self
													   userInfo:nil];
    [self addTrackingArea:area];
}

- (void)mouseEntered:(NSEvent *)event
{	
	[self setMouseOver:YES];
}

- (void)mouseExited:(NSEvent *)event 
{
	[self setMouseOver:NO];
}

@end
