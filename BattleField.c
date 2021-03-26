#include "BattleField.h"
#include "Vector.h"
#include "Defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TerranAirship.h"
#include "ProtossAirship.h"
void deleteLastShipFromString(char* str){
  str[strlen(str)-1] = '\0';
}


void generateTerranFleet(BattleField *battleField, const char *terranFleetStr) {
  vectorInit(&battleField->terranFleet, strlen(terranFleetStr));
  int i = 0;
  while (terranFleetStr[i] != '\0')
  {
      TerranAirship* terranAirship;
      initTerranAirship(&terranAirship, terranFleetStr[i]);
      vectorPush(&battleField->terranFleet,terranAirship);  
    i++;
  }
  
}

void generateProtossFleet(BattleField *battleField, const char *protossFleetStr) {
  vectorInit(&battleField->protossFleet, strlen(protossFleetStr));
  int i = 0;
  while (protossFleetStr[i] != '\0')
  {
      ProtossAirship* protossAirship;
      initProtossAirship(&protossAirship, protossFleetStr[i]);
      vectorPush(&battleField->protossFleet, protossAirship);  
    i++;
  }
}

void startBattle(BattleField *battleField) {
  int turn = 0;
  while (true) {
    turn ++;
    if (processTerranTurn(battleField, turn)) {
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

bool processTerranTurn(BattleField *battleField, int turn) {
  int terranSize = battleField->terranFleet.size;
  ProtossAirship* lastOfProtoss;
  for (int i = 0; i < terranSize; i++){
    lastOfProtoss = vectorBack(&battleField->protossFleet);
    TerranAirship* terranAirship = (TerranAirship*)vectorGet(&battleField->terranFleet, i);
    TerranAtack(lastOfProtoss, terranAirship, turn);
    if(lastOfProtoss->health <= 0){
      printDeadProtoss(terranAirship, lastOfProtoss);
      vectorPop(&battleField->protossFleet);
      lastOfProtoss = vectorBack(&battleField->protossFleet);
    }
    if(battleField->protossFleet.size == 0){
      return true;
    }
    
  }
  printTerranAtack(lastOfProtoss);
  ProtosAfterTurn(lastOfProtoss);
  return false;
}

bool processProtossTurn(BattleField *battleField) {
  int protossSize = battleField->protossFleet.size;
  TerranAirship* lastOfTerran = vectorBack(&battleField->terranFleet);
  for (int i = 0; i < protossSize; i++)
  {
    ProtossAirship* protossAirship = (ProtossAirship*)vectorGet(&battleField->protossFleet, i);
    ProtossAtack(lastOfTerran, protossAirship);
    if(lastOfTerran->health <= 0){
      printDeadTerran(protossAirship, lastOfTerran);
      vectorPop(&battleField->terranFleet);
    }
    lastOfTerran = vectorBack(&battleField->terranFleet);

    if(battleField->terranFleet.size == 0){
      return true;
    }
    if(protossAirship->atacks > 0){
      ProtossAtack(lastOfTerran, protossAirship);
    }
    updateProtossAtacks(protossAirship);
  }
  if(isDamagedTerran(lastOfTerran)){
      printProtossAtack(lastOfTerran);
    }
  return false;
}

void printProtossAtack(TerranAirship* terranAirship){
printf("Last Terran AirShip has %d health left\n",terranAirship->health);
}
void printTerranAtack(ProtossAirship* protossAirship){
  printf("Last Protoss AirShip has %d health and %d shield left\n",protossAirship->health, protossAirship->shield);
}
void printDeadTerran(ProtossAirship* protossAirship,TerranAirship* lastOfTerran){
  if(protossAirship->type == PHOENIX){
    printf("Phoenix killed enemy airship\n");
  }
  else if(protossAirship->type == CARRIER){
    printf("Carrier killed enemy airship\n");
  }
}

void printDeadProtoss(TerranAirship* terranAirship, ProtossAirship* lastOfProtoss){
  if(terranAirship->type == VIKING){
    printf("Viking killed enemy airship\n");
  }
  else if(terranAirship->type == BATTLE_CRUSER){
    printf("Battle cruiser killed enemy airship\n");
  }
}



