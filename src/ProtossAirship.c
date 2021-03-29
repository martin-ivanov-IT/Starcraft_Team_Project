#include "Defines.h"
#include "Airships.h"
#include <stdlib.h>
#include"ProtossAirship.h"

// Check ship type according input string and initialize Protoss Airship
void initProtossAirship(ProtossAirship** protossAirship, char letter){
    (*protossAirship) = malloc(sizeof(ProtossAirship));
    if(letter == 'p'){
        initPhoenix(*protossAirship);
    }
    else if(letter == 'c'){
        initCarrier(*protossAirship);
    }
}
// assign values (see Defines.h) to the ProtossAirship struct elements for Phoenix Airship
void initPhoenix(ProtossAirship* protossAirship){
    protossAirship->type = PHOENIX;
    protossAirship->health = (short)PHOENIX_HEALTH;
    protossAirship->shield = (short)PHOENIX_SHIELD;
    protossAirship->shieldRegenerateRate = (short)PHOENIX_SHIELD_REGENERATE_RATE;
    protossAirship->damage = (short)PHOENIX_DAMAGE;
    protossAirship->attacks = (short)PHOENIX_ATTACKS;
    protossAirship->name = "Phoenix";
}

// assign values (see Defines.h) to the ProtossAirship struct elements for Carrier Airship
void initCarrier(ProtossAirship* protossAirship){
    protossAirship->type = CARRIER;
    protossAirship->health = (short)CARRIER_HEALTH;
    protossAirship->shield = (short)CARRIER_SHIELD;
    protossAirship->shieldRegenerateRate = (short)CARRIER_SHIELD_REGENERATE_RATE;
    protossAirship->damage = (short)CARRIER_DAMAGE;
    protossAirship->attacks = (short)MAX_INTERCEPTORS;
    protossAirship->name = "Carrier";
}

// Protoss Airship produce attack until Terran Airship is killed or strikes are finished
void ProtossAttack(TerranAirship* terranAirship, ProtossAirship* protossAirship){
    int i;
    short countIterations =  protossAirship->attacks;
    for (i = 0; i < countIterations; i++)
    {
        terranAirship->health -= protossAirship->damage;
        protossAirship->attacks--;
        if(terranAirship->health <= 0){
            break;
        }
    }  
}

// Calculate number of strikes of the current attacking Protoss Airship
void updateProtossAttacks(ProtossAirship* protossAirship){
    if(protossAirship->type == PHOENIX){
        protossAirship->attacks = PHOENIX_ATTACKS;
    }
    else if(protossAirship->type == CARRIER){
        if(protossAirship->health == CARRIER_HEALTH){
            protossAirship->attacks = MAX_INTERCEPTORS;
        }
        else if(protossAirship->health < CARRIER_HEALTH){
            protossAirship->attacks = DAMAGED_STATUS_INTERCEPTORS;
        }
    }
}

// One function updateShield for both Protos ships
void regenarateShield(ProtossAirship* protossAirship){
    if(protossAirship->type == PHOENIX){
        if(protossAirship->shield + PHOENIX_SHIELD_REGENERATE_RATE >= PHOENIX_SHIELD){
            protossAirship->shield = PHOENIX_SHIELD;
        }
        else{
            protossAirship->shield += PHOENIX_SHIELD_REGENERATE_RATE;
        }
    }
    else if(protossAirship->type == CARRIER){
            if(protossAirship->shield + CARRIER_SHIELD_REGENERATE_RATE >= CARRIER_SHIELD){
                protossAirship->shield = CARRIER_SHIELD;
            }
            else{
                protossAirship->shield += CARRIER_SHIELD_REGENERATE_RATE;
            }
    }
    updateProtossAttacks(protossAirship);
}


