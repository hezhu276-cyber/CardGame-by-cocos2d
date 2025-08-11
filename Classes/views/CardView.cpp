#include "CardView.h"
#include <iostream>
#include "managers/CardManager.h"
#include "utils/CardResConfig.h"

// Static creation method with model and position offset
CardView* CardView::create(const CardModel& model, const Vec2& offset) {
    auto view = new (std::nothrow) CardView();
    if (view && view->init(model, offset)) {
        view->autorelease();
        return view;
    }
    CC_SAFE_DELETE(view);
    return nullptr;
}

// Set callback function for click events
void CardView::setClickCallback(const ClickCallback& callback) {
    _clickCallback = callback;

    if (_cardManager) {
        _cardManager->setCardClickedCallback([this, callback](CardModel& model) {
            if (callback) {
                callback(this);
            }
            });
    }
}

// Check if touch position is within card bounds
bool CardView::isTouchInside(const Vec2& touchPos) {
    if (!_background) {
        return false;
    }

    Vec2 localPos = convertToNodeSpace(touchPos);
    return _background->getBoundingBox().containsPoint(localPos);
}

// Initialization with card model and position offset
bool CardView::init(const CardModel& model, const Vec2& offset) {
    if (!Node::init()) {
        return false;
    }

    // Load background first to establish card dimensions
    loadBackground();
    if (!_background) {
        CCLOG("CardView initialization failed: Background sprite missing");
        return false;
    }

    // Create and configure card manager
    _cardManager = new CardManager(model);
    _cardManager->setCard(model, this);

    // Load card components
    loadSmallNumber(model);
    loadBigNumber(model);
    loadSuitIcon(model);

    // Set initial position with offset
    setPosition(model.get_position() + offset);

    // Dummy initialization for padding
    _viewPadding[0] = 0.0f;
    _viewPadding[1] = 0.0f;

    return true;
}

// Load card background sprite
void CardView::loadBackground() {
    _background = Sprite::create(CardResConfig::getBackGround());
    if (_background) {
        _background->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        addChild(_background);
        setContentSize(_background->getContentSize());
    }
}

// Load small number indicator (top-left)
void CardView::loadSmallNumber(const CardModel& model) {
    CardSuit suit = model.get_suit();
    CardFace face = model.get_face();
    std::string resPath = CardResConfig::getSmallNumberRes(suit, face);

    _smallNumber = Sprite::create(resPath);
    if (_smallNumber) {
        _smallNumber->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
        _smallNumber->setPosition(_smallNumberPos);
        addChild(_smallNumber);
    }
    else {
        CCLOG("Missing small number resource: %s", resPath.c_str());
    }
}

// Load large number indicator (center)
void CardView::loadBigNumber(const CardModel& model) {
    CardSuit suit = model.get_suit();
    CardFace face = model.get_face();
    std::string resPath = CardResConfig::getBigNumberRes(suit, face);

    _bigNumber = Sprite::create(resPath);
    if (_bigNumber) {
        _bigNumber->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        _bigNumber->setPosition(_bigNumberPos);
        addChild(_bigNumber);
    }
    else {
        CCLOG("Missing big number resource: %s", resPath.c_str());
    }
}

// Load suit icon (top-right)
void CardView::loadSuitIcon(const CardModel& model) {
    CardSuit suit = model.get_suit();
    std::string resPath = CardResConfig::getSuitRes(suit);

    _suitIcon = Sprite::create(resPath);
    if (_suitIcon) {
        _suitIcon->setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);
        _suitIcon->setPosition(_suitIconPos);
        addChild(_suitIcon);
    }
    else {
        CCLOG("Missing suit icon resource: %s", resPath.c_str());
    }
}

// Destructor for resource cleanup
CardView::~CardView() {
    CC_SAFE_DELETE(_cardManager);
}
