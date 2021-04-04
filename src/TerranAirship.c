#include"../include/TerranAirship.h"
#include"../include/Airship.h"
#include"../include/Carrier.h"
#include"../include/Defines.h"
void initTerranAirship(TerranAirship* terranAirship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    initAirship(terranAirship, airShipType, inputName, inputHealth, inputDamage, index);
}

void terranDealDamageByCarrier(TerranAirship** lastOfTerran, Vector* terranFleet, int damage, char* atackerName, int atackerID){
    while (damage > 0)
    {
        int currentTerranHealth = (*lastOfTerran)->health;
        baseTakeDamage((*lastOfTerran), damage);
        damage -= currentTerranHealth;
        if(!isAirshipAlive((*lastOfTerran))){
        printDead(atackerName, atackerID, (*lastOfTerran)->ID);
        vectorPop(terranFleet);
        if(terranFleet->size == 0){
            break;
        }
        (*lastOfTerran) = (TerranAirship*)vectorBack(terranFleet);
        if(damage > 0){
            damage = damage/8 * 8;
        }
     }
    }
}
