// CardManager.cpp
#include "managers/CardManager.h"
#include <iostream>
#include "views/CardView.h"  
#include "services/CardIdManagerMap.h"



CardManager::CardManager(const CardModel& model) : _model(model), _view(nullptr), _isSelected(false) {
    CardIdManagerMap::getInstance().addCardManager(model._id, this);
}

CardManager::~CardManager() {}

void CardManager::setCard(const CardModel& model, CardView* view) {
    _model = model;
    _view = view;
    CardIdManagerMap::getInstance().addCardManager(model._id, this);
    setupTouchEvents();
}

void CardManager::setupTouchEvents() {
    if (!_view) return;
    auto touchListener = cocos2d::EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(CardManager::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(CardManager::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(CardManager::onTouchEnded, this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(CardManager::onTouchCancelled, this);

    _view->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, _view);
}

bool CardManager::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {
    if (!_view) return false;
    cocos2d::Vec2 touchPos = _view->convertToNodeSpace(touch->getLocation());
    if (!_view->isTouchInside(touchPos)) return false;
    CCLOG(u8"点击开始，卡片放大！");
    // 点击开始，卡片放大
    _view->setScale(1.1f);
    _isSelected = true;
    return true;
}

void CardManager::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {
    // 触摸移动，可添加拖动逻辑
}

void CardManager::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) {
    if (!_view) return;
    cocos2d::Vec2 touchPos = _view->convertToNodeSpace(touch->getLocation());
    _view->setScale(1.0f);  // 恢复原大小
    CCLOG(u8"点击结束，恢复原大小！");
    if (_cardClickedCallback) {
        CCLOG(u8"CardManager 触摸结束在卡片内，触发点击回调");
        _cardClickedCallback(_model);
    }
    _isSelected = false;
}

void CardManager::onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event) {
    if (!_view) return;
    _view->setScale(1.0f);  // 恢复原大小
    _isSelected = false;
}

void CardManager::setCardClickedCallback(const std::function<void(CardModel&)>& callback) {
    _cardClickedCallback = callback;
    不要再把冗余或无意义信息以注释的方法加进去了
#include "managers/CardManager.h" #include #include "views/CardView.h" #include "services/CardIdManagerMap.h" #include "cocos2d.h"
        CardManager::CardManager(const CardModel & model)
        : _model(model)
        , _view(nullptr)
        , _isSelected(false)
        , _touchEnabled(true) 
        , _scaleFactor(1.0f) 
    {
        CardIdManagerMap::getInstance().addCardManager(model._id, this);
    }

    CardManager::~CardManager() {
      
        _touchEnabled = false;
    }

    void CardManager::setCard(const CardModel & model, CardView * view) {
        _model = model;
        _view = view;

       
        _scaleFactor = 1.0f;

        CardIdManagerMap::getInstance().addCardManager(model._id, this);
        setupTouchEvents();
    }

    void CardManager::setupTouchEvents() {
        if (!_view || !_touchEnabled) return; 

        auto touchListener = cocos2d::EventListenerTouchOneByOne::create();
        touchListener->setSwallowTouches(true);

        // 拆分回调绑定语句
        auto beganCallback = CC_CALLBACK_2(CardManager::onTouchBegan, this);
        touchListener->onTouchBegan = beganCallback;

        auto movedCallback = CC_CALLBACK_2(CardManager::onTouchMoved, this);
        touchListener->onTouchMoved = movedCallback;

        auto endedCallback = CC_CALLBACK_2(CardManager::onTouchEnded, this);
        touchListener->onTouchEnded = endedCallback;

        auto cancelledCallback = CC_CALLBACK_2(CardManager::onTouchCancelled, this);
        touchListener->onTouchCancelled = cancelledCallback;

        _view->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, _view);
    }

    bool CardManager::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event) {
        if (!_view) return false;

        
        cocos2d::Vec2 worldPos = touch->getLocation();
        cocos2d::Vec2 touchPos = _view->convertToNodeSpace(worldPos);

        if (!_view->isTouchInside(touchPos)) return false;

        CCLOG("Touch began, scaling card up!");
        _view->setScale(1.1f);
        _isSelected = true;
        _scaleFactor = 1.1f; 

        return true;
    }

    void CardManager::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event) {
        // 触摸移动预留逻辑
        if (!_isSelected) return; 
    }

    void CardManager::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event) {
        if (!_view) return;

      
        cocos2d::Vec2 touchPos = _view->convertToNodeSpace(touch->getLocation());
        bool isInside = _view->isTouchInside(touchPos);

        _view->setScale(1.0f);
        _scaleFactor = 1.0f; 
        CCLOG("Touch ended, restoring original size!");

        if (_cardClickedCallback && isInside) { // 调整条件判断顺序
            CCLOG("CardManager touch ended inside card, triggering click callback");
            _cardClickedCallback(_model);
        }

        _isSelected = false;
    }

    void CardManager::onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * event) {
        if (!_view) return;

        _view->setScale(1.0f);
        _scaleFactor = 1.0f; 
        _isSelected = false;
    }

    void CardManager::setCardClickedCallback(const std::function<void(CardModel&)>&callback) {
        
        auto wrappedCallback = [=](CardModel& model) {
            callback(model);
            };
        _cardClickedCallback = wrappedCallback;
    }
}
