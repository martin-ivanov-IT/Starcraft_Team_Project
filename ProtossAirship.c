#include "Defines.h"
#include "Airships.h"
#include <stdlib.h>
#include"ProtossAirship.h"

void initProtossAirship(ProtossAirship** protossAirship, char letter){
    (*protossAirship) = malloc(sizeof(ProtossAirship));
    if(letter == 'p'){
        initPhoenix(*protossAirship);
    }
    else if(letter == 'c'){
        initCarrier(*protossAirship);
    }
}

void initPhoenix(ProtossAirship* protossAirship){
    protossAirship->type = PHOENIX;
    protossAirship->health = (int)PHOENIX_HEALTH;
    protossAirship->shield = (int)PHOENIX_SHIELD;
    protossAirship->shieldRegenerateRate = (int)PHOENIX_SHIELD_REGENERATE_RATE;
    protossAirship->demage = (int)PHOENIX_DAMAGE;
    protossAirship->atacks = (int)PHOENIX_ATACKS;
}

void initCarrier(ProtossAirship* protossAirship){
    protossAirship->type = CARRIER;
    protossAirship->health = (int)CARRIER_HEALTH;
    protossAirship->shield = (int)CARRIER_SHIELD;
    protossAirship->shieldRegenerateRate = (int)CARRIER_SHIELD_REGENERATE_RATE;
    protossAirship->demage = (int)CARRIER_DAMAGE;
    protossAirship->atacks = (int)MAX_INTERCEPTORS;
}

void ProtossAtack(TerranAirship* terranAirship, ProtossAirship* protossAirship){
    int i;
    int countIterations =  protossAirship->atacks;
    for (i = 0; i < countIterations; i++)
    {
        terranAirship->health -= protossAirship->demage;
        protossAirship->atacks--;
        if(terranAirship->health <= 0){
            break;
        }
    }  
}

void updateProtossAtacks(ProtossAirship* protossAirship){
    if(protossAirship->type == PHOENIX){
        protossAirship->atacks = PHOENIX_ATACKS;
    }
    else if(protossAirship->type == CARRIER){
        if(protossAirship->health == CARRIER_HEALTH){
            protossAirship->atacks = MAX_INTERCEPTORS;
        }
        else if(protossAirship->health < CARRIER_HEALTH){
            protossAirship->atacks = DAMAGED_STATUS_INTERCEPTORS;
        }
    }
}

void ProtosAfterTurn(ProtossAirship* protossAirship){
    if(protossAirship->type == PHOENIX){
        updatePhoenixShield(protossAirship);
    }
    else if(protossAirship->type == CARRIER){
        updateCarrierShield(protossAirship);
    }
    updateProtossAtacks(protossAirship);
}

void updatePhoenixShield(ProtossAirship* protossAirship){
    if(protossAirship->shield + PHOENIX_SHIELD_REGENERATE_RATE >= PHOENIX_SHIELD){
        protossAirship->shield = PHOENIX_SHIELD;
    }
    else{
        protossAirship->shield += PHOENIX_SHIELD_REGENERATE_RATE;
    }
}

void updateCarrierShield(ProtossAirship* protossAirship){
    if(protossAirship->shield + CARRIER_SHIELD_REGENERATE_RATE >= CARRIER_SHIELD){
        protossAirship->shield = CARRIER_SHIELD;
    }
    else{
        protossAirship->shield += CARRIER_SHIELD_REGENERATE_RATE;
    }
}

bool isDamagedProtoss(ProtossAirship* protossAirship){
  if(protossAirship->type == PHOENIX){
    if(protossAirship->shield < PHOENIX_SHIELD){
      return true;
    }
    else{
      return false;
    }
  }
  else if(protossAirship->type == CARRIER){
      if(protossAirship->shield < CARRIER_SHIELD){   
          return true;
      }
      else{
        return false;
      }
    }
}


