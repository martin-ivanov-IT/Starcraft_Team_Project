#include"../include/Airship.h"
#include"../include/Defines.h"
#include <string.h>
#include <stdio.h>

void initAirship(Airship* airship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    strncpy(airship->name, inputName, MAX_AIRSHIP_NAME_SIZE);
    airship->health = inputHealth;
    airship->damage = inputDamage;
    airship->type = airShipType;
    airship->ID = index;
}

int baseProduceDamage(Airship* airship){
    return airship->damage;
}
void baseTakeDamage(Airship* airship, int damage){
    airship->health -= damage;
    
}
// void baseDealDamage(Airship* airship,int damage, int atackerID){
//     baseTakeDamage(airship, damage);
//     if(!isAirshipAlive(airship)){
//         printDead(airship, atackerID);
//     }  
// }

bool isAirshipAlive(Airship* airship){
    if(airship->health <= 0){
        return false;
    }
    return true;
}

void printDead(Airship* airship, int enemyID)
{
  printf("%s with ID: %d killed enemy airship with ID: %d\n",airship->name, airship->ID, enemyID);
}


