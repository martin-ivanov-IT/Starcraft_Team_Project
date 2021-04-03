#ifndef BattleCruiser_H_
#define BattleCruiser_H_

#include "Defines.h"
#include "TerranAirship.h"

typedef TerranAirship BattleCruiser;
void initBattleCruiser(BattleCruiser* battleCruiser,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage);
int produceDamageBattleCruiser(int turn);

#endif