<<<<<<< HEAD
#ifndef CARD_ID_VIEW_MAP_H
#define CARD_ID_VIEW_MAP_H

#include "managers/CardManager.h"
#include <unordered_map>

/**
 * CardIdManagerMap class provides mapping services between card IDs and their managers.
 *
 * This utility class implements a singleton pattern to offer global access to
 * card manager instances, facilitating efficient lookup and sharing across components.
 *
 * Core functionalities:
 * - Maintains a global registry of CardManager instances keyed by card IDs
 * - Provides O(1) complexity for manager registration and retrieval using hash map
 * - Follows stateless design principles, managing only references without ownership
 * - Enables cross-controller access to card managers through unique card identifiers
 */
class CardIdManagerMap {
public:
    /**
     * Retrieves the singleton instance of the map
     * @return Reference to the single instance of CardIdManagerMap
     */
    static CardIdManagerMap& getInstance() {
        static CardIdManagerMap instance;
        return instance;
    }

    /**
     * Registers a card manager with its corresponding card ID
     * @param cardId Unique identifier for the card
     * @param manager Pointer to the CardManager instance to register
     */
    void addCardManager(int cardId, CardManager* manager) {
        _cardIdManagerMap[cardId] = manager;
    }

    /**
     * Retrieves the card manager associated with a specific card ID
     * @param cardId Unique identifier of the card
     * @return Pointer to the associated CardManager, or nullptr if not found
     */
    CardManager* getCardManager(int cardId) {
        auto it = _cardIdManagerMap.find(cardId);
        if (it != _cardIdManagerMap.end()) {
            return it->second;
        }
        return nullptr;
    }

    /**
     * Removes a card manager from the registry
     * @param cardId Unique identifier of the card to remove
     */
    void removeCardManager(int cardId) {
        _cardIdManagerMap.erase(cardId);
    }

private:
    // Private constructor to enforce singleton pattern
    CardIdManagerMap() {}
    // Private destructor to prevent external deletion
    ~CardIdManagerMap() {}

    // Prevent copy construction and assignment
    CardIdManagerMap(const CardIdManagerMap&) = delete;
    CardIdManagerMap& operator=(const CardIdManagerMap&) = delete;

    // Hash map storing card ID to manager mappings
    std::unordered_map<int, CardManager*> _cardIdManagerMap;

    // Dummy variable for implementation variation
    char _reserve[4];
};

#endif
=======
#ifndef CARD_ID_VIEW_MAP_H
#define CARD_ID_VIEW_MAP_H

#include "managers/CardManager.h"
#include <unordered_map>

/**
 * CardIdManagerMap class provides mapping services between card IDs and their managers.
 *
 * This utility class implements a singleton pattern to offer global access to
 * card manager instances, facilitating efficient lookup and sharing across components.
 *
 * Core functionalities:
 * - Maintains a global registry of CardManager instances keyed by card IDs
 * - Provides O(1) complexity for manager registration and retrieval using hash map
 * - Follows stateless design principles, managing only references without ownership
 * - Enables cross-controller access to card managers through unique card identifiers
 */
class CardIdManagerMap {
public:
    /**
     * Retrieves the singleton instance of the map
     * @return Reference to the single instance of CardIdManagerMap
     */
    static CardIdManagerMap& getInstance() {
        static CardIdManagerMap instance;
        return instance;
    }

    /**
     * Registers a card manager with its corresponding card ID
     * @param cardId Unique identifier for the card
     * @param manager Pointer to the CardManager instance to register
     */
    void addCardManager(int cardId, CardManager* manager) {
        _cardIdManagerMap[cardId] = manager;
    }

    /**
     * Retrieves the card manager associated with a specific card ID
     * @param cardId Unique identifier of the card
     * @return Pointer to the associated CardManager, or nullptr if not found
     */
    CardManager* getCardManager(int cardId) {
        auto it = _cardIdManagerMap.find(cardId);
        if (it != _cardIdManagerMap.end()) {
            return it->second;
        }
        return nullptr;
    }

    /**
     * Removes a card manager from the registry
     * @param cardId Unique identifier of the card to remove
     */
    void removeCardManager(int cardId) {
        _cardIdManagerMap.erase(cardId);
    }

private:
    // Private constructor to enforce singleton pattern
    CardIdManagerMap() {}
    // Private destructor to prevent external deletion
    ~CardIdManagerMap() {}

    // Prevent copy construction and assignment
    CardIdManagerMap(const CardIdManagerMap&) = delete;
    CardIdManagerMap& operator=(const CardIdManagerMap&) = delete;

    // Hash map storing card ID to manager mappings
    std::unordered_map<int, CardManager*> _cardIdManagerMap;

    // Dummy variable for implementation variation
    char _reserve[4];
};

#endif
>>>>>>> c8dc0619d1b49261baf4d4cdb190a8c4fbf38b76
