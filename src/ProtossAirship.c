#include"../include/ProtossAirship.h"
#include"../include/Airship.h"
#include"../include/Defines.h"
#include"../include/Vector.h"
int initProtossAirship(ProtossAirship* protossAirship, const char *inputName, int inputHealth, int inputDamage,
                 int shield, int shieldRegenerateRate, enum AirShipType airShipType, int index){
                    if (protossAirship == NULL)
                    {
                        return 1;
                    }
                    if(initAirship(&protossAirship->airship, airShipType, inputName, inputHealth, inputDamage, index)){
                        exit(0);
                    }
                     protossAirship->shield = shield;
                     protossAirship->shieldRegenerateRate = shieldRegenerateRate;
                     return 0;
                 }
                 
int takeDamageProtoss(ProtossAirship* protossAirship, int damage){
    if (protossAirship == NULL)
    {
        return 1;
    }
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
        exit(0);
    }
    int errNo;
    if(!isAirshipAlive(&(*lastOfProtoss)->airship, &errNo)){
        if(!errNo){
            exit(0);
        }
        if(printDead(atackerName, atackerID, (*lastOfProtoss)->airship.ID)){
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
