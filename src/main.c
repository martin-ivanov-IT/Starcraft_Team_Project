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
    fprintf(stderr,"File \"main.c\",  generateTerranFleet()");
    exit(EXIT_FAILURE);
  }
  
  if(generateProtossFleet(&battleField, protossFleet)){
    fprintf(stderr,"File \"main.c\",  generateProtossFleet()");
    exit(EXIT_FAILURE);
  }
  
  if(startBattle(&battleField)){
    fprintf(stderr,"File \"main.c\",  startBattle()");
    exit(EXIT_FAILURE);
  }
  
  if(deinit(&battleField)){
    fprintf(stderr,"File \"main.c\",  deinit()");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}