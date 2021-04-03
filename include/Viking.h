#ifndef Viking_H_
#define Viking_H_

#include "Defines.h"
#include "Airship.h"
#include "TerranAirship.h"

typedef TerranAirship Viking;
void initViking(Viking* viking,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage);
int produceDamageViking(enum AirShipType enemyAirShipType);
#endif