#include"../include/ProtossAirship.h"
#include"../include/Carrier.h"
#include"../include/Airship.h"
#include"../include/Defines.h"
void initCarrier(Carrier* carrier, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType, int index){

    initProtossAirship((ProtossAirship*)carrier, inputName, inputHealth, inputDamage, inputShield, inputShieldRegenerateRate, airShipType, index);
}

int carrierProduceDamage(Carrier* carrier){
    int damage = 0;
    if(carrier->airship.health < CARRIER_HEALTH){
        damage = CARRIER_DAMAGE * DAMAGED_STATUS_INTERCEPTORS;
    }
    else{
        damage = CARRIER_DAMAGE * MAX_INTERCEPTORS;
    }
    return damage;
}
void carrierDealDamageToTerranAirship(Vector* terranFleet, Carrier* carrier, TerranAirship** lastOfTerran){
    int damage = carrierProduceDamage(carrier);
    while (damage > 0)
    {
        int currentTerranHealth = (*lastOfTerran)->health;
        baseTakeDamage((*lastOfTerran), damage);
        damage -= currentTerranHealth;
        if(!isAirshipAlive((*lastOfTerran))){
        printDead(&carrier->airship, (*lastOfTerran)->ID);
        vectorPop(terranFleet);
        if(terranFleet->size == 0){
            break;
        }
        (*lastOfTerran) = (TerranAirship*)vectorBack(terranFleet);
        if(damage > 0){
            damage = damage/8 * 8;
        }
     }
    }
}
