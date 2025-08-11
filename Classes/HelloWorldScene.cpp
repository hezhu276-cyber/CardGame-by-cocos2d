// HelloWorldScene.cpp
#include "HelloWorldScene.h"
#include "services/GameModelGenerator.h"

USING_NS_CC;

Scene* HelloWorld::create_scene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{
    if (!Scene::init()) return false;

    const auto visible_size = Director::getInstance()->getVisibleSize();
    const Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // 创建关闭按钮
    auto close_item = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        [](Ref* sender) {
            Director::getInstance()->end();
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
            exit(0);
#endif
        }
    );

    if (close_item && close_item->getContentSize().width > 0) {
        const float x = origin.x + visible_size.width - close_item->getContentSize().width / 2;
        const float y = origin.y + close_item->getContentSize().height / 2;
        close_item->setPosition(Vec2(x, y));
    }

    auto menu = Menu::create(close_item, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    // 创建游戏区域背景
    constexpr float TOP_HEIGHT_RATIO = 2.0f / 3.0f;
    const Color4B TOP_COLOR(165, 42, 42, 255);
    const Color4B BOTTOM_COLOR(128, 0, 128, 255);

    auto top_layer = LayerColor::create(TOP_COLOR, visible_size.width, visible_size.height * TOP_HEIGHT_RATIO);
    top_layer->setPosition(0, visible_size.height * (1 - TOP_HEIGHT_RATIO));
    addChild(top_layer, 0);

    auto bottom_layer = LayerColor::create(BOTTOM_COLOR, visible_size.width, visible_size.height * (1 - TOP_HEIGHT_RATIO));
    addChild(bottom_layer, 0);

    // 初始化游戏模型和视图
    auto game_model = GameModelGenerator::generate("level_1.json");
    GameModelGenerator::create_view(game_model, this);

    return true;
}