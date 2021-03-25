#include "Airship.h"

void initAirship(char c, Airship* ship){
   if(c == 'v'){
      ship->type = VIKING;
      ship->health =(int) VIKING_HEALTH;
      ship->shield = 0;
      ship->shieldRegenerateRate = 0;
      ship->demage =(int)VIKING_DAMAGE;
    }
    else if (c =='b'){
      ship->type = BATTLE_CRUSER;
      ship->health = (int)BATTLE_CRUSER_HEALTH;
      ship->shield = 0;
      ship->shieldRegenerateRate = 0;
      ship->demage = (int)BATTLE_BRUSER_DAMAGE;
    }
    else if(c == 'p'){
      ship->type = PHOENIX;
      ship->health = (int)PHOENIX_HEALTH;
      ship->shield = (int)PHOENIX_SHIELD;
      ship->shieldRegenerateRate =(int)PHOENIX_SHIELD_REGENERATE_RATE;
      ship->demage = (int)PHOENIX_DAMAGE;
    }
    else if (c == 'c'){
      ship->type = CARRIER;
      ship->health =(int)CARRIER_HEALTH;
      ship->shield = (int)CARRIER_SHIELD;
      ship->shieldRegenerateRate = (int)CARRIER_SHIELD_REGENERATE_RATE;
      ship->demage = (int)CARRIER_DAMAGE;
    }
}
