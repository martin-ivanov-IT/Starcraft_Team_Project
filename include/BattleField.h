#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_
#include "Defines.h"
#include "TerranAirship.h"
#include "TerranAirship.h"
#include "ProtossAirship.h"
#include <stdbool.h>

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
void printTerranHurt(TerranAirship *terranAirship);
void printProtossHurt(ProtossAirship *protossAirship);
void printKilledTerranByProtoss(ProtossAirship *protossAirship, int attackerID, int enemyID);
void printKilledProtossByTerran(TerranAirship *terranAirship, int attackerID, int enemyID);


#endif /* BATTLEFIELD_H_ */