#include "BattleField.h"
#include "Vector.h"
#include "Defines.h"
#include "Airship.h"
#include <stdio.h>
#include <stdlib.h>

void generateTerranFleet(BattleField *battleField, const char *terranFleetStr) {
  vectorInit(&battleField->terranFleet, strlen(terranFleetStr));
  int i = 0;
  while (terranFleetStr[i] != '\0')
  {
    Airship* ship;
    ship = malloc(sizeof(Airship));
    initAirship(terranFleetStr[i],ship);
    vectorPush(&battleField->terranFleet, (void*)ship);
    i++;
  }
  
}

void generateProtossFleet(BattleField *battleField, const char *protossFleetStr) {
  vectorInit(&battleField->protossFleet, strlen(protossFleetStr));
  int i = 0;
  while (protossFleetStr[i] != '\0')
  {
    Airship* ship;
    ship = malloc(sizeof(Airship));
    initAirship(protossFleetStr[i],ship);
    vectorPush(&battleField->protossFleet, (void*)ship);
    i++;
  }
}

void startBattle(BattleField *battleField) {
  while (true) {
    if (processTerranTurn(battleField)) {
      printf("TERRAN has won!\n");
      break;
    }

    if (processProtossTurn(battleField)) {
      printf("PROTOSS has won!\n");
      break;
    }
  }
}

void deinit(BattleField *battleField) {
}

bool processTerranTurn(BattleField *battleField) {
  return false;
}

bool processProtossTurn(BattleField *battleField) {
  return false;
}

