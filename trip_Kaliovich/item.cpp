#include "item.h"

const Item s_item[item_count] =
{
    //NAME                Usage              Lvl $
    {L"�����",            USAGE_WEAPON,      1,  1, L""},                   //0+
    {L"���",              USAGE_WEAPON,      2,  2, L""},                         //1+
    {L"�����",            USAGE_LEGS,        1,  1, L""},                         //2+
    {L"�����",            USAGE_FOOT,        1,  1, L""},                         //3+
    {L"�������",          USAGE_HEAD,        1,  1, L""},                         //4+
    {L"��������",         USAGE_FOOD,        1,  2, L""},                         //5+
    {L"�����",            USAGE_HEAD,        1,  1, L""},                         //6+
    {L"��������",         USAGE_FOOD,        3,  3, L""},                         //7
    {L"�������",          USAGE_FOOD,        1,  1, L""},                         //8
    {L"����",             USAGE_FOOD,        3,  3, L""},                         //9
    {L"������",           USAGE_FOOD,        4,  4, L""},                         //10
    {L"���",              USAGE_FOOD,        5,  5, L""},                         //11
    {L"�������",          USAGE_FOOD,        6,  6, L""},                         //12
    {L"�������",          USAGE_FOOD,        1,  1, L""},                         //13
    {L"�������",          USAGE_FOOD,        7,  7, L""},                         //14
    {L"�������",          USAGE_FOOD,        8,  8, L""},                         //15
    {L"��������",         USAGE_FOOT,        1,  1, L""},                         //16+
    {L"�����",            USAGE_FOOT,        2,  2, L""},                         //17+
    {L"����",             USAGE_FOOT,        3,  3, L""},                         //18
    {L"��������",         USAGE_FOOT,        4,  4, L""},                         //19
    {L"������",           USAGE_FOOT,        5,  5, L""},                         //20
    {L"�����",            USAGE_FOOT,        6,  6, L""},                         //21
    {L"������",           USAGE_BODY,        1,  1, L""},                         //22+
    {L"�����",            USAGE_BODY,        1,  1, L""},                         //23+
    {L"��������",         USAGE_BODY,        2,  2, L""},                         //24+
    {L"�����",            USAGE_BODY,        3,  3, L""},                         //25+
    {L"����",             USAGE_BODY,        4,  4, L""},                         //26
    {L"��������",         USAGE_BODY,        5,  5, L""},                         //27
    {L"������",           USAGE_BODY,        6,  6, L""},                         //28
    {L"������",           USAGE_BODY,        7,  7, L""},                         //29
    {L"�������",          USAGE_BODY,        8,  8, L""},                         //30
    {L"��������",         USAGE_BODY,        10,10, L""},                         //31
    {L"����",             USAGE_HEAD,        1,  1, L""},                         //32+
    {L"�����",            USAGE_HEAD,        2,  2, L""},                         //33+
    {L"�����",            USAGE_HEAD,        3,  3, L""},                         //34+
    {L"��������",         USAGE_HEAD,        4,  4, L""},                         //35
    {L"�����",            USAGE_HEAD,        5,  5, L""},                         //36
    {L"���������",        USAGE_HEAD,        6,  6, L""},                         //37
    {L"�����",            USAGE_HEAD,        7,  7, L""},                         //38
    {L"����",             USAGE_HEAD,        8,  8, L""},                         //39
    {L"�����",            USAGE_NECK,        1,  1, L""},                         //40+
    {L"�������",          USAGE_NECK,        2,  2, L""},                         //41+
    {L"�������",          USAGE_NECK,        3,  3, L""},                         //42+
    {L"��������",         USAGE_NECK,        4,  4, L""},                         //43
    {L"������",           USAGE_NECK,        5,  5, L""},                         //44
    {L"����",             USAGE_NECK,        6,  6, L""},                         //45
    {L"����",             USAGE_NECK,        7,  7, L""},                         //46
    {L"����",             USAGE_NECK,        8,  8, L""},                         //47
    {L"������",           USAGE_ARMS,        1,  1, L""},                         //48+
    {L"���������",        USAGE_ARMS,        2,  2, L""},                         //49+
    {L"���������",        USAGE_ARMS,        3,  3, L""},                         //50
    {L"��������",         USAGE_ARMS,        4,  4, L""},                         //51
    {L"��������",         USAGE_ARMS,        5,  5, L""},                         //52
    {L"���������",        USAGE_LEGS,        1,  1, L""},                         //53+
    {L"�������",          USAGE_LEGS,        2,  2, L""},                         //54+
    {L"������",           USAGE_LEGS,        3,  3, L""},                         //55+
    {L"�����",            USAGE_LEGS,        4,  4, L""},                         //56
    {L"����",             USAGE_LEGS,        5,  5, L""},                         //57
    {L"�����",            USAGE_LEGS,        6,  6, L""},                         //58
    {L"������",           USAGE_LEGS,        7,  7, L""},                         //59   
    {L"��������",         USAGE_LEGS,        8,  8, L""},                         //60    
    {L"�����",            USAGE_WEAPON,      2,  2, L""},                         //61+    
    {L"������",           USAGE_WEAPON,      3,  3, L""},                         //62+    
    {L"���������",        USAGE_WEAPON,      4,  4, L""},                         //63    
    {L"�����",            USAGE_WEAPON,      5,  5, L""},                         //64    
    {L"����",             USAGE_WEAPON,      6,  6, L""},                         //65    
    {L"���",              USAGE_WEAPON,      7,  7, L""},                         //66
    {L"����",             USAGE_NONE,        0,  3, L""},                         //67
    {L"����������",       USAGE_NONE,        0,  2, L""},                         //68
    {L"�������",          USAGE_NONE,        0,  4, L""},                         //69
    {L"���",              USAGE_NONE,        0,  5, L""},                         //70
    {L"���������",        USAGE_INC_HP_MAX,  2,  3, L"������������ � ����"},      //71
    {L"��������",         USAGE_INC_HP_MAX,  1,  3, L"�� �����������"},           //72+
    {L"��������",         USAGE_INC_HP_MAX,  3,  4, L"������������� �����"},      //73
    {L"�������",          USAGE_INC_HP_MAX,  4,  7, L"�������� �� ��������"},     //74
    {L"�������",          USAGE_INC_HP_MAX,  4,  8, L"������ �� �����"},          //75
    {L"����",             USAGE_POISON,      1,  1, L"�� ���������"},             //76
    {L"�����",            USAGE_POISON,      2,  1, L"� ��� ����� �������"},      //77
    {L"�����",            USAGE_POISON,      2,  1, L"���� ������ �������"},      //78
    {L"�����",            USAGE_POISON,      3,  1, L"� ��� ������"},             //79
    {L"������",           USAGE_POISON,      4,  1, L"�� ���������� �� 30 �����"},//80
    {L"��",               USAGE_POISON,      99, 1, L"�� ��� ��"},                //81
    {L"�����",            USAGE_POISON,      1,  1, L"� ��� �������� �����"},     //82
    {L"������",           USAGE_POISON,      5, 19, L"�� �� ������"},             //83
};

std::wstring ItemUsageText(int usage)
{
    if (usage == USAGE_WEAPON)
        return L"������";
    if (usage == USAGE_LEGS)
        return L"����";
    if (usage == USAGE_ARMS)
        return L"����";
    if (usage == USAGE_NECK)
        return L"���";
    if (usage == USAGE_HEAD)
        return L"������";
    if (usage == USAGE_BODY)
        return L"����";
    if (usage == USAGE_FOOT)
        return L"�����";
    if (usage == USAGE_FOOD)
        return L"���";
    if (usage == USAGE_NONE)
        return L"�����";
    if (usage == USAGE_INC_HP_MAX)
        return L"�������";
    if (usage == USAGE_POISON)
        return L"���";
    return L"**Error**";
}