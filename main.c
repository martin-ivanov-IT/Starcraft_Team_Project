#include <stdio.h>
#include <stdlib.h>
#include "Defines.h"
#include "Vector.h"
#include "BattleField.h"
void printShip(Airship* currShip){
  if(currShip->type == VIKING){
      printf("VIKING\n");
  }
  else if(currShip->type == BATTLE_CRUSER){
      printf("BATTLE CRUSER\n");
  }
  else if(currShip->type == PHOENIX){
      printf("Pheonix\n");
  }
  else if(currShip->type == CARRIER){
      printf("CARRIER\n");
  }

  printf("Health: %d\n",currShip->health);
  printf("Shield: %d\n",currShip->shield);
  printf("Shield RegenerateRate: %d\n",currShip->shieldRegenerateRate);
  printf("Demage: %d\n",currShip->demage);

}

int main() {
  const int buffSize = 50;
  char terranFleet[buffSize];
  char protossFleet[buffSize];
  printf("enter terrantFlеets\n");
  scanf("%s", terranFleet);
  fflush(stdin);
  printf("enter protossFlеets\n");
  scanf("%s", protossFleet);
 
  BattleField battleField;
  generateTerranFleet(&battleField, terranFleet);
  generateProtossFleet(&battleField, protossFleet);
  int i;

  for (i = 0; i < battleField.terranFleet.size; i++)
  {
    Airship* currShip = (Airship*)vectorGet(&battleField.terranFleet,i);
    printShip(currShip);
  }

  printf("-----\n");

  for (i = 0; i < battleField.protossFleet.size; i++)
  {
    Airship* currShip = (Airship*)vectorGet(&battleField.protossFleet,i);
    printShip(currShip);
    
  }
  
  // startBattle(&battleField);
  // deinit(&battleField);

  return EXIT_SUCCESS;
}
