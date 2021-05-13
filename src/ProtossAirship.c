#include"ProtossAirship.h"
#include <stdio.h>

int initProtossAirship(ProtossAirship* protossAirship, const char *inputName, int inputHealth, int inputDamage,
                 int shield, int shieldRegenerateRate, enum AirShipType airShipType, int index){
    if(initAirship(&protossAirship->airship, airShipType, inputName, inputHealth, inputDamage, index)){
        printf("ERROR: File \"ProtossAirship.c\",  initAirship()");
        exit(EXIT_FAILURE);
    }
    protossAirship->shield = shield;
    protossAirship->shieldRegenerateRate = shieldRegenerateRate;
return 0;
}
                 
int takeDamageProtoss(ProtossAirship* protossAirship, int damage){
   if(protossAirship->shield >= damage){
       protossAirship->shield -= damage;
   }
   else{
       int damageToHealth = damage - protossAirship->shield;
       protossAirship->shield = 0;
       protossAirship->airship.health -= damageToHealth;
   }
   return 0;
}

int protossDealDamage(ProtossAirship** lastOfProtoss, Vector* protossFleet, int damage, char* atackerName, int atackerID){
    if(takeDamageProtoss((*lastOfProtoss), damage)){
        printf("ERROR: File \"ProtossAirship.c\",  takeDamageProtoss()");
        exit(EXIT_FAILURE);
    }
    errNo = 0;
    if(!isAirshipAlive(&(*lastOfProtoss)->airship)){
        if(errNo){
            printf("ERROR: File \"ProtossAirship.c\",  isAirshipAlive()");
            exit(EXIT_FAILURE);
        }
        if(printDead(atackerName, atackerID, (*lastOfProtoss)->airship.ID)){
            printf("ERROR: File \"ProtossAirship.c\",  printDead()");
            exit(EXIT_FAILURE);
        }
        vectorPop(protossFleet);
        if(protossFleet->size == 0){
            return 0;
        }
        (*lastOfProtoss) = (ProtossAirship*)vectorBack(protossFleet);
    }
    return 0;
}
