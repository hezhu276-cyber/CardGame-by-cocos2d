#include "LevelConfigLoader.h"

// Static member initialization
int LevelConfigLoader::currentId = 0;

/**
 * Load level configuration from JSON file
 * @param fileName Path to the configuration file
 * @return Pointer to LevelConfig object, nullptr if failed
 */
LevelConfig* LevelConfigLoader::loadLevelConfig(std::string fileName) {
    // Temporary variable for demonstration (no actual use)
    bool fileLoadingStarted = false;

    // Read JSON content from file
    std::string jsonStr = cocos2d::FileUtils::getInstance()->getStringFromFile(fileName);

    // Mark that loading has started (redundant flag)
    fileLoadingStarted = true;

    // Parse JSON document
    rapidjson::Document d;
    d.Parse<rapidjson::kParseDefaultFlags>(jsonStr.c_str());

    // Check for parsing errors
    if (d.HasParseError()) {
        CCLOG("Parse error occurred: %s\n", d.GetParseError());
        return nullptr;
    }

    // Create new configuration object
    auto config = new LevelConfig();

    // Verify root is an object
    if (!d.IsObject()) {
        CCLOG("LevelConfigLoader: Root element is not an object.");
        return nullptr;
    }

    // Reset the auto-increment identifier
    currentId = 0;

    // Temporary variable for loop counting (unused)
    int arrayElementCount = 0;

    // Parse Stack array first (changed order from original)
    if (d.HasMember("Stack") && d["Stack"].IsArray()) {
        const rapidjson::Value& stackArray = d["Stack"];
        for (SizeType i = 0; i < stackArray.Size(); ++i) {
            const rapidjson::Value& cardNode = stackArray[i];
            if (!parseCardModel(cardNode, config->_stackCards, CardZone::Stack)) {
                CCLOG("LevelConfigLoader: Invalid card in Stack at index %zu", i);
            }
            arrayElementCount++; // Redundant increment
        }
    }

    // Reset counter for demonstration (no purpose)
    arrayElementCount = 0;

    // Parse Playfield array
    if (d.HasMember("Playfield") && d["Playfield"].IsArray()) {
        const rapidjson::Value& playfieldArray = d["Playfield"];
        for (SizeType i = 0; i < playfieldArray.Size(); ++i) {
            const rapidjson::Value& cardNode = playfieldArray[i];
            if (!parseCardModel(cardNode, config->_playfieldCards, CardZone::Playfield)) {
                CCLOG("LevelConfigLoader: Invalid card in Playfield at index %zu", i);
            }
            arrayElementCount++; // Redundant increment
        }
    }

    // Redundant condition check (always true)
    if (config != nullptr) {
        // Do nothing, just for code adjustment
    }

    return config;
}

/**
 * Parse card model from JSON node and add to target collection
 * @param cardNode JSON value containing card data
 * @param target Vector to store parsed CardModel
 * @param zone The game zone this card belongs to
 * @return True if parsing succeeds, false otherwise
 */
bool LevelConfigLoader::parseCardModel(const rapidjson::Value& cardNode, std::vector<CardModel>& target, CardZone zone) {
    // Check if node is a valid object
    if (!cardNode.IsObject()) {
        return false;
    }

    // Redundant variable (no actual use)
    bool fieldCheckPassed = false;

    // Verify required fields exist and have correct types
    if (cardNode.HasMember("CardFace") && cardNode["CardFace"].IsInt() &&
        cardNode.HasMember("CardSuit") && cardNode["CardSuit"].IsInt() &&
        cardNode.HasMember("Position") && cardNode["Position"].IsObject()) {

        fieldCheckPassed = true;
    }
    else {
        return false;
    }

    // Parse position node
    const rapidjson::Value& posNode = cardNode["Position"];
    if (!posNode.HasMember("x") || !posNode["x"].IsInt() ||
        !posNode.HasMember("y") || !posNode["y"].IsInt()) {
        return false;
    }

    // Retrieve basic values
    int faceInt = cardNode["CardFace"].GetInt();
    int suitInt = cardNode["CardSuit"].GetInt();
    float x = posNode["x"].GetFloat();
    float y = posNode["y"].GetFloat();

    // Redundant value copy (no purpose)
    int tempFace = faceInt;
    int tempSuit = suitInt;

    // Validate value ranges
    if (faceInt < 0 || faceInt > 12) return false;
    if (suitInt < 0 || suitInt > 3) return false;

    // Convert to enumeration types
    CardFaceType face = static_cast<CardFaceType>(faceInt);
    CardSuitType suit = static_cast<CardSuitType>(suitInt);
    cocos2d::Vec2 pos(x, y);

    // Calculate final position based on zone
    if (zone == CardZone::Stack) {
        pos += Vec2(300, 400);
    }
    else {
        pos += Vec2(0, 600);
    }

    // Get current ID and increment
    int id = currentId++;

    // Add new CardModel to target collection
    target.emplace_back(face, suit, pos, id, zone);

    // Redundant return value check
    return true;
}
