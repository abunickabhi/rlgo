//----------------------------------------------------------------------------
/** @file RlTestUtil.h
    Utility functions for unit tests
*/
//----------------------------------------------------------------------------

#ifndef RLTESTUTIL_H
#define RLTESTUTIL_H

#include "GoBoard.h"
#include "SgRect.h"

class RlTracker;
class RlBinaryFeatures;
class RlActiveSet;

//----------------------------------------------------------------------------

// BOOST_CHECK_SMALL isn't available in all versions yet
#ifndef BOOST_CHECK_SMALL
#define BOOST_CHECK_SMALL(val, tol) BOOST_CHECK(fabsf(val) < tol);
#endif

extern bool tryall;
extern float testtol;
extern bool printdebug;

void TryAll(GoBoard& bd, RlTracker& tracker);
void Reset(RlTracker& tracker, RlActiveSet& active, RlBinaryFeatures& features);
void Play(SgPoint point, SgBlackWhite colour, 
    GoBoard& bd, RlTracker& tracker, RlActiveSet& active, 
    RlBinaryFeatures& features);
void Undo(GoBoard& bd, RlTracker& tracker, RlActiveSet& active, 
    RlBinaryFeatures& features);
int CountOccurrences(const RlActiveSet& active, int featureindex);
SgRect MakeRect(int x, int y);
void DisplayActive(const RlActiveSet& active, RlBinaryFeatures& features);

//----------------------------------------------------------------------------

#endif // RLTESTUTIL_H
