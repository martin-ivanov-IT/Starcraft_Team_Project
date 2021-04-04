#ifndef Viking_H_
#define Viking_H_

#include "Defines.h"
#include "Airship.h"
#include "TerranAirship.h"
#include"ProtossAirship.h"


typedef TerranAirship Viking;
void initViking(Viking* viking,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index);
int vikingProduceDamage(enum AirShipType enemyAirShipType);
void vikinngDealDamageToProtossAirship(Vector* protossFleet, ProtossAirship** lastOfProtoss, Viking* viking);
#endif