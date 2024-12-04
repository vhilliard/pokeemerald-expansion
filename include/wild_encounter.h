#ifndef GUARD_WILD_ENCOUNTER_H
#define GUARD_WILD_ENCOUNTER_H

#include "constants/wild_encounter.h"
#include "config/wild_encounter_times.h"

struct WildPokemon
{
    u8 minLevel;
    u8 maxLevel;
    u16 species;
};

struct WildPokemonInfo
{
    u8 encounterRate;
    const struct WildPokemon *wildPokemon;
};

struct WildPokemonHeader
{
    u8 mapGroup;
    u8 mapNum;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;
    const struct WildPokemonInfo *rockSmashMonsInfo;
    const struct WildPokemonInfo *hiddenMonsInfo;
    const struct WildPokemonInfo *fishingMonsInfo;

#if ENABLE_DAY_NIGHT_ENCOUNTERS
    const struct WildPokemonInfo *landMonsDayInfo;
    const struct WildPokemonInfo *landMonsNiteInfo;
    const struct WildPokemonInfo *landMonsMornInfo;
    const struct WildPokemonInfo *landMonsEvenInfo;
    const struct WildPokemonInfo *waterMonsDayInfo;
    const struct WildPokemonInfo *waterMonsNiteInfo;
    const struct WildPokemonInfo *waterMonsMornInfo;
    const struct WildPokemonInfo *waterMonsEvenInfo;
    const struct WildPokemonInfo *rockSmashMonsDayInfo;
    const struct WildPokemonInfo *rockSmashMonsNiteInfo;
    const struct WildPokemonInfo *rockSmashMonsMornInfo;
    const struct WildPokemonInfo *rockSmashMonsEvenInfo;
#endif
};

extern const struct WildPokemonHeader gWildMonHeaders[];
extern bool8 gIsFishingEncounter;
extern bool8 gIsSurfingEncounter;
extern u8 gChainFishingDexNavStreak;

void DisableWildEncounters(bool8 disabled);
u8 PickWildMonNature(void);
bool8 StandardWildEncounter(u16 currMetaTileBehavior, u16 previousMetaTileBehavior);
bool8 SweetScentWildEncounter(void);
bool8 DoesCurrentMapHaveFishingMons(void);
void FishingWildEncounter(u8 rod);
u16 GetLocalWildMon(bool8 *isWaterMon);
u16 GetLocalWaterMon(void);
bool8 UpdateRepelCounter(void);
bool8 TryDoDoubleWildBattle(void);
bool8 StandardWildEncounter_Debug(void);
u32 CalculateChainFishingShinyRolls(void);
void CreateWildMon(u16 species, u8 level);
u16 GetCurrentMapWildMonHeaderId(void);
u8 ChooseWildMonIndex_Land(void);
u8 ChooseWildMonIndex_WaterRock(void);
u8 ChooseHiddenMonIndex(void);
bool32 MapHasNoEncounterData(void);

#endif // GUARD_WILD_ENCOUNTER_H
