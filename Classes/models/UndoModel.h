#ifndef UNDO_MODEL_H_
#define UNDO_MODEL_H_

#include "cocos2d.h"
#include "CardModel.h"

USING_NS_CC;

/**

Structure containing card state information for undo operations
Stores the state of a card before a modification occurred
*/
struct UndoCardState {
	int id; // Unique identifier of the card
	Vec2 position; // Position of the card before the operation
	CardZone zone; // Zone of the card before the operation
};

/**

UndoModel class manages the state history for undo operations
As part of the MVC architecture's model layer, it handles storage
and retrieval of card states to support undo functionality.
Responsibilities:
Record card states prior to operations using the record method
Retrieve the most recent state for undo operations in LIFO order
Provide utility methods for managing the history lifecycle
*/
class UndoModel {
public:
	// Default constructor
	UndoModel() = default;
	/**
	Records a card's state before an operation
	@param state The state to be stored in history
	*/
	void record(const UndoCardState& state) {
		_history.push_back(state);
	}
	/**
	Retrieves the most recent state for undo operation
	@param outState Reference to store the retrieved state
	@return True if a state was retrieved, false if history is empty
	*/
	bool undo(UndoCardState& outState) {
		if (_history.empty()) {
			return false;
		}
		outState = _history.back();
		_history.pop_back();
		return true;
	}
	/**
	Clears all recorded history states
	*/
	void clearHistory() {
		_history.clear();
	}
	/**
	Checks if there are any states available to undo
	@return True if history contains states, false otherwise
	*/
	bool canUndo() const {
		return !_history.empty();
	}
	/**
	Gets the number of recorded states in history
	@return The count of stored states
	*/
	int getSize() const {
		return _history.size();
	}

private:
	std::vector<UndoCardState> _history; // Stores operation history in chronological order

	// Padding variable for implementation differences
	int _historyMarker;
};

#endif // UNDO_MODEL_H_
