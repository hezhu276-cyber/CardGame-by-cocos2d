#ifndef GAME_VIEW_H_
#define GAME_VIEW_H_

#include "cocos2d.h"
#include "models/GameModel.h"
#include "CardView.h"
#include <vector>
#include "controllers/GameController.h"

USING_NS_CC;

/**
 * GameView class represents the main visual component of the game.
 *
 * As part of the MVC architecture's view layer, it manages all visual elements
 * and user interactions, providing a visual representation of the game state.
 *
 * Key responsibilities:
 * - Render the main game interface including playfield and stackfield
 * - Manage lifecycle of all CardView instances
 * - Handle global touch events and UI interactions
 * - Provide visual feedback for game state changes
 *
 * Visual components:
 * - Playfield card views collection
 * - Stackfield card views collection
 * - Status label for game state information
 */
class GameView : public Node {
public:
    /**
     * Factory method to create a GameView instance
     * @param model Reference to the game data model
     * @return Newly created GameView instance, or nullptr on failure
     */
    static GameView* create(GameModel& model);

protected:
    /**
     * Initializes the game view with model data
     * @param model Reference to the game data model
     * @return True if initialization succeeds, false otherwise
     */
    bool init(GameModel& model) override;

    /**
     * Creates and configures the status label UI element
     */
    void setupStatusLabel();

    /**
     * Generates card views based on model data
     * @param model Reference to the game data model
     */
    void generateCardViews(GameModel& model);

    /**
     * Configures click handling for card views
     */
    void setupCardClickHandling();

private:
    // Collections of card views
    std::vector<CardView*> _playfieldCardViews;  // Card views for main play area
    std::vector<CardView*> _stackfieldCardViews; // Card views for stack area

    // UI components
    Label* _statusLabel = nullptr;               // Label for game status information

    // Controller reference
    GameController* _gameController = nullptr;   // Associated game controller

    // Event handling methods
    void registerTouchEvents();                  // Registers touch event listeners
    void onLabelClicked();                       // Handles status label click events

    // Dummy variables for implementation variation
    int _viewState = 0;                          // Placeholder for view state tracking
    float _layoutPadding = 0.0f;                 // Placeholder for layout calculations

    // Constructor and destructor
    GameView() = default;
    ~GameView() override;
};

#endif // GAME_VIEW_H_
