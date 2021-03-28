#include "Defines.h"
#include "Airships.h"
void initViking(TerranAirship* viking);
void initBattleCruser(TerranAirship* battleCruser);
void initTerranAirship(TerranAirship** terranAirship, char letter);
void TerranAtack(ProtossAirship* protossAirship, TerranAirship* terranAirship, int turn);
void produceDamage(ProtossAirship* protossAirship, short damage);
bool isDamagedTerran(TerranAirship* terranAirship);