//
//  Cocos2dxFox.cpp
//  FoxSDK Cocos2d-x Plugin v2.8
//
//  Created by CyberZ on 13/04/25.
//  Copyright 2013 CyberZ, Inc. All rights reserved.
//

#include <iostream>
#include "cocos2d.h"
#include "Cocos2dxFox.h"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>

//----------------------------------------
// Cocos2dxAdManager.java
// 成果通信
//----------------------------------------

/**
 * 成果通信
 */
void FoxPlugin::sendConversion() {
    
    jobject ctx = getContext();   
    cocos2d::JniMethodInfo minfo;
    
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
                                                    minfo,
                                                    "jp/appAdForce/android/cocos2dx/Cocos2dxAdManager",
                                                    "sendConversion",
                                                    "(Landroid/content/Context;)V"
                                                    );
    if (exists) {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, ctx);
    }
}

/**
 * 成果通信(ブラウザの起動あり)
 */
void FoxPlugin::sendConversion(const char * urlString) {
    

    
    jobject ctx = getContext();
    cocos2d::JniMethodInfo minfo;
    
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
                                                            minfo,
                                                            "jp/appAdForce/android/cocos2dx/Cocos2dxAdManager",
                                                            "sendConversion",
                                                            "(Landroid/content/Context;Ljava/lang/String;)V"
                                                          );
    if (exists) {
        jstring stringArg0 = minfo.env->NewStringUTF(urlString);
                
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, ctx, stringArg0);
        minfo.env->DeleteLocalRef(stringArg0);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}

/**
 * 成果通信(ブラウザの起動あり)
 */
void FoxPlugin::sendConversion(const char * urlString, const char * buid) {
    
    jobject ctx = getContext();
    cocos2d::JniMethodInfo minfo;
    
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
                                                    minfo,
                                                    "jp/appAdForce/android/cocos2dx/Cocos2dxAdManager",
                                                    "sendConversion",
                                                    "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V"
                                                    );

    if (exists) {
        jstring stringArg0 = minfo.env->NewStringUTF(urlString);
        jstring stringArg1 = minfo.env->NewStringUTF(buid);
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, ctx, stringArg0, stringArg1);
        minfo.env->DeleteLocalRef(stringArg0);
        minfo.env->DeleteLocalRef(stringArg1);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}

/**
 * 成果通信(リエンゲージメント)
 */
void FoxPlugin::sendConversionWithUrlScheme(const char * urlString, const char * buid) {
    
    jobject ctx = getContext();
    cocos2d::JniMethodInfo minfo;
    
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
														  minfo,
														  "jp/appAdForce/android/cocos2dx/Cocos2dxAdManager",
														  "sendConversionWithUrlScheme",
														  "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V"
														  );
	
    if (exists) {
        jstring stringArg0 = minfo.env->NewStringUTF(urlString);
        jstring stringArg1 = minfo.env->NewStringUTF(buid);
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, ctx, stringArg0, stringArg1);
        minfo.env->DeleteLocalRef(stringArg0);
        minfo.env->DeleteLocalRef(stringArg1);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}

/**
 * v2.10.4g以前(2.8u以降〜v2.10.4g)のSDKからアップデートする際にコールするメソッド。
 * 全ての処理の先頭で必ずコールすること。
 */
void FoxPlugin::updateFrom2_10_4g() {
    cocos2d::JniMethodInfo minfo;
    
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
                                                          minfo,
                                                          "jp/appAdForce/android/cocos2dx/Cocos2dxAdManager",
                                                          "updateFrom2_10_4g",
                                                          "()V"
                                                          );
    if (exists) {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}

/**
 * Androidでは未対応
 */
void FoxPlugin::setModeString(const char* mode)
{
}

/**
 * Androidでは未対応
 */
void FoxPlugin::setMessage(const char* title,const char* message)
{
}



//----------------------------------------
// Cocos2dxLtvManager.java
// LTVの計測
//----------------------------------------

/**
 * アプリ内遷移成果処理
 */
void FoxPlugin::sendLtv(int cvPoint) {
    
    jobject ctx = getContext();
    cocos2d::JniMethodInfo minfo;
    
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
                                                    minfo,
                                                    "jp/appAdForce/android/cocos2dx/Cocos2dxLtvManager",
                                                    "sendLtvConversion",
                                                    "(Landroid/content/Context;I)V"
                                                    );

    if (exists) {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, ctx, (jint)cvPoint);
    }
}

/**
 * アプリ内遷移成果処理
 */
void FoxPlugin::sendLtv(int cvPoint, const char * buid) {
    jobject ctx = getContext();
    cocos2d::JniMethodInfo minfo;
    
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
                                                    minfo,
                                                    "jp/appAdForce/android/cocos2dx/Cocos2dxLtvManager",
                                                    "sendLtvConversion",
                                                    "(Landroid/content/Context;ILjava/lang/String;)V"
                                                    );

    if (exists) {
        jstring stringArg = minfo.env->NewStringUTF(buid);
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, ctx, (jint)cvPoint, stringArg);
    }
}

/**
 * 任意パラメータ追加処理
 */
