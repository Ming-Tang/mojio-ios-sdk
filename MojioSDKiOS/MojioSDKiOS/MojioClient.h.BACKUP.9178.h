//
//  MojioClient.h
//  SdkTryout
//
//  Created by Ashish Agarwal on 2015-01-22.
//  Copyright (c) 2015 Ashish Agarwal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MojioResponse.h"
#import "Token.h"
#import "Vehicle.h"

@interface MapEntity : NSObject

@end

@class MojioClient;

@protocol MojioClientDelegate <NSObject>

-(void) loggedIn;

@end

/**
 'MojioClient' is the main class of Mojio SDK.
 */
@interface MojioClient : NSObject

+(id) sharedInstance;

- (void)login;
- (void)logout;
- (void)handleOpenURL:(NSURL *)url;

- (void) initWithAppId : (NSString *) appId andSecretKey : (NSString *)secretKey andRedirectUrlScheme : (NSString *) urlScheme;


- (void) deleteEntity : (NSString *)entity withEntityId : (NSString *)entityId withQueryOptions : (NSDictionary *) queryOptions withParams : (NSArray *)params success : (void (^)(id responseObject)) success fail : (void (^) (NSError *error))fail;

- (void) updateEntity : (NSString *)entity withQueryOptions : (NSDictionary *)queryOptions withParams : (NSArray *)params success : (void (^)(id responseObject)) success fail : (void (^) (NSError *error)) fail;

- (void) createEntity : (NSString *)entity withQueryOptions : (NSDictionary *)queryOptions withParams : (NSArray *)params success : (void (^)(id responseObject)) success fail : (void (^) (NSError *error)) fail;

// new calls

// Get Entity with path 
- (void)getEntityWithPath:(NSString *)path withQueryOptions:(NSDictionary *)queryOptions success:(void (^)(id responseObject))success failure:(void (^) (NSError *error))failure;

<<<<<<< HEAD
- (void)updateEntityWithPath:(NSString*)path withQueryOptions : (NSDictionary *)queryOptions success : (void(^)(void))success failure : (void(^)(void)) failure;
=======
- (void)getImage:(NSString*)path success:(void (^)(id responseObject))success failure:(void (^)(NSError *error))failure;
- (void)postImage:(NSString*)path image:(UIImage*)image success:(void (^)(id))success failure:(void (^)(NSError *))failure;
>>>>>>> Get and post image methods

@property (nonatomic) int pageSize;
@property (nonatomic) int sessionTime;

@property (nonatomic, strong) Token *token;


@property (nonatomic, strong) NSString *appId;
@property (nonatomic, strong) NSString *secretKey;
@property (nonatomic, strong) NSString *redirectUrlScheme;
@property (nonatomic, strong) NSString *authToken;


@property (nonatomic, weak) id <MojioClientDelegate> delegate;



@end
