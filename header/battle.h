//battle.h

#ifndef BATTLE_H
#define BATTLE_H

#include <string>
#include <vector>
using namespace std;

int callBattle(const string p_name, int& p_hp, int p_atk[2], const string e_name, int& e_hp, int e_atk[2], bool (&items)[6], float time_allowed);

int call_sample_battle();

int call_new_battle(const string p_name, const string e_name, vector<string> items, string difficulty, int level);

#endif