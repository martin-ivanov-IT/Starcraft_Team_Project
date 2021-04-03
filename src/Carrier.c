#include"../include/ProtossAirship.h"
#include"../include/Carrier.h"
#include"../include/Airship.h"
#include"../include/Defines.h"
void initCarrier(Carrier* carrier, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType){

    initProtossAirship((ProtossAirship*)carrier, inputName, inputHealth, inputDamage, inputShield, inputShieldRegenerateRate, airShipType);
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
