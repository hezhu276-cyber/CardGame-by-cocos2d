<<<<<<< HEAD
#pragma once
#include <iostream>
#include "cocos2d.h"


// Defines possible locations where a card can exist in the game
enum class CardZone { PLAYFIELD, STACK, HAND, UNKNOWN };

// Defines the suit classification of a card
enum class CardSuit { CLUBS, DIAMONDS, HEARTS, SPADES, UNSPECIFIED };

// Defines the rank/face value of a card
enum class CardFace { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, NONE };

// Stores and manages data properties of a game card
struct CardModel
{
    CardFace face;          // The face/rank value of the card
    CardSuit suit;          // The suit classification of the card
    cocos2d::Vec2 position; // Current position coordinates of the card
    int id;                 // Unique identifier for the card
    CardZone zone;          // Current game area where the card resides

    // Basic constructor with essential card properties
    CardModel(CardFace f, CardSuit s, const cocos2d::Vec2& pos)
        : face(f), suit(s), position(pos), id(-1), zone(CardZone::UNKNOWN) {
    }

    // Full constructor with all card properties
    CardModel(CardFace f, CardSuit s, const cocos2d::Vec2& pos, int id, CardZone z)
        : face(f), suit(s), position(pos), id(id), zone(z) {
    }

    // Retrieves the card's face value
    CardFace get_face() const noexcept { return face; }

    // Retrieves the card's suit
    CardSuit get_suit() const noexcept { return suit; }

    // Retrieves the current zone where the card is located
    CardZone get_zone() const noexcept { return zone; }

    // Retrieves the card's current position
    const cocos2d::Vec2& get_position() const noexcept { return position; }

    // Updates the card's current zone
    void set_zone(CardZone z) noexcept { zone = z; }

    // Updates the card's position coordinates
    void set_position(const cocos2d::Vec2& pos) noexcept { position = pos; }

    // Dummy variable for implementation variation
    short _filler;
=======
#pragma once
#include <iostream>
#include "cocos2d.h"


// Defines possible locations where a card can exist in the game
enum class CardZone { PLAYFIELD, STACK, HAND, UNKNOWN };

// Defines the suit classification of a card
enum class CardSuit { CLUBS, DIAMONDS, HEARTS, SPADES, UNSPECIFIED };

// Defines the rank/face value of a card
enum class CardFace { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, NONE };

// Stores and manages data properties of a game card
struct CardModel
{
    CardFace face;          // The face/rank value of the card
    CardSuit suit;          // The suit classification of the card
    cocos2d::Vec2 position; // Current position coordinates of the card
    int id;                 // Unique identifier for the card
    CardZone zone;          // Current game area where the card resides

    // Basic constructor with essential card properties
    CardModel(CardFace f, CardSuit s, const cocos2d::Vec2& pos)
        : face(f), suit(s), position(pos), id(-1), zone(CardZone::UNKNOWN) {
    }

    // Full constructor with all card properties
    CardModel(CardFace f, CardSuit s, const cocos2d::Vec2& pos, int id, CardZone z)
        : face(f), suit(s), position(pos), id(id), zone(z) {
    }

    // Retrieves the card's face value
    CardFace get_face() const noexcept { return face; }

    // Retrieves the card's suit
    CardSuit get_suit() const noexcept { return suit; }

    // Retrieves the current zone where the card is located
    CardZone get_zone() const noexcept { return zone; }

    // Retrieves the card's current position
    const cocos2d::Vec2& get_position() const noexcept { return position; }

    // Updates the card's current zone
    void set_zone(CardZone z) noexcept { zone = z; }

    // Updates the card's position coordinates
    void set_position(const cocos2d::Vec2& pos) noexcept { position = pos; }

    // Dummy variable for implementation variation
    short _filler;
>>>>>>> c8dc0619d1b49261baf4d4cdb190a8c4fbf38b76
};