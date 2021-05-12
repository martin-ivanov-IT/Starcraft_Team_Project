#include"../include/Airship.h"
#include"../include/Defines.h"
#include <string.h>
#include <stdio.h>

int initAirship(Airship* airship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    strncpy(airship->name, inputName, MAX_AIRSHIP_NAME_SIZE);
    if (airship == NULL)
    {
        return 1;
    }
    
    airship->health = inputHealth;
    airship->damage = inputDamage;
    airship->type = airShipType;
    airship->ID = index;

    return 0;
}

int baseProduceDamage(Airship* airship, int* errNo){
    if (airship == NULL)
    {
        *errNo = 1;
    }
    *errNo = 0;
    return airship->damage;
}
int baseTakeDamage(Airship* airship, int damage){
    if (airship == NULL)
    {
        return 1;
    }
    airship->health -= damage;
    return 0;
}

//reduce health and remove airhip if is dead after attack
int baseDealDamage(Airship** lastAirship, Vector* army, int damage, char* atackerName,int atackerID){
    if (lastAirship == NULL)
    {
        return 1;
    }
    int errNo = 0;
    if(baseTakeDamage((*lastAirship), damage)){
        exit(0);
    }
    
    if(!isAirshipAlive(*lastAirship, &errNo)){
        if(errNo){
            exit(0);
        }
        if(printDead(atackerName,atackerID, (*lastAirship)->ID)){
            exit(0);
        }
        
        vectorPop(army);
        if(army->size == 0){
            return 0;
        }
        (*lastAirship) = (Airship*)vectorBack(army);
    }
    return 0;
}
// check if airship health is under 0 and return true if is above 0
bool isAirshipAlive(Airship* airship, int* errNo){
    if (airship == NULL)
    {
        *errNo = 1;
    }
    *errNo = 0;

    if(airship->health <= 0){
        return false;
    }
    return true;
}

int printDead(char* atackerName,int atackerID, int enemyID)
{
    if (atackerName == NULL)
    {
        return 1;
    }
    printf("%s with ID: %d killed enemy airship with ID: %d\n",atackerName, atackerID, enemyID);
    return 0;
}


