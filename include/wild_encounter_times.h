#ifndef GUARD_WILD_ENCOUNTER_TIMES_H
#define GUARD_WILD_ENCOUNTER_TIMES_H

#include "config/wild_encounter_times.h"
#include "constants/wild_encounter_times.h"

#if ENABLE_SEASONAL_ENCOUNTERS

u8 GetCurrentSeason(void);
bool8 GetSeasonMon(void);
u8 ChooseSeasonMonIndex(void);

#endif

#endif // GUARD_WILD_ENCOUNTER_TIMES_H
