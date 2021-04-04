#include"../include/ProtossAirship.h"
#include"../include/Phoenix.h"
#include"../include/Airship.h"
#include"../include/Defines.h"
#include"../include/TerranAirship.h"


void initPhoenix(Phoenix* phoenix, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType, int index){

    initProtossAirship(phoenix, inputName, inputHealth, inputDamage, inputShield, inputShieldRegenerateRate, airShipType, index);
}

void phoenixRegenerate(ProtossAirship* protossAirship){
    protossAirship->shield += protossAirship->shieldRegenerateRate;
    if(protossAirship->shield > PHOENIX_SHIELD){
            protossAirship->shield = PHOENIX_SHIELD;
    }
}