#include"../include/ProtossAirship.h"
#include"../include/Carrier.h"
#include"../include/Airship.h"
#include"../include/Defines.h"
int initCarrier(Carrier* carrier, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType, int index){
    if (carrier == NULL)
    {
        return 1;
    }
    if(initProtossAirship((ProtossAirship*)carrier, inputName, inputHealth, inputDamage, inputShield, inputShieldRegenerateRate, airShipType, index)){
        exit(0);
    }
    
    return 0;
}
// return count of intereptort
int getCarrierAtacks(Carrier* carrier, int* errNo){
    if (carrier == NULL)
    {
        *errNo = 1;
    }
    int attacks =MAX_INTERCEPTORS;
    if(carrier->airship.health < CARRIER_HEALTH){
        attacks = DAMAGED_STATUS_INTERCEPTORS;
    }
    *errNo = 0;
    return attacks;
}

int carrierRegenerate(ProtossAirship* protossAirship){
    if (protossAirship == NULL)
    {
        return 1;
    }
    protossAirship->shield += protossAirship->shieldRegenerateRate;
    if(protossAirship->shield > CARRIER_SHIELD){
            protossAirship->shield = CARRIER_SHIELD;
    }
    return 0;
}

