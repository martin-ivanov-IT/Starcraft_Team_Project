#include"../include/ProtossAirship.h"
#include"../include/Airship.h"
#include"../include/Defines.h"
#include"../include/Vector.h"
#include <stdio.h>
int initProtossAirship(ProtossAirship* protossAirship, const char *inputName, int inputHealth, int inputDamage,
                 int shield, int shieldRegenerateRate, enum AirShipType airShipType, int index){
                    if (protossAirship == NULL)
                    {
                        return 1;
                    }
                    if(initAirship(&protossAirship->airship, airShipType, inputName, inputHealth, inputDamage, index)){
                        perror("File \"ProtossAirship.c\",  initAirship()");
                        exit(0);
                    }
                     protossAirship->shield = shield;
                     protossAirship->shieldRegenerateRate = shieldRegenerateRate;
                     return 0;
                 }
                 
int takeDamageProtoss(ProtossAirship* protossAirship, int damage){
    // if (protossAirship == NULL)
    // {
    //     return 1;
    // }
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
    if (lastOfProtoss == NULL)
    {
        return 1;
    }
    if(takeDamageProtoss((*lastOfProtoss), damage)){
        perror("File \"ProtossAirship.c\",  takeDamageProtoss()");
        exit(0);
    }
    int errNo = 0;
    if(!isAirshipAlive(&(*lastOfProtoss)->airship, &errNo)){
        if(errNo){
            perror("File \"ProtossAirship.c\",  isAirshipAlive()");
            exit(0);
        }
        if(printDead(atackerName, atackerID, (*lastOfProtoss)->airship.ID)){
            perror("File \"ProtossAirship.c\",  printDead()");
            exit(0);
        }
        vectorPop(protossFleet);
        if(protossFleet->size == 0){
            return 0;
        }
        (*lastOfProtoss) = (ProtossAirship*)vectorBack(protossFleet);
    }
    return 0;
}
