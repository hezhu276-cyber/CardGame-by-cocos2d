<<<<<<< HEAD
// GameController.h
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <vector>
#include <cstdint> 
#include "models/GameModel.h"
#include "managers/UndoManager.h"
#include "managers/CardManager.h"

class CardManager;
/**
 * @class GameController
 * @brief Core game controller following MVC architecture's controllers layer specifications
 *
 * This class serves as the central controller for game flow, responsible for coordinating interactions
 * between GameModel and GameView/CardView components. It handles the following key functionalities:
 * 1. Processes click and matching logic for playfield cards, verifying if cards meet elimination rules
 * 2. Manages Stack zone card click events, recording operation states through UndoManager
 * 3. Implements undo functionality, restoring card positions and states based on UndoModel records
 * 4. Coordinates view layer updates, such as invoking CardView animation interfaces for card movements
 */
class GameController {
public:
    /**
   * @brief Constructor with game model initialization
   * @param gameModel Reference to the game model containing initial state
   */
    GameController(GameModel gameModel);
    ~GameController();

  
    bool selectCardFromPlayefieldAndMatch(CardModel& selectedCard);

    /**
       * @brief Processes general card click events
       * @param card Reference to the clicked card model
       */
    void handleCardClicked(CardModel& card);

    /**
       * @brief Handles Stack zone card click events
       * @param card Reference to the clicked stack card model
       */
    void clickStackCard(CardModel& card);

;

    // undobutton
    bool undo();

    void GameController::handleLabelClick();

private:
    GameModel _gameModel;
    UndoManager _undoManager;

    // get cardmod
    CardModel getBottomCard();

    // check wherher match
    bool isCardMatch(const CardModel& card1, const CardModel& card2);

    // move card back
    void moveCardToOriginalPosition(const UndoCardState& state);

    // get CardManager by CardModel
    CardManager* getCardManager(const CardModel& card);


};
=======
// GameController.h
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <vector>
#include <cstdint> 
#include "models/GameModel.h"
#include "managers/UndoManager.h"
#include "managers/CardManager.h"

class CardManager;
/**
 * @class GameController
 * @brief Core game controller following MVC architecture's controllers layer specifications
 *
 * This class serves as the central controller for game flow, responsible for coordinating interactions
 * between GameModel and GameView/CardView components. It handles the following key functionalities:
 * 1. Processes click and matching logic for playfield cards, verifying if cards meet elimination rules
 * 2. Manages Stack zone card click events, recording operation states through UndoManager
 * 3. Implements undo functionality, restoring card positions and states based on UndoModel records
 * 4. Coordinates view layer updates, such as invoking CardView animation interfaces for card movements
 */
class GameController {
public:
    /**
   * @brief Constructor with game model initialization
   * @param gameModel Reference to the game model containing initial state
   */
    GameController(GameModel gameModel);
    ~GameController();

  
    bool selectCardFromPlayefieldAndMatch(CardModel& selectedCard);

    /**
       * @brief Processes general card click events
       * @param card Reference to the clicked card model
       */
    void handleCardClicked(CardModel& card);

    /**
       * @brief Handles Stack zone card click events
       * @param card Reference to the clicked stack card model
       */
    void clickStackCard(CardModel& card);

;

    // undobutton
    bool undo();

    void GameController::handleLabelClick();

private:
    GameModel _gameModel;
    UndoManager _undoManager;

    // get cardmod
    CardModel getBottomCard();

    // check wherher match
    bool isCardMatch(const CardModel& card1, const CardModel& card2);

    // move card back
    void moveCardToOriginalPosition(const UndoCardState& state);

    // get CardManager by CardModel
    CardManager* getCardManager(const CardModel& card);


};
>>>>>>> c8dc0619d1b49261baf4d4cdb190a8c4fbf38b76
#endif