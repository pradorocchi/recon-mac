/*
 *  CocoatechCore.h
 *  CocoatechCore
 *
 *  Created by Steve Gehrman on 1/25/06.
 *  Copyright 2006 __MyCompanyName__. All rights reserved.
 *
 */

#import <Carbon/Carbon.h>
#import <CocoatechCore/NTCoreMacros.h>
#import <CocoatechCore/NTTaskController.h>
#import <CocoatechCore/NSThread-NTExtensions.h>
#import <CocoatechCore/NSData-NTExtensions.h>
#import <CocoatechCore/NSObject-NTExtensions.h>
#import <CocoatechCore/NSError-NTExtensions.h>
#import <CocoatechCore/NTSingletonObject.h>
#import <CocoatechCore/NTDateFormatter.h>
#import <CocoatechCore/NSDate-NTExtensions.h>
#import <CocoatechCore/NSCalendarDate-NTExtensions.h>
#import <CocoatechCore/NTGlobalPreferences.h>
#import <CocoatechCore/NSString-Utilities.h>
#import <CocoatechCore/NTSimpleTimer.h>
#import <CocoatechCore/NTPath.h>
#import <CocoatechCore/NTNameAndID.h>
#import <CocoatechCore/NTFont.h>
#import <CocoatechCore/NTUsersAndGroups.h>
#import <CocoatechCore/NSMenu-NTExtensions.h>
#import <CocoatechCore/NSMenuItem-NTExtensions.h>
#import <CocoatechCore/NTThreadHelper.h>
#import <CocoatechCore/NTThreadRunner.h>
#import <CocoatechCore/NTUtilities.h>
#import <CocoatechCore/NTSizeFormatter.h>
#import <CocoatechCore/NTSimpleAlert.h>
#import <CocoatechCore/NTGeometry.h>
#import <CocoatechCore/NSGraphicsContext-NTExtensions.h>
#import <CocoatechCore/NSDrawer-NTExtensions.h>
#import <CocoatechCore/NTTime.h>
#import <CocoatechCore/NSShadow-NTExtensions.h>
#import <CocoatechCore/NTLazyMenu.h>
#import <CocoatechCore/NTCarbonGeometry.h>
#import <CocoatechCore/NSImage-NTExtensions.h>
#import <CocoatechCore/NTImageButton.h>
#import <CocoatechCore/NTGradientFill.h>
#import <CocoatechCore/NTGradient.h>
#import <CocoatechCore/NTAlertPanel.h>
#import <CocoatechCore/NSBezierPath-NTExtensions.h>
#import <CocoatechCore/NSDictionary-NTExtensions.h>
#import <CocoatechCore/NSMutableDictionary-NTExtensions.h>
#import <CocoatechCore/NSMutableDictionary-ThreadSafe.h>
#import <CocoatechCore/NTView.h>
#import <CocoatechCore/NTKeyChainUtils.h>
#import <CocoatechCore/NTCoordinate.h>
#import <CocoatechCore/NSMatrix-CoreExtensions.h>
#import <CocoatechCore/NTEnablingTextField.h>
#import <CocoatechCore/NTEnablingTextFieldCell.h>
#import <CocoatechCore/NSView-CoreExtensions.h>
#import <CocoatechCore/NSWindow-NTExtensions.h>
#import <CocoatechCore/NTChooseDestinationPanel.h>
#import <CocoatechCore/NTChooseFilePanel.h>
#import <CocoatechCore/NSSavePanel-NTExtensions.h>
#import <CocoatechCore/NSTableViewNoFirstResponder.h>
#import <CocoatechCore/NTTableHeaderImages.h>
#import <CocoatechCore/NSTabView-NTExtensions.h>
#import <CocoatechCore/NTGradientDraw.h>
#import <CocoatechCore/NTColorSet.h>
#import <CocoatechCore/NTStandardColors.h>
#import <CocoatechCore/NTSynchronousTask.h>
#import <CocoatechCore/NSEvent-Utilities.h>
#import <CocoatechCore/NTImageMaker.h>
#import <CocoatechCore/NTAnimations.h>
#import <CocoatechCore/NTSplitViewDelegate.h>
#import <CocoatechCore/NTGradientImage.h>
#import <CocoatechCore/NSSplitView-NTExtensions.h>
#import <CocoatechCore/NSView-NSSplitViewExtensions.h>
#import <CocoatechCore/NSNumber-NTExtensions.h>
#import <CocoatechCore/NSAttributedString-NTExtensions.h>
#import <CocoatechCore/NSMutableAttributedString-Extensions.h>
#import <CocoatechCore/NSAnimationContext-NTExtensions.h>
#import <CocoatechCore/NTSpringLoadedViewHelper.h>
#import <CocoatechCore/NSArray-NTExtensions.h>
#import <CocoatechCore/NTStringView.h>
#import <CocoatechCore/NTStaticImageView.h>
#import <CocoatechCore/NTDoubleClickHandler.h>
#import <CocoatechCore/NTRevealParameters.h>
#import <CocoatechCore/NTTemplateButton.h>
#import <CocoatechCore/NTBackgroundView.h>
#import <CocoatechCore/NTBoxView.h>
#import <CocoatechCore/NTStandardImages.h>
#import <CocoatechCore/NSBundle-NTExtensions.h>
#import <CocoatechCore/NTKVObserverProxy.h>
#import <CocoatechCore/NSColor-NTExtensions.h>
#import <CocoatechCore/NTFramedSplitView.h>
#import <CocoatechCore/NTClickState.h>
#import <CocoatechCore/NTMenuSlider.h>
#import <CocoatechCore/NTSliderGradientView.h>
#import <CocoatechCore/NTSliderMenuItem.h>
#import <CocoatechCore/CATextLayer-NTExtensions.h>
#import <CocoatechCore/NTSpaceKeyPoll.h>
#import <CocoatechCore/NTHotKeyManager.h>
#import <CocoatechCore/CALayer-NTExtensions.h>
#import <CocoatechCore/NTPopUpButton.h>
#import <CocoatechCore/CATransaction-NTExtensions.h>
#import <CocoatechCore/NTMetalWindowTheme.h>
#import <CocoatechCore/NTSCPrefsListener.h>
#import <CocoatechCore/NSButton-NTExtensions.h>
#import <CocoatechCore/NTTransitionView.h>
#import <CocoatechCore/NTProxy.h>
#import <CocoatechCore/NTPointerObject.h>
#import <CocoatechCore/NSMutableArray-NTExtensions.h>
#import <CocoatechCore/NTSelectionGradient.h>
#import <CocoatechCore/NTFontButton.h>
#import <CocoatechCore/NTPasteboardHelper.h>
#import <CocoatechCore/NTWindowCascade.h>
#import <CocoatechCore/NTObjcRuntimeTools.h>
#import <CocoatechCore/NSDateFormatter-NTExtensions.h>
#import <CocoatechCore/NSLayoutManager-NTExtensions.h>
#import <CocoatechCore/NSFont-NTExtensions.h>
#import <CocoatechCore/NTTimeIntervalMeter.h>
#import <CocoatechCore/NTAnimationDelegate.h>
#import <CocoatechCore/NTSavePanel.h>
#import <CocoatechCore/NTAquaButtonCell.h>

// some common defines
#define kFinderApplicationName @"Finder.app"


