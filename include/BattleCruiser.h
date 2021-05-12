#ifndef BattleCruiser_H_
#define BattleCruiser_H_

#include "TerranAirship.h"
#include"ProtossAirship.h"

typedef TerranAirship BattleCruiser;
int initBattleCruiser(BattleCruiser* battleCruiser,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index);
int battleCruiseProduceDamage(int turn, int* errNo);
int battleCruiserDealDamageToProtossAirship(Vector* protossFleet,ProtossAirship** lastOfProtoss, int turn, BattleCruiser* battleCruiser);

#endif