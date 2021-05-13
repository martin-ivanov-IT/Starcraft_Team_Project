#include <string.h>
#include <stdio.h>
#include <Airship.h>


int initAirship(Airship* airship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index){
    strncpy(airship->name, inputName, MAX_AIRSHIP_NAME_SIZE);
    if (airship == NULL)
    {
        return EXIT_FAILURE;
    }
    
    airship->health = inputHealth;
    airship->damage = inputDamage;
    airship->type = airShipType;
    airship->ID = index;

    return EXIT_SUCCESS;
}

int baseProduceDamage(Airship* airship, int* errNo){
    if (airship == NULL)
    {
        *errNo = EXIT_FAILURE;
    }
    *errNo = EXIT_SUCCESS;
    return airship->damage;
}
int baseTakeDamage(Airship* airship, int damage){
    if (airship == NULL)
    {
        return EXIT_FAILURE;
    }
    airship->health -= damage;
    return EXIT_SUCCESS;
}

//reduce health and remove airhip if is dead after attack
int baseDealDamage(Airship** lastAirship, Vector* army, int damage, char* atackerName,int atackerID){
    if (lastAirship == NULL)
    {
        return EXIT_FAILURE;
    }
    int errNo = EXIT_SUCCESS;
    if(baseTakeDamage((*lastAirship), damage)){
        perror("File \"Airship.c\",  printDead()");
        exit(EXIT_FAILURE);
    }
    
    if(!isAirshipAlive(*lastAirship, &errNo)){
        if(errNo){
            perror("File \"Airship.c\",  isAirshipAlive()");
            exit(EXIT_FAILURE);
        }
        if(printDead(atackerName,atackerID, (*lastAirship)->ID)){
            perror("File \"Airship.c\",  printDead()");
            exit(EXIT_FAILURE);
        }
        
        vectorPop(army);
        if(army->size == 0){
            return EXIT_SUCCESS;
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
    *errNo = EXIT_SUCCESS;

    if(airship->health <= 0){
        return false;
    }
    return true;
}

int printDead(char* atackerName,int atackerID, int enemyID)
{
    if (atackerName == NULL)
    {
        return EXIT_FAILURE;
    }
    printf("%s with ID: %d killed enemy airship with ID: %d\n",atackerName, atackerID, enemyID);
    return EXIT_SUCCESS;
}


