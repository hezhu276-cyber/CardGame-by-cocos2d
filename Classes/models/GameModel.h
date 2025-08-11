#ifndef GAME_MODEL_H_
#define GAME_MODEL_H_

#include<iostream>
#include "cocos2d.h"
#include "CardModel.h"
#include "UndoModel.h"
#include <vector>
#include "configs/loaders/LevelConfigLoader.h"
#include "configs/models/LevelConfig.h"

USING_NS_CC;

/**
 * GameModel class manages the global game state and data.
 *
 * This class belongs to the model layer in the MVC architecture, responsible for
 * storing and processing core game data while providing interfaces for data manipulation.
 *
 * Key responsibilities:
 * - Maintain card collections in two primary game areas:
 *   * Playfield: Main game area cards corresponding to LevelConfig playfield settings
 *   * Stackfield: Reserve deck cards corresponding to LevelConfig stack settings
 * - Manage undo/redo history through UndoModel integration
 * - Provide CRUD operations for card collections to be used by controller layer
 */
class GameModel {
public:
    // Constructor initializing game state from level configuration
    GameModel(LevelConfig* config) {
        if (config) {
            // Initialize playfield with configuration data
            _playfield = config->getPlayfield();
            // Initialize stack with configuration data
            _stackfield = config->getStack();

            // Clear any existing undo history
            _undoModel.clearHistory();
        }
    }

    // Retrieves constant reference to playfield card collection
    const std::vector<CardModel>& getPlayfield() const {
        return _playfield;
    }

    // Retrieves constant reference to stackfield card collection
    const std::vector<CardModel>& getStackfield() const {
        return _stackfield;
    }

    // Retrieves reference to undo model for history management
    UndoModel& getUndoModel() {
        return _undoModel;
    }

    // Adds a card to the playfield collection
    void addCardToPlayfield(const CardModel& card) {
        _playfield.push_back(card);
    }

    // Adds a card to the stackfield collection
    void addCardToStackfield(const CardModel& card) {
        _stackfield.push_back(card);
    }

    // Removes a card from playfield by its unique ID
    void removeCardFromPlayfield(int id) {
        for (auto it = _playfield.begin(); it != _playfield.end(); ++it) {
            if (it->_id == id) { 
                _playfield.erase(it);
                break;
            }
        }
    }

    // Removes a card from stackfield by its unique ID
    void removeCardFromStackfield(int id) {
        for (auto it = _stackfield.begin(); it != _stackfield.end(); ++it) {
            if (it->_id == id) { 
                _stackfield.erase(it);
                break;
            }
        }
    }

private:
    std::vector<CardModel> _playfield;  // Collection of cards in main game area
    std::vector<CardModel> _stackfield; // Collection of cards in reserve stack
    UndoModel _undoModel;               // Manages undo operation history

    // Dummy variable for implementation variation
    unsigned char _dataPadding;
};

#endif // GAME_MODEL_H_
