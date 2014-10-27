//
//  TestCode.h
//  FoxAndroidSdkApp
//
//  Created by hiraga_tsuyoshi_gn on 13/05/07.
//
//

#ifndef TestCode_h
#define TestCode_h
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include <jni.h>
#endif

class TestPlugin
{
    
public:
    static void accessWeb(const char * url);
    
    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        static jobject getContext();
    #endif
};

#endif
