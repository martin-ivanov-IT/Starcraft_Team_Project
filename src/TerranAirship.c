#include"TerranAirship.h"
#include"stdio.h"

int initTerranAirship(TerranAirship* terranAirship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    if (terranAirship == NULL)
    {
        return EXIT_FAILURE;
    }
    if(initAirship(terranAirship, airShipType, inputName, inputHealth, inputDamage, index)){
        fprintf(stderr,"File \"TerranAirship.c\",  initAirship()");
        exit(EXIT_FAILURE);
    }
    return 0;
}

int terranDealDamageByCarrier(TerranAirship** lastOfTerran, Vector* terranFleet, int attacks, char* atackerName, int atackerID){
   if (lastOfTerran == NULL)
    {
        return EXIT_FAILURE;
    }
    for(int i=0;i<attacks;i++)
    {
        if(baseTakeDamage((*lastOfTerran), CARRIER_DAMAGE)){
            fprintf(stderr,"File \"TerranAirship.c\",  baseTakeDamage()");
            exit(EXIT_FAILURE);
        }
        
        int errNo;
        if(!isAirshipAlive(*lastOfTerran,&errNo)){
            if(errNo){
                fprintf(stderr,"File \"TerranAirship.c\",  isAirshipAlive()");
                exit(EXIT_FAILURE);
            }
            if(printDead(atackerName, atackerID, (*lastOfTerran)->ID)){
                fprintf(stderr,"File \"TerranAirship.c\",  printDead()");
               exit(EXIT_FAILURE); 
            }
            vectorPop(terranFleet);
            if(terranFleet->size == 0){
                break;
            }
        (*lastOfTerran) = (TerranAirship*)vectorBack(terranFleet);
        
     }
    }
    return EXIT_SUCCESS;
}
