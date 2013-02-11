//
//  ViewController.m
//  CoreDataTest
//
//  Created by Ken Thomsen on 2/11/13.
//  Copyright (c) 2013 Ben McCloskey. All rights reserved.
//

#import "ViewController.h"
#import "DTDevices.h"
#import "CoreDataHelper.h"
#import "Entity.h"

@interface ViewController ()

@end

@implementation ViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
	//uncomment this to try the fetch statement before connecting to Linea
	//ios will quit with an uncaught exception
	//[self fetchNoCatch];
	
	//fetch statements run from the connectionState: method
	[[DTDevices sharedDevice] addDelegate:self];
    [[DTDevices sharedDevice] connect];
	
	
	
    [super viewDidLoad];
	// Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


-(void)connectionState:(int)state
{
	switch (state) {
		case CONN_DISCONNECTED:
		case CONN_CONNECTING:
			break;
		case CONN_CONNECTED:
			NSLog(@"Connected to Linea");
			
			//try the fetch statements after connecting
			
			[self fetchCatch];
			[self fetchNoCatch];
			break;
	}
	
}

-(void)fetchNoCatch
{
	NSLog(@"Fetching data without @catch");
	
	NSManagedObjectContext *managedObjectContext = [CoreDataHelper getMainMOC];
	Entity *dummyEntity = [CoreDataHelper insertObjectForEntity:@"Entity" andContext:managedObjectContext];
	dummyEntity.attribute = @"test";
	
	//this fetch will fail and throw a Core Data Exception.
	[CoreDataHelper searchObjectsForEntity:@"Entity" withPredicate:[NSPredicate predicateWithFormat:@"%@ BEGINSWITH attribute",@"testy"] andSortKey:nil andSortAscending:NO andContext:managedObjectContext];
	
	//DTDevices will catch the exception and ignore it, causing any code after the fetch to not be run
	
	//we will never reach this breakpoint.	
	NSLog(@"Fetch exception did not get caught");
	//because DTDevices catches the exception THIS WILL NOT ABORT THE PROGRAM
	abort();
}
-(void)fetchCatch
{
	NSLog(@"Fetching data WITH @catch");
	NSArray *imAnArray;
	@try {
		
		//this fetch will fail and throw a Core Data Exception.
	NSManagedObjectContext *managedObjectContext = [CoreDataHelper getMainMOC];
	Entity *dummyEntity = [CoreDataHelper insertObjectForEntity:@"Entity" andContext:managedObjectContext];
	dummyEntity.attribute = @"test";
	
	imAnArray = [CoreDataHelper searchObjectsForEntity:@"Entity" withPredicate:[NSPredicate predicateWithFormat:@"%@ BEGINSWITH attribute",@"testy"] andSortKey:nil andSortAscending:NO andContext:managedObjectContext];
	}
	@catch (NSException* exception) {
		//this will explicitly catch the exception
		NSLog(@"Caught Exception!\n\n%@\n\n%@\n\n%@",[exception name], [exception reason], [exception userInfo]);
	}
	@finally {
		NSLog(@"%@",[imAnArray description]);
	}
}

@end
