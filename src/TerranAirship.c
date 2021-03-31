#include "Defines.h"
#include "Airships.h"
#include <stdlib.h>
#include <stdio.h>
#include "TerranAirship.h"
#include "BattleField.h"
// Check ship type according input string and initialize 
void initTerranAirship(TerranAirship** terranAirship, char letter){
    (*terranAirship) = malloc(sizeof(TerranAirship));

    if(*terranAirship == NULL){
        fprintf(stderr, "error by initializing! Exiting...\n");
        exit(-1);
    }

    if(letter == 'v'){
        initViking(*terranAirship);
    }
    else if(letter == 'b'){
        initBattleCruser(*terranAirship);
    }
    else{
        fprintf(stderr, "wrong Airship %c type for Terran! Exiting...\n", letter);
        exit(-1);
    }
}
// assign values (see Defines.h) to the TerranAirship struct elements for Viking Airship
void initViking(TerranAirship* viking){
    viking->type = VIKING;
    viking->health = (short)VIKING_HEALTH;
    viking->damage = (short)VIKING_DAMAGE;
    viking->name = "Viking";
}
// assign values (see Defines.h) to the TerranAirship struct elements for Battle Cruser Airship
void initBattleCruser(TerranAirship* battleCruser){
    battleCruser->type = BATTLE_CRUSER;
    battleCruser->health = (short)BATTLE_CRUSER_HEALTH;
    battleCruser->damage = (short)BATTLE_BRUSER_DAMAGE;
    battleCruser->name = "BattleCruser";
}
// calculate damage variable according to ships involved and the turn number and produce attack
bool TerranAttack(ProtossAirship** protossAirship,BattleField * battleField,TerranAirship* terranAirship,int *lastProtossID,int attackerID){
    
    short damage = terranAirship->damage;
    if((*protossAirship)->type == PHOENIX && terranAirship->type == VIKING){
        damage = VIKING_DOUBLE_DAMAGE;
    }

    if(terranAirship->type == BATTLE_CRUSER && !(turn%=YAMATO_CANNON_LOADING_TURNS)){
        damage = BATTLE_BRUSER_POWER_DAMAGE;
    }

    produceDamage((*protossAirship), damage);
    if ((*protossAirship)->health <= 0)
    {
      *lastProtossID=battleField->protossFleet.size - 1;
      printDeadProtoss(terranAirship, attackerID, *lastProtossID);
      vectorPop(&battleField->protossFleet);
      (*protossAirship) = (ProtossAirship *)vectorBack(&battleField->protossFleet);
      if (battleField->protossFleet.size == 0)
      {
        return true;
      }
    }
    *lastProtossID=battleField->protossFleet.size - 1;
    return false;
}
// decrease enemy shield and/or health values according to damage
void produceDamage(ProtossAirship* protossAirship, short damage){

    if(protossAirship->shield >= damage){
        protossAirship->shield -= damage;
    }
    else{
        short demageToHealth = damage - protossAirship->shield; 
        protossAirship->shield = 0;
        protossAirship->health -= demageToHealth;
    }
}

void printTerranAttack(int ID, ProtossAirship *protossAirship)
{
  printf("Last Protoss AirShip with ID: %d has %d health and %d shield left\n", ID, protossAirship->health, protossAirship->shield);
}

void printDeadProtoss(TerranAirship *terranAirship, int attackerID, int enemyID)
{
  printf("%s with ID: %d killed enemy airship with ID: %d\n", terranAirship->name, attackerID, enemyID);
}