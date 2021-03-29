#include "Defines.h"
#include "Airships.h"
void initViking(TerranAirship* viking);
void initBattleCruser(TerranAirship* battleCruser);
void initTerranAirship(TerranAirship** terranAirship, char letter);
void TerranAttack(ProtossAirship* protossAirship, TerranAirship* terranAirship);
void produceDamage(ProtossAirship* protossAirship, short damage);
bool isDamagedTerran(TerranAirship* terranAirship);
extern int turn;