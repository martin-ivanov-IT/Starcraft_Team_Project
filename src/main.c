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
    exit(0);
  }
  
  if(generateProtossFleet(&battleField, terranFleet)){
    exit(0);
  }
  
  if(startBattle(&battleField)){
    exit(0);
  }
  
  if(deinit(&battleField)){
    exit(0);
  }

  return EXIT_SUCCESS;
}