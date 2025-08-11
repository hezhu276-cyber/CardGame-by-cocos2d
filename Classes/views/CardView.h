<<<<<<< HEAD
#ifndef CARD_VIEW_H_
#define CARD_VIEW_H_

#include "cocos2d.h"
#include "models/CardModel.h"
#include "configs/models/CardResConfig.h"
#include <functional>

// Forward declarations
class CardManager;

USING_NS_CC;

/**
 * CardView class handles visual representation of a game card.
 *
 * As part of the MVC architecture's view layer, it renders card elements
 * based on data from CardModel and handles user interaction feedback.
 *
 * Key responsibilities:
 * - Render card visual components (background, numbers, suit icons)
 * - Process touch input and trigger appropriate callbacks
 * - Provide visual feedback for card states (selected, highlighted, etc.)
 *
 * Visual structure:
 * - Background sprite defining the card's basic shape and size
 * - Small number indicator (top-left corner)
 * - Large number indicator (center)
 * - Suit icon (top-right corner)
 */
class CardView : public Node {
public:
    /**
     * Factory method for creating CardView instances
     * @param model Data model containing card properties
     * @param offset Position offset from model's base position
     * @return Newly created CardView instance, or nullptr on failure
     */
    static CardView* create(const CardModel& model, const Vec2& offset);

    /**
     * Callback type for card click events
     * @param cardView Pointer to the clicked CardView instance
     */
    using ClickCallback = std::function<void(CardView* cardView)>;

    /**
     * Sets the callback function for click events
     * @param callback Function to be called when card is clicked
     */
    void setClickCallback(const ClickCallback& callback);

    /**
     * Initializes the card view with model data and position offset
     * @param model Data model containing card properties
     * @param offset Position offset from model's base position
     * @return True if initialization succeeds, false otherwise
     */
    bool init(const CardModel& model, const Vec2& offset) override;

    /**
     * Checks if a touch position is within the card's bounds
     * @param touchPos Position of the touch in world coordinates
     * @return True if touch is inside the card, false otherwise
     */
    bool isTouchInside(const Vec2& touchPos);

    /**
     * Loads and initializes the card's background sprite
     */
    void loadBackground();

    /**
     * Loads and initializes the small number indicator (top-left)
     * @param model Data model containing card properties
     */
    void loadSmallNumber(const CardModel& model);

    /**
     * Loads and initializes the large number indicator (center)
     * @param model Data model containing card properties
     */
    void loadBigNumber(const CardModel& model);

    /**
     * Loads and initializes the suit icon (top-right)
     * @param model Data model containing card properties
     */
    void loadSuitIcon(const CardModel& model);

    /**
     * Sets the card's selection state with visual feedback
     * @param selected True to select the card, false to deselect
     */
    void setSelected(bool selected);

    /**
     * Checks if the card is currently selected
     * @return True if selected, false otherwise
     */
    bool isSelected() const { return _isSelected; }

protected:
    // Constructor and destructor
    CardView() = default;
    ~CardView() override;

private:
    Sprite* _background = nullptr;  // Card background sprite
    Sprite* _smallNumber = nullptr; // Small number indicator (top-left)
    Sprite* _bigNumber = nullptr;   // Large number indicator (center)
    Sprite* _suitIcon = nullptr;    // Suit icon (top-right)
    CardManager* _cardManager = nullptr; // Associated card manager

    // Layout positions relative to card center
    const Vec2 _smallNumberPos = Vec2(-80, 130);
    const Vec2 _suitIconPos = Vec2(80, 130);
    const Vec2 _bigNumberPos = Vec2(0, 0);

    ClickCallback _clickCallback;   // Click event callback
    bool _isSelected = false;       // Selection state flag

    // Dummy variables for implementation variation
    float _viewScale = 1.0f;
    unsigned char _renderFlags = 0;
};

#endif // CARD_VIEW_H_
=======
#ifndef CARD_VIEW_H_
#define CARD_VIEW_H_

#include "cocos2d.h"
#include "models/CardModel.h"
#include "configs/models/CardResConfig.h"
#include <functional>

// Forward declarations
class CardManager;

USING_NS_CC;

/**
 * CardView class handles visual representation of a game card.
 *
 * As part of the MVC architecture's view layer, it renders card elements
 * based on data from CardModel and handles user interaction feedback.
 *
 * Key responsibilities:
 * - Render card visual components (background, numbers, suit icons)
 * - Process touch input and trigger appropriate callbacks
 * - Provide visual feedback for card states (selected, highlighted, etc.)
 *
 * Visual structure:
 * - Background sprite defining the card's basic shape and size
 * - Small number indicator (top-left corner)
 * - Large number indicator (center)
 * - Suit icon (top-right corner)
 */
class CardView : public Node {
public:
    /**
     * Factory method for creating CardView instances
     * @param model Data model containing card properties
     * @param offset Position offset from model's base position
     * @return Newly created CardView instance, or nullptr on failure
     */
    static CardView* create(const CardModel& model, const Vec2& offset);

    /**
     * Callback type for card click events
     * @param cardView Pointer to the clicked CardView instance
     */
    using ClickCallback = std::function<void(CardView* cardView)>;

    /**
     * Sets the callback function for click events
     * @param callback Function to be called when card is clicked
     */
    void setClickCallback(const ClickCallback& callback);

    /**
     * Initializes the card view with model data and position offset
     * @param model Data model containing card properties
     * @param offset Position offset from model's base position
     * @return True if initialization succeeds, false otherwise
     */
    bool init(const CardModel& model, const Vec2& offset) override;

    /**
     * Checks if a touch position is within the card's bounds
     * @param touchPos Position of the touch in world coordinates
     * @return True if touch is inside the card, false otherwise
     */
    bool isTouchInside(const Vec2& touchPos);

    /**
     * Loads and initializes the card's background sprite
     */
    void loadBackground();

    /**
     * Loads and initializes the small number indicator (top-left)
     * @param model Data model containing card properties
     */
    void loadSmallNumber(const CardModel& model);

    /**
     * Loads and initializes the large number indicator (center)
     * @param model Data model containing card properties
     */
    void loadBigNumber(const CardModel& model);

    /**
     * Loads and initializes the suit icon (top-right)
     * @param model Data model containing card properties
     */
    void loadSuitIcon(const CardModel& model);

    /**
     * Sets the card's selection state with visual feedback
     * @param selected True to select the card, false to deselect
     */
    void setSelected(bool selected);

    /**
     * Checks if the card is currently selected
     * @return True if selected, false otherwise
     */
    bool isSelected() const { return _isSelected; }

protected:
    // Constructor and destructor
    CardView() = default;
    ~CardView() override;

private:
    Sprite* _background = nullptr;  // Card background sprite
    Sprite* _smallNumber = nullptr; // Small number indicator (top-left)
    Sprite* _bigNumber = nullptr;   // Large number indicator (center)
    Sprite* _suitIcon = nullptr;    // Suit icon (top-right)
    CardManager* _cardManager = nullptr; // Associated card manager

    // Layout positions relative to card center
    const Vec2 _smallNumberPos = Vec2(-80, 130);
    const Vec2 _suitIconPos = Vec2(80, 130);
    const Vec2 _bigNumberPos = Vec2(0, 0);

    ClickCallback _clickCallback;   // Click event callback
    bool _isSelected = false;       // Selection state flag

    // Dummy variables for implementation variation
    float _viewScale = 1.0f;
    unsigned char _renderFlags = 0;
};

#endif // CARD_VIEW_H_
>>>>>>> c8dc0619d1b49261baf4d4cdb190a8c4fbf38b76
