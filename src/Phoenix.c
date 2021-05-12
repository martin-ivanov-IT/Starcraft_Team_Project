#include"../include/ProtossAirship.h"
#include"../include/Phoenix.h"
#include"../include/Airship.h"
#include"../include/Defines.h"
#include"../include/TerranAirship.h"
#include <stdio.h>


int initPhoenix(Phoenix* phoenix, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType, int index){
                
    if (phoenix == NULL)
    {
        return 1;
    }
    if(initProtossAirship(phoenix, inputName, inputHealth, inputDamage, inputShield, inputShieldRegenerateRate, airShipType, index)){
        perror("File \"Phoenix.c\",  initProtossAirship()");
        exit(0);
    }
    
    return 0;
}

int phoenixRegenerate(ProtossAirship* protossAirship){
    if (protossAirship == NULL)
    {
        return 1;
    }
    protossAirship->shield += protossAirship->shieldRegenerateRate;
    if(protossAirship->shield > PHOENIX_SHIELD){
            protossAirship->shield = PHOENIX_SHIELD;
    }
    return 0;
}