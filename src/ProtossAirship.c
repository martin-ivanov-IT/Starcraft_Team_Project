#include"ProtossAirship.h"
#include <stdio.h>
int initProtossAirship(ProtossAirship* protossAirship, const char *inputName, int inputHealth, int inputDamage,
                 int shield, int shieldRegenerateRate, enum AirShipType airShipType, int index){
                    if (protossAirship == NULL)
                    {
                        return EXIT_SUCCESS;
                    }
                    if(initAirship(&protossAirship->airship, airShipType, inputName, inputHealth, inputDamage, index)){
                        perror("File \"ProtossAirship.c\",  initAirship()");
                        exit(EXIT_FAILURE);
                    }
                     protossAirship->shield = shield;
                     protossAirship->shieldRegenerateRate = shieldRegenerateRate;
                     return EXIT_SUCCESS;
                 }
                 
int takeDamageProtoss(ProtossAirship* protossAirship, int damage){
    if (protossAirship == NULL)
    {
        return EXIT_FAILURE;
    }
   if(protossAirship->shield >= damage){
       protossAirship->shield -= damage;
   }
   else{
       int damageToHealth = damage - protossAirship->shield;
       protossAirship->shield = 0;
       protossAirship->airship.health -= damageToHealth;
   }
   return EXIT_SUCCESS;
}

int protossDealDamage(ProtossAirship** lastOfProtoss, Vector* protossFleet, int damage, char* atackerName, int atackerID){
    if (lastOfProtoss == NULL)
    {
        return EXIT_SUCCESS;
    }
    if(takeDamageProtoss((*lastOfProtoss), damage)){
        perror("File \"ProtossAirship.c\",  takeDamageProtoss()");
        exit(EXIT_FAILURE);
    }
    int errNo = 0;
    if(!isAirshipAlive(&(*lastOfProtoss)->airship, &errNo)){
        if(errNo){
            perror("File \"ProtossAirship.c\",  isAirshipAlive()");
            exit(EXIT_FAILURE);
        }
        if(printDead(atackerName, atackerID, (*lastOfProtoss)->airship.ID)){
            perror("File \"ProtossAirship.c\",  printDead()");
            exit(EXIT_FAILURE);
        }
        vectorPop(protossFleet);
        if(protossFleet->size == 0){
            return EXIT_FAILURE;
        }
        (*lastOfProtoss) = (ProtossAirship*)vectorBack(protossFleet);
    }
    return EXIT_SUCCESS;
}
