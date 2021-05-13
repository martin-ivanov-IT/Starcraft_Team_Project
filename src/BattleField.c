#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"BattleField.h"
#include"Phoenix.h"
#include"Carrier.h"
#include"BattleCruiser.h"
#include"Viking.h"
#include "Vector.h"


//Initialize and fill up TerranFleet with Terran Airships according to string input
int generateTerranFleet(BattleField *battleField, const char *terranFleetStr)
{
  if (battleField == NULL)
    {
        return 1;
    }
  vectorInit(&battleField->terranFleet, strlen(terranFleetStr));
  int index = 0;
  while (terranFleetStr[index] != '\0')
  {
    if(terranFleetStr[index] == 'v'){
      Viking* viking = malloc(sizeof(Viking));
      if(viking == NULL){
        perror("File \"BattleField.c\",  initViking()");
      }

      if(initViking(viking, VIKING, VIKING_NAME, VIKING_HEALTH, VIKING_DAMAGE, index)){
        fprintf(stderr, "File \"BattleField.c\",  initViking()");
        exit(EXIT_FAILURE);
      }
      vectorPush(&battleField->terranFleet, viking);
    }
    else if(terranFleetStr[index] == 'b'){
      BattleCruiser* battleCruiser = malloc(sizeof(BattleCruiser));
      if(battleCruiser == NULL){
        perror("File \"BattleField.c\",  initViking()");
      }
      if(initBattleCruiser(battleCruiser, BATTLE_CRUSER, BATTLE_CRUSER_NAME, BATTLE_CRUSER_HEALTH, BATTLE_BRUSER_DAMAGE, index)){
        fprintf(stderr, "File \"BattleField.c\",  initBattleCruiser()");
        exit(EXIT_FAILURE);
      }

      
  
      vectorPush(&battleField->terranFleet, battleCruiser);
    }

    else{
      return 1;
    }

    index++;
  }
  return 0;
}

//Initialize and fill up ProtossFleet with Protoss Airships according to string input
int generateProtossFleet(BattleField *battleField, const char *protossFleetStr)
{
  if (battleField == NULL)
    {
        return 1;
    }
  
  vectorInit(&battleField->protossFleet, strlen(protossFleetStr));
  int index = 0;

  while (protossFleetStr[index] != '\0')
  {
    
    if(protossFleetStr[index] == 'p'){
      
      Phoenix* phoenix = malloc(sizeof(Phoenix));
      if(phoenix == NULL){
        perror("File \"BattleField.c\",  initViking()");
      }
      if(initPhoenix(phoenix, PHOENIX_NAME, PHOENIX_HEALTH, PHOENIX_DAMAGE, PHOENIX_SHIELD,
                  PHOENIX_SHIELD_REGENERATE_RATE, PHOENIX, index)){
                    fprintf(stderr, "File \"BattleField.c\",  initPhoenix()");
                    exit(EXIT_FAILURE);
                  }
      vectorPush(&battleField->protossFleet, phoenix);
    }

    else if(protossFleetStr[index] == 'c'){
      Carrier* carrier = malloc(sizeof(Carrier));
      if(carrier == NULL){
        perror("File \"BattleField.c\",  initViking()");
      }
      if(initCarrier(carrier, CARRIER_NAME, CARRIER_HEALTH, CARRIER_DAMAGE, CARRIER_SHIELD,
                  CARRIER_SHIELD_REGENERATE_RATE, CARRIER, index)){
                    fprintf(stderr, "File \"BattleField.c\",  initCarrier()");
                    exit(EXIT_FAILURE);
                  }
      vectorPush(&battleField->protossFleet, carrier);
    }
    else{
      return 1;
    }
    index++;
  }

  return 0;
}
// Count attack turns and check which Battelfield Fleed has remaining ships
int startBattle(BattleField *battleField)
{
  int errNo;
  if (battleField == NULL)
    {
        return 1;
    }

  int turn = 0;
  while (true)
  {
     turn++;
    if (processTerranTurn(battleField, turn, &errNo))
    {
      if(errNo){
        fprintf(stderr, "File \"BattleField.c\",  processTerranTurn()");
        exit(EXIT_FAILURE);
      }
      printf("TERRAN has won!\n");
      break;
    }

    if (processProtossTurn(battleField, &errNo))
    {
      if(errNo){
        fprintf(stderr, "File \"BattleField.c\",  processProtossTurn()");
        exit(EXIT_FAILURE);
      }
      printf("PROTOSS has won!\n");
      break;
    }

  }
  return 0;
}

