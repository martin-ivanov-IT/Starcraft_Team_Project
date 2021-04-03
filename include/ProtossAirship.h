#ifndef ProtossAirship_H_
#define ProtossAirship_H_

#include "Defines.h"
#include "Airship.h"

typedef struct {
  Airship airship;
  int shield;
  int shieldRegenerateRate;
}ProtossAirship;

void initProtossAirship(ProtossAirship* protossAirship, const char *inputName, int inputHealth, int inputDamage,
                 int shield, int shieldRegenerateRate, enum AirShipType airShipType, int index);

void takeDamageProtoss(ProtossAirship* protossAirship, int damage);
void protossRegenerate(ProtossAirship* protossAirship);
#endif
