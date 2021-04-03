#ifndef Airship_H_
#define Airship_H_

#include "Defines.h"
typedef struct {
  enum AirShipType type;
  int ID;
  int health;
  int damage;
  char name[MAX_AIRSHIP_NAME_SIZE];
}Airship;

void initAirship(Airship* airship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index);
int baseProduceDamage(Airship* airship);
void baseTakeDamage(Airship* airship, int damage);
bool isAirshipAlive(Airship* airship);
void baseDealDamage(Airship* airship,int damage, int atackerID);
void printDead(Airship* airship, int attackerID);

#endif