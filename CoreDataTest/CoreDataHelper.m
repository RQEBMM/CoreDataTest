//
//  CoreDataHelper.m
//  Scanner
//
//  Created by Simon@MaybeLost.com 

#import "CoreDataHelper.h"
#import "AppDelegate.h"

@implementation CoreDataHelper

#pragma mark - Retrieve objects

// Fetch objects with a predicate
+(NSMutableArray *)searchObjectsForEntity:(NSString*)entityName withPredicate:(NSPredicate *)predicate andSortKey:(NSString*)sortKey andSortAscending:(BOOL)sortAscending andContext:(NSManagedObjectContext *)managedObjectContext
{
	// Create fetch request
	NSFetchRequest *request = [[NSFetchRequest alloc] init];
	NSEntityDescription *entity = [NSEntityDescription entityForName:entityName inManagedObjectContext:managedObjectContext];
	[request setEntity:entity];	
    
	// If a predicate was specified then use it in the request
	if (predicate != nil)
		[request setPredicate:predicate];
    
	// If a sort key was passed then use it in the request
	if (sortKey != nil) {
		NSSortDescriptor *sortDescriptor = [[NSSortDescriptor alloc] initWithKey:sortKey ascending:sortAscending];
		NSArray *sortDescriptors = [[NSArray alloc] initWithObjects:sortDescriptor, nil];
		[request setSortDescriptors:sortDescriptors];
	}
    
	// Execute the fetch request
	NSError *error;
	NSArray *fetchResults = nil;
	fetchResults = [managedObjectContext executeFetchRequest:request error:&error];
	// If the returned array was nil then there was an error
	if (fetchResults == nil)
	{		
#ifdef DEBUG
		NSLog(@"Unresolved Core Data Fetch error %@, %@", error, [error userInfo]);
#endif
	}	
	NSMutableArray *mutableFetchResults = [fetchResults mutableCopy];
	// Return the results
	return mutableFetchResults;
}

// Fetch objects without a predicate
+(NSMutableArray *)getObjectsForEntity:(NSString*)entityName withSortKey:(NSString*)sortKey andSortAscending:(BOOL)sortAscending andContext:(NSManagedObjectContext *)managedObjectContext
{
	return [self searchObjectsForEntity:entityName withPredicate:nil andSortKey:sortKey andSortAscending:sortAscending andContext:managedObjectContext];
}

+(id)insertObjectForEntity:(NSString*)entityName andContext:(NSManagedObjectContext *)managedObjectContext
{
	return [NSEntityDescription insertNewObjectForEntityForName:entityName inManagedObjectContext:managedObjectContext];
}

#pragma mark - Count objects

// Get a count for an entity with a predicate
+(NSUInteger)countForEntity:(NSString *)entityName withPredicate:(NSPredicate *)predicate andContext:(NSManagedObjectContext *)managedObjectContext
{
	// Create fetch request
	NSFetchRequest *request = [[NSFetchRequest alloc] init];
	NSEntityDescription *entity = [NSEntityDescription entityForName:entityName inManagedObjectContext:managedObjectContext];
	[request setEntity:entity];
	[request setIncludesPropertyValues:NO];
    
	// If a predicate was specified then use it in the request
	if (predicate != nil)
		[request setPredicate:predicate];
    
	// Execute the count request
	NSError *error = nil;
	NSUInteger count = [managedObjectContext countForFetchRequest:request error:&error];
    
	// If the count returned NSNotFound there was an error
	if (count == NSNotFound)
	{
		#ifdef DEBUG 
		NSLog(@"Couldn't get count for entity %@", entityName);
	#endif
    }
	// Return the results
	return count;
}

// Get a count for an entity without a predicate
+(NSUInteger)countForEntity:(NSString *)entityName andContext:(NSManagedObjectContext *)managedObjectContext
{
	return [self countForEntity:entityName withPredicate:nil andContext:managedObjectContext];
}

#pragma mark - Delete Objects

// Delete all objects for a given entity
+(BOOL)deleteAllObjectsForEntity:(NSString*)entityName withPredicate:(NSPredicate*)predicate andContext:(NSManagedObjectContext *)managedObjectContext
{
	// Create fetch request
	NSFetchRequest *request = [[NSFetchRequest alloc] init];
	NSEntityDescription *entity = [NSEntityDescription entityForName:entityName inManagedObjectContext:managedObjectContext];
	[request setEntity:entity];	
    
	// Ignore property values for maximum performance
	[request setIncludesPropertyValues:NO];
    
	// If a predicate was specified then use it in the request
	if (predicate != nil)
		[request setPredicate:predicate];
    
	// Execute the count request
	NSError *error = nil;
	NSArray *fetchResults = [managedObjectContext executeFetchRequest:request error:&error];
    
	// Delete the objects returned if the results weren't nil
	if (fetchResults != nil) {
		for (NSManagedObject *manObj in fetchResults) {
			[managedObjectContext deleteObject:manObj];
		}
	} else {
		#ifdef DEBUG 
		NSLog(@"Couldn't delete objects for entity %@", entityName);
		#endif
	    return NO;
	}
    
	return YES;	
}

+(BOOL)deleteAllObjectsForEntity:(NSString*)entityName andContext:(NSManagedObjectContext *)managedObjectContext
{
	return [self deleteAllObjectsForEntity:entityName withPredicate:nil andContext:managedObjectContext];
}

+(void) saveObjectsInContext:(NSManagedObjectContext *)managedObjectContext
{
	managedObjectContext.mergePolicy = NSMergeByPropertyObjectTrumpMergePolicy;
	NSError *error = nil;
	if(![managedObjectContext save:&error]) {
		NSLog(@"Failed to save to data store: %@", [error localizedDescription]);
		NSArray* detailedErrors = [[error userInfo] objectForKey:NSDetailedErrorsKey];
		if(detailedErrors != nil && [detailedErrors count] > 0) {
			for(NSError* detailedError in detailedErrors) {
				NSLog(@"  DetailedError: %@\n", [detailedError userInfo]);
			}
		}
		else {
			NSLog(@"  %@", [error userInfo]);
		}
		NSAssert(1==1, @"core Data save failure");
	}		
	//[ErrorAlert saveFailure];
	
}

+(NSManagedObjectContext *)getMainMOC
{
	AppDelegate *appDelegate = (AppDelegate *)[[UIApplication sharedApplication] delegate];
	NSManagedObjectContext *mainMOC = appDelegate.managedObjectContext;
	return mainMOC;
}

+(NSPersistentStoreCoordinator *)getMainStoreCoordinator
{
	AppDelegate *appDelegate = (AppDelegate *)[[UIApplication sharedApplication] delegate];
	NSPersistentStoreCoordinator *mainStore = appDelegate.persistentStoreCoordinator;
	return mainStore;
}

@end