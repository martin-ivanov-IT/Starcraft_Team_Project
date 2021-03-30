#include "Defines.h"
#include "Airships.h"
#include "BattleField.h"
void initProtossAirship(ProtossAirship** protossAirship, char letter);
void initPhoenix(ProtossAirship* protossAirship);
void initCarrier(ProtossAirship* protossAirship);
bool ProtossAttack(TerranAirship** terranAirship, ProtossAirship* protossAirship,BattleField * battlefield,int atackerID, int* lastTerranID); 
void regenarateShield(ProtossAirship* protossAirship);
void updateProtossAttacks(ProtossAirship* protossAirship);
void printDeadTerran(ProtossAirship *protossAirship, int attackerID, int enemyID);
