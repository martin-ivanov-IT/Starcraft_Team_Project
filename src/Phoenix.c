
#include"Phoenix.h"
#include <stdio.h>


int initPhoenix(Phoenix* phoenix, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType, int index){
                
    if (phoenix == NULL)
    {
        return EXIT_FAILURE;
    }
    if(initProtossAirship(phoenix, inputName, inputHealth, inputDamage, inputShield, inputShieldRegenerateRate, airShipType, index)){
        fprintf(stderr,"File \"Phoenix.c\",  initProtossAirship()");
        exit(EXIT_FAILURE);
    }
    
    return EXIT_SUCCESS;
}

int phoenixRegenerate(ProtossAirship* protossAirship){
    if (protossAirship == NULL)
    {
        return EXIT_FAILURE;
    }
    protossAirship->shield += protossAirship->shieldRegenerateRate;
    if(protossAirship->shield > PHOENIX_SHIELD){
            protossAirship->shield = PHOENIX_SHIELD;
    }
    return EXIT_SUCCESS;
}