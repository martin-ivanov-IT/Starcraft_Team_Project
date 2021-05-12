#include"../include/TerranAirship.h"
#include"../include/Airship.h"
#include"../include/Viking.h"
#include"../include/Defines.h"
#include"../include/Vector.h"
#include"../include/ProtossAirship.h"
int initViking(Viking* viking,  enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    if (viking == NULL)
    {
        return 1;
    }
    if(initAirship(viking, airShipType, inputName, inputHealth, inputDamage, index)){
        exit(0);
    }
    return 0;
}

int vikingProduceDamage(enum AirShipType enemyAirShipType, int* errNo){
    int damage = VIKING_DAMAGE;
    if(enemyAirShipType == PHOENIX){
        damage = VIKING_DOUBLE_DAMAGE;
    }
    *errNo = 0;
    return damage;
}
