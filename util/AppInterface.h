// -*- C++ -*-
#ifndef _AppInterface_h_
#define _AppInterface_h_

#include <log4cpp/Category.hh>

#if defined(_MSC_VER) && defined(int64_t)
#undef int64_t
#endif

class EmpireManager;
class Universe;

/** Accessor for the App's empire manager */
EmpireManager& Empires();

/** Accessor for the App's universe object */
Universe& GetUniverse();
    
/** Accessor for the App's logger */
log4cpp::Category& Logger();

/** Returns a new object ID from the server */
int GetNewObjectID();

/** Returns a new object ID from the server */
int GetNewDesignID();

/** Returns current game turn.  This is >= 1 during a game, BEFORE_FIRST_TURN during galaxy setup, or is
    INVALID_GAME_TURN at other times */
int CurrentTurn();

// sentinel values returned by CurrentTurn().  Can't be an enum since CurrentGameTurn() needs to return an integer
// game turn number
extern const int INVALID_GAME_TURN;     ///< returned by CurrentGameTurn if a game is not currently in progress or being set up.
extern const int BEFORE_FIRST_TURN;     ///< returned by CurrentGameTurn if the galaxy is currently being set up
extern const int IMPOSSIBLY_LARGE_TURN; ///< a number that's almost assuredly larger than any real turn number that might come up

/* add additional accessors here for app specific things
   that are needed for both the server and the client, but for which
   access will vary and requires an #ifdef */

#endif // _AppInterface_h_
