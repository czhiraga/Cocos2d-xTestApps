#ifndef __BYEWORLD_SCENE_H__
#define __BYEWORLD_SCENE_H__

#include "cocos2d.h"


class ByeWorld : public cocos2d::CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::Scene* scene();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Object* pSender);
    void clickAd(cocos2d::Object* pSender);
    void sendConversion(cocos2d::Object* pSender);
    // アクセス解析
//    void sendEvent(CCObject* pSender);
//    void sendEventPurchase(CCObject* pSender);
//    void sendUserInfo(CCObject* pSender);
//    void startSession(CCObject* pSender);
//    void endSession(CCObject* pSender);
    // LTV計測
    void addParam(cocos2d::Object* pSender);
    void addParam2(cocos2d::Object* pSender);
    void sendLtv(cocos2d::Object* pSender);

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(ByeWorld);
};

#endif // __HELLOWORLD_SCENE_H__
