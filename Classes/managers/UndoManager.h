#ifndef UNDO_MANAGER_H
#define UNDO_MANAGER_H

#include "models/UndoModel.h"

/**
 * UndoManager class provides functionality for managing undo operations in the application.
 *
 * This class operates within the manager layer of the MVC architecture, offering centralized
 * services for handling undo functionality. It maintains association with model data and
 * processes it according to the application's requirements.
 *
 * Key responsibilities:
 * - Establishes connection with UndoModel through constructor injection for state management
 * - Records operational states via recordUndoState method, maintaining proper undo sequence
 * - Implements undo functionality through the undo method, restoring previous states
 * - Provides auxiliary methods for checking undo availability and managing history
 */
class UndoManager {
public:
    // Constructor initializing with an UndoModel instance
    UndoManager(UndoModel& undoModel) {
        _undoModel = undoModel;
    }

    // Records a new state to the undo history
    void recordUndoState(const UndoCardState& state) {
        _undoModel.record(state);
    }

    // Performs undo operation, retrieving the previous state
    bool undo(UndoCardState& outState) {
        return _undoModel.undo(outState);
    }

    // Checks if there are states available to undo
    bool canUndo() const {
        return _undoModel.canUndo();
    }

    // Clears all recorded undo history
    void clearUndoHistory() {
        _undoModel.clearHistory();
    }

    // Returns the number of recorded undo states
    int getUndoSize() {
        return _undoModel.getSize();
    }

private:
    // Underlying model handling undo state storage
    UndoModel _undoModel;

    // Temporary variable for implementation differences
    char _placeHolder;
};

#endif // UNDO_MANAGER_H
