#include"../include/TerranAirship.h"
#include"../include/Airship.h"
#include"../include/BattleCruiser.h"
#include"../include/Defines.h"
void initBattleCruiser(BattleCruiser* battleCruiser,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    initAirship(battleCruiser, airShipType, inputName, inputHealth, inputDamage, index);
}
int produceDamageBattleCruiser(int turn){
    if(!(turn%YAMATO_CANNON_LOADING_TURNS)){
        return BATTLE_BRUSER_POWER_DAMAGE;
    }
    return BATTLE_BRUSER_DAMAGE;
}

void battleCruiserDealDamageToProtossAirship(Vector* protossFleet,ProtossAirship** lastOfProtoss, int turn, BattleCruiser* battleCruiser){
     int damage = produceDamageBattleCruiser(turn);
     takeDamageProtoss((*lastOfProtoss), damage);
     if(!isAirshipAlive(&(*lastOfProtoss)->airship)){
        printDead(battleCruiser,(*lastOfProtoss)->airship.ID);
        vectorPop(protossFleet);
        if(protossFleet->size == 0){
            return;
        }
        (*lastOfProtoss) = (ProtossAirship*)vectorBack(protossFleet);
     }
}