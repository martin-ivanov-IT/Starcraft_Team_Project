#include "Defines.h"
#include "Airships.h"
#include <stdlib.h>
#include "TerranAirship.h"

void initTerranAirship(TerranAirship** terranAirship, char letter){
    (*terranAirship) = malloc(sizeof(TerranAirship));
    if(letter == 'v'){
        initViking(*terranAirship);
    }
    else if(letter == 'b'){
        initBattleCruser(*terranAirship);
    }
}

void initViking(TerranAirship* viking){
    viking->type = VIKING;
    viking->health = (int)VIKING_HEALTH;
    viking->demage = (int)VIKING_DAMAGE;
}

void initBattleCruser(TerranAirship* battleCruser){
    battleCruser->type = BATTLE_CRUSER;
    battleCruser->health = (int)BATTLE_CRUSER_HEALTH;
    battleCruser->demage = (int)BATTLE_BRUSER_DAMAGE;
}

void TerranAtack(ProtossAirship* protossAirship, TerranAirship* terranAirship, int turn){
    int demage = terranAirship->demage;
    if(protossAirship->type == PHOENIX && terranAirship->type == VIKING){
        demage = VIKING_DOUBLE_DAMAGE;
    }

    if(terranAirship->type == BATTLE_CRUSER && !(turn%=YAMATO_CANNON_LOADING_TURNS)){
        demage = BATTLE_BRUSER_POWER_DAMAGE;
    }

    produceDamage(protossAirship, demage);
}

void produceDamage(ProtossAirship* protossAirship, int demage){

    if(protossAirship->shield >= demage){
        protossAirship->shield -= demage;
    }
    else{
        int demageToHealth = demage - protossAirship->shield;
        protossAirship->shield = 0;
        protossAirship->health -= demageToHealth;
    }
}

bool isDamagedTerran(TerranAirship* terranAirship){
  if(terranAirship->type == VIKING){
    if(terranAirship->health < VIKING_HEALTH){
      return true;
    }
    else{
      return false;
    }
  }
  else if(terranAirship->type == BATTLE_CRUSER){
      if(terranAirship->health < BATTLE_CRUSER_HEALTH){   
          return true;
      }
      else{
        return false;
      }
    }
}

