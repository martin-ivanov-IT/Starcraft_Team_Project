
#include"Viking.h"
#include <stdio.h>

void initViking(Viking *viking,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    if(initAirship(viking, airShipType, inputName, inputHealth, inputDamage, index)){
        printf("ERROR: File \"Viking.c\",  initAirship()");
        exit(EXIT_FAILURE);
    }
}

int vikingProduceDamage(enum AirShipType enemyAirShipType){
    int damage = VIKING_DAMAGE;
    if(enemyAirShipType == PHOENIX){
        damage = VIKING_DOUBLE_DAMAGE;
    }  
    errNo = 0;
    return damage;
}
