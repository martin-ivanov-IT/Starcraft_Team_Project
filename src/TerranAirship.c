#include"../include/TerranAirship.h"
#include"../include/Airship.h"
#include"../include/Carrier.h"
#include"../include/Defines.h"
void initTerranAirship(TerranAirship* terranAirship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    initAirship(terranAirship, airShipType, inputName, inputHealth, inputDamage, index);
}

void terranDealDamageByCarrier(TerranAirship** lastOfTerran, Vector* terranFleet, int attacks, char* atackerName, int atackerID){
   
    for(int i=0;i<attacks;i++)
    {
        baseTakeDamage((*lastOfTerran), CARRIER_DAMAGE);
        if(!isAirshipAlive((*lastOfTerran))){
        printDead(atackerName, atackerID, (*lastOfTerran)->ID);
        vectorPop(terranFleet);
        if(terranFleet->size == 0){
            break;
        }
        (*lastOfTerran) = (TerranAirship*)vectorBack(terranFleet);
        
     }
    }
}
