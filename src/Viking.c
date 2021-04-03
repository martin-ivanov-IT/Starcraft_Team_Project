#include"../include/TerranAirship.h"
#include"../include/Airship.h"
#include"../include/Viking.h"
#include"../include/Defines.h"
void initViking(Viking* viking,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage){
    initAirship(viking, airShipType, inputName, inputHealth, inputDamage);
}

int produceDamageViking(enum AirShipType enemyAirShipType){
    int damage = VIKING_DAMAGE;
    if(enemyAirShipType == PHOENIX){
        damage = VIKING_DOUBLE_DAMAGE;
    }
    return damage;
}