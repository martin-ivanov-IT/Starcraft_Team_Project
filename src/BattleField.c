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
      if(initViking(viking, VIKING, VIKING_NAME, VIKING_HEALTH, VIKING_DAMAGE, index)){
        perror("File \"BattleField.c\",  initViking()");
        exit(0);
      }
      vectorPush(&battleField->terranFleet, viking);
    }
    else if(terranFleetStr[index] == 'b'){
      BattleCruiser* battleCruiser = malloc(sizeof(BattleCruiser));
      if(initBattleCruiser(battleCruiser, BATTLE_CRUSER, BATTLE_CRUSER_NAME, BATTLE_CRUSER_HEALTH, BATTLE_BRUSER_DAMAGE, index)){
        perror("File \"BattleField.c\",  initBattleCruiser()");
        exit(0);
      }
      
  
      vectorPush(&battleField->terranFleet, battleCruiser);
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
      if(initPhoenix(phoenix, PHOENIX_NAME, PHOENIX_HEALTH, PHOENIX_DAMAGE, PHOENIX_SHIELD,
                  PHOENIX_SHIELD_REGENERATE_RATE, PHOENIX, index)){
                    perror("File \"BattleField.c\",  initPhoenix()");
                    exit(0);
                  }
      vectorPush(&battleField->protossFleet, phoenix);
    }

    else if(protossFleetStr[index] == 'c'){
      Carrier* carrier = malloc(sizeof(Carrier));
      if(initCarrier(carrier, CARRIER_NAME, CARRIER_HEALTH, CARRIER_DAMAGE, CARRIER_SHIELD,
                  CARRIER_SHIELD_REGENERATE_RATE, CARRIER, index)){
                    perror("File \"BattleField.c\",  initCarrier()");
                    exit(0);
                  }
      vectorPush(&battleField->protossFleet, carrier);
    }
    index++;
  }

  return 0;
}
// Count attack turns and check which Battelfield Fleed has remaining ships
int startBattle(BattleField *battleField)
{
  //int errNo;
  if (battleField == NULL)
    {
        return 1;
    }

  int turn = 0;
  while (true)
  {
     turn++;
    if (processTerranTurn(battleField, turn))
    {
      if(errNo){
        perror("File \"BattleField.c\",  processTerranTurn()");
        exit(0);
      }
      printf("TERRAN has won!\n");
      break;
    }

    if (processProtossTurn(battleField))
    {
      if(errNo){
        perror("File \"BattleField.c\",  processProtossTurn()");
        exit(0);
      }
      printf("PROTOSS has won!\n");
      break;
    }

  }
  return 0;
}

// returns true when ProtossFleet has no ships left, else prints turn info and returns false
bool processTerranTurn(BattleField *battleField, int turn)
{
  if (battleField == NULL)
    {
        errNo = 1;
    }
    
  internErrNo = 0;
  int terranSize = battleField->terranFleet.size;
  ProtossAirship *lastOfProtoss = (ProtossAirship *)vectorBack(&battleField->protossFleet);
  
  // Terran Airships attack one by one
  int damage = 0;
  for (int i = 0; i < terranSize; i++)
  {
    TerranAirship* terranAirship = (TerranAirship *)vectorGet(&battleField->terranFleet, i);
    
    if(terranAirship->type == VIKING){
      // take damage done by atack airship and return value as int
      damage = vikingProduceDamage(lastOfProtoss->airship.type);

      if(internErrNo){
        perror("File \"BattleField.c\",  vikingProduceDamage()");
        exit(0);
      }
      
    }
    
    else if(terranAirship->type == BATTLE_CRUSER){
      damage = battleCruiseProduceDamage(turn);
      if(internErrNo){
        perror("File \"BattleField.c\",  battleCruiseProduceDamage()");
        exit(0);
      }
    }
    // reduce health and sheild of enemy airship and remove if dead
    if(protossDealDamage(&lastOfProtoss, &battleField->protossFleet,damage, terranAirship->name, terranAirship->ID)){
        perror("File \"BattleField.c\",  protossDealDamage()");
        exit(0);
    }
    
    if(battleField->protossFleet.size == 0){
      return true;
    }
  }
  if(printProtossHurt(lastOfProtoss)){
        perror("File \"BattleField.c\",  printProtossHurt()");
        exit(0);
    }
  errNo = 0;
  return false;
}

// returns true when TerranFleet has no ships left, else prints turn info and returns false
bool processProtossTurn(BattleField *battleField)
{
  if (battleField == NULL)
    {
        errNo = 1;
    }
  internErrNo = 0;
  int protossSize = battleField->protossFleet.size;
  TerranAirship *lastOfTerran = (TerranAirship *)vectorBack(&battleField->terranFleet);
  for (int i = 0; i < protossSize; i++)
  {
    ProtossAirship* protossAirship = (ProtossAirship *)vectorGet(&battleField->protossFleet, i);
    int damage = 0;
    if(protossAirship->airship.type == PHOENIX){
      // take damage done by atack airship and return value as int
      damage = baseProduceDamage(&protossAirship->airship);
      if(internErrNo){
        perror("File \"BattleField.c\",  baseProduceDamage()");
        exit(0);
      }

      // reduce health of enemy airship and remove if dead
      if(baseDealDamage(&lastOfTerran, &battleField->terranFleet, damage, protossAirship->airship.name, protossAirship->airship.ID)){
        perror("File \"BattleField.c\",  baseDealDamage()");
        exit(0);
      }
      
      // regen shield after phoenix turn is finished
      if(phoenixRegenerate(protossAirship)){
        perror("File \"BattleField.c\",  phoenixRegenerate()");
        exit(0);
      }    
    }
    else if(protossAirship->airship.type == CARRIER){
    // return value of intercoptors count
     int attacks = getCarrierAtacks(protossAirship);
     if(internErrNo){
       perror("File \"BattleField.c\",  getCarrierAtacks()");
       exit(0);
     }
     if(terranDealDamageByCarrier(&lastOfTerran, &battleField->terranFleet, attacks,
      protossAirship->airship.name, protossAirship->airship.ID)){
        perror("File \"BattleField.c\",  terranDealDamageByCarrier()");
        exit(0);
      } 
      // regen shield after carrier turn is finished
      if(carrierRegenerate(protossAirship)){
        perror("File \"BattleField.c\",  carrierRegenerate()");
        exit(0);
      }  
    } 
    if(battleField->terranFleet.size == 0){
      return true;
    }
  }
  if(printTerranHurt(lastOfTerran)){
    perror("File \"BattleField.c\",  printTerranHurt()");
    exit(0);
  }
   // after all Protoss Airships have stiked
  errNo = 0;
  return false;
}

int printTerranHurt(TerranAirship *terranAirship)
{
  if (terranAirship == NULL)
    {
        return 1;
    }
  printf("Last Terran AirShip with ID: %d has %d health left\n", terranAirship->ID, terranAirship->health);
  return 0;
}

int printProtossHurt(ProtossAirship *protossAirship)
{
  if (protossAirship == NULL)
    {
        return 1;
    }

  printf("Last Protoss AirShip with ID: %d has %d health and %d shield left\n", protossAirship->airship.ID, protossAirship->airship.health, protossAirship->shield);
  return 0;
}

// Free the memory allocated for the Airships, then free the memory allocated for the BattleFleeds
int deinit(BattleField *battleField)
{
  if (battleField == NULL)
    {
        return 1;
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
  return 0;
}