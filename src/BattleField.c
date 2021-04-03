#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"../include/BattleField.h"
#include"../include/ProtossAirship.h"
#include"../include/TerranAirship.h"
#include"../include/Viking.h"
#include"../include/BattleCruiser.h"
#include"../include/Phoenix.h"
#include"../include/Carrier.h"
#include"../include/Airship.h"
#include"../include/Defines.h"


//Initialize and fill up TerranFleet with Terran Airships according to string input
void generateTerranFleet(BattleField *battleField, const char *terranFleetStr)
{
  vectorInit(&battleField->terranFleet, strlen(terranFleetStr));
  int i = 0;
  while (terranFleetStr[i] != '\0')
  {
    if(terranFleetStr[i] == 'v'){
      Viking* viking = malloc(sizeof(Viking));
      initViking(viking, VIKING, VIKING_NAME, VIKING_HEALTH, VIKING_DAMAGE);
      vectorPush(&battleField->terranFleet, viking);
    }
    else if(terranFleetStr[i] == 'b'){
      BattleCruiser* battleCruiser = malloc(sizeof(BattleCruiser));
      initBattleCruiser(battleCruiser, BATTLE_CRUSER, BATTLE_CRUSER_NAME, BATTLE_CRUSER_HEALTH, BATTLE_BRUSER_DAMAGE);
      vectorPush(&battleField->terranFleet, battleCruiser);
    }
    
    i++;
  }
}

//Initialize and fill up ProtossFleet with Protoss Airships according to string input
void generateProtossFleet(BattleField *battleField, const char *protossFleetStr)
{
  vectorInit(&battleField->protossFleet, strlen(protossFleetStr));
  int i = 0;
  while (protossFleetStr[i] != '\0')
  {
    if(protossFleetStr[i] == 'p'){
      Phoenix* phoenix = malloc(sizeof(Phoenix));
      initPhoenix(phoenix, PHOENIX_NAME, PHOENIX_HEALTH, PHOENIX_DAMAGE, PHOENIX_SHIELD,
                  PHOENIX_SHIELD_REGENERATE_RATE, PHOENIX);
      vectorPush(&battleField->protossFleet, phoenix);
    }

    else if(protossFleetStr[i] == 'c'){
      Carrier* carrier = malloc(sizeof(Carrier));
      initCarrier(carrier, CARRIER_NAME, CARRIER_HEALTH, CARRIER_DAMAGE, CARRIER_SHIELD,
                  CARRIER_SHIELD_REGENERATE_RATE, CARRIER);
      vectorPush(&battleField->protossFleet, carrier);
    }
    i++;
  }
}
// Count attack turns and check which Battelfield Fleed has remaining ships
void startBattle(BattleField *battleField)
{
  int turn = 0;
  while (true)
  {
     turn++;
    if (processTerranTurn(battleField, turn))
    {
      printf("TERRAN has won!\n");
      break;
    }

    if (processProtossTurn(battleField))
    {
      printf("PROTOSS has won!\n");
      break;
    }

  }
}

// returns true when ProtossFleet has no ships left, else prints turn info and returns false
bool processTerranTurn(BattleField *battleField, int turn)
{
  int terranSize = battleField->terranFleet.size;
  // Takes last enemy ship
  ProtossAirship *lastOfProtoss = (ProtossAirship *)vectorBack(&battleField->protossFleet);
  int lastProtossID;
  // Terran Airships attack one by one
  for (int i = 0; i < terranSize; i++)
  {
    lastProtossID = battleField->protossFleet.size - 1;
    TerranAirship *terranAirship = (TerranAirship *)vectorGet(&battleField->terranFleet, i);
    int damage = 0;
    if(terranAirship->type == VIKING){
      damage = produceDamageViking(lastOfProtoss->airship.type);
    }
    else if(terranAirship->type == BATTLE_CRUSER){
      damage = produceDamageBattleCruiser(turn);
    }
    takeDamageProtoss(lastOfProtoss, damage);
    // If Protoss ship is killed, prints ships info, removes (free the memory) the killed ship and takes the last ship again
    if (lastOfProtoss->airship.health <= 0)
    {
      printKilledProtossByTerran(terranAirship, i, lastProtossID);
      vectorPop(&battleField->protossFleet);
      if (battleField->protossFleet.size == 0)
      {
        return true;
      }
      lastProtossID = battleField->protossFleet.size - 1;
      lastOfProtoss = (ProtossAirship *)vectorBack(&battleField->protossFleet);
    }
  }
  printProtossHurt(lastProtossID, lastOfProtoss);
  return false;
}

// returns true when TerranFleet has no ships left, else prints turn info and returns false
bool processProtossTurn(BattleField *battleField)
{
  protossRegenerate((ProtossAirship *)vectorBack(&battleField->protossFleet));
  int protossSize = battleField->protossFleet.size;
  // Takes last enemy ship
  TerranAirship *lastOfTerran = (TerranAirship *)vectorBack(&battleField->terranFleet);
  int lastTerranID;
  // Protoss Airships attack one by one
  for (int i = 0; i < protossSize; i++)
  {
    lastTerranID = battleField->terranFleet.size - 1;
    ProtossAirship *protossAirship = (ProtossAirship *)vectorGet(&battleField->protossFleet, i);
    int damage = 0;
    if(protossAirship->airship.type == PHOENIX){
      damage = baseProduceDamage(&protossAirship->airship);
      baseTakeDamage(lastOfTerran, damage);
      damage = 0;
    }
    else if(protossAirship->airship.type == CARRIER){
      damage = carrierProduceDamage(protossAirship);
      int currentTerranHealth = lastOfTerran->health;
      baseTakeDamage(lastOfTerran, damage);
      damage -= currentTerranHealth;
    }

    // If Terran ship is killed, prints ships info, removes (free the memory) the killed ship and takes the last ship again
    if (lastOfTerran->health <= 0)
    {
      printKilledTerranByProtoss(protossAirship, i, lastTerranID);
      vectorPop(&battleField->terranFleet);
      lastOfTerran = (TerranAirship *)vectorBack(&battleField->terranFleet);
      if (battleField->terranFleet.size == 0)
      {
        return true;
      }
      // if attacking ship has stikes left continue attack (only one ship can be killed with max strykes, because the new last ship will be with max health)
      if (damage > 0)
      {
        damage = (damage/8)*8;
        baseTakeDamage(lastOfTerran, damage);
      }
      lastTerranID = battleField->terranFleet.size - 1;
    }
  }
  printTerranHurt(lastTerranID, lastOfTerran); // after all Protoss Airships have stiked
  return false;
}

void printKilledTerranByProtoss(ProtossAirship *protossAirship, int attackerID, int enemyID)
{
  printf("%s with ID: %d killed enemy airship with ID: %d\n",protossAirship->airship.name, attackerID, enemyID);
}

void printKilledProtossByTerran(TerranAirship *terranAirship, int attackerID, int enemyID)
{
  printf("%s with ID: %d killed enemy airship with ID: %d\n", terranAirship->name, attackerID, enemyID);
}

void printTerranHurt(int ID, TerranAirship *terranAirship)
{
  printf("Last Terran AirShip with ID: %d has %d health left\n", ID, terranAirship->health);
}

void printProtossHurt(int ID, ProtossAirship *protossAirship)
{
  printf("Last Protoss AirShip with ID: %d has %d health and %d shield left\n", ID, protossAirship->airship.health, protossAirship->shield);
}

// Free the memory allocated for the Airships, then free the memory allocated for the BattleFleeds
void deinit(BattleField *battleField)
{
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
}