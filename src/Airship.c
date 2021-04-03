#include"../include/Airship.h"
#include"../include/Defines.h"
#include <string.h>

void initAirship(Airship* airship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage){
    strncpy(airship->name, inputName, MAX_AIRSHIP_NAME_SIZE);
    airship->health = inputHealth;
    airship->damage = inputDamage;
    airship->type = airShipType;
}

int baseProduceDamage(Airship* airship){
    return airship->damage;
}
void baseTakeDamage(Airship* airship, int damage){
    airship->health -= damage;
}