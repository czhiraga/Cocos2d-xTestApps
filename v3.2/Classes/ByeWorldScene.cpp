#include "ByeWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Cocos2dxFox.h"
#include "cocos2d.h"
#include "TestCode.h"

using namespace cocos2d;
using namespace CocosDenshion;

cocos2d::Scene* ByeWorld::scene()
{
    // 'scene' is an autorelease object
    cocos2d::Scene *scene = cocos2d::Scene::create();
    
    // 'layer' is an autorelease object
    ByeWorld *layer = ByeWorld::create();
    CCLOG("--------run scene!");
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene; 
}

// on "init" you need to initialize your instance
bool ByeWorld::init()
{
    CCLOG("--------run init!");
    
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    cocos2d::MenuItemImage *pCloseItem = cocos2d::MenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(ByeWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(cocos2d::Director::sharedDirector()->getWinSize().width - 20, 20) );

//    // create menu, it's an autorelease object
//    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
//    pMenu->setPosition( CCPointZero );
//    this->addChild(pMenu, 1);
//    
//    //TapAd
//    CCMenuItemLabel *btnTapAd =
//    CCMenuItemLabel::create(
//                            CCLabelTTF::create(
//                                               "Click Advertise!",
//                                               "Thonburi",
//                                               40
//                                               ),
//                            this,
//                            menu_selector(ByeWorld::clickAd)
//                            );
//    
//    //sendConversion
//    CCMenuItemLabel *btnsendConversion =
//                        CCMenuItemLabel::create(
//                                                CCLabelTTF::create(
//                                                                   "sendConversion(buid)",
//                                                                   "Thonburi",
//                                                                   40
//                                                ),
//                                                this,
//                                                menu_selector(ByeWorld::sendConversion)
//                                            );
    //sendLTV
    cocos2d::MenuItemLabel *btnSendLtv =
    cocos2d::MenuItemLabel::create(
                            cocos2d::LabelTTF::create(
                                               "sendLtv",
                                               "Thonburi",
                                               40
                                               ),
                            this,
                            menu_selector(ByeWorld::sendLtv)
                            );
    
    cocos2d::Menu* btnMenu0 = cocos2d::Menu::create(btnSendLtv, NULL);
    // 縦に配置(隙間を10ずつ空ける)
    btnMenu0->alignItemsVerticallyWithPadding(100);
    btnMenu0->setPosition(ccp(190, 200));
    this->addChild(btnMenu0, 1);

    
    
//------------------------------------------------------------------------
    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    cocos2d::LabelTTF* pLabel = cocos2d::LabelTTF::create("-- F.O.X SDK for Cocos2d-x TEST_APP --", "Thonburi", 34);

    // ask director the window size
    cocos2d::Size size = cocos2d::Director::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    cocos2d::Sprite* pSprite = cocos2d::Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    return true;
}

void ByeWorld::menuCloseCallback(cocos2d::Object* pSender)
{
    cocos2d::Director::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


//// 広告クリック処理
//void ByeWorld::clickAd(CCObject* pSender)
//{
//    CCLOG("--------Click Ad - Boot browser");
//    CCString* url = CCString::create("http://app-adforce.jp/ad/p/r?_site=845&_article=3664&_link=1049180&_image=1049175");
//    TestPlugin::accessWeb(url->getCString());
//   
//}
//
//// アプリの初回起動と同じ機能(サーバーにコンバージョンを送る)
//void ByeWorld::sendConversion(CCObject* pSender)
//{
//    CCLOG("--------Send Conversion - Boot browser");
//    CCString* url = CCString::create("http://www.google.co.jp");
//    CCString* buid = CCString::create("testoyosey");
//    FoxPlugin::sendConversion(url->getCString(), buid->getCString());
//    
//}
//
//// イベント送信
//void ByeWorld::sendEvent(CCObject* pSender)
//{
//    CCString* eventName = CCString::create("SHOPING");
//    CCString* action = CCString::create("USE_MONEY");
//    CCString* label = CCString::create("SWORD");
//    
//    FoxPlugin::sendEvent(eventName->getCString(), action->getCString(), label->getCString(), 5);
//}
//
//// ユーザー課金情報送信
//void ByeWorld::sendEventPurchase(CCObject* pSender)
//{
//    CCString* eventName = CCString::create("SendTestPurchaseData");
//    CCString* label = CCString::create("BUY_SWORD");
//    CCString* orderId = CCString::create("test123");
//    CCString* sku = CCString::create("abcdefghijklmnopqrstuvwxyz");
//    CCString* itemName = CCString::create("SWORD");
//    CCString* currency = CCString::create("JPY");
////    CCString* _null = CCString::create("test");
//    
//    FoxPlugin::sendEvent(eventName->getCString(), NULL, label->getCString(), orderId->getCString(), sku->getCString(), itemName->getCString(), 1500, 3, currency->getCString());
//    
//}
//
//// ユーザー情報送信
//void ByeWorld::sendUserInfo(CCObject* pSender)
//{
//
//    CCString* userId = CCString::create("cocos_android_user");
//    CCString* userAttr1 = CCString::create("beef");
//    CCString* userAttr2 = CCString::create("chiken");
//    CCString* userAttr3 = CCString::create("poke");
//    CCString* userAttr4 = CCString::create("rice");
//    CCString* userAttr5 = CCString::create("fish");
//    
//    FoxPlugin::sendUserInfo(userId->getCString(), userAttr1->getCString(), userAttr2->getCString(), userAttr3->getCString(), userAttr4->getCString(), userAttr5->getCString());
//}

//--------------------------------------

// パラメータ追加
void ByeWorld::addParam(CCObject* pSender)
{
    CCString* attr0 = CCString::create(LTV_PARAM_SKU);
    CCString* attr1 = CCString::create("AIUEO-COCOS1");
    FoxPlugin::addParameter(attr0->getCString(), attr1->getCString());
    
}

// パラメータ追加2
void ByeWorld::addParam2(CCObject* pSender)
{
    
    CCString* attr0 = CCString::create(LTV_PARAM_PRICE);
    CCString* attr1 = CCString::create("100");
    FoxPlugin::addParameter(attr0->getCString(), attr1->getCString());
    
    attr0 = CCString::create(LTV_PARAM_OUT);
    attr1 = CCString::create("Test_Out");
    FoxPlugin::addParameter(attr0->getCString(), attr1->getCString());
}

// LTV送信
void ByeWorld::sendLtv(CCObject* pSender)
{
    // 成果地点ID
    int attr0 = 52;
    CCString* attr1 = CCString::create("GarhiraTest_123");
//    CCString* attr2 = CCString::create("100");
//    CCString* attr3 = CCString::create("test_abc");
    FoxPlugin::sendLtv(attr0, attr1->getCString());
//    FoxPlugin::sendLtv(attr0);
//    FoxPlugin::testSendLtv(attr0, attr1->getCString());
    
    //FoxPlugin::sendLtvTest(attr0, attr1->getCString(), attr2->getCString(), attr3->getCString());
}

//void ByeWorld::startSession(CCObject* pSender)
//{
//    CCLOG("--------Send Start Session!!");
//    FoxPlugin::sendStartSession();
//}
//
//void ByeWorld::endSession(CCObject* pSender)
//{
//    CCLOG("--------Send End Session!!");
//    FoxPlugin::sendEndSession();
//}

