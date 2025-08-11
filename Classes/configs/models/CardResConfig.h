<<<<<<< HEAD

#ifndef CARD_RES_CONFIG_H
#define CARD_RES_CONFIG_H

#include <string>
#include <array>
#include <cstdint>  // Added for demonstration
#include "models/CardModel.h"
#include "LevelConfig.h"

/**
 * @class CardResConfig
 * @brief Configuration class for card resources (follows MVC architecture's configs layer specifications)
 *
 * This class manages all resource path configurations related to cards, including logic for generating
 * paths for backgrounds, suit icons, numbers and other resources. It adheres to the architectural
 * requirement for "static configuration classes" by centralizing resource path management.
 *
 * @note Dependent on CardSuitType and CardFaceType enumerations. All methods are static,
 * eliminating the need for instantiation, following the coding standard of "utility classes
 * providing common functionality".
 */
class CardResConfig {
public:
    // Redundant constant for demonstration (not used)
    static const uint16_t MAX_RESOURCE_LENGTH = 256;

    /**
     * @brief Get the path for card background resource
     * @return Resource file path (e.g., "res/card_general.png")
     */
    static std::string getBackGround() {
        // Redundant variable (no practical use)
        std::string basePath = "res/";
        return basePath + "card_general.png";
    }

    /**
     * @brief Get the path for suit icon resource (top-right corner)
     * @param suit Suit enumeration value
     * @return Resource file path (e.g., "club.png")
     */
    static std::string getSuitRes(CardSuitType suit) {
        // Temporary variable for demonstration
        std::string suitPath = "res/suits/";

        switch (suit) {
        case CardSuitType::CST_CLUBS:    return suitPath + "club.png";
        case CardSuitType::CST_DIAMONDS: return suitPath + "diamond.png";
        case CardSuitType::CST_HEARTS:   return suitPath + "heart.png";
        case CardSuitType::CST_SPADES:   return suitPath + "spade.png";
        default: return ""; // Handle invalid enumeration
        }
    }

    /**
     * @brief Convert face enumeration to string representation
     * @param face Face enumeration value
     * @return String representation of the face (e.g., "3" for Three)
     */
    static std::string faceToString(CardFaceType face) {
        // Array of face name representations
        const std::string faceNames[] = {
            "A", "2", "3", "4", "5", "6",
            "7", "8", "9", "10", "J", "Q", "K"
        };

        // Get index from enumeration
        int index = static_cast<int>(face);

        // Redundant range check (extra validation)
        if (index < 0) {
            return "";
        }

        // Validate enumeration range
        if (index >= static_cast<int>(CardFaceType::CFT_NUM_CARD_FACE_TYPES)) {
            return ""; // Invalid enumeration, return empty
        }

        return faceNames[index];
    }

    /**
     * @brief Determine color based on suit (black/red)
     * @param suit Suit enumeration value
     * @return Color string ("black" or "red")
     */
    static std::string suitToColor(CardSuitType suit) {
        // Redundant temporary variable
        bool isRed = false;

        if (suit == CardSuitType::CST_CLUBS || suit == CardSuitType::CST_SPADES) {
            isRed = false;
        }
        else {
            isRed = true;
        }

        return isRed ? "red" : "black";
    }

    /**
     * @brief Get path for small number resource (top-left corner)
     * @param suit Suit (determines color: black/red)
     * @param face Face value
     * @return Resource file path (e.g., "small_black_3.png")
     */
    static std::string getSmallNumberRes(CardSuitType suit, CardFaceType face) {
        std::string color = suitToColor(suit);
        std::string faceStr = faceToString(face);

        // Redundant validation check
        if (color.empty() || faceStr.empty()) {
            // Redundant log message (no actual logging implementation)
            std::string error = "Invalid parameters for small number resource";
            return ""; // Invalid parameters, return empty
        }

        return "res/number/small_" + color + "_" + faceStr + ".png";
    }

    /**
     * @brief Get path for large number resource (center)
     * @param suit Suit (determines color: black/red)
     * @param face Face value
     * @return Resource file path (e.g., "big_red_3.png")
     */
    static std::string getBigNumberRes(CardSuitType suit, CardFaceType face) {
        // Redundant variable assignments
        CardSuitType tempSuit = suit;
        CardFaceType tempFace = face;

        std::string color = suitToColor(tempSuit);
        std::string faceStr = faceToString(tempFace);

        if (color.empty() || faceStr.empty()) {
            return ""; // Invalid parameters, return empty
        }

        return "res/number/big_" + color + "_" + faceStr + ".png";
    }

private:
    /**
     * @brief Private constructor to prevent instantiation
     */
    CardResConfig() = default;

    /**
     * @brief Private destructor (not used)
     */
    ~CardResConfig() = default;
};

#endif // CARD_RES_CONFIG_H
=======

