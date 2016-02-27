
#import <Cocoa/Cocoa.h>

@interface BonjourListener : NSObject <NSNetServiceBrowserDelegate, NSNetServiceDelegate> {
   NSNetServiceBrowser *primaryBrowser;
   NSNetServiceBrowser *secondaryBrowser;
   NSMutableArray *services;   
   NSDictionary *bonjourDict;
}

@property (readonly, retain) NSMutableArray *services;

- (void)setBonjourDict;
-(IBAction)search:(id)sender;

@end
