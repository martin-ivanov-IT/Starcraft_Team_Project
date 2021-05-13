#include <stdio.h>
#include <BattleCruiser.h>

int initBattleCruiser(BattleCruiser* battleCruiser,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    if (battleCruiser == NULL)
    {
        return EXIT_FAILURE;
    }
    if(initAirship(battleCruiser, airShipType, inputName, inputHealth, inputDamage, index)){
        fprintf(stderr, "File \"BattleCruiser.c\",  initAirship()");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
int battleCruiseProduceDamage(int turn, int* errNo){
    if(turn < 0 ){
        *errNo = EXIT_FAILURE;
    }
    if(!(turn%YAMATO_CANNON_LOADING_TURNS)){
        return BATTLE_BRUSER_POWER_DAMAGE;
    }
    *errNo = EXIT_SUCCESS;
    return BATTLE_BRUSER_DAMAGE;
}
