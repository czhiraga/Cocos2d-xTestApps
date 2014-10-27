#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"


class HelloWorld : public cocos2d::CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::Scene* createScene();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Object* pSender);
    void clickAd(cocos2d::Object* pSender);
    void v2_10_5g(cocos2d::Object* pSender);
    void sendConversion(cocos2d::Object* pSender);
    // アクセス解析
    void sendEvent(cocos2d::Object* pSender);
    void sendEventPurchase(cocos2d::Object* pSender);
    void sendUserInfo(cocos2d::Object* pSender);
    // LTV計測
    void startSession(cocos2d::Object* pSender);
    void addParam(cocos2d::Object* pSender);
    void addParam2(cocos2d::Object* pSender);
    void sendLtv(cocos2d::Object* pSender);
    void endSession(cocos2d::Object* pSender);
    // 画面遷移ボタン
    void transBtn(cocos2d::Object* pSender);

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
