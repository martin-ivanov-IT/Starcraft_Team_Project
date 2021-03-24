#include "Defines.h"
#include "Airships.h"
#include "Carrier.h"
#include <stdlib.h>

void initCarrier(Carrier** carrier){
    (*carrier) = malloc(sizeof(Carrier));
    (*carrier)->type = CARRIER;
    (*carrier)->health = CARRIER_HEALTH;
    (*carrier)->shield = CARRIER_SHIELD;
    (*carrier)->shieldRegenerateRate = CARRIER_SHIELD_REGENERATE_RATE;
    (*carrier)->demage = CARRIER_DAMAGE;
    (*carrier)->interceptors = MAX_INTERCEPTORS;
}

void afterTurnCarrier(Carrier* carrier){
    if(carrier->shield + CARRIER_SHIELD_REGENERATE_RATE >= CARRIER_SHIELD){
        carrier->shield = CARRIER_SHIELD;
    }
    else{
        carrier->shield += CARRIER_SHIELD_REGENERATE_RATE;
    }
}

void updateInterceptors(Carrier* carrier){
    if(carrier->health < CARRIER_HEALTH){
        carrier->interceptors = DAMAGED_STATUS_INTERCEPTORS;
    }
    else{
        carrier->interceptors = MAX_INTERCEPTORS;
    }
}

void carrierAtackViking(Viking* viking, Carrier* carrier){
    int i;
    for (i = 0; i < carrier->interceptors; i++)
    {
        viking->health -= CARRIER_DAMAGE;
        carrier->interceptors--;
        if(viking->health<=0){
            break;
        }
    }  
}

void carrierAtackBattleCruser(BattleCruser* battleCruser, Carrier* carrier){
    int i;
    for (i = 0; i < carrier->interceptors; i++)
    {
        battleCruser->health -= carrier->demage;
        carrier->interceptors--;
        if(carrier->health<=0){
            break;
        }
    }
}