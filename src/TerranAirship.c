#include"../include/TerranAirship.h"
#include"../include/Airship.h"
#include"../include/Defines.h"
void initTerranAirship(TerranAirship* terranAirship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage){
    initAirship(terranAirship, airShipType, inputName, inputHealth, inputDamage);
}