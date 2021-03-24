#include "Defines.h"
#include "Airships.h"

void initCarrier(Carrier** carrier);
void afterTurnCarrier(Carrier* carrier);
void updateInterceptors(Carrier* carrier);
void carrierAtackViking(Viking* viking, Carrier* carrier);
void carrierAtackBattleCruser(BattleCruser* battleCruser, Carrier* carrier);