// returns true when ProtossFleet has no ships left, else prints turn info and returns false
bool processTerranTurn(BattleField *battleField, int turn, int* errNo)
{
  if (battleField == NULL)
    {
        *errNo = 1;
    }
    
  int internErrNo = 0;
  int terranSize = battleField->terranFleet.size;
  ProtossAirship *lastOfProtoss = (ProtossAirship *)vectorBack(&battleField->protossFleet);
  
  // Terran Airships attack one by one
  int damage = 0;
  for (int i = 0; i < terranSize; i++)
  {
    TerranAirship* terranAirship = (TerranAirship *)vectorGet(&battleField->terranFleet, i);
    
    if(terranAirship->type == VIKING){
      // take damage done by atack airship and return value as int
      damage = vikingProduceDamage(lastOfProtoss->airship.type, &internErrNo);

      if(internErrNo){
        fprintf(stderr, "File \"BattleField.c\",  vikingProduceDamage()");
        exit(EXIT_FAILURE);
      }
      
    }
    
    else if(terranAirship->type == BATTLE_CRUSER){
      damage = battleCruiseProduceDamage(turn, &internErrNo);
      if(internErrNo){
        fprintf(stderr, "File \"BattleField.c\",  battleCruiseProduceDamage()");
        exit(EXIT_FAILURE);
      }
    }
    // reduce health and sheild of enemy airship and remove if dead
    if(protossDealDamage(&lastOfProtoss, &battleField->protossFleet,damage, terranAirship->name, terranAirship->ID)){
        fprintf(stderr, "File \"BattleField.c\",  protossDealDamage()");
        exit(EXIT_FAILURE);
    }
    
    if(battleField->protossFleet.size == 0){
      return true;
    }
  }
  if(printProtossHurt(lastOfProtoss)){
        fprintf(stderr, "File \"BattleField.c\",  printProtossHurt()");
        exit(EXIT_FAILURE);
    }
  *errNo = 0;
  return false;
}

// returns true when TerranFleet has no ships left, else prints turn info and returns false
bool processProtossTurn(BattleField *battleField, int* errNo)
{
  if (battleField == NULL)
    {
        *errNo = EXIT_FAILURE;
    }

  int internErrNo;
  int protossSize = battleField->protossFleet.size;
  TerranAirship *lastOfTerran = (TerranAirship *)vectorBack(&battleField->terranFleet);
  for (int i = 0; i < protossSize; i++)
  {
    ProtossAirship* protossAirship = (ProtossAirship *)vectorGet(&battleField->protossFleet, i);
    int damage = 0;
    if(protossAirship->airship.type == PHOENIX){
      // take damage done by atack airship and return value as int
      damage = baseProduceDamage(&protossAirship->airship, &internErrNo);
      if(internErrNo){
        fprintf(stderr, "File \"BattleField.c\",  baseProduceDamage()");
        exit(EXIT_FAILURE);
      }

      // reduce health of enemy airship and remove if dead
      if(baseDealDamage(&lastOfTerran, &battleField->terranFleet, damage, protossAirship->airship.name, protossAirship->airship.ID)){
        fprintf(stderr, "File \"BattleField.c\",  baseDealDamage()");
        exit(EXIT_FAILURE);
      }
      
      // regen shield after phoenix turn is finished
      if(phoenixRegenerate(protossAirship)){
        fprintf(stderr, "File \"BattleField.c\",  phoenixRegenerate()");
        exit(EXIT_FAILURE);
      }    
    }
    else if(protossAirship->airship.type == CARRIER){
    // return value of intercoptors count
     int attacks = getCarrierAtacks(protossAirship, &internErrNo);
     if(internErrNo){
       fprintf(stderr, "File \"BattleField.c\",  getCarrierAtacks()");
       exit(EXIT_FAILURE);
     }
     if(terranDealDamageByCarrier(&lastOfTerran, &battleField->terranFleet, attacks,
      protossAirship->airship.name, protossAirship->airship.ID)){
        fprintf(stderr, "File \"BattleField.c\",  terranDealDamageByCarrier()");
        exit(EXIT_FAILURE);
      } 
      // regen shield after carrier turn is finished
      if(carrierRegenerate(protossAirship)){
        fprintf(stderr, "File \"BattleField.c\",  carrierRegenerate()");
        exit(EXIT_FAILURE);
      }  
    } 
    if(battleField->terranFleet.size == 0){
      return true;
    }
  }
  if(printTerranHurt(lastOfTerran)){
    fprintf(stderr, "File \"BattleField.c\",  printTerranHurt()");
    exit(EXIT_FAILURE);
  }
   // after all Protoss Airships have stiked
  *errNo = 0;
  return false;
}

int printTerranHurt(TerranAirship *terranAirship)
{
  if (terranAirship == NULL)
    {
        return EXIT_FAILURE;
    }
  printf("Last Terran AirShip with ID: %d has %d health left\n", terranAirship->ID, terranAirship->health);
  return EXIT_SUCCESS;
}

int printProtossHurt(ProtossAirship *protossAirship)
{
  if (protossAirship == NULL)
    {
        return EXIT_FAILURE;
    }

  printf("Last Protoss AirShip with ID: %d has %d health and %d shield left\n", protossAirship->airship.ID, protossAirship->airship.health, protossAirship->shield);
  return EXIT_SUCCESS;
}

// Free the memory allocated for the Airships, then free the memory allocated for the BattleFleeds
int deinit(BattleField *battleField)
{
  if (battleField == NULL)
    {
        return EXIT_FAILURE;
    }

  int terranSize = battleField->terranFleet.size;
  for (int i = 0; i < terranSize; i++)
  {
    free(vectorGet(&battleField->terranFleet, i));
  }
  int protossSize = battleField->protossFleet.size;
  for (int i = 0; i < protossSize; i++)
  {
    free(vectorGet(&battleField->protossFleet, i));
  }
  vectorFree(&battleField->terranFleet);
  vectorFree(&battleField->protossFleet);
  return EXIT_SUCCESS;
}