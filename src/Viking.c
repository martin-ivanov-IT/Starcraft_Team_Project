
#include"Viking.h"
#include <stdio.h>
int initViking(Viking* viking,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    if (viking == NULL)
    {
        return EXIT_SUCCESS;
    }
    if(initAirship(viking, airShipType, inputName, inputHealth, inputDamage, index)){
        perror("File \"Viking.c\",  initAirship()");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

int vikingProduceDamage(enum AirShipType enemyAirShipType, int* errNo){
    int damage = VIKING_DAMAGE;
    if(enemyAirShipType == PHOENIX){
        damage = VIKING_DOUBLE_DAMAGE;
    }
    
    *errNo = EXIT_SUCCESS;
    
    return damage;
}
