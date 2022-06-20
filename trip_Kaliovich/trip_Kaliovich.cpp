// trip_Kaliovich.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <iomanip>

#include "room.h"
#include "item.h"
#include "enemy.h"
#include "shop.h"

#define COLOR_RED     L"\x1B[91m"
#define COLOR_GREEN   L"\x1B[92m"
#define COLOR_YELLOW  L"\x1B[93m"
#define COLOR_BLUE    L"\x1B[94m"
#define COLOR_MAGENTA L"\x1B[95m"
#define COLOR_CYAN    L"\x1B[96m"
#define COLOR_WHITE   L"\x1B[97m"
#define COLOR_NONE   L"\x1B[0m"

std::wstring separator = L"________________________";

void ItemDump()
{
    for (size_t i = 0; i < item_count; ++i)
    {
        std::wcout << i << L":" << std::setw(10) << s_item[i].name
            << std::setw(8) << ItemUsageText(s_item[i].usage)
            << L" уровень " << s_item[i].level
            << std::endl;
    }
}

#define INPUT_RECORD

#ifdef INPUT_RECORD
std::vector<int> input_history;
int s_record[96] =
{
    1,1,1,1,1,0,1,1,1,0,1,2,1,1,1,0,1,2,0,1,3,1,1,1,0,2,2,2,0,1,1,1,1,2,1,3,0,0,7,2,1,1,1,1,1,1,0,4,7,1,4,4,4,4,0,0,1,1,1,1,0,4,0,0,4,2,0,1,0,2,2,0,2,0,2,2,0,0,3,1,2,4,7,2,1,1,0,1,4,0,0,1,0,4,4,3,
};
int s_record_index = 0;
#endif

