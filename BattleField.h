#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_
#include "Defines.h"
#include <stdbool.h>
#include "Airships.h"

#include "Vector.h"

typedef struct {
  Vector terranFleet;
  Vector protossFleet;
} BattleField;

void generateTerranFleet(BattleField *battleField, const char *terranFleetStr);
void generateProtossFleet(BattleField *battleField, const char *protossFleetStr);

void startBattle(BattleField *battleField);

void deinit(BattleField *battleField);

bool processTerranTurn(BattleField *battleField, int turn);
bool processProtossTurn(BattleField *battleField);

void printProtossAtack(TerranAirship* terranAirship);
void printTerranAtack(ProtossAirship* protossAirship);
void printDeadTerran(ProtossAirship* protossAirship,TerranAirship* lastOfTerran);
void printDeadProtoss(TerranAirship* terranAirship, ProtossAirship* lastOfProtoss);
bool isDamagedTerran(TerranAirship* terranAirship);

#endif /* BATTLEFIELD_H_ */
