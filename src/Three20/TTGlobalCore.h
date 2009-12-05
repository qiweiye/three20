/**
 * Copyright 2009 Facebook
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "Three20/TTDebug.h"
#import "Three20/TTDebugFlags.h"

#import "Three20/NSObjectAdditions.h"
#import "Three20/NSDataAdditions.h"
#import "Three20/NSStringAdditions.h"
#import "Three20/NSArrayAdditions.h"
#import "Three20/NSMutableArrayAdditions.h"
#import "Three20/NSMutableDictionaryAdditions.h"
#import "Three20/NSDateAdditions.h"

/**
 * Borrowed from Apple's AvailabiltyInternal.h header. There's no reason why we shouldn't be
 * able to use this macro, as it's a gcc-supported flag.
 * Here's what we based it off of.
 * #define __AVAILABILITY_INTERNAL_DEPRECATED         __attribute__((deprecated))
 */
#define __TTDEPRECATED_METHOD __attribute__((deprecated))

///////////////////////////////////////////////////////////////////////////////////////////////////
// Logging Helpers

void TTDeprecatedLog(NSString* text, ...) __TTDEPRECATED_METHOD;

// Deprecated, please see Three20/TTDebug.h for more details.
#ifdef DEBUG
#define TTLOG TTDeprecatedLog
#else
#define TTLOG    
#endif

// Deprecated, please see Three20/TTDebug.h for more details.
#define TTWARN TTLOG


// Helper

#define TTLOGRECT(rect) \
  TTDINFO(@"%s x=%f, y=%f, w=%f, h=%f", #rect, rect.origin.x, rect.origin.y, \
    rect.size.width, rect.size.height)

#define TTLOGPOINT(pt) \
  TTDINFO(@"%s x=%f, y=%f", #pt, pt.x, pt.y)

#define TTLOGSIZE(size) \
  TTDINFO(@"%s w=%f, h=%f", #size, size.width, size.height)

#define TTLOGEDGES(edges) \
  TTDINFO(@"%s left=%f, right=%f, top=%f, bottom=%f", #edges, edges.left, edges.right, \
    edges.top, edges.bottom)

#define TTLOGHSV(_COLOR) \
  TTDINFO(@"%s h=%f, s=%f, v=%f", #_COLOR, _COLOR.hue, _COLOR.saturation, _COLOR.value)

///////////////////////////////////////////////////////////////////////////////////////////////////
// Errors

#define TT_ERROR_DOMAIN @"three20.net"

#define TT_EC_INVALID_IMAGE 101

///////////////////////////////////////////////////////////////////////////////////////////////////
// Time

#define TT_MINUTE 60
#define TT_HOUR (60*TT_MINUTE)
#define TT_DAY (24*TT_HOUR)
#define TT_WEEK (7*TT_DAY)
#define TT_MONTH (30.5*TT_DAY)
#define TT_YEAR (365*TT_DAY)

///////////////////////////////////////////////////////////////////////////////////////////////////

#define TT_RELEASE_SAFELY(__POINTER) { [__POINTER release]; __POINTER = nil; }
#define TT_AUTORELEASE_SAFELY(__POINTER) { [__POINTER autorelease]; __POINTER = nil; }
#define TT_INVALIDATE_TIMER(__TIMER) { [__TIMER invalidate]; __TIMER = nil; }
#define TT_RELEASE_CF_SAFELY(__REF) { if (nil != (__REF)) { CFRelease(__REF); __REF = nil; } }

///////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Creates a mutable array which does not retain references to the objects it contains.
 */
NSMutableArray* TTCreateNonRetainingArray();

/**
 * Creates a mutable dictionary which does not retain references to the values it contains.
 */
NSMutableDictionary* TTCreateNonRetainingDictionary();

/**
 * Tests if an object is an array which is empty.
 */
BOOL TTIsEmptyArray(id object);

/**
 * Tests if an object is a set which is empty.
 */
BOOL TTIsEmptySet(id object);

/**
 * Tests if an object is a string which is empty.
 */
BOOL TTIsEmptyString(id object);

void TTSwapMethods(Class cls, SEL originalSel, SEL newSel);