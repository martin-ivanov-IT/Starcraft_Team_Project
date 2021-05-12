#ifndef ProtossAirship_H_
#define ProtossAirship_H_
#include"Airship.h"

typedef struct {
  Airship airship;
  int shield;
  int shieldRegenerateRate;
}ProtossAirship;

int initProtossAirship(ProtossAirship* protossAirship, const char *inputName, int inputHealth, int inputDamage,
                 int shield, int shieldRegenerateRate, enum AirShipType airShipType, int index);

int takeDamageProtoss(ProtossAirship* protossAirship, int damage);
int protossDealDamage(ProtossAirship** lastOfProtoss, Vector* protossFleet, int damage, char* atackerName, int atackerID);
#endif
