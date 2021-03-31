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


// returns true when ProtossFleet has no ships left, else return false
bool ProtossAttack(TerranAirship** terranAirship, ProtossAirship* protossAirship,BattleField* battlefield,int atackerID, int* lastTerranID){
    setProtossAttacks(protossAirship);
    // Protoss Airship produce attack until strikes are finished
    for(int i=0;i<protossAirship->attacks;i++){
        (*terranAirship)->health -= protossAirship->damage;
        // If Terran ship is killed, updates the last Terran ship ID, prints info who killed who, removes (free the memory) the killed ship and takes the last ship again
        if( (*terranAirship)->health <= 0){
            *lastTerranID = battlefield->terranFleet.size - 1;
            printDeadTerran(protossAirship,atackerID,*lastTerranID);
            vectorPop(&battlefield->terranFleet);
            (*terranAirship)=(TerranAirship*)vectorBack(&battlefield->terranFleet);
            // returns true when ProtossFleet has no ships left
            if(battlefield->terranFleet.size == 0 ){
            return true;                
            }              
        }     
    }
    //updates the last Terran ship ID
    *lastTerranID = battlefield->terranFleet.size - 1;
    return false;    
}

// Calculate number of strikes of the current attacking Protoss Airship
void setProtossAttacks(ProtossAirship* protossAirship){
    if(protossAirship->type==CARRIER && protossAirship->health==CARRIER_HEALTH){
       protossAirship->attacks=MAX_INTERCEPTORS;
       }
    else if(protossAirship->type==CARRIER && protossAirship->health<CARRIER_HEALTH){
        protossAirship->attacks=DAMAGED_STATUS_INTERCEPTORS;
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
}

void printDeadTerran(ProtossAirship *protossAirship, int attackerID, int enemyID)
{
  printf("%s with ID: %d killed enemy airship with ID: %d\n", protossAirship->name, attackerID, enemyID);
}

void printProtossAttack(int ID, TerranAirship *terranAirship)
{
  printf("Last Terran AirShip with ID: %d has %d health left\n", ID, terranAirship->health);
}
