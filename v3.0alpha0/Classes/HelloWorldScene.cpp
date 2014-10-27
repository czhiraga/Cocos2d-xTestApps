#include "HelloWorldScene.h"
#include "ByeWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Cocos2dxFox.h"
#include "cocos2d.h"
#include "TestCode.h"

using namespace cocos2d;
using namespace CocosDenshion;

cocos2d::Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    cocos2d::Scene *scene = cocos2d::Scene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();
    CCLOG("--------run scene!");
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene; 
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
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
                                        menu_selector(HelloWorld::menuCloseCallback));
    pCloseItem->setPosition( ccp(cocos2d::Director::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    cocos2d::Menu* pMenu = cocos2d::Menu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    //TapAd
    cocos2d::MenuItemLabel *btnTapAd =
    cocos2d::MenuItemLabel::create(
                            cocos2d::LabelTTF::create(
                                               "Click Advertise!",
                                               "Thonburi",
                                               40
                                               ),
                            this,
                            menu_selector(HelloWorld::clickAd)
                            );
    
    // before 2.10.4g
    cocos2d::MenuItemLabel *btnV2_10_5g =
    cocos2d::MenuItemLabel::create(
                            cocos2d::LabelTTF::create(
                                               "事前準備!",
                                               "Thonburi",
                                               40
                                               ),
                            this,
                            menu_selector(HelloWorld::v2_10_5g));
    
    //sendConversion
    cocos2d::MenuItemLabel *btnsendConversion =
                        cocos2d::MenuItemLabel::create(
                                                cocos2d::LabelTTF::create(
                                                                   "sendConversion(buid)",
                                                                   "Thonburi",
                                                                   40
                                                ),
                                                this,
                                                menu_selector(HelloWorld::sendConversion)
                                            );
    
    //addParam
    cocos2d::MenuItemLabel *addParam =
    cocos2d::MenuItemLabel::create(
                            cocos2d::LabelTTF::create(
                                               "addParam1",
                                               "Thonburi",
                                               40
                                               ),
                            this,
                            menu_selector(HelloWorld::addParam)
                            );
    
    //addParam
    cocos2d::MenuItemLabel *addParam2 =
    cocos2d::MenuItemLabel::create(
                            cocos2d::LabelTTF::create(
                                               "addParam2",
                                               "Thonburi",
                                               40
                                               ),
                            this,
                            menu_selector(HelloWorld::addParam2)
                            );
    
    //sendLTV
    cocos2d::MenuItemLabel *btnSendLtv =
    cocos2d::MenuItemLabel::create(
                            cocos2d::LabelTTF::create(
                                               "sendLtv",
                                               "Thonburi",
                                               40
                                               ),
                            this,
                            menu_selector(HelloWorld::sendLtv)
                            );
    
    // cocos2d::Menu* btnMenu0 = cocos2d::Menu::create(btnTapAd, btnV2_10_5g, btnsendConversion, addParam, addParam2, btnSendLtv, NULL);
    cocos2d::Menu* btnMenu0 = cocos2d::Menu::create(btnTapAd, btnsendConversion, addParam, addParam2, btnSendLtv, NULL);
    // 縦に配置(隙間を10ずつ空ける)
    btnMenu0->alignItemsVerticallyWithPadding(150);
    btnMenu0->setPosition(ccp(190, 600));
    this->addChild(btnMenu0, 1);
    
//------------------------------------------------------------------------
    
    //sendStartSession
    cocos2d::MenuItemLabel *btnStartSession =
    cocos2d::MenuItemLabel::create(
                            cocos2d::LabelTTF::create(
                                               "StartSession",
                                               "Thonburi",
                                               40
                                               ),
                            this,
                            menu_selector(HelloWorld::startSession)
                            );

    
    //sendEvent
    cocos2d::MenuItemLabel *btnSendEvent =
    cocos2d::MenuItemLabel::create(
                            cocos2d::LabelTTF::create(
                                               "sendEvent",
                                               "Thonburi",
                                               40
                                               ),
                            this,
                            menu_selector(HelloWorld::sendEvent)
                            );
    
    //sendEvent(課金)
    cocos2d::MenuItemLabel *btnSendEventPurchase =
    cocos2d::MenuItemLabel::create(
                            cocos2d::LabelTTF::create(
                                               "sendEventPurchase",
                                               "Thonburi",
                                               40
                                               ),
                            this,
                            menu_selector(HelloWorld::sendEventPurchase)
                            );
    
    
    //sendUserInfo
    cocos2d::MenuItemLabel *btnSendUserInfo =
    cocos2d::MenuItemLabel::create(
                            cocos2d::LabelTTF::create(
                                               "sendUserInfo",
                                               "Thonburi",
                                               40
                                               ),
                            this,
                            menu_selector(HelloWorld::sendUserInfo)
                            );
    
    //sendStartSession
    cocos2d::MenuItemLabel *btnEndSession =
    cocos2d::MenuItemLabel::create(
                            cocos2d::LabelTTF::create(
                                               "EndSession",
                                               "Thonburi",
                                               40
                                               ),
                            this,
                            menu_selector(HelloWorld::endSession)
                            );
    
    //sendStartSession
    cocos2d::MenuItemLabel *btnTransition =
    cocos2d::MenuItemLabel::create(
                            cocos2d::LabelTTF::create(
                                               "transition",
                                               "Thonburi",
                                               40
                                               ),
                            this,
                            menu_selector(HelloWorld::transBtn)
                            );

    
    cocos2d::Menu* btnMenu1 = cocos2d::Menu::create(btnStartSession, btnSendEvent, btnSendEventPurchase, btnSendUserInfo, btnEndSession, btnTransition, NULL);
    btnMenu1->alignItemsVerticallyWithPadding(150);
    btnMenu1->setPosition(ccp(530, 600));
    this->addChild(btnMenu1, 1);
    

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    cocos2d::LabelTTF* pLabel = cocos2d::LabelTTF::create("-- F.O.X SDK for Cocos2d-x TEST_APP --", "Thonburi", 34);

    // ask director the window size
    CCSize size = cocos2d::Director::sharedDirector()->getWinSize();

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

void HelloWorld::menuCloseCallback(cocos2d::Object* pSender)
{
    cocos2d::Director::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


// 広告クリック処理
void HelloWorld::clickAd(cocos2d::Object* pSender)
{
    CCLOG("--------Click Ad - Boot browser");
//    cocos2d::String* url = cocos2d::String::create("http://app-adforce.jp/ad/p/r?_site=845&_article=3664&_link=1049180&_image=1049175");
    cocos2d::String* url = cocos2d::String::create("http://app-adforce.jp/ad/p/r?_site=6&_article=84866&_link=1995694&_image=1993317");
    TestPlugin::accessWeb(url->getCString());
   
}
                            
void HelloWorld::v2_10_5g(cocos2d::Object* pSender)
{
    CCLOG("--------Click Before - v2.10.5g");
    FoxPlugin::updateFrom2_10_4g();
    
}

// アプリの初回起動と同じ機能(サーバーにコンバージョンを送る)
void HelloWorld::sendConversion(cocos2d::Object* pSender)
{
    CCLOG("--------Send Conversion - Boot browser");
    cocos2d::String* url = cocos2d::String::create("http://www.google.co.jp");
    cocos2d::String* buid = cocos2d::String::create("testoyosey");
    FoxPlugin::sendConversion(url->getCString(), buid->getCString());
    
}

// イベント送信
void HelloWorld::sendEvent(cocos2d::Object* pSender)
{
    cocos2d::String* eventName = cocos2d::String::create("SHOPING");
    cocos2d::String* action = cocos2d::String::create("USE_MONEY");
    cocos2d::String* label = cocos2d::String::create("SWORD");
    
    FoxPlugin::sendEvent(eventName->getCString(), action->getCString(), label->getCString(), 5);
}

// ユーザー課金情報送信
void HelloWorld::sendEventPurchase(cocos2d::Object* pSender)
{
    cocos2d::String* eventName = cocos2d::String::create("SendTestPurchaseData");
    cocos2d::String* label = cocos2d::String::create("BUY_SWORD");
    cocos2d::String* orderId = cocos2d::String::create("test123");
    cocos2d::String* sku = cocos2d::String::create("abcdefghijklmnopqrstuvwxyz");
    cocos2d::String* itemName = cocos2d::String::create("SWORD");
    cocos2d::String* currency = cocos2d::String::create("JPY");
//    cocos2d::String* _null = cocos2d::String::create("test");
    
    FoxPlugin::sendEvent(eventName->getCString(), NULL, label->getCString(), orderId->getCString(), sku->getCString(), itemName->getCString(), 1500, 3, currency->getCString());
    
}

// ユーザー情報送信
void HelloWorld::sendUserInfo(cocos2d::Object* pSender)
{

    cocos2d::String* userId = cocos2d::String::create("cocos_android_user");
    cocos2d::String* userAttr1 = cocos2d::String::create("beef");
    cocos2d::String* userAttr2 = cocos2d::String::create("chiken");
    cocos2d::String* userAttr3 = cocos2d::String::create("poke");
    cocos2d::String* userAttr4 = cocos2d::String::create("rice");
    cocos2d::String* userAttr5 = cocos2d::String::create("fish");
    
    FoxPlugin::sendUserInfo(userId->getCString(), userAttr1->getCString(), userAttr2->getCString(), userAttr3->getCString(), userAttr4->getCString(), userAttr5->getCString());
}

//--------------------------------------

// パラメータ追加
void HelloWorld::addParam(cocos2d::Object* pSender)
{
    cocos2d::String* attr0 = cocos2d::String::create(LTV_PARAM_SKU);
    cocos2d::String* attr1 = cocos2d::String::create("AIUEO-COCOS1");
    FoxPlugin::addParameter(attr0->getCString(), attr1->getCString());
    
}

// パラメータ追加2
void HelloWorld::addParam2(cocos2d::Object* pSender)
{
    
    cocos2d::String* attr0 = cocos2d::String::create(LTV_PARAM_PRICE);
    cocos2d::String* attr1 = cocos2d::String::create("20000");
    FoxPlugin::addParameter(attr0->getCString(), attr1->getCString());
    
    attr0 = cocos2d::String::create(LTV_PARAM_OUT);
    attr1 = cocos2d::String::create("Test_Out");
    FoxPlugin::addParameter(attr0->getCString(), attr1->getCString());
}

// LTV送信
void HelloWorld::sendLtv(cocos2d::Object* pSender)
{
    // 成果地点ID
//    int attr0 = 207;
    // int attr0 = 1771;
    int attr0 = 191;
    cocos2d::String* attr1 = cocos2d::String::create("test_123");
//    cocos2d::String* attr2 = cocos2d::String::create("100");
//    cocos2d::String* attr3 = cocos2d::String::create("test_abc");
//    FoxPlugin::sendLtv(attr0, attr1->getCString());
    FoxPlugin::sendLtv(attr0);

    
    //FoxPlugin::sendLtvTest(attr0, attr1->getCString(), attr2->getCString(), attr3->getCString());
}

void HelloWorld::startSession(cocos2d::Object* pSender)
{
    CCLOG("--------Send Start Session!!");
    FoxPlugin::sendStartSession();
}

void HelloWorld::endSession(cocos2d::Object* pSender)
{
    CCLOG("--------Send End Session!!");
    FoxPlugin::sendEndSession();
}

void HelloWorld::transBtn(cocos2d::Object* pSender)
{
    CCLOG("--------tansition!!");
    // cocos2d::Scene* byeWorldScene = ByeWorld::scene();
    // // ゲーム画面の登場シーンの種類を　0.5秒間 右からスライドに設定
    // cocos2d::TransitionScene *transitionScen = cocos2d::TransitionSlideInR::create( 0.5, byeWorldScene );
    // // 画面シーンの切り替えを実行（メニュー画面からゲーム画面に遷移開始！）
    // cocos2d::Director::sharedDirector()->replaceScene( transitionScen );

}

