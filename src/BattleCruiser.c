#include"../include/TerranAirship.h"
#include"../include/Airship.h"
#include"../include/BattleCruiser.h"
#include"../include/Defines.h"
int initBattleCruiser(BattleCruiser* battleCruiser,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    if (battleCruiser == NULL)
    {
        return 1;
    }
    if(initAirship(battleCruiser, airShipType, inputName, inputHealth, inputDamage, index)){
        exit(0);
    }
    
    return 0;
}
int battleCruiseProduceDamage(int turn, int* errNo){
    if(turn < 0 ){
        *errNo = 1;
    }
    if(!(turn%YAMATO_CANNON_LOADING_TURNS)){
        return BATTLE_BRUSER_POWER_DAMAGE;
    }
    *errNo = 0;
    return BATTLE_BRUSER_DAMAGE;
}
