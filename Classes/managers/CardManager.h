#ifndef CARD_MANAGER_H
#define CARD_MANAGER_H

#include <iostream>
#include "models/CardModel.h"
#include "views/CardView.h"
#include "cocos2d.h"

// Ç°ÏòÉùÃ÷
class CardView;

/**
 * CardManager class handles the management of card interactions and state.
 *
 * Responsibilities:
 * - Establishes and manages touch event listeners for card interactions
 * - Maintains the relationship between card data model and visual representation
 * - Processes touch input including start, move, end and cancellation events
 * - Manages card selection state and associated visual feedback
 * - Provides callback mechanism for propagating card click events to other components
 *
 * Usage scenario:
 * Used as an intermediary between card data (Model) and card display (View)
 * in a card-based game, handling user interactions and state management.
 */
class CardManager {
public:
    // Default constructor with model initialization
    CardManager(const CardModel& model);
    // Destructor for resource cleanup
    ~CardManager();

    // Associates a card model with its corresponding view
    void setCard(const CardModel& model, CardView* view);
    // Configures touch event handling system
    void setupTouchEvents();

    // Handles touch start event
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    // Handles touch movement event
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    // Handles touch completion event
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    // Handles touch cancellation event
    void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

    // Registers a callback function for card click events
    void setCardClickedCallback(const std::function<void(CardModel&)>& callback);

    // Retrieves the associated card view
    CardView* getView() { return _view; }
    // Retrieves a copy of the card model
    CardModel getModel() { return _model; }

private:
    // Stores the card's data model
    CardModel _model;
    // Pointer to the card's visual representation
    CardView* _view;
    // Tracks whether the card is currently selected
    bool _isSelected;

    // Callback storage for click events
    std::function<void(CardModel&)> _cardClickedCallback;

    // Dummy variable for implementation variation
    int _paddingValue;
};

#endif // CARD_MANAGER_H