void FoxPlugin::addParameter(const char * name, const char * value) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
                                                    minfo,
                                                    "jp/appAdForce/android/cocos2dx/Cocos2dxLtvManager",
                                                    "addParam",
                                                    "(Ljava/lang/String;Ljava/lang/String;)V"
                                                    );

    if (exists) {
        jstring stringArg0 = minfo.env->NewStringUTF(name);
        jstring stringArg1 = minfo.env->NewStringUTF(value);
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1);
    }
}



//----------------------------------------
// Cocos2dxAnalyticsManager.java
// アクセス解析の計測
//----------------------------------------

/**
 * スタートセッション（アプリ起動時）
 */
void FoxPlugin::sendStartSession() {
    
    jobject ctx = getContext();
    cocos2d::JniMethodInfo minfo;
    
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
                                                    minfo,
                                                    "jp/appAdForce/android/cocos2dx/Cocos2dxAnalyticsManager",
                                                    "sendStartSession",
                                                    "(Landroid/content/Context;)V"
                                                    );

    if (exists) {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, ctx);
    }
}

/**
 * エンドセッション（アプリ終了時）
 *
 */
void FoxPlugin::sendEndSession() {
    
    jobject ctx = getContext();
    cocos2d::JniMethodInfo minfo;
    
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
                                                    minfo,
                                                    "jp/appAdForce/android/cocos2dx/Cocos2dxAnalyticsManager",
                                                    "sendEndSession",
                                                    "(Landroid/content/Context;)V"
                                                    );

    if (exists) {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID ,ctx);
    }
}

/**
 * イベントトラッキング (イベント名、イベントアクション、ラベル、値)
 */
void FoxPlugin::sendEvent(const char * eventName, const char * action, const char * label, int value) {
    
    jobject ctx = getContext();
    cocos2d::JniMethodInfo minfo;
    
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
                                                    minfo,
                                                    "jp/appAdForce/android/cocos2dx/Cocos2dxAnalyticsManager",
                                                    "sendEvent",
                                                    "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V"
                                                    );

    if (exists) {
        jstring stringArg0 = minfo.env->NewStringUTF(eventName);
        jstring stringArg1 = minfo.env->NewStringUTF(action);
        jstring stringArg2 = minfo.env->NewStringUTF(label);
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, ctx, stringArg0, stringArg1, stringArg2, value);
    }
}

/**
 * 購入イベントトラッキング（通貨対応） (イベント名、アクション、ラベル、オーダーID、SKU、アイテム名、プライス、個数、通貨)
 */
void FoxPlugin::sendEvent(const char * eventName, const char * action, const char * label, const char * orderId, const char * sku, const char * itemName, double price, int quantity, const char * currency) {
    
    jobject ctx = getContext();
    cocos2d::JniMethodInfo minfo;
    
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
                                                    minfo,
                                                    "jp/appAdForce/android/cocos2dx/Cocos2dxAnalyticsManager",
                                                    "sendEvent",
                                                    "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;DILjava/lang/String;)V"
                                                    );

    if (exists) {
        jstring stringArg0 = minfo.env->NewStringUTF(eventName);
        jstring stringArg1 = minfo.env->NewStringUTF(action);
        jstring stringArg2 = minfo.env->NewStringUTF(label);
        jstring stringArg3 = minfo.env->NewStringUTF(orderId);
        jstring stringArg4 = minfo.env->NewStringUTF(sku);
        jstring stringArg5 = minfo.env->NewStringUTF(itemName);
        jstring stringArg6 = minfo.env->NewStringUTF(currency);
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, ctx, stringArg0, stringArg1, stringArg2, stringArg3, stringArg4, stringArg5, price, quantity, stringArg6);
    }
}

/**
 * 任意の属性によるトラッキング（ユーザーID、属性１、属性２、属性３、属性４、属性５）
 */
void FoxPlugin::sendUserInfo(const char * userId, const char * userAttr1, const char * userAttr2, const char * userAttr3, const char * userAttr4, const char * userAttr5) {
    
    jobject ctx = getContext();
    cocos2d::JniMethodInfo minfo;
    
    bool exists = cocos2d::JniHelper::getStaticMethodInfo(
                                                    minfo,
                                                    "jp/appAdForce/android/cocos2dx/Cocos2dxAnalyticsManager",
                                                    "sendUserInfo",
                                                    "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"
                                                    );

    if (exists) {
        jstring stringArg0 = minfo.env->NewStringUTF(userId);
        jstring stringArg1 = minfo.env->NewStringUTF(userAttr1);
        jstring stringArg2 = minfo.env->NewStringUTF(userAttr2);
        jstring stringArg3 = minfo.env->NewStringUTF(userAttr3);
        jstring stringArg4 = minfo.env->NewStringUTF(userAttr4);
        jstring stringArg5 = minfo.env->NewStringUTF(userAttr5);
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, ctx, stringArg0, stringArg1, stringArg2, stringArg3, stringArg4, stringArg5);
    }
}

jobject FoxPlugin::getContext() {
    cocos2d::JniMethodInfo t;
    cocos2d::JniHelper::getStaticMethodInfo(t, "org/cocos2dx/cpp/AppActivity", "getContext", "()Landroid/content/Context;");
    // cocos2d::JniHelper::getStaticMethodInfo(t, "org/cocos2dx/lib/Cocos2dxActivity", "getContext", "()Landroid/content/Context;");
    jobject ctx = t.env->CallStaticObjectMethod(t.classID, t.methodID);
    return ctx;
}
