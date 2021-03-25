
#ifndef Airship_H_
#define Airship_H_
#include "Defines.h"

typedef struct {
  enum AirShipType type;
  int health;
  int demage;
  int shield;
  int shieldRegenerateRate;
} Airship;

void initAirship(char c, Airship* ship);

#endif
