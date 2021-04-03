#include"../include/ProtossAirship.h"
#include"../include/Phoenix.h"
#include"../include/Airship.h"
#include"../include/Defines.h"
#include"../include/TerranAirship.h"


void initPhoenix(Phoenix* phoenix, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType, int index){

    initProtossAirship(phoenix, inputName, inputHealth, inputDamage, inputShield, inputShieldRegenerateRate, airShipType, index);
}

void phoenixDealDamageToTerranAirship(Vector* terranFleet,TerranAirship** lastOfTerran, Phoenix* phoenix){
    int damage = PHOENIX_DAMAGE;
    baseTakeDamage((*lastOfTerran), damage);
    if(!isAirshipAlive((*lastOfTerran))){
        printDead(&phoenix->airship, (*lastOfTerran)->ID);
        vectorPop(terranFleet);
        if(terranFleet->size == 0){
            return;
        }
        (*lastOfTerran) = (TerranAirship*)vectorBack(terranFleet);
    }
}