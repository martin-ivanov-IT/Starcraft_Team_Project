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
void baseDealDamage(Airship** lastAirship, Vector* army, int damage, char* atackerName,int atackerID){
    baseTakeDamage((*lastAirship), damage);
    if(!isAirshipAlive((*lastAirship))){
        printDead(atackerName,atackerID, (*lastAirship)->ID);
        vectorPop(army);
        if(army->size == 0){
            return;
        }
        (*lastAirship) = (Airship*)vectorBack(army);
    }
}
bool isAirshipAlive(Airship* airship){
    if(airship->health <= 0){
        return false;
    }
    return true;
}

void printDead(char* atackerName,int atackerID, int enemyID)
{
  printf("%s with ID: %d killed enemy airship with ID: %d\n",atackerName, atackerID, enemyID);
}


