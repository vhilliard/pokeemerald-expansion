#include "global.h"
#include "wild_encounter_times.h"
#include "wild_encounter.h"
#include "rtc.h"
#include "random.h"

#if ENABLE_SEASONAL_ENCOUNTERS

u8 GetCurrentSeason(void)
{
    return SEASONS_DEFAULT;
}

bool8 GetSeasonMon(void)
{
    u8 rand = Random() % 100;

    if(rand < SEASON_ENC_RATE)
        return TRUE;

    return FALSE;
}

u8 ChooseSeasonMonIndex(void)
{
    u8 wildMonIndex = 0;
    u8 rand = Random() % SEASON_SLOT_TOTAL;

    if (rand < SEASON_SLOT_0)
        wildMonIndex = 0;
    else if (rand < SEASON_SLOT_1)
        wildMonIndex = 1;
    else   
        wildMonIndex = -1;

    return wildMonIndex;
}

#endif