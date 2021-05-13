#include <stdio.h>
#include <stdlib.h>
#include "BattleField.h"

int main() {
  const int buffSize = 50;
  char terranFleet[buffSize];
  char protossFleet[buffSize];

  MENU:
    scanf("%s %s", terranFleet, protossFleet);
  
  BattleField battleField;

  if(generateTerranFleet(&battleField, terranFleet)){
    printf("Invalid Terran airship type! Try again:\n");
    goto MENU;
  }
  
  if(generateProtossFleet(&battleField, protossFleet)){
    printf("Invalid Protoss airship type! Try again:\n");
    goto MENU;
  }
  
  if(startBattle(&battleField)){
    exit(EXIT_FAILURE);
  }
  
  if(deinit(&battleField)){
    perror("File \"main.c\",  deinit()");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}