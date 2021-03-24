#include "Phoenix.h"
#include "Defines.h"
#include "Airships.h"
#include <stdlib.h>

void initPhoenix(Phoenix** phoenix){
    (*phoenix) = malloc(sizeof(Phoenix));
    (*phoenix)->type = PHOENIX;
    (*phoenix)->health = PHOENIX_HEALTH;
    (*phoenix)->shield = PHOENIX_SHIELD;
    (*phoenix)->shieldRegenerateRate = PHOENIX_SHIELD_REGENERATE_RATE;
    (*phoenix)->demage = PHOENIX_DAMAGE;
}

void afterTurnPhoenix(Phoenix* phoenix){
    int regenerateValue = 20;
    int shieldMax = PHOENIX_SHIELD;
    if(phoenix->shield + regenerateValue >= shieldMax){
        phoenix->shield = shieldMax;
    }
    else{
        phoenix->shield += regenerateValue;
    }
}

void phoenixAtackViking(Viking* viking){
    viking->health -= PHOENIX_DAMAGE;
    if(viking->health < 0){
        viking->health = 0;
    }
}

void phoenixAtackBattleCruser(BattleCruser* battleCruser){
    battleCruser->health -= PHOENIX_DAMAGE;
    if(battleCruser->health < 0){
        battleCruser->health = 0;
    }
}