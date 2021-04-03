#include"../include/TerranAirship.h"
#include"../include/Airship.h"
#include"../include/Viking.h"
#include"../include/Defines.h"
#include"../include/Vector.h"
#include"../include/ProtossAirship.h"
void initViking(Viking* viking,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    initAirship(viking, airShipType, inputName, inputHealth, inputDamage, index);
}

int produceDamageViking(enum AirShipType enemyAirShipType){
    int damage = VIKING_DAMAGE;
    if(enemyAirShipType == PHOENIX){
        damage = VIKING_DOUBLE_DAMAGE;
    }
    return damage;
}

void vikinngDealDamageToProtossAirship(Vector* protossFleet, ProtossAirship** lastOfProtoss, Viking* viking){
    int damage = produceDamageViking((*lastOfProtoss)->airship.type);
    takeDamageProtoss((*lastOfProtoss), damage);
    if(!isAirshipAlive(&(*lastOfProtoss)->airship)){
        printDead(viking, (*lastOfProtoss)->airship.ID);
        vectorPop(protossFleet);
        if(protossFleet->size == 0){
            return;
        }
        (*lastOfProtoss) = (ProtossAirship*)vectorBack(protossFleet);
    }
}