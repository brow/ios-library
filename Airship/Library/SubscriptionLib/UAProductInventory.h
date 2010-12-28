/*
 Copyright 2009-2010 Urban Airship Inc. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binaryform must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided withthe distribution.

 THIS SOFTWARE IS PROVIDED BY THE URBAN AIRSHIP INC``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL URBAN AIRSHIP INC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
#import "UAObservable.h"

@class UA_ASIHTTPRequest;
@class UASubscriptionProduct;

@interface UAProductInventory : UAObservable <SKProductsRequestDelegate> {
    NSMutableArray *productIDArray;
    NSMutableDictionary *productDict;
    BOOL hasLoaded;
}

@property (nonatomic, retain, readonly) NSMutableArray *productIDArray;
@property (nonatomic, retain, readonly) NSMutableDictionary *productDict;
@property (nonatomic, assign, readonly) BOOL hasLoaded;

- (id)init;
- (void)loadWithArray:(NSArray *)invArray;
- (void)loadInventory;
- (NSArray *)productsForSubscription:(NSString *)subscriptionKey;

- (void)addProduct:(UASubscriptionProduct *)product;
- (void)removeProduct:(NSString*)productID;
- (BOOL)containsProduct:(NSString *)productID;
- (UASubscriptionProduct *)productForKey:(NSString *)productKey;
+ (NSString*)localizedPrice:(SKProduct*)product;

@end