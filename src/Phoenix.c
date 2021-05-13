
#include"Phoenix.h"
#include <stdio.h>


void initPhoenix(Phoenix* phoenix, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType, int index){
    if(initProtossAirship(phoenix, inputName, inputHealth, inputDamage, inputShield, inputShieldRegenerateRate, airShipType, index)){
        perror("File \"Phoenix.c\",  initProtossAirship()");
        exit(EXIT_FAILURE);
    }
}

int phoenixRegenerate(ProtossAirship *protossAirship){
    protossAirship->shield += protossAirship->shieldRegenerateRate;
    if(protossAirship->shield > PHOENIX_SHIELD){
            protossAirship->shield = PHOENIX_SHIELD;
    }
    return 0;
}