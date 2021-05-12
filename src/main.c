#include <stdio.h>
#include <stdlib.h>
#include "BattleField.h"

int main() {
  const int buffSize = 50;
  char terranFleet[buffSize];
  char protossFleet[buffSize];
  scanf("%s %s", terranFleet, protossFleet);
  
  BattleField battleField;
  if(generateTerranFleet(&battleField, terranFleet)){
    perror("File \"main.c\",  generateTerranFleet()");
    exit(0);
  }
  
  if(generateProtossFleet(&battleField, protossFleet)){
    perror("File \"main.c\",  generateProtossFleet()");
    exit(0);
  }
  
  if(startBattle(&battleField)){
    perror("File \"main.c\",  startBattle()");
    exit(0);
  }
  
  if(deinit(&battleField)){
    perror("File \"main.c\",  deinit()");
    exit(0);
  }

  return EXIT_SUCCESS;
}