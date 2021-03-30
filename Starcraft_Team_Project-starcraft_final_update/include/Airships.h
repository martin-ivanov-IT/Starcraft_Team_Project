#ifndef Airships_H_
#define Airships_H_

#include "Defines.h"

typedef struct {
  enum AirShipType type;
  short health;
  short damage;
  short shield;
  short shieldRegenerateRate;
  short attacks;
  char * name;
} ProtossAirship;

typedef struct {
  enum AirShipType type;
  short health;
  short damage;
  char * name;
} TerranAirship;

#endif