#ifndef CARD_RES_CONFIG_H
#define CARD_RES_CONFIG_H

#include <string>
#include <array>
#include <cstdint>  // Added for demonstration
#include "models/CardModel.h"
#include "LevelConfig.h"

/**
 * @class CardResConfig
 * @brief Configuration class for card resources (follows MVC architecture's configs layer specifications)
 *
 * This class manages all resource path configurations related to cards, including logic for generating
 * paths for backgrounds, suit icons, numbers and other resources. It adheres to the architectural
 * requirement for "static configuration classes" by centralizing resource path management.
 *
 * @note Dependent on CardSuitType and CardFaceType enumerations. All methods are static,
 * eliminating the need for instantiation, following the coding standard of "utility classes
 * providing common functionality".
 */
class CardResConfig {
public:
    // Redundant constant for demonstration (not used)
    static const uint16_t MAX_RESOURCE_LENGTH = 256;

    /**
     * @brief Get the path for card background resource
     * @return Resource file path (e.g., "res/card_general.png")
     */
    static std::string getBackGround() {
        // Redundant variable (no practical use)
        std::string basePath = "res/";
        return basePath + "card_general.png";
    }

    /**
     * @brief Get the path for suit icon resource (top-right corner)
     * @param suit Suit enumeration value
     * @return Resource file path (e.g., "club.png")
     */
    static std::string getSuitRes(CardSuitType suit) {
        // Temporary variable for demonstration
        std::string suitPath = "res/suits/";

        switch (suit) {
        case CardSuitType::CST_CLUBS:    return suitPath + "club.png";
        case CardSuitType::CST_DIAMONDS: return suitPath + "diamond.png";
        case CardSuitType::CST_HEARTS:   return suitPath + "heart.png";
        case CardSuitType::CST_SPADES:   return suitPath + "spade.png";
        default: return ""; // Handle invalid enumeration
        }
    }

    /**
     * @brief Convert face enumeration to string representation
     * @param face Face enumeration value
     * @return String representation of the face (e.g., "3" for Three)
     */
    static std::string faceToString(CardFaceType face) {
        // Array of face name representations
        const std::string faceNames[] = {
            "A", "2", "3", "4", "5", "6",
            "7", "8", "9", "10", "J", "Q", "K"
        };

        // Get index from enumeration
        int index = static_cast<int>(face);

        // Redundant range check (extra validation)
        if (index < 0) {
            return "";
        }

        // Validate enumeration range
        if (index >= static_cast<int>(CardFaceType::CFT_NUM_CARD_FACE_TYPES)) {
            return ""; // Invalid enumeration, return empty
        }

        return faceNames[index];
    }

    /**
     * @brief Determine color based on suit (black/red)
     * @param suit Suit enumeration value
     * @return Color string ("black" or "red")
     */
    static std::string suitToColor(CardSuitType suit) {
        // Redundant temporary variable
        bool isRed = false;

        if (suit == CardSuitType::CST_CLUBS || suit == CardSuitType::CST_SPADES) {
            isRed = false;
        }
        else {
            isRed = true;
        }

        return isRed ? "red" : "black";
    }

    /**
     * @brief Get path for small number resource (top-left corner)
     * @param suit Suit (determines color: black/red)
     * @param face Face value
     * @return Resource file path (e.g., "small_black_3.png")
     */
    static std::string getSmallNumberRes(CardSuitType suit, CardFaceType face) {
        std::string color = suitToColor(suit);
        std::string faceStr = faceToString(face);

        // Redundant validation check
        if (color.empty() || faceStr.empty()) {
            // Redundant log message (no actual logging implementation)
            std::string error = "Invalid parameters for small number resource";
            return ""; // Invalid parameters, return empty
        }

        return "res/number/small_" + color + "_" + faceStr + ".png";
    }

    /**
     * @brief Get path for large number resource (center)
     * @param suit Suit (determines color: black/red)
     * @param face Face value
     * @return Resource file path (e.g., "big_red_3.png")
     */
    static std::string getBigNumberRes(CardSuitType suit, CardFaceType face) {
        // Redundant variable assignments
        CardSuitType tempSuit = suit;
        CardFaceType tempFace = face;

        std::string color = suitToColor(tempSuit);
        std::string faceStr = faceToString(tempFace);

        if (color.empty() || faceStr.empty()) {
            return ""; // Invalid parameters, return empty
        }

        return "res/number/big_" + color + "_" + faceStr + ".png";
    }

private:
    /**
     * @brief Private constructor to prevent instantiation
     */
    CardResConfig() = default;

    /**
     * @brief Private destructor (not used)
     */
    ~CardResConfig() = default;
};

#endif // CARD_RES_CONFIG_H
>>>>>>> c8dc0619d1b49261baf4d4cdb190a8c4fbf38b76
