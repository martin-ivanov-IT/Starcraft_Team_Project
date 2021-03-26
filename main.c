#include <stdio.h>
#include <stdlib.h>
#include "Defines.h"
#include "Vector.h"
#include "BattleField.h"
#include "Airships.h"
#include <string.h>

void printTerran(TerranAirship* terranAirship){
  if(terranAirship->type == VIKING){
    printf("VIKING\n");
  }
  else if(terranAirship->type == BATTLE_CRUSER){
    printf("BATTLE CRUSER\n");
  }
  printf("Health: %d\n",terranAirship->health);
  printf("Demage: %d\n",terranAirship->demage);
}

void printProtoss(ProtossAirship* protossAirship){
  if(protossAirship->type == PHOENIX){
    printf("PHOENIX\n");
  }
  else if(protossAirship->type == CARRIER){
    printf("CARRIER\n");
  }
  printf("Health: %d\n",protossAirship->health);
  printf("Demage: %d\n",protossAirship->demage);
  printf("Shield RegenerateRate: %d\n",protossAirship->shieldRegenerateRate);
  printf("Demage: %d\n",protossAirship->demage);
  printf("Atacks: %d\n",protossAirship->atacks);
  
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

  // int i;
  // for (i = 0; i < battleField.terranFleet.size; i++)
  // {
  //     TerranAirship* terranAirship = (TerranAirship*)vectorGet(&battleField.terranFleet,i);
  //     printTerran(terranAirship);
  
  // }

  // printf("-----\n");

  // for (i = 0; i < battleField.protossFleet.size; i++)
  // {
  //   ProtossAirship* protossAirship = (ProtossAirship*)vectorGet(&battleField.protossFleet,i);
  //   printProtoss(protossAirship);
  // }
  
  startBattle(&battleField);
  //deinit(&battleField);

  return EXIT_SUCCESS;
}
