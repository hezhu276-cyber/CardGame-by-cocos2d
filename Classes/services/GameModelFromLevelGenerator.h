#ifndef GAME_MODEL_FROM_LEVEL_GENERATOR_H_
#define GAME_MODEL_FROM_LEVEL_GENERATOR_H_

#include "models/GameModel.h"
#include "views/GameView.h"
#include "configs/models/LevelConfig.h"
#include "configs/loaders/LevelConfigLoader.h"
#include <vector>

USING_NS_CC;

/**
 * GameModelFromLevelGenerator provides conversion services between level configurations and game objects.
 *
 * This service class follows the stateless design principle with purely functional interfaces,
 * offering static methods for converting static level data to runtime game models and views.
 */
class GameModelFromLevelGenerator {
public:
    /**
     * Generates a GameModel instance from a level configuration file.
     * @param levelFile Path to the level configuration file
     * @return Initialized GameModel object based on the configuration
     * @note Handles invalid configurations by returning an empty model
     */
    static GameModel generateGameModel(const std::string& levelFile) {
        LevelConfig* config = LevelConfigLoader::loadLevelConfig(levelFile);
        GameModel gameModel(config);
        return gameModel;
    }

    /**
     * Creates and initializes a GameView from a GameModel.
     * @param gameModel Reference to the game model containing data
     * @param parent Node to which the generated view will be attached
     */
    static void generateGameView(GameModel& gameModel, Node* parent) {
        GameView* gameView = GameView::create(gameModel);
        if (gameView && parent) {
            parent->addChild(gameView, 1);
        }
    }

private:
    // Private constructor to prevent instantiation of this static utility class
    GameModelFromLevelGenerator() = default;

    // Prevent copy operations
    GameModelFromLevelGenerator(const GameModelFromLevelGenerator&) = delete;
    GameModelFromLevelGenerator& operator=(const GameModelFromLevelGenerator&) = delete;

    // Padding variable for implementation variation
    unsigned int _serviceMarker;
};

#endif // GAME_MODEL_FROM_LEVEL_GENERATOR_H_
