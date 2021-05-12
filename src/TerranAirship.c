#include"../include/TerranAirship.h"
#include"../include/Airship.h"
#include"../include/Carrier.h"
#include"../include/Defines.h"
int initTerranAirship(TerranAirship* terranAirship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    if (terranAirship == NULL)
    {
        return 1;
    }
    if(initAirship(terranAirship, airShipType, inputName, inputHealth, inputDamage, index)){
        exit(0);
    }
    return 0;
}

int terranDealDamageByCarrier(TerranAirship** lastOfTerran, Vector* terranFleet, int attacks, char* atackerName, int atackerID){
   if (lastOfTerran == NULL)
    {
        return 1;
    }
    for(int i=0;i<attacks;i++)
    {
        if(baseTakeDamage((*lastOfTerran), CARRIER_DAMAGE)){
            exit(0);
        }
        
        int errNo;
        if(!isAirshipAlive(*lastOfTerran,&errNo)){
            if(!errNo){
                exit(0);
            }
            if(printDead(atackerName, atackerID, (*lastOfTerran)->ID)){
               exit(0); 
            }
            vectorPop(terranFleet);
            if(terranFleet->size == 0){
                break;
            }
        (*lastOfTerran) = (TerranAirship*)vectorBack(terranFleet);
        
     }
    }
    return 0;
}
