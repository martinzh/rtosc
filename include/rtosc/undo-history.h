#include <functional>

/**
 * Known event types:
 * /undo_change /path/location old-data new-data
 */
class UndoHistory
{
    //TODO think about the consequences of largish loads
    public:
        UndoHistory(void);

        //Records any undoable event
        void recordEvent(const char *msg);

        //Prints out a history
        void showHistory(void) const;

        //Seek to another point in history relative to the current one
        //Negative values mean undo, positive values mean redo
        void seekHistory(int distance);

        void setCallback(std::function<void(const char*)> cb);
    private:
        class UndoHistoryImpl *impl;
};
