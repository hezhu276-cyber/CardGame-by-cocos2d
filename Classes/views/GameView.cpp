#include "GameView.h"
#include <iostream>
#include "controllers/GameController.h"
#include "views/CardView.h"
#include "models/CardModel.h"

// Static creation method with game model
GameView* GameView::create(GameModel& model) {
    GameView* pRet = new (std::nothrow) GameView();
    if (pRet && pRet->init(model)) {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

// Initialization with game model data
bool GameView::init(GameModel& model) {
    if (!Node::init()) {
        return false;
    }

    // Create controller and associate with model
    _gameController = new GameController(model);

    // Generate card views from model data
    generateCardViews(model);

    // Create and configure status label
    setupStatusLabel();

    // Register touch event handlers
    registerTouchEvents();

    // Initialize dummy variables
    _viewState = 0;
    _layoutPadding = 5.0f;

    return true;
}

// Setup status label properties and position
void GameView::setupStatusLabel() {
    _statusLabel = Label::createWithSystemFont("Undo", "Microsoft YaHei", 36);
    if (_statusLabel) {
        _statusLabel->setPosition(900, 400);
        _statusLabel->setTextColor(Color4B::WHITE);
        addChild(_statusLabel, 100);

        // Log label properties for debugging
        CCLOG("Status label size: %.2f, %.2f",
            _statusLabel->getContentSize().width,
            _statusLabel->getContentSize().height);
        CCLOG("Status label position: %.2f, %.2f",
            _statusLabel->getPositionX(),
            _statusLabel->getPositionY());
    }
}

// Generate card views from model data
void GameView::generateCardViews(GameModel& model) {
    // Create views for playfield cards
    const auto& playfield = model.getPlayfield();
    for (const auto& cardModel : playfield) {
        CardView* cardView = CardView::create(cardModel, Vec2(0, 0));
        if (cardView) {
            _playfieldCardViews.push_back(cardView);
            addChild(cardView);
        }
    }

    // Create views for stackfield cards
    const auto& stackfield = model.getStackfield();
    for (const auto& cardModel : stackfield) {
        CardView* cardView = CardView::create(cardModel, Vec2(0, 0));
        if (cardView) {
            _stackfieldCardViews.push_back(cardView);
            addChild(cardView);
        }
    }

    // Setup click handling for all cards
    setupCardClickHandling();
}

// Configure click callbacks for card views
void GameView::setupCardClickHandling() {
    auto handleCardClick = [this](CardView* cardView) {
        if (!cardView) return;

        // Visual feedback for card selection
        cardView->setOpacity(180);

        // Get associated card model through manager
        CardModel cardModel = cardView->_cardManager->getModel();
        CCLOG("Card clicked - processing interaction");

        // Route click to appropriate controller method
        if (cardModel.get_zone() == CardZone::PLAYFIELD) {
            _gameController->selectCardFromPlayefieldAndMatch(cardModel);
        }
        else if (cardModel.get_zone() == CardZone::STACK) {
            _gameController->clickStackCard(cardModel);
        }
        };

    // Assign callback to playfield cards
    for (auto cardView : _playfieldCardViews) {
        cardView->setClickCallback(handleCardClick);
    }

    // Assign callback to stackfield cards
    for (auto cardView : _stackfieldCardViews) {
        cardView->setClickCallback(handleCardClick);
    }
}

// Register touch event listeners
void GameView::registerTouchEvents() {
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);

    // Handle touch start events
    touchListener->onTouchBegan = [this](Touch* touch, Event* event) {
        Vec2 touchPos = convertToNodeSpace(touch->getLocation());
        if (_statusLabel && _statusLabel->getBoundingBox().containsPoint(touchPos)) {
            _statusLabel->setScale(1.2f);  // Highlight effect
            return true;
        }
        return false;
        };

    // Handle touch end events
    touchListener->onTouchEnded = [this](Touch* touch, Event* event) {
        _statusLabel->setScale(1.0f);  // Restore normal scale
        Vec2 touchPos = convertToNodeSpace(touch->getLocation());
        if (_statusLabel && _statusLabel->getBoundingBox().containsPoint(touchPos)) {
            onLabelClicked();  // Trigger label action
        }
        };

    // Handle touch cancellation
    touchListener->onTouchCancelled = [this](Touch* touch, Event* event) {
        _statusLabel->setScale(1.0f);  // Restore normal scale
        };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

// Handle status label click events
void GameView::onLabelClicked() {
    CCLOG("Status label clicked - invoking controller");
    _gameController->handleLabelClick();
}

// Destructor for resource cleanup
GameView::~GameView() {
    CC_SAFE_DELETE(_gameController);
    _playfieldCardViews.clear();
    _stackfieldCardViews.clear();
}
