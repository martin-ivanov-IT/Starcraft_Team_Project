#include "Defines.h"
#include "Airships.h"
#include <stdlib.h>
#include <stdio.h>
#include"ProtossAirship.h"
#include "Vector.h"
#include "BattleField.h"
// Check ship type according input string and initialize Protoss Airship
void initProtossAirship(ProtossAirship** protossAirship, char letter){
    (*protossAirship) = malloc(sizeof(ProtossAirship));
    if(*protossAirship == NULL){
        fprintf(stderr, "error by initializing! Exiting...\n");
        exit(-1);
    }
    if(letter == 'p'){
        initPhoenix(*protossAirship);
    }
    else if(letter == 'c'){
        initCarrier(*protossAirship);
    }
    else{
        fprintf(stderr, "wrong Airship %c type for Protoss! Exiting...\n", letter);
        exit(-1);
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
bool ProtossAttack(TerranAirship** terranAirship, ProtossAirship* protossAirship,BattleField* battlefield,int atackerID, int* lastTerranID){
    int attacks;
   if(protossAirship->type==PHOENIX){
       attacks=1;
   }
   else if(protossAirship->type==CARRIER && protossAirship->health==CARRIER_HEALTH){
       attacks=MAX_INTERCEPTORS;
       }
    else if(protossAirship->type==CARRIER && protossAirship->health<CARRIER_HEALTH){
        attacks=DAMAGED_STATUS_INTERCEPTORS;
    }

    for(int i=0;i<attacks;i++){
            (*terranAirship)->health -= protossAirship->damage;
                if( (*terranAirship)->health <= 0){
                    // If Terran ship is killed, prints ships info, removes (free the memory) the killed ship and takes the last ship again
                    printDeadTerran(protossAirship,atackerID,battlefield->terranFleet.size-1);
                    vectorPop(&battlefield->terranFleet);
                    (*terranAirship)=(TerranAirship*)vectorBack(&battlefield->terranFleet);
                     if(battlefield->terranFleet.size == 0 ){
                        return true;                
                    }
                }     
        }

    *lastTerranID = battlefield->terranFleet.size - 1;
    return false;    
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
}


