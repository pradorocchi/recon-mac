//
//  NTTransitionView.h
//  Path Finder
//
//  Created by Steve Gehrman on 7/24/08.
//  Copyright 2008 Cocoatech. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class NTTransitionView;

@protocol NTTransitionViewDelegateProtocol <NSObject>
- (void)transitionViewDone:(NTTransitionView*)theView;
@end

@interface NTTransitionView : NSView
{
	__unsafe_unretained id<NTTransitionViewDelegateProtocol> delegate;
	
	NSImageView* imageView;
	NSImageView* newImageView;
}

@property (assign) id<NTTransitionViewDelegateProtocol> delegate;  // not retained
@property (retain) NSImageView* imageView;
@property (retain) NSImageView* newImageView;

- (NSImageView*)newImageView __attribute__((objc_method_family(none)));

+ (NTTransitionView*)transitionView:(NSView*)theView 
				  newView:(NSView*)theNewView
				 delegate:(id<NTTransitionViewDelegateProtocol>)theDelegate;

@end
