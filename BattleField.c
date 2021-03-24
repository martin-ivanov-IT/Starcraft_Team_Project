#include "BattleField.h"
#include "Vector.h"
#include "Defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Carrier.h"
#include "BattleCruser.h"
#include "Viking.h"
#include "Phoenix.h"
void deleteLastShipFromString(char* str){
  str[strlen(str)-1] = '\0';
}

void generateTerranFleet(BattleField *battleField, const char *terranFleetStr) {
  vectorInit(&battleField->terranFleet, sizeof(Vector));
  int i = 0;
  while (terranFleetStr[i] != '\0')
  {
    if(terranFleetStr[i] == 'v'){
      Viking* viking;
      initViking(&viking);
      printViking(viking);
      vectorPush(&battleField->terranFleet,viking);
    }
    else if(terranFleetStr[i] == 'b'){
      BattleCruser* battleCruser;
      initBattleCruser(&battleCruser);
      vectorPush(&battleField->terranFleet,battleCruser);
    }
    i++;
  }
  
}

void generateProtossFleet(BattleField *battleField, const char *protossFleetStr) {
  vectorInit(&battleField->protossFleet, sizeof(Vector));
  int i = 0;
  while (protossFleetStr[i] != '\0')
  {
    if(protossFleetStr[i] == 'p'){
      Phoenix* phoenix;
      initPhoenix(&phoenix);
      vectorPush(&battleField->protossFleet,phoenix);
    }
    else if(protossFleetStr[i] == 'c'){
      Carrier* carrier;
      initCarrier(&carrier);
      vectorPush(&battleField->protossFleet,carrier);
    }
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
  int i;
  for (i = 0; i < battleField->terranFleet.size; i++)
  {
    Ship* ship = (Ship*)vectorGet(&battleField->terranFleet,i);
    if(ship->type == VIKING){
        Viking* viking = (Viking*)vectorGet(&battleField->terranFleet,i);
      }
  }
  
  return false;
}

bool processProtossTurn(BattleField *battleField) {
  return false;
}