int ReadInput()
{
    int vvod;
#ifdef INPUT_RECORD
    if (s_record_index < sizeof(s_record) / sizeof(int))
    {
        vvod = s_record[s_record_index];
        s_record_index++;
    }
    else
    {
        std::cin >> vvod;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    }
    input_history.push_back(vvod);
    std::wcout << COLOR_BLUE << input_history.size() << COLOR_NONE << std::endl;
    for (size_t i = 0; i < input_history.size(); ++i)
        std::wcout << input_history[i] << L",";
    std::wcout << std::endl;
#else
    std::cin >> vvod;
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
#endif
    return vvod;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    _setmode(_fileno(stdout), _O_U16TEXT);
    //_setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    srand(GetTickCount());

    //ItemDump();
game_reset:
    for (int i = 0; i < room_count; ++i)
    {
        room_fight_complete[i] = 0;
        room_used_item[i].clear();
    }

    for (int i = 0; i < action_count; ++i)
        room_action_complete[i] = 0;

    std::wcout << separator << std::endl;
    std::wcout << COLOR_YELLOW << L"Путишествие чипикика " << COLOR_NONE << std::endl;

    std::vector<int> inventory;
    int player_hp_max = 4;
    int player_hp = player_hp_max;
    int player_level = 1;
    int player_slot[7];
    int player_money = 0;
    for (int i = 0; i < 7; ++i)
        player_slot[i] = -1;
    int room = 1;

    //inventory.push_back(66);
    //inventory.push_back(68);
    //inventory.push_back(69);
    //inventory.push_back(70);

main_loop:
        std::wcout << separator << std::endl;
        std::wcout << s_room[room].welcome << std::endl;
        if (s_room[room].enemy != -1 && room_fight_complete[room] == 0)
        {
            int enemy = s_room[room].enemy;
            int ehp = s_enemy[enemy].hp;
            std::wcout << COLOR_RED << L"На вас напал " << s_enemy[enemy].name << COLOR_NONE << std::endl;
            std::wcout << L"Уровень " << s_enemy[enemy].level << L" урон " << s_enemy[enemy].damage << std::endl;
            std::wcout << std::endl;
            int player_power = player_level;
            for (int i = USAGE_WEAPON; i <= USAGE_FOOT; ++i)
            {
                if (player_slot[i] != -1)
                    player_power = player_power + s_item[player_slot[i]].level;
            }
            if (player_power - s_enemy[enemy].level <= 0 &&
                s_enemy[enemy].level +  s_enemy[enemy].damage - player_power <= 0)
            {
                std::wcout << COLOR_YELLOW << L"Ваши силы равны!" << COLOR_NONE << std::endl;
                std::wcout << COLOR_YELLOW << L"Борьба длится слишком долго" << COLOR_NONE << std::endl;
                std::wcout << COLOR_YELLOW << L"Вы состарились и умерли вместе" << COLOR_NONE << std::endl;
                goto game_reset;
            }
            for (int i = 0; i < 1000; ++i)
            {
                int damage = player_power - s_enemy[enemy].level;
                if (damage < 0)
                    damage = 0;
                std::wcout << L"Вы наносите " << damage << L" урона" << std::endl;
                ehp = ehp - (damage);
                if (ehp < 0)
                    ehp = 0;
                std::wcout << L"Здоровье противника " << ehp << std::endl;
                if (ehp == 0)
                {
                    std::wcout << separator << std::endl;
                    std::wcout << COLOR_CYAN << L"Вы победили" << COLOR_NONE << std::endl;
                    if (s_enemy[enemy].loot != -1)
                    {
                        std::wcout << COLOR_CYAN << L"Вы получили предмет "
                            << s_item[s_enemy[enemy].loot].name << COLOR_NONE << std::endl;
                        inventory.push_back(s_enemy[enemy].loot);
                    }
                    if (s_enemy[enemy].money != 0)
                    {
                        player_money = player_money + s_enemy[enemy].money;
                        std::wcout << COLOR_YELLOW << L"Получено "
                            << s_enemy[enemy].money << L"$, всего " << player_money << L"$" << COLOR_NONE << std::endl;
                    }
                    room_fight_complete[room] = 1;
                    goto room_input;
                }
                std::wcout << std::endl;

                damage = s_enemy[enemy].level + s_enemy[enemy].damage - player_power;
                if (damage < 0)
                    damage = 0;
                std::wcout << s_enemy[enemy].name << L" наносит " << damage << L" урона" << std::endl;
                player_hp = player_hp - damage;
                if (player_hp < 0)
                    player_hp = 0;
                std::wcout << COLOR_GREEN << L"Здоровье игрока " << player_hp << COLOR_NONE << std::endl;
                if (player_hp == 0)
                {
                    std::wcout << separator << std::endl;
                    std::wcout << COLOR_RED << L"Вы умерли" << COLOR_NONE << std::endl;
                    goto game_reset;
                }
                std::wcout << std::endl;
            }
        }
    room_input:
        std::wcout << L"Что вы будите делать?" << std::endl;
        std::wcout << L"" << std::endl;
        int number = 1;
        for (int i = 0; i < action_count; ++i)
        {
            if (s_action[i].room == room &&
                room_action_complete[i] == 0)
            {
                std::wcout << L"  " << number << "-" << s_action[i].text << std::endl;
                number = number+1;
            }
        }
        std::wcout << L"  " << 0 << "-" << L"Меню" << std::endl;
        int vvod = ReadInput();
        
        number = 1;
        for (int i = 0; i < action_count; ++i)
        {
            if (s_action[i].room == room &&
                room_action_complete[i] == 0)
            {
                if (number == vvod)
                {
                    if (s_action[i].type == AT_LOOT)   //Loot
                    {
                        int item = s_action[i].result;
                        std::wcout << separator << std::endl;
                        std::wcout << COLOR_CYAN << L"Вы нашли предмет " << s_item[item].name
                                   << COLOR_NONE <<std::endl;
                        inventory.push_back(item);
                        room_action_complete[i] = 1;
                        goto room_input;
                    }
                    else if (s_action[i].type == AT_GOTO_ROOM)   //Next room
                    {
                        room = s_action[i].result;
                        goto main_loop;
                    }
                    else if (s_action[i].type == AT_MESSAGE)   //Just a test
                    {
                        std::wcout << s_action[i].message << std::endl;
                        room_action_complete[i] = 1;
                        goto main_loop;
                    }
                    else if (s_action[i].type == AT_DAMAGE)
                    {
                        std::wcout << s_action[i].message << std::endl;
                        std::wcout << L"Вы получили " << s_action[i].result << L" единиц урона" << std::endl;
                        player_hp = player_hp - s_action[i].result;
                        if (player_hp < 0)
                            player_hp = 0;
                        std::wcout << COLOR_GREEN << L"Здоровье игрока " << player_hp << L" из " << player_hp_max << COLOR_NONE<< std::endl;
                        if (player_hp <= 0)
                        {
                            std::wcout << separator << std::endl;
                            std::wcout << COLOR_RED << L"Вы умерли" << COLOR_NONE << std::endl;
                            goto game_reset;
                        }
                        //room_action_complete[i] = 1;
                        goto main_loop;
                    }
                    else if (s_action[i].type == AT_LOST_ITEM)
                    {
                        std::wcout << s_action[i].message << std::endl;
                        int slot = s_action[i].result;
                        int item = player_slot[slot];
                        if (item != -1)
                        {
                            std::wcout << COLOR_RED << L"Вы потеряли предмет " << s_item[item].name << COLOR_NONE << std::endl;
                            player_slot[slot] = -1;
                        }
                        room_action_complete[i] = 1;
                        goto main_loop;
                    }
                    else if (s_action[i].type == AT_USE_ITEM)
                    {
                        int item = s_action[i].result;
                        int index = -1;
                        for (size_t n = 0; n < inventory.size(); ++n)
                        {
                            if (inventory[n] == item)
                            {
                                index = n;
                                break;
                            }
                        }
                        if (index == -1)
                            std::wcout << COLOR_RED << L"У вас нет предмета " << s_item[item].name << COLOR_NONE << std::endl;
                        else
                        {
                            inventory.erase(inventory.begin() + index);
                            if (!s_action[i].message.empty())
                                std::wcout << s_action[i].message << std::endl;
                            room_used_item[room].insert(item);
                        }
                        goto main_loop;
                    }
                    else if (s_action[i].type == AT_GAME_OVER)
                    {
                        if (room_used_item[room].find(s_action[i].result) != room_used_item[room].end())
                        {
                            std::wcout << s_action[i].message << std::endl;
                            goto main_loop;
                        }
                        else
                        {
                            std::wcout << COLOR_CYAN << L"Спасибо маме" << COLOR_NONE << std::endl;
                            std::wcout << COLOR_CYAN << L"мам я так заеба**** это делать" << COLOR_NONE << std::endl;
                            std::wcout << COLOR_CYAN << L"програмистом быть сложно" << COLOR_NONE << std::endl;
                            std::wcout << separator << std::endl;
                            std::wcout << COLOR_GREEN << L"Молодец" << COLOR_NONE << std::endl;
                            std::wcout << COLOR_WHITE << L"Программист:" << COLOR_NONE << std::endl;
                            std::wcout << COLOR_WHITE << L"      Сашик" << COLOR_NONE << std::endl;
                            std::wcout << COLOR_GREEN << L"Гейм-дизайнер" << COLOR_NONE << std::endl;
                            std::wcout << COLOR_GREEN << L"      Сашик" << COLOR_NONE << std::endl;
                            std::wcout << COLOR_GREEN << L"Директор" << COLOR_NONE << std::endl;
                            std::wcout << COLOR_GREEN << L"      Сашик" << COLOR_NONE << std::endl;
                            std::wcout << COLOR_GREEN << L"Удачи" << COLOR_NONE << std::endl;
                            goto game_reset;
                        }
                    }
                    else if (s_action[i].type == AT_HEAL)
                    {
                        std::wcout << s_action[i].message << std::endl;
                        std::wcout << L"Вы восполнили " << s_action[i].result << L" единиц здоровья " << std::endl;
                        player_hp = player_hp + s_action[i].result;
                        if (player_hp > player_hp_max)
                            player_hp = player_hp_max;
                        std::wcout << COLOR_GREEN << L"Здоровье игрока " << player_hp << L" из " << player_hp_max << COLOR_NONE << std::endl;
                        room_action_complete[i] = 1;
                        goto main_loop;
                    }
                    else if (s_action[i].type == AT_GET_MONEY)
                    {
                        if (!s_action[i].message.empty())
                            std::wcout << s_action[i].message << std::endl;
                        std::wcout << L"Вы получили " << s_action[i].result << L"$" << std::endl;
                        player_money = player_money + s_action[i].result;
                        std::wcout << COLOR_YELLOW << L"У вас всего " << player_money << L"$" << COLOR_NONE << std::endl;
                        room_action_complete[i] = 1;
                        goto main_loop;
                    }
                    else if (s_action[i].type == AT_LOST_MONEY)
                    {
                        if (!s_action[i].message.empty())
                            std::wcout << s_action[i].message << std::endl;
                        int lost = s_action[i].result;
                        if (lost > player_money)
                            lost = player_money;
                        std::wcout << L"Вы потеряли " << lost << L"$" << std::endl;
                        player_money = player_money - lost;
                        std::wcout << COLOR_YELLOW << L"У вас всего " << player_money << L"$" << COLOR_NONE << std::endl;
                        room_action_complete[i] = 1;
                        goto main_loop;
                    }
                    else if (s_action[i].type == AT_BUY)
                    {
                        loop_buy:
                        int number = 1;
                        for (int i = 0; i < shop_count; ++i)
                        {
                            if (s_shop[i].room == room)
                            {
                                std::wcout << COLOR_YELLOW << L"  " << number << "-"
                                           << std::setw(10) << s_item[s_shop[i].item].name
                                           << std::setw(8) << ItemUsageText(s_item[s_shop[i].item].usage)
                                           << L"   уровень " << s_item[s_shop[i].item].level
                                           << L"   " << s_item[s_shop[i].item].price << L"$"
                                           << std::endl;
                                number++;
                            }
                        }
                        std::wcout << L"  " << 0 << "-" << std::setw(10) << L"Отмена" << COLOR_NONE << std::endl;
                        int vvod = ReadInput();
                        if (vvod == 0)
                        {
                            goto main_loop;
                        }
                        else
                        {
                            int number = 1;
                            for (int i = 0; i < shop_count; ++i)
                            {
                                if (s_shop[i].room == room)
                                {
                                    if (number == vvod)
                                    {
                                        int item = s_shop[i].item;
                                        if (player_money < s_item[item].price)
                                        {
                                            std::wcout << COLOR_RED << L"Недостаточно денег" << COLOR_NONE << std::endl;
                                            goto loop_buy;
                                        }
                                        else
                                        {
                                            player_money = player_money - s_item[item].price;
                                            inventory.push_back(item);
                                            std::wcout << L"Вы приобрели предмет " << s_item[item].name << std::endl;
                                            std::wcout << COLOR_YELLOW << L"Остаток денег " << player_money << L"$" << COLOR_NONE << std::endl;
                                        }
                                    }
                                    number++;
                                }
                            }
                            goto loop_buy;
                        }
                    }
                    else if (s_action[i].type == AT_SELL)
                    {
                loop_sell:
                        std::wcout << L"Инвентарь:" << COLOR_YELLOW << std::endl;
                        int number = 1;
                        for (size_t i = 0; i < inventory.size(); ++i)
                        {
                            int item = inventory[i];
                            std::wcout << L"  " << number << "-"
                                << std::setw(10) << s_item[item].name
                                << std::setw(8) << ItemUsageText(s_item[item].usage)
                                << L"   уровень " << s_item[item].level
                                << L"   " << s_item[item].price << L"$"
                                << std::endl;
                            number = number + 1;
                        }
                        std::wcout << L"  " << 0 << "-" << std::setw(10) << L"Отмена" << COLOR_NONE << std::endl;
                        int vvod = ReadInput();
                        if (vvod == 0)
                        {
                            goto main_loop;
                        }
                        else
                        {
                            int number = 1;
                            for (size_t i = 0; i < inventory.size(); ++i)
                            {
                                int item = inventory[i];
                                if (number == vvod)
                                {
                                    player_money = player_money + s_item[item].price;
                                    std::wcout << L"Вы продали предмет " << s_item[item].name << std::endl;
                                    std::wcout << COLOR_YELLOW << L"Всего денег " << player_money << L"$" << COLOR_NONE << std::endl;
                                    inventory.erase(inventory.begin()+i);
                                }
                                number = number + 1;
                            }
                            goto loop_sell;
                        }
                    }

                }
                number = number + 1;
            }
        }
        if (vvod == 0)
        {
            inventory:
            std::wcout << separator << std::endl;
            std::wcout << COLOR_BLUE << L"Уровень " << player_level << std::endl;
            std::wcout << COLOR_GREEN << L"Здоровье " << player_hp << L" из " << player_hp_max << COLOR_NONE << std::endl;
            std::wcout << COLOR_YELLOW << L"Деньги " << player_money << L"$"<< COLOR_NONE << std::endl;

            std::wcout << L"На персонаже:" << COLOR_WHITE << std::endl;
            for (int i = 0; i <= USAGE_FOOT; ++i)
            {
                std::wcout << std::setw(8) << ItemUsageText(i)
                           << L" ";
                if (player_slot[i] == -1)
                    std::wcout << L"  " << std::setw(10) << L"Пусто" << std::endl;
                else
                {
                    int item = player_slot[i];
                    std::wcout << L"  " << std::setw(10) << s_item[item].name;
                    std::wcout << L"  уровень " << s_item[item].level;
                    std::wcout << std::setw(0) << std::endl;
                }
            }
            std::wcout << COLOR_NONE;

            std::wcout << L"Инвентарь:" << COLOR_YELLOW << std::endl;
            int number = 1;
            for (size_t i = 0; i < inventory.size(); ++i)
            {
                int item = inventory[i];
                std::wcout << number << L":" << std::setw(10) << s_item[item].name
                           << std::setw(8) << ItemUsageText(s_item[item].usage)
                           << L" уровень " << s_item[item].level
                           << std::setw(0) << std::endl;
                number = number + 1;
            }
            std::wcout << COLOR_NONE;

            int vvod = ReadInput();
            if (vvod > 0 && vvod <= inventory.size())
            {
                int i = vvod - 1;
                int item = inventory[i];
                if (s_item[item].usage == USAGE_FOOD)
                {
                    if (player_hp == player_hp_max)
                    {
                        std::wcout << L"Вы не голодны" << std::endl;
                    }
                    else
                    {
                        std::wcout << L"Вы сьедаете " << s_item[item].name << L" и востанавливаете " << s_item[item].level << L" здоровья" << std::endl;
                        player_hp = player_hp + s_item[item].level;
                        if (player_hp > player_hp_max)
                            player_hp = player_hp_max;
                        inventory.erase(inventory.begin() + i);
                    }
                }
                else if (s_item[item].usage == USAGE_INC_HP_MAX)
                {
                    std::wcout << L"Вы употребяете " << s_item[item].name  << std::endl;
                    if (!s_item[item].message.empty())
                        std::wcout << COLOR_GREEN << s_item[item].message << COLOR_NONE << std::endl;
                    player_hp_max = player_hp_max + s_item[item].level;
                    player_hp = player_hp + s_item[item].level;
                    std::wcout << COLOR_GREEN << L"Здоровье игрока " << player_hp
                               << L" из " << player_hp_max << COLOR_NONE << std::endl;
                    inventory.erase(inventory.begin() + i);
                }
                else if (s_item[item].usage == USAGE_NONE)
                {
                    int use = rand() % 3;
                    if (use == 0)
                        std::wcout << L"Вы грызете зубами предмет " << s_item[item].name << std::endl;
                    else if (use == 1)
                        std::wcout << L"Вы прикладываете к голове предмет " << s_item[item].name << std::endl;
                    else
                        std::wcout << L"Вы облизываете предмет " << s_item[item].name << std::endl;
                    std::wcout << L"Никакого эффекта не произошло, но предмет испорчен" << std::endl;
                    inventory.erase(inventory.begin() + i);
                }
                else if (s_item[item].usage == USAGE_POISON)
                {
                    std::wcout << L"Вы употребили " << s_item[item].name << std::endl;
                    if (!s_item[item].message.empty())
                        std::wcout << COLOR_RED << s_item[item].message << COLOR_NONE << std::endl;
                    player_hp = player_hp - s_item[item].level;
                    inventory.erase(inventory.begin() + i);
                    if (player_hp < 0)
                        player_hp = 0;
                    std::wcout << COLOR_GREEN << L"Здоровье игрока " << player_hp << L" из " << player_hp_max << COLOR_NONE << std::endl;
                    if (player_hp <= 0)
                    {
                        std::wcout << separator << std::endl;
                        std::wcout << COLOR_RED << L"Вы умерли" << COLOR_NONE << std::endl;
                        goto game_reset;
                    }
                }
                else if (s_item[item].usage >= USAGE_WEAPON && s_item[item].usage <= USAGE_FOOT)
                {
                    int tip = s_item[item].usage;
                    if (player_slot[tip] != -1)
                    {
                        int t = player_slot[tip];
                        player_slot[tip] = inventory[i];
                        inventory[i] = t;
                    }
                    else
                    {
                        player_slot[tip] = inventory[i];
                        inventory.erase(inventory.begin() + i);
                    }
                }
            }
            if (vvod == 0)
                goto room_input;
            else
                goto inventory;
        }
        else
        {
            std::wcout << separator << std::endl;
            std::wcout << L"Неправильный ввод" << std::endl;
            goto room_input;
        }

    goto main_loop;
    return 0;
}
