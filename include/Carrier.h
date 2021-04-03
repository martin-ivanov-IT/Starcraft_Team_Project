#ifndef Carrier_H_
#define Carrier_H_

#include "Defines.h"
#include "Airship.h"
#include "ProtossAirship.h"
typedef struct {
  int count;
  int damage;
}Interceptors;

typedef ProtossAirship Carrier;
 
void initCarrier(Carrier* carrier, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType);

int carrierProduceDamage(Carrier* carrier);

#endif
