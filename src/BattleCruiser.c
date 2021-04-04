#include"../include/TerranAirship.h"
#include"../include/Airship.h"
#include"../include/BattleCruiser.h"
#include"../include/Defines.h"
void initBattleCruiser(BattleCruiser* battleCruiser,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    initAirship(battleCruiser, airShipType, inputName, inputHealth, inputDamage, index);
}
int battleCruiseProduceDamage(int turn){
    if(!(turn%YAMATO_CANNON_LOADING_TURNS)){
        return BATTLE_BRUSER_POWER_DAMAGE;
    }
    return BATTLE_BRUSER_DAMAGE;
}
