#include"../include/ProtossAirship.h"
#include"../include/Airship.h"
#include"../include/Defines.h"
void initProtossAirship(ProtossAirship* protossAirship, const char *inputName, int inputHealth, int inputDamage,
                 int shield, int shieldRegenerateRate, enum AirShipType airShipType, int index){
                     initAirship(&protossAirship->airship, airShipType, inputName, inputHealth, inputDamage, index);
                     protossAirship->shield = shield;
                     protossAirship->shieldRegenerateRate = shieldRegenerateRate;
                 }
void protossRegenerate(ProtossAirship* protossAirship){
    protossAirship->shield += protossAirship->shieldRegenerateRate;
    if(protossAirship->airship.type == PHOENIX){
        if(protossAirship->shield > PHOENIX_SHIELD){
            protossAirship->shield = PHOENIX_SHIELD;
        }
    }
    else if(protossAirship->airship.type == CARRIER){
        if(protossAirship->shield > CARRIER_SHIELD){
            protossAirship->shield = CARRIER_SHIELD;
        }
    }
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
