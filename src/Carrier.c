#include"Carrier.h"

int initCarrier(Carrier* carrier, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType, int index){
    if (carrier == NULL)
    {
        return 1;
    }
    if(initProtossAirship((ProtossAirship*)carrier, inputName, inputHealth, inputDamage, inputShield, inputShieldRegenerateRate, airShipType, index)){
        perror("File \"Carrier.c\",  initProtossAirship()");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
// return count of intereptort
int getCarrierAtacks(Carrier* carrier, int* errNo){
    if (carrier == NULL)
    {
        *errNo = EXIT_FAILURE;
    }
    int attacks =MAX_INTERCEPTORS;
    if(carrier->airship.health < CARRIER_HEALTH){
        attacks = DAMAGED_STATUS_INTERCEPTORS;
    }
    *errNo = EXIT_SUCCESS;
    return attacks;
}

int carrierRegenerate(ProtossAirship* protossAirship){
    if (protossAirship == NULL)
    {
        return EXIT_FAILURE;
    }
    protossAirship->shield += protossAirship->shieldRegenerateRate;
    if(protossAirship->shield > CARRIER_SHIELD){
            protossAirship->shield = CARRIER_SHIELD;
    }
    return EXIT_SUCCESS;
}

