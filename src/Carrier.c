#include <stdio.h>
#include"Carrier.h"

void initCarrier(Carrier* carrier, const char *inputName, int inputHealth, int inputDamage,
                int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType, int index){
    if(initProtossAirship((ProtossAirship*)carrier, inputName, inputHealth, inputDamage, inputShield, inputShieldRegenerateRate, airShipType, index)){
        printf("ERROR: File \"Carrier.c\",  initProtossAirship()");
        exit(EXIT_FAILURE);
    }
}
// return count of intereptort
int getCarrierAtacks(Carrier *carrier){
    if (carrier == NULL){
        errNo = 1;
    }
    int attacks =MAX_INTERCEPTORS;
    if(carrier->airship.health < CARRIER_HEALTH){
        attacks = DAMAGED_STATUS_INTERCEPTORS;
    }
    errNo = 0;
    return attacks;
}

int carrierRegenerate(ProtossAirship* protossAirship){
    protossAirship->shield += protossAirship->shieldRegenerateRate;
    if(protossAirship->shield > CARRIER_SHIELD){
            protossAirship->shield = CARRIER_SHIELD;
    }
    return 0;
}

