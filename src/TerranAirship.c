#include"TerranAirship.h"

int initTerranAirship(TerranAirship* terranAirship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    if (terranAirship == NULL)
    {
        return 1;
    }
    if(initAirship(terranAirship, airShipType, inputName, inputHealth, inputDamage, index)){
        perror("File \"TerranAirship.c\",  initAirship()");
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
            perror("File \"TerranAirship.c\",  baseTakeDamage()");
            exit(0);
        }
        
        if(!isAirshipAlive(*lastOfTerran)){
            if(errNo){
                perror("File \"TerranAirship.c\",  isAirshipAlive()");
                exit(0);
            }
            if(printDead(atackerName, atackerID, (*lastOfTerran)->ID)){
                perror("File \"TerranAirship.c\",  printDead()");
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
