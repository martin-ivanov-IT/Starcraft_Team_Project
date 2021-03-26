#ifndef Airships_H_
#define Airships_H_

#include "Defines.h"

typedef struct {
  enum AirShipType type;
  int health;
  int demage;
  int shield;
  int shieldRegenerateRate;
  int atacks;
} ProtossAirship;

typedef struct {
  enum AirShipType type;
  int health;
  int demage;
} TerranAirship;

#endif