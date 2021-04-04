#include"../include/ProtossAirship.h"
#include"../include/Airship.h"
#include"../include/Defines.h"
#include"../include/Vector.h"
void initProtossAirship(ProtossAirship* protossAirship, const char *inputName, int inputHealth, int inputDamage,
                 int shield, int shieldRegenerateRate, enum AirShipType airShipType, int index){
                     initAirship(&protossAirship->airship, airShipType, inputName, inputHealth, inputDamage, index);
                     protossAirship->shield = shield;
                     protossAirship->shieldRegenerateRate = shieldRegenerateRate;
                 }
                 
void takeDamageProtoss(ProtossAirship* protossAirship, int damage){
   if(protossAirship->shield >= damage){
       protossAirship->shield -= damage;
   }
   else{
       int damageToHealth = damage - protossAirship->shield;
       protossAirship->shield = 0;
       protossAirship->airship.health -= damageToHealth;
   }
}

void protossDealDamage(ProtossAirship** lastOfProtoss, Vector* protossFleet, int damage, char* atackerName, int atackerID){
    takeDamageProtoss((*lastOfProtoss), damage);
    if(!isAirshipAlive(&(*lastOfProtoss)->airship)){
        printDead(atackerName, atackerID, (*lastOfProtoss)->airship.ID);
        vectorPop(protossFleet);
        if(protossFleet->size == 0){
            return;
        }
        (*lastOfProtoss) = (ProtossAirship*)vectorBack(protossFleet);
    }
}
