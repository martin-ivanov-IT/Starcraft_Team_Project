#ifndef Airship_H_
#define Airship_H_

#include "Defines.h"
#include"Vector.h"
#include <stdlib.h>
typedef struct {
  enum AirShipType type;
  int ID;
  int health;
  int damage;
  char name[MAX_AIRSHIP_NAME_SIZE];
}Airship;

int initAirship(Airship* airship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index);
int baseProduceDamage(Airship* airship);
int baseTakeDamage(Airship* airship, int damage);
bool isAirshipAlive(Airship* airship);
int baseDealDamage(Airship** lastAirship, Vector* army, int damage, char* atackerName,int atackerID);
int printDead(char* atackerName,int atackerID, int enemyID);

#endif