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
  int index = 0;
  while (terranFleetStr[index] != '\0')
  {
    if(terranFleetStr[index] == 'v'){
      Viking* viking = malloc(sizeof(Viking));
      initViking(viking, VIKING, VIKING_NAME, VIKING_HEALTH, VIKING_DAMAGE, index);
      vectorPush(&battleField->terranFleet, viking);
    }
    else if(terranFleetStr[index] == 'b'){
      BattleCruiser* battleCruiser = malloc(sizeof(BattleCruiser));
      initBattleCruiser(battleCruiser, BATTLE_CRUSER, BATTLE_CRUSER_NAME, BATTLE_CRUSER_HEALTH, BATTLE_BRUSER_DAMAGE, index);
      vectorPush(&battleField->terranFleet, battleCruiser);
    }
    
    index++;
  }
}

//Initialize and fill up ProtossFleet with Protoss Airships according to string input
void generateProtossFleet(BattleField *battleField, const char *protossFleetStr)
{
  vectorInit(&battleField->protossFleet, strlen(protossFleetStr));
  int index = 0;
  while (protossFleetStr[index] != '\0')
  {
    if(protossFleetStr[index] == 'p'){
      Phoenix* phoenix = malloc(sizeof(Phoenix));
      initPhoenix(phoenix, PHOENIX_NAME, PHOENIX_HEALTH, PHOENIX_DAMAGE, PHOENIX_SHIELD,
                  PHOENIX_SHIELD_REGENERATE_RATE, PHOENIX, index);
      vectorPush(&battleField->protossFleet, phoenix);
    }

    else if(protossFleetStr[index] == 'c'){
      Carrier* carrier = malloc(sizeof(Carrier));
      initCarrier(carrier, CARRIER_NAME, CARRIER_HEALTH, CARRIER_DAMAGE, CARRIER_SHIELD,
                  CARRIER_SHIELD_REGENERATE_RATE, CARRIER, index);
      vectorPush(&battleField->protossFleet, carrier);
    }
    index++;
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
  ProtossAirship *lastOfProtoss = (ProtossAirship *)vectorBack(&battleField->protossFleet);
  // Terran Airships attack one by one
  for (int i = 0; i < terranSize; i++)
  {
    TerranAirship* terranAirship = (TerranAirship *)vectorGet(&battleField->terranFleet, i);
    if(terranAirship->type == VIKING){
      vikinngDealDamageToProtossAirship(&battleField->protossFleet, &lastOfProtoss, terranAirship);
    }
    else if(terranAirship->type == BATTLE_CRUSER){
      battleCruiserDealDamageToProtossAirship(&battleField->protossFleet, &lastOfProtoss,turn, terranAirship);
    }
    if(battleField->protossFleet.size == 0){
      return true;
    }
  }
  printProtossHurt(lastOfProtoss);
  return false;
}

// returns true when TerranFleet has no ships left, else prints turn info and returns false
bool processProtossTurn(BattleField *battleField)
{
  protossRegenerate((ProtossAirship *)vectorBack(&battleField->protossFleet));
  int protossSize = battleField->protossFleet.size;
  TerranAirship *lastOfTerran = (TerranAirship *)vectorBack(&battleField->terranFleet);
  for (int i = 0; i < protossSize; i++)
  {
    ProtossAirship* protossAirship = (ProtossAirship *)vectorGet(&battleField->protossFleet, i);
    if(protossAirship->airship.type == PHOENIX){
      phoenixDealDamageToTerranAirship(&battleField->terranFleet, &lastOfTerran, protossAirship);
    }
    else if(protossAirship->airship.type == CARRIER){
      carrierDealDamageToTerranAirship(&battleField->terranFleet, protossAirship, &lastOfTerran);
    } 
    if(battleField->terranFleet.size == 0){
      return true;
    }
  }
  printTerranHurt(lastOfTerran); // after all Protoss Airships have stiked
  return false;
}

void printTerranHurt(TerranAirship *terranAirship)
{
  printf("Last Terran AirShip with ID: %d has %d health left\n", terranAirship->ID, terranAirship->health);
}

void printProtossHurt(ProtossAirship *protossAirship)
{
  printf("Last Protoss AirShip with ID: %d has %d health and %d shield left\n", protossAirship->airship.ID, protossAirship->airship.health, protossAirship->shield);
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