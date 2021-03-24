#include <stdio.h>
#include <stdlib.h>
#include "Defines.h"
#include "Vector.h"
#include "BattleField.h"
#include "Airships.h"
#include "string.h"

void printViking2(Viking* viking){
  printf("VIKING\n");
  printf("Health: %d\n",viking->health);
  printf("Demage: %d\n",viking->demage);
}

void printBattleCruser(BattleCruser* battleCruser){
  printf("BATTLE CRUSER\n");
  printf("Health: %d\n",battleCruser->health);
  printf("Demage: %d\n",battleCruser->demage);
}

void printPhoenix(Phoenix* phoenix){
  printf("Pheonix\n");
  printf("Health: %d\n",phoenix->health);
  printf("Demage: %d\n",phoenix->demage);
  printf("Shield RegenerateRate: %d\n",phoenix->shieldRegenerateRate);
  printf("Demage: %d\n",phoenix->demage);
}

void printCarrier(Carrier* carrier){
  printf("Carrier\n");
  printf("Health: %d\n",carrier->health);
  printf("Demage: %d\n",carrier->demage);
  printf("Shield RegenerateRate: %d\n",carrier->shieldRegenerateRate);
  printf("Demage: %d\n",carrier->demage);
}

int main() {
  const int buffSize = 50;
  char terranFleet[buffSize];
  char protossFleet[buffSize];
  printf("enter terrantFllets\n");
  scanf("%s", terranFleet);
  fflush(stdin);
  printf("enter protossFllets\n");
  scanf("%s", protossFleet);
 
  BattleField battleField;
  generateTerranFleet(&battleField, terranFleet);
  generateProtossFleet(&battleField, protossFleet);

  int i;
  for (i = 0; i < battleField.terranFleet.size; i++)
  {
    if(terranFleet[i] == 'v'){
      Ship* ship = (Ship*)vectorGet(&battleField.terranFleet,i);
      if(ship->type == VIKING){
        Viking* viking = (Viking*)vectorGet(&battleField.terranFleet,i);
        printViking2(viking);
      }
      
    }
    if(terranFleet[i] == 'b'){
      BattleCruser* battleCruser = (BattleCruser*)vectorGet(&battleField.terranFleet,i);
      printBattleCruser(battleCruser);
    }
    
  }

  printf("-----\n");

  for (i = 0; i < battleField.protossFleet.size; i++)
  {
    if(protossFleet[i] == 'p'){
        Phoenix* phoenix = (Phoenix*)vectorGet(&battleField.protossFleet,i);
        printPhoenix(phoenix);
      }

      if(protossFleet[i] == 'c'){
        Carrier* carrier = (Carrier*)vectorGet(&battleField.protossFleet,i);
        printCarrier(carrier);
      }
    
  }
  
  // startBattle(&battleField);
  // deinit(&battleField);

  return EXIT_SUCCESS;
}
