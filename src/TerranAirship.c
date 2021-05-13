#include <stdio.h>
#include"TerranAirship.h"

int initTerranAirship(TerranAirship *terranAirship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    if(initAirship(terranAirship, airShipType, inputName, inputHealth, inputDamage, index)){
        printf("ERROR: File \"TerranAirship.c\",  initAirship()");
        exit(EXIT_FAILURE);
    }
    return 0;
}

int terranDealDamageByCarrier(TerranAirship **lastOfTerran, Vector *terranFleet, int attacks, char *atackerName, int atackerID){
   if (lastOfTerran == NULL){
        return 1;
    }
    for(int i=0;i<attacks;i++){
        if(baseTakeDamage((*lastOfTerran), CARRIER_DAMAGE)){
            printf("ERROR: File \"TerranAirship.c\",  baseTakeDamage()");
            exit(EXIT_FAILURE);
        }
        if(!isAirshipAlive(*lastOfTerran)){
            if(errNo){
                printf("ERROR: File \"TerranAirship.c\",  isAirshipAlive()");
                exit(EXIT_FAILURE);
            }
            printDead(atackerName, atackerID, (*lastOfTerran)->ID);
            vectorPop(terranFleet);
            if(terranFleet->size == 0){
                break;
            }
        (*lastOfTerran) = (TerranAirship*)vectorBack(terranFleet);
        }
    }
    return 0;
}
