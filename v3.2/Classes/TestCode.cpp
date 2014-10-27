//
//  TestCode.cpp
//  FoxAndroidSdkApp
//
//  Created by hiraga_tsuyoshi_gn on 13/05/07.
//
//

#include "TestCode.h"
#include "cocos2d.h"
//#include "../android/jni/JniHelper.h"
#include "platform/android/jni/JniHelper.h"

// 任意のURLでブラウザ起動
void TestPlugin::accessWeb(const char * url)
{
    jobject ctx = getContext();
    cocos2d::JniMethodInfo minfo;
    
    bool exist = cocos2d::JniHelper::getStaticMethodInfo(
                                                    minfo,
                                                    "to/grenge/from/cyberz/activity/GrengeActivity",
                                                    "launchUrl",
                                                    "(Landroid/content/Context;Ljava/lang/String;)V"
                                                    );
    if (exist) {
        jstring stringArg0 = minfo.env->NewStringUTF(url);
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, ctx, stringArg0);
        minfo.env->DeleteLocalRef(stringArg0);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}

jobject TestPlugin::getContext() {
    cocos2d::JniMethodInfo t;
    // cocos2d::JniHelper::getStaticMethodInfo(t, "org/cocos2dx/lib/Cocos2dxActivity", "getContext", "()Landroid/content/Context;");
    cocos2d::JniHelper::getStaticMethodInfo(t, "to/grenge/from/cyberz/activity/GrengeActivity", "getContext", "()Landroid/content/Context;");
    jobject ctx = t.env->CallStaticObjectMethod(t.classID, t.methodID);
    return ctx;
}