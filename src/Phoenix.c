#include"../include/ProtossAirship.h"
#include"../include/Phoenix.h"
#include"../include/Airship.h"
#include"../include/Defines.h"

void initPhoenix(Phoenix* phoenix, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType){

    initProtossAirship(phoenix, inputName, inputHealth, inputDamage, inputShield, inputShieldRegenerateRate, airShipType);
}