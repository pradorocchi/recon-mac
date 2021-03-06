//
//  NmapController.h
//  Recon
//
//  Created by Sumanth Peddamatham on 7/1/09.
//  Copyright 2009 bafoontecha.com. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class Session;

@interface NmapController : NSObject {
   
   BOOL hasRun;
	NSTask *task;   
   
	NSMutableData *standardOutput;
	NSMutableData *standardError;
   
   NSString *outputFilePath;
}

@property(readonly) BOOL hasRun;

- (id) initWithNmapBinary:(NSString *)nmapBinary 
                 withArgs:(NSArray *)nmapArgs 
       withOutputFilePath:(NSString *)outputFilePath;

@property (readonly, getter=isRunning) BOOL running;
- (void) startScan;
- (void) abortScan;


@end
