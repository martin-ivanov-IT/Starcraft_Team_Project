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
    if(phoenix->shield + PHOENIX_SHIELD_REGENERATE_RATE >= PHOENIX_SHIELD){
        phoenix->shield = PHOENIX_SHIELD;
    }
    else{
        phoenix->shield += PHOENIX_SHIELD_REGENERATE_RATE;
    }
}

void phoenixAtackViking(Viking* viking){
    viking->health -= PHOENIX_DAMAGE;
}

void phoenixAtackBattleCruser(BattleCruser* battleCruser){
    battleCruser->health -= PHOENIX_DAMAGE;
}