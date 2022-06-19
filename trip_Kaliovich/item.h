#pragma once
#include <string>

#define item_count 84

struct Item
{
    std::wstring name;
    int usage;
    int level;
    int price;
    std::wstring message;
};

#define USAGE_WEAPON      0
#define USAGE_LEGS        1
#define USAGE_ARMS        2
#define USAGE_NECK        3
#define USAGE_HEAD        4
#define USAGE_BODY        5
#define USAGE_FOOT        6
#define USAGE_FOOD        7
#define USAGE_NONE        8
#define USAGE_INC_HP_MAX  9
#define USAGE_POISON      10

extern const Item s_item[item_count];
std::wstring ItemUsageText(int usage);