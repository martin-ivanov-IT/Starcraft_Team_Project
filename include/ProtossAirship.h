#ifndef ProtossAirship_H_
#define ProtossAirship_H_

#include "Defines.h"
#include "Airship.h"
#include "Vector.h"

typedef struct {
  Airship airship;
  int shield;
  int shieldRegenerateRate;
}ProtossAirship;

void initProtossAirship(ProtossAirship* protossAirship, const char *inputName, int inputHealth, int inputDamage,
                 int shield, int shieldRegenerateRate, enum AirShipType airShipType, int index);

void takeDamageProtoss(ProtossAirship* protossAirship, int damage);
void protossDealDamage(ProtossAirship** lastOfProtoss, Vector* protossFleet, int damage, char* atackerName, int atackerID);
#endif
