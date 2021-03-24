#include <stdlib.h>
#include "BattleCruser.h"
#include "Airships.h"
#include "Defines.h"

void initBattleCruser(BattleCruser** battleCruser){
    (*battleCruser) = malloc(sizeof(BattleCruser));
    (*battleCruser)->type = BATTLE_CRUSER;
    (*battleCruser)->health = BATTLE_CRUSER_HEALTH;
    (*battleCruser)->demage = BATTLE_BRUSER_DAMAGE;
}

void battleCruserAtackPhoenix(Phoenix* phoenix, int turn){
    int turnRate = 5;
    int powerIncreasment = 5;
    int power = BATTLE_BRUSER_DAMAGE;
    if(turn % turnRate == 0){
        power *= powerIncreasment;
    }

    if(phoenix->shield >= power){
        phoenix->shield -= power;
    }
    else{
        int demageToHealth = power - phoenix->shield;
        phoenix->shield = 0;
        phoenix->health -= demageToHealth;
    }
}

void battleCruserAtackCarrier(Carrier* carrier, int turn){
    int turnRate = 5;
    int powerIncreasment = 5;
    int power = BATTLE_BRUSER_DAMAGE;
    if(turn % turnRate == 0){
        power *= powerIncreasment;
    }

    if(carrier->shield >= power){
        carrier->shield -= power;
    }
    else{
        int demageToHealth = power - carrier->shield;
        carrier->shield = 0;
        carrier->health -= demageToHealth;
    }
}