/* 

AppController.h created by eepstein on Mon 15-Apr-2002

Author: Ezra Epstein (eepstein@prajna.com)

Copyright (c) 2002 by Prajna IT Consulting.
                      http://www.prajna.com

========================================================================

THIS PROGRAM AND THIS CODE COME WITH ABSOLUTELY NO WARRANTY.
THIS CODE HAS BEEN PROVIDED "AS IS" AND THE RESPONSIBILITY
FOR ITS OPERATIONS IS 100% YOURS.

========================================================================
This file is part of RuntimeBrowser.

RuntimeBrowser is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

RuntimeBrowser is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with RuntimeBrowser (in a file called "COPYING.txt"); if not,
write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330,
Boston, MA  02111-1307  USA

*/

//TODO: make text size changeable
//TODO: reveal in Finder
//TODO: add history with navigation
//TODO: improve cells appearance (icons margins, ...)
//TODO: improve search (define search fields, ...)
//TODO: keep selection on view change

#import <AppKit/AppKit.h>
#import "ClassDisplayDeprecated.h"

@class AllClasses;
@class BrowserNode;

typedef enum {
	RBBrowserViewTypeImages = 0,
	RBBrowserViewTypeList = 1,
	RBBrowserViewTypeTree = 2,
    RBBrowserViewTypeProtocols = 3
} RBBrowserViewType;

@interface AppController : NSObject <NSOpenSavePanelDelegate, NSBrowserDelegate> {
	IBOutlet NSWindow *mainWindow;
    IBOutlet NSBrowser *classBrowser;
    IBOutlet NSTextField *label;
    IBOutlet NSTextView *headerTextView;
	IBOutlet NSSearchField *searchField;
    IBOutlet NSSegmentedControl *segmentedControl;
    
//    BOOL canUseLionAPIs;
    
#ifdef DEBUG
    double searchStart;
#endif
    
    BrowserNode *searchResultsNode;
	
	AllClasses *allClasses;
    
	NSString *openDir;
	NSURL *saveDirURL;
	
	NSArray *keywords;
	NSArray *classes;

	NSMutableArray *searchResults;
    
    NSOperationQueue *searchQueue;
}

@property (nonatomic, retain) NSWindow *mainWindow;
//@property (nonatomic, retain) NSString *openDir;
@property (nonatomic, retain) NSURL *saveDirURL;
@property (nonatomic, retain) NSArray *keywords;
@property (nonatomic, retain) AllClasses *allClasses;
@property (nonatomic, retain) NSArray *classes;
@property (nonatomic, retain) NSSegmentedControl *segmentedControl;
@property (nonatomic, retain) BrowserNode *searchResultsNode;
@property (nonatomic, retain) NSMutableArray *searchResults;
@property (nonatomic, retain) NSOperationQueue *searchQueue;

- (IBAction)openAction:(id)sender;
- (IBAction)saveAction:(id)sender;
- (IBAction)saveAllAction:(id)sender;

- (IBAction)changeViewTypeFromSegmentedControl:(NSSegmentedControl *)sender;
- (IBAction)changeViewTypeFromMenuItem:(NSMenuItem *)sender;

- (IBAction)cellClickedAction:(id)sender;

- (IBAction)search:(id)sender;

@end
