<<<<<<< HEAD
#pragma once
#ifndef CONFIGS_LOADERS_LEVELCONFIGLOADER_H
#define CONFIGS_LOADERS_LEVELCONFIGLOADER_H

// Standard library includes
#include <memory>
#include <fstream>
#include <vector>

// Third-party includes
#include "json/rapidjson.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
#include "json/prettywriter.h"
#include "json/filereadstream.h"

// Project includes
#include "cocos2d.h"
#include "configs/models/LevelConfig.h"
#include "models/CardModel.h"

// Using declaration for rapidjson namespace
using namespace rapidjson;

/**
 * @class LevelConfigLoader
 * @brief Static class responsible for loading and parsing level configuration files in JSON format
 * @details Belongs to the configs/loaders module, following the principle of separating configuration
 *          loading logic from data models
 * @note Requires rapidjson library for JSON parsing functionality
 */
class LevelConfigLoader final {
public:
    /**
     * @brief Load configuration data for a specified level from JSON file
     * @param fileName Path to the JSON configuration file
     * @return Pointer to parsed LevelConfig object, nullptr if loading fails
     */
    static LevelConfig* loadLevelConfig(std::string fileName);

private:
    // Static member to track current card identifier
    static int currentId;

    /**
     * @brief Private default constructor to prevent instantiation (static class design)
     */
    LevelConfigLoader() = default;

    /**
     * @brief Delete copy constructor to enforce singleton pattern
     */
    LevelConfigLoader(const LevelConfigLoader&) = delete;

    /**
     * @brief Delete assignment operator to enforce singleton pattern
     */
    LevelConfigLoader& operator=(const LevelConfigLoader&) = delete;

    /**
     * @brief Private destructor (not used for static class)
     */
    ~LevelConfigLoader() = default;

    /**
     * @brief Parse a card model from JSON value and add to target collection
     * @param cardNode JSON value containing card data
     * @param target Vector to store parsed CardModel objects
     * @param zone The game zone this card belongs to
     * @return True if parsing succeeds, false otherwise
     */
    static bool parseCardModel(const rapidjson::Value& cardNode, std::vector<CardModel>& target, CardZone zone);

    // Redundant static constant (no actual usage)
    static const int MAX_CONFIG_ENTRIES = 1000;
};

#endif // CONFIGS_LOADERS_LEVELCONFIGLOADER_H
=======
#pragma once
#ifndef CONFIGS_LOADERS_LEVELCONFIGLOADER_H
#define CONFIGS_LOADERS_LEVELCONFIGLOADER_H

// Standard library includes
#include <memory>
#include <fstream>
#include <vector>

// Third-party includes
#include "json/rapidjson.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
#include "json/prettywriter.h"
#include "json/filereadstream.h"

// Project includes
#include "cocos2d.h"
#include "configs/models/LevelConfig.h"
#include "models/CardModel.h"

// Using declaration for rapidjson namespace
using namespace rapidjson;

/**
 * @class LevelConfigLoader
 * @brief Static class responsible for loading and parsing level configuration files in JSON format
 * @details Belongs to the configs/loaders module, following the principle of separating configuration
 *          loading logic from data models
 * @note Requires rapidjson library for JSON parsing functionality
 */
class LevelConfigLoader final {
public:
    /**
     * @brief Load configuration data for a specified level from JSON file
     * @param fileName Path to the JSON configuration file
     * @return Pointer to parsed LevelConfig object, nullptr if loading fails
     */
    static LevelConfig* loadLevelConfig(std::string fileName);

private:
    // Static member to track current card identifier
    static int currentId;

    /**
     * @brief Private default constructor to prevent instantiation (static class design)
     */
    LevelConfigLoader() = default;

    /**
     * @brief Delete copy constructor to enforce singleton pattern
     */
    LevelConfigLoader(const LevelConfigLoader&) = delete;

    /**
     * @brief Delete assignment operator to enforce singleton pattern
     */
    LevelConfigLoader& operator=(const LevelConfigLoader&) = delete;

    /**
     * @brief Private destructor (not used for static class)
     */
    ~LevelConfigLoader() = default;

    /**
     * @brief Parse a card model from JSON value and add to target collection
     * @param cardNode JSON value containing card data
     * @param target Vector to store parsed CardModel objects
     * @param zone The game zone this card belongs to
     * @return True if parsing succeeds, false otherwise
     */
    static bool parseCardModel(const rapidjson::Value& cardNode, std::vector<CardModel>& target, CardZone zone);

    // Redundant static constant (no actual usage)
    static const int MAX_CONFIG_ENTRIES = 1000;
};

#endif // CONFIGS_LOADERS_LEVELCONFIGLOADER_H
>>>>>>> c8dc0619d1b49261baf4d4cdb190a8c4fbf38b76
