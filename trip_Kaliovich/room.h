#pragma once
#include <string>
#include <set>

#define room_count 39
#define action_count  156

struct Room
{
    std::wstring welcome;
    int enemy;
};

extern const Room s_room[room_count];
extern int room_fight_complete[room_count];
extern std::set<int> room_used_item[room_count];

#define AT_LOOT       0
#define AT_GOTO_ROOM  1
#define AT_DAMAGE     2
#define AT_MESSAGE    3
#define AT_LOST_ITEM  4
#define AT_HEAL       5
#define AT_GET_XP     6
#define AT_GET_MONEY  7
#define AT_LOST_MONEY 8
#define AT_INC_MAX_HP 9
#define AT_BUY        10
#define AT_SELL       11
#define AT_USE_ITEM   12
#define AT_GAME_OVER  13

struct Action
{
    int room;
    int type;
    std::wstring text;
    int result;
    std::wstring message;
};
extern const Action s_action[action_count];
extern int room_action_complete[action_count];
