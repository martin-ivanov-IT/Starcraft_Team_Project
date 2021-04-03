#include"../include/TerranAirship.h"
#include"../include/Airship.h"
#include"../include/TerranAirship.h"
#include"../include/Defines.h"
void initTerranAirship(TerranAirship* terranAirship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    initAirship(terranAirship, airShipType, inputName, inputHealth, inputDamage, index);
}

void terranTakeDamage(int damage, TerranAirship* terranAirship, Vector* vector, int atackerId){
    baseTakeDamage(terranAirship, damage);
    
    if(!isAirshipAlive(terranAirship)){
        printDead(terranAirship,atackerId);
        vectorPop(vector);
        terranAirship = vectorBack(vector);
        if (damage > 0)
        {
            damage = (damage/8)*8;
            baseTakeDamage(terranAirship, damage);
        }
    }
}