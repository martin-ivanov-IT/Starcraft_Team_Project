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
int generateTerranFleet(BattleField *battleField, const char *terranFleetStr){
  vectorInit(&battleField->terranFleet, strlen(terranFleetStr));
  int index = 0;
  while (terranFleetStr[index] != '\0'){
      if(terranFleetStr[index] == 'v'){
          Viking *viking = malloc(sizeof(Viking));
            if(viking==NULL){
                perror("File \"BattleField.c\",  generateProtossFleet()");
                exit(EXIT_FAILURE);
            }

          initViking(viking, VIKING, VIKING_NAME, VIKING_HEALTH, VIKING_DAMAGE, index);
          vectorPush(&battleField->terranFleet, viking);
      }
      else if(terranFleetStr[index] == 'b'){
          BattleCruiser *battleCruiser = malloc(sizeof(BattleCruiser));
          if(battleCruiser==NULL){
              perror("File \"BattleField.c\",  generateProtossFleet()");
              exit(EXIT_FAILURE);
          }
          initBattleCruiser(battleCruiser, BATTLE_CRUSER, BATTLE_CRUSER_NAME, BATTLE_CRUSER_HEALTH, BATTLE_BRUSER_DAMAGE, index);
          vectorPush(&battleField->terranFleet, battleCruiser);
      }
      else return 1; 
      index++;
  }
return 0;
}

//Initialize and fill up ProtossFleet with Protoss Airships according to string input
int generateProtossFleet(BattleField *battleField, const char *protossFleetStr){
    vectorInit(&battleField->protossFleet, strlen(protossFleetStr));
    int index = 0;
    while (protossFleetStr[index] != '\0'){
        if(protossFleetStr[index] == 'p'){
            Phoenix* phoenix = malloc(sizeof(Phoenix));
            if(phoenix==NULL){
                perror("File \"BattleField.c\",  generateProtossFleet()");
                exit(EXIT_FAILURE);
            }
            initPhoenix(phoenix, PHOENIX_NAME, PHOENIX_HEALTH, PHOENIX_DAMAGE, PHOENIX_SHIELD,
                            PHOENIX_SHIELD_REGENERATE_RATE, PHOENIX, index);
            vectorPush(&battleField->protossFleet, phoenix);
        }
        else if(protossFleetStr[index] == 'c'){
            Carrier *carrier = malloc(sizeof(Carrier));
            if(carrier==NULL){
                perror("File \"BattleField.c\",  generateProtossFleet()");
                exit(EXIT_FAILURE);
            }
            initCarrier(carrier, CARRIER_NAME, CARRIER_HEALTH, CARRIER_DAMAGE, CARRIER_SHIELD,
                        CARRIER_SHIELD_REGENERATE_RATE, CARRIER, index);
            vectorPush(&battleField->protossFleet, carrier);
        }
        else return 1;
      
        index++;
      }
  return 0;
  }

  // Count attack turns and check which Battelfield Fleed has remaining ships
  int startBattle(BattleField *battleField){
      int turn = 0;
      while (true){
          turn++;
          if (processTerranTurn(battleField, turn)){
              if(errNo){
                  printf("ERROR: File \"BattleField.c\",  processTerranTurn()");
                  exit(EXIT_FAILURE);
              }
              printf("TERRAN has won!\n");
              break;
          }
          if (processProtossTurn(battleField)){
              if(errNo){
                  printf("ERROR: File \"BattleField.c\",  processProtossTurn()");
                  exit(EXIT_FAILURE);
              }
              printf("PROTOSS has won!\n");
              break;
          }
    }
return 0;
}

