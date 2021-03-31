#include "Defines.h"
#include "Airships.h"
#include "BattleField.h"
void initViking(TerranAirship* viking);
void initBattleCruser(TerranAirship* battleCruser);
void initTerranAirship(TerranAirship** terranAirship, char letter);
bool TerranAttack(ProtossAirship** protossAirship,BattleField * battleField,TerranAirship* terranAirship,int *lastProtossID,int attackerID);
void produceDamage(ProtossAirship* protossAirship, short damage);
bool isDamagedTerran(TerranAirship* terranAirship);
void printDeadProtoss(TerranAirship *terranAirship, int attackerID, int enemyID);
void printTerranAttack(int ID, ProtossAirship *protossAirship);
extern int turn;