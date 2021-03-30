#include "BattleField.h"
#include "Vector.h"
#include "Defines.h"
#include "Airships.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TerranAirship.h"
#include "ProtossAirship.h"

int turn = 0;
//Initialize and fill up TerranFleet with Terran Airships according to string input
void generateTerranFleet(BattleField *battleField, const char *terranFleetStr)
{
  vectorInit(&battleField->terranFleet, strlen(terranFleetStr));
  int i = 0;
  while (terranFleetStr[i] != '\0')
  {
    TerranAirship *terranAirship;
    initTerranAirship(&terranAirship, terranFleetStr[i]);
    vectorPush(&battleField->terranFleet, terranAirship);
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
    ProtossAirship *protossAirship;
    initProtossAirship(&protossAirship, protossFleetStr[i]);
    vectorPush(&battleField->protossFleet, protossAirship);
    i++;
  }
}
// Count attack turns and check which Battelfield Fleed has remaining ships
void startBattle(BattleField *battleField)
{
  while (true)
  {
    
    if (processTerranTurn(battleField))
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
bool processTerranTurn(BattleField *battleField)
{
  turn++;
  ProtossAirship *lastOfProtoss=lastOfProtoss = (ProtossAirship *)vectorBack(&battleField->protossFleet);
  int terranSize = battleField->terranFleet.size;
  // Takes last enemy ship
 
  int lastProtossID=0;
  // Terran Airships attack one by one
  for (int i = 0; i < terranSize; i++)
  {
    TerranAirship *terranAirship = (TerranAirship *)vectorGet(&battleField->terranFleet, i);
    if(TerranAttack(&lastOfProtoss,battleField, terranAirship,&lastProtossID,i)){
      return true;
    }
    
  }
  printTerranAttack(lastProtossID, lastOfProtoss);
  regenarateShield(lastOfProtoss);
  return false;
}

// returns true when TerranFleet has no ships left, else prints turn info and returns false
bool processProtossTurn(BattleField *battleField)
{
  int protossSize = battleField->protossFleet.size;

  // Takes last enemy ship
  TerranAirship *lastOfTerran = lastOfTerran = (TerranAirship *)vectorBack(&battleField->terranFleet);
  int lastTerranID = 0;
  
  // Protoss Airships attack one by one
  for (int i = 0; i < protossSize; i++)
  {  
    ProtossAirship *protossAirship = (ProtossAirship *)vectorGet(&battleField->protossFleet, i);
    if(ProtossAttack(&lastOfTerran, protossAirship,battleField,i, &lastTerranID)){
      return true;
    }  
  }
 printProtossAttack(lastTerranID, lastOfTerran);
  return false;
}

void printProtossAttack(int ID, TerranAirship *terranAirship)
{
  printf("Last Terran AirShip with ID: %d has %d health left\n", ID, terranAirship->health);
}
void printTerranAttack(int ID, ProtossAirship *protossAirship)
{
  printf("Last Protoss AirShip with ID: %d has %d health and %d shield left\n", ID, protossAirship->health, protossAirship->shield);
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
