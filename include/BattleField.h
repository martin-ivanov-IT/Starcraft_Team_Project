#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_
#include "TerranAirship.h"
#include "ProtossAirship.h"


typedef struct {
  Vector terranFleet;
  Vector protossFleet;
} BattleField;

int generateTerranFleet(BattleField *battleField, const char *terranFleetStr);
int generateProtossFleet(BattleField *battleField, const char *protossFleetStr);

int startBattle(BattleField *battleField);

int deinit(BattleField *battleField);

bool processTerranTurn(BattleField *battleField, int turn);
bool processProtossTurn(BattleField *battleField);
void printTerranHurt(TerranAirship *terranAirship);
void printProtossHurt(ProtossAirship *protossAirship);
void printKilledTerranByProtoss(ProtossAirship *protossAirship, int attackerID, int enemyID);
void printKilledProtossByTerran(TerranAirship *terranAirship, int attackerID, int enemyID);


#endif /* BATTLEFIELD_H_ */