#include "EntranceScene.h"
#include "AppMacros.h"

USING_NS_CC;


CCScene* EntranceLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    EntranceLayer *layer = EntranceLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool EntranceLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    // add "EntranceLayer" splash screen"
    m_preface = CCSprite::create("preface.jpg");

    // position the sprite on the center of the screen
    m_preface->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	m_preface->schedule( schedule_selector(EntranceLayer::ditherSprite), 0.1f );
	//pSprite->runAction( CCRepeatForever::create( CCCallFuncN::create(this, callfuncN_selector(EntranceLayer::ditherSprite)) ) );

    // add the sprite as a child to this layer
    this->addChild(m_preface, 0);	
    return true;
}

void EntranceLayer::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void EntranceLayer::ditherSprite( float dt )
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCSize offset( CCRANDOM_MINUS1_1() * visibleSize.width * 0.05f, CCRANDOM_MINUS1_1() * visibleSize.height * 0.05f );
	m_preface->setPositionX( offset.width + m_preface->getPositionX() );
	m_preface->setPositionY( offset.height + m_preface->getPositionY() );
}
