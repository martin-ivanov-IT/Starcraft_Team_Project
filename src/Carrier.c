#include"../include/ProtossAirship.h"
#include"../include/Carrier.h"
#include"../include/Airship.h"
#include"../include/Defines.h"
void initCarrier(Carrier* carrier, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType, int index){

    initProtossAirship((ProtossAirship*)carrier, inputName, inputHealth, inputDamage, inputShield, inputShieldRegenerateRate, airShipType, index);
}
// return count of intereptort
int getCarrierAtacks(Carrier* carrier){
    int attacks =MAX_INTERCEPTORS;
    if(carrier->airship.health < CARRIER_HEALTH){
        attacks = DAMAGED_STATUS_INTERCEPTORS;
    }
    return attacks;
}

void carrierRegenerate(ProtossAirship* protossAirship){
    protossAirship->shield += protossAirship->shieldRegenerateRate;
    if(protossAirship->shield > CARRIER_SHIELD){
            protossAirship->shield = CARRIER_SHIELD;
    }
}

