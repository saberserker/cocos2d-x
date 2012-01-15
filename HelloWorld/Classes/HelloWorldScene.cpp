#include "HelloWorldScene.h"
#include <android/log.h>

USING_NS_CC;

CCScene* HelloWorld::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::node();
	
	// 'layer' is an autorelease object
	HelloWorld *layer = HelloWorld::node();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
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
	CCMenuItemImage *pCloseItem = CCMenuItemImage::itemFromNormalImage(
										"CloseNormal.png",
										"CloseSelected.png",
										this,
										menu_selector(HelloWorld::menuCloseCallback) );
	pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::menuWithItems(pCloseItem, NULL);
	pMenu->setPosition( CCPointZero );
	this->addChild(pMenu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::labelWithString("Hello World!", "Arial", 24);
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// position the label on the center of the screen
    //CCLabelTTF* pLabel = CCLabelTTF::labelWithString("Hello World", "Arial", 24);
	pLabel->setPosition( ccp(size.width / 2, size.height - 50) );

	// add the label as a child to this layer
	this->addChild(pLabel, 1);

	// add "HelloWorld" splash screen"
	CCSprite* pSprite = CCSprite::spriteWithFile("HelloWorld.png");

	// position the sprite on the center of the screen
	pSprite->setPosition( ccp(size.width/2, size.height/2) );

	// add the sprite as a child to this layer
	this->addChild(pSprite, 0);

    this->setIsTouchEnabled(true);

	return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

//Below is crap that *I* added

void HelloWorld::ccTouchesMoved(CCSet* touches, CCEvent *pEvent){
    renderPointsUpdate(touches); 
        CCLabelTTF* pLabel = CCLabelTTF::labelWithString("X", "Arial", 24);
        pLabel->setPosition( ccp(100,100));
        this->addChild(pLabel);
}

void HelloWorld::renderPointsUpdate(CCSet* touches) {
    CCLabelTTF* pLabel;
    renderPoints.clear(); 
    //__android_log_print(ANDROID_LOG_VERBOSE, "dickbar", "update!");
    for(CCSetIterator i = touches->begin(); i!= touches->end(); i++) {
        CCTouch* pTouch = (CCTouch*)*i;
        CCPoint whateverPoint = pTouch->locationInView(pTouch->view());
        renderPoints.push_back(whateverPoint);
        
        pLabel = CCLabelTTF::labelWithString("X", "Arial", 24);
        pLabel->setPosition( whateverPoint );
        this->addChild( pLabel);
        //__android_log_print(ANDROID_LOG_VERBOSE, "dickbar", "x:%f,y:%f",
        //       whateverPoint.x,whateverPoint.y );
    }
}

