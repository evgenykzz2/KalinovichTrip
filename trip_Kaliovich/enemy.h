#pragma once
#include <string>

#define enemy_count 17


struct Enemy
{
    std::wstring name;
    int hp;
    int level;
    int damage;
    int loot;
    int money;
};

extern const Enemy s_enemy[enemy_count];