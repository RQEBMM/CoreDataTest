//
//  Entity.h
//  CoreDataTest
//
//  Created by Ken Thomsen on 2/11/13.
//  Copyright (c) 2013 Ben McCloskey. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface Entity : NSManagedObject

@property (nonatomic, retain) NSString * attribute;

@end
