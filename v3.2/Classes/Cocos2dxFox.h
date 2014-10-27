//
//  Cocos2dxFox.h
//  FoxSDK Cocos2d-x Plugin v2.8
//
//  Created by Shingo Hagiwara on 13/05/07.
//  Copyright 2013 CyberZ, Inc. All rights reserved.
//

#ifndef Cocos2dxFox_h
#define Cocos2dxFox_h
#define LTV_PARAM_SKU "_sku"
#define LTV_PARAM_PRICE "_price"
#define LTV_PARAM_OUT "_out"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    #include <jni.h>
#endif

class FoxPlugin
{
public:
    // Conversion -----------------
    static void sendConversion();
    static void sendConversion(const char * url);
    static void sendConversion(const char * url, const char * buid);
    static void sendConversionWithUrlScheme(const char * url, const char * buid);
    static void setModeString(const char* mode);
    static void setMessage(const char* title,const char* message);
    
    // LTV ------------------------
    static void sendLtv(int cvPoint);
    static void sendLtv(int cvPoint, const char * buid);
    static void addParameter(const char* name, const char* value);
    
    static void testSendLtv(int cvPoint, const char * buid);
    
    // Analytics ------------------
    static void sendStartSession();
    static void sendEndSession();
    static void sendEvent(const char * eventName, const char * action, const char * label, int value);
    static void sendUserInfo(const char * userId, const char * userAttr1, const char * userAttr2, const char * userAttr3, const char * userAttr4, const char * userAttr5);
    static void sendEvent(const char* eventName, const char* action, const char* label, const char* orderID, const char* sku, const char* itemName, double price, int quantity, const char* currency);
    
    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        static jobject getContext();
        static void updateFrom2_10_4g();
    #endif
};

#endif