// returns true when ProtossFleet has no ships left, else prints turn info and returns false
bool processTerranTurn(BattleField *battleField, int turn){
  if (battleField == NULL){
        errNo = 1;
    }
  internErrNo = 0;
  int terranSize = battleField->terranFleet.size;
  ProtossAirship *lastOfProtoss = (ProtossAirship *)vectorBack(&battleField->protossFleet);
  
  // Terran Airships attack one by one
  int damage = 0;
  for (int i = 0; i < terranSize; i++){
    TerranAirship* terranAirship = (TerranAirship *)vectorGet(&battleField->terranFleet, i);
    if(terranAirship->type == VIKING){
      // take damage done by atack airship and return value as int
      damage = vikingProduceDamage(lastOfProtoss->airship.type);
      if(internErrNo){
        printf("ERROR: File \"BattleField.c\",  vikingProduceDamage()");
        exit(EXIT_FAILURE);
      }
    }
    else if(terranAirship->type == BATTLE_CRUSER){
      damage = battleCruiseProduceDamage(turn);
      if(internErrNo){
        printf("ERROR: File \"BattleField.c\",  battleCruiseProduceDamage()");
        exit(EXIT_FAILURE);
      }
    }
    // reduce health and sheild of enemy airship and remove if dead
    if(protossDealDamage(&lastOfProtoss, &battleField->protossFleet,damage, terranAirship->name, terranAirship->ID)){
        printf("ERROR: File \"BattleField.c\",  protossDealDamage()");
        exit(EXIT_FAILURE);
    }
    
    if(battleField->protossFleet.size == 0){
      return true;
    }
  }
  printProtossHurt(lastOfProtoss);
  errNo = 0;
  return false;
}

// returns true when TerranFleet has no ships left, else prints turn info and returns false
bool processProtossTurn(BattleField *battleField){
  if (battleField == NULL){
        errNo = 1;
    }
  internErrNo = 0;
  int protossSize = battleField->protossFleet.size;
  TerranAirship *lastOfTerran = (TerranAirship *)vectorBack(&battleField->terranFleet);
  for (int i = 0; i < protossSize; i++){
    ProtossAirship* protossAirship = (ProtossAirship *)vectorGet(&battleField->protossFleet, i);
    int damage = 0;
    if(protossAirship->airship.type == PHOENIX){
      // take damage done by atack airship and return value as int
      damage = baseProduceDamage(&protossAirship->airship);
      if(internErrNo){
        printf("ERROR: File \"BattleField.c\",  baseProduceDamage()");
        exit(EXIT_FAILURE);
      }

      // reduce health of enemy airship and remove if dead
      if(baseDealDamage(&lastOfTerran, &battleField->terranFleet, damage, protossAirship->airship.name, protossAirship->airship.ID)){
        printf("ERROR: File \"BattleField.c\",  baseDealDamage()");
        exit(EXIT_FAILURE);
      }
      
      // regen shield after phoenix turn is finished
      if(phoenixRegenerate(protossAirship)){
        printf("ERROR: File \"BattleField.c\",  phoenixRegenerate()");
        exit(EXIT_FAILURE);
      }    
    }
    else if(protossAirship->airship.type == CARRIER){
    // return value of intercoptors count
     int attacks = getCarrierAtacks(protossAirship);
    if(internErrNo){
       printf("ERROR: File \"BattleField.c\",  getCarrierAtacks()");
       exit(EXIT_FAILURE);
    }
    if(terranDealDamageByCarrier(&lastOfTerran, &battleField->terranFleet, attacks,
      protossAirship->airship.name, protossAirship->airship.ID)){
          printf("ERROR: File \"BattleField.c\",  terranDealDamageByCarrier()");
          exit(EXIT_FAILURE);
    } 
      // regen shield after carrier turn is finished
      if(carrierRegenerate(protossAirship)){
          printf("ERROR: File \"BattleField.c\",  carrierRegenerate()");
          exit(EXIT_FAILURE);
      }  
    } 
    if(battleField->terranFleet.size == 0){
        return true;
    }
  }
  printTerranHurt(lastOfTerran);
  errNo = 0;
  return false;
}

void printTerranHurt(TerranAirship *terranAirship){
    printf("Last Terran AirShip with ID: %d has %d health left\n", terranAirship->ID, terranAirship->health);
}

void printProtossHurt(ProtossAirship *protossAirship){
    printf("Last Protoss AirShip with ID: %d has %d health and %d shield left\n", protossAirship->airship.ID, protossAirship->airship.health, protossAirship->shield);
}

// Free the memory allocated for the Airships, then free the memory allocated for the BattleFleeds
int deinit(BattleField *battleField){
    int terranSize = battleField->terranFleet.size;
    for (int i = 0; i < terranSize; i++){
        free(vectorGet(&battleField->terranFleet, i));
    }
    int protossSize = battleField->protossFleet.size;
    for (int i = 0; i < protossSize; i++){
        free(vectorGet(&battleField->protossFleet, i));
    }
    vectorFree(&battleField->terranFleet);
    vectorFree(&battleField->protossFleet);
return 0;
}