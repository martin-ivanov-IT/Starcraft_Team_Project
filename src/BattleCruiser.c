#include <stdio.h>
#include <BattleCruiser.h>

void initBattleCruiser(BattleCruiser* battleCruiser,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    if(initAirship(battleCruiser, airShipType, inputName, inputHealth, inputDamage, index)){
        printf("ERROR: File \"BattleCruiser.c\",  initAirship()");
        exit(EXIT_FAILURE);
    }
}

int battleCruiseProduceDamage(int turn){
    if(turn < 0 ){
        errNo = 1;
    }
    if(!(turn%YAMATO_CANNON_LOADING_TURNS)){
        return BATTLE_BRUSER_POWER_DAMAGE;
    }
    errNo = 0;
    return BATTLE_BRUSER_DAMAGE;
}
