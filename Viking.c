#include <stdlib.h>
#include "Viking.h"
#include "Airships.h"

void initViking(Viking** viking){
    (*viking) = malloc(sizeof(Viking));
    (*viking)->type = VIKING;
    (*viking)->health = VIKING_HEALTH;
    (*viking)->demage = VIKING_DAMAGE;
}

void VikingAtackPhoenix(Viking* viking, Phoenix* phoenix){
    int doubleVikingDemage = viking->demage * 2;
    if(phoenix->shield >= doubleVikingDemage){
        phoenix->shield -= doubleVikingDemage;
    }
    else{
        int demageToHealth = doubleVikingDemage - phoenix->shield;
        phoenix->shield = 0;
        phoenix->health -= demageToHealth;
    }
}

void VikingAtackCarrier(Viking* viking, Carrier* carrier){
    if(carrier->shield >= viking->demage){
        carrier->shield -= viking->demage;
    }
    else{
        int demageToHealth = viking->demage - carrier->shield;
        carrier->shield = 0;
        carrier->health -= demageToHealth;
    }
}

