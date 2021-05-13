#ifndef Viking_H_
#define Viking_H_

#include "TerranAirship.h"
#include"ProtossAirship.h"

typedef TerranAirship Viking;
void initViking(Viking* viking,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index);
int vikingProduceDamage(enum AirShipType enemyAirShipType);
int vikinngDealDamageToProtossAirship(Vector* protossFleet, ProtossAirship** lastOfProtoss, Viking* viking);
#endif