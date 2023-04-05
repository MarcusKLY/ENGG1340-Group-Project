//battle.h

#ifndef BATTLE_H
#define BATTLE_H

#include <string>
#include <vector>
using namespace std;

int callBattle(string& p_name, int& p_hp, int p_atk[2], string& e_name, int& e_hp, int e_atk[2], bool (&items)[6], float time_allowed);

int call_sample_battle();

#endif