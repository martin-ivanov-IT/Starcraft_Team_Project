#include <stdio.h>
#include <BattleCruiser.h>

int initBattleCruiser(BattleCruiser* battleCruiser,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    if (battleCruiser == NULL)
    {
        return 1;
    }
    if(initAirship(battleCruiser, airShipType, inputName, inputHealth, inputDamage, index)){
        perror("File \"BattleCruiser.c\",  initAirship()");
        exit(0);
    }
    
    return 0;
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
