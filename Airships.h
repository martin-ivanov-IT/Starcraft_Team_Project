#ifndef Airships_H_
#define Airships_H_

#include "Defines.h"

typedef struct {
  enum AirShipType type;
  enum AirShipDefines health;
  enum AirShipDefines demage;
} BattleCruser;

typedef struct {
  enum AirShipType type;
  enum AirShipDefines health;
  enum AirShipDefines demage;
  enum AirShipDefines shield;
  enum AirShipDefines shieldRegenerateRate;
  int interceptors;
} Carrier;

typedef struct {
  enum AirShipType type;
  enum AirShipDefines health;
  enum AirShipDefines demage;
  enum AirShipDefines shield;
  enum AirShipDefines shieldRegenerateRate;
} Phoenix;

typedef struct {
  enum AirShipType type;
  enum AirShipDefines health;
  enum AirShipDefines demage;
} Viking;

#endif