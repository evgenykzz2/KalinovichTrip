#include "room.h"
#include "item.h"

const Room s_room[room_count] =
{
    //Text                                                      Enemy
    {L"",                                                       -1   }, //0
    {L"�� ���������� � ������ ������, � �� ������ �� �������",  -1   }, //1
    {L"�� ����� �� ����",                                        1   }, //2
    {L"�� ����� � ������",                                      -1   }, //3
    {L"�� ����� � �������",                                     -1   }, //4
    {L"�� ������� � �������",                                    0   }, //5
    {L"�� ����� �� �����",                                       1   }, //6
    {L"�� ������� � ������",                                    -1   }, //7
    {L"�� ����� � �����",                                       -1   }, //8
    {L"�� ����� �� ������",                                      1   }, //9
    {L"�� ����� � ������� ���� ���",                            -1   }, //10
    {L"�� ����� � ������",                                      -1   }, //11
    {L"�� ����� �� �����",                                      -1   }, //12
    {L"�� ������� � ��������",                                  -1   }, //13
    {L"�� ����������� � ��������",                               2   }, //14
    {L"�� ����� ����� � ������",                                -1   }, //15
    {L"�� �������� � ��������",                                 -1   }, //16
    {L"�� ���������� ������ ����� � �����",                      5   }, //17
    {L"�� ����� � ������!",                                     -1   }, //18
    {L"� ����� �������",                                        -1   }, //19
    {L"�� ��������� � ��������",                                 4   }, //20
    {L"�� ������� � �����",                                     -1   }, //21
    {L"�� ����� � ������",                                       3   }, //22
    {L"�� �������� � ������",                                    2   }, //23
    {L"�� ��������� � ���",                                      2   }, //24
    {L"�� ������� � �������",                                    2   }, //25
    {L"�� ����� � ����-������",                                  2   }, //26
    {L"�� ����� � ������� ������",                               2   }, //27
    {L"�� ���������� � �����",                                   2   }, //28
    {L"�� ��������� ����� � ���������",                          2   }, //29
    {L"�� ����� � �������",                                      2   }, //30
    {L"�� ������ �� ��������",                                  -1   }, //31
    {L"�� ���� � �������",                                       5   }, //32
    //{L"�� ",                                      2   }, //33
    //{L"�� ",                                      2   }, //34
};

int room_fight_complete[room_count];


extern const Action s_action[action_count]=
{
// ������� ���         �����                          ���������
    {1,  AT_LOOT,      L"��������� ��� �������",          0      , L""},
    {1,  AT_MESSAGE,   L"�������� ��� ������",            0      , L"��� ������ �����" },
    {1,  AT_GOTO_ROOM, L"����� � �������",                4      , L"" },
    {1,  AT_GOTO_ROOM, L"����� � ������",                 3      , L"" },
    {1,  AT_GOTO_ROOM, L"����� �� �����",                 2      , L"" },
                                                          
    {2,  AT_LOOT,      L"������� ������",                 48     , L""},
    {2,  AT_GOTO_ROOM, L"����� �� ���",                   6      , L""},
    {2,  AT_GOTO_ROOM, L"������� � �������",              5      , L""},
    {2,  AT_GOTO_ROOM, L"��������� � ������",             1      , L""},
                                                         
    {3, AT_LOOT,       L"�������� ������",                2      , L""},
    {3, AT_HEAL,       L"������� � ��������",             1      , L"��� ����� �����"},
    {3, AT_GET_MONEY,  L"������� ������",                 1      , L"�� ����� ������!"},
    {3, AT_GOTO_ROOM,  L"��������� � ������",             1      , L""},
                                                          
    {4, AT_LOOT,       L"���������� � �����",             3      , L""},
    {4, AT_LOOT,       L"�������� �������",               4      , L""},
    {4, AT_GOTO_ROOM,  L"��������� � ������",             1      , L""},
                                                          
    {5, AT_LOOT,       L"�������� � ����",                16     , L""},
    {5, AT_DAMAGE,     L"������ ���� � �������",          1      , L"���� �������� �����"},
    {5, AT_GOTO_ROOM,  L"������� � ������",               7      , L""},
    {5, AT_GOTO_ROOM,  L"����� �� ����� �����",           9      , L""},
    {5, AT_GOTO_ROOM,  L"��������� �� ����",              2      , L""},
                                                          
    {6, AT_LOOT,       L"��������� ��� �����",            1     , L""},
    {6, AT_GOTO_ROOM,  L"����� � �����",                  8      , L""},
    {6, AT_GOTO_ROOM,  L"��������� �� ����",              2      , L""},
                                                          
    {7, AT_DAMAGE,     L"������� �� ������",              1      , L"��� ����� ������"},
    {7, AT_MESSAGE,    L"������ ������",                  0      , L"�� ���������� ���� �� ��������"},
    {7, AT_GOTO_ROOM,  L"��������� � ������� ",           5      , L""},
                                                          
    {8, AT_LOOT,       L"���������� � ����",              8      , L""},
    {8, AT_HEAL,       L"����� �� �����",                 2      , L"�� ��������"},
    {8, AT_GOTO_ROOM,  L"��������� �� ���",               2      , L""},
                                                         
    {9, AT_DAMAGE,     L"���������� ��� ������ ",         2      , L"��� ������� �����"},
    {9, AT_MESSAGE,    L"���������� � �����",             0      , L"�� ����� ������"},
    {9, AT_GOTO_ROOM,  L"����� � ������",                 11     , L""},
    {9, AT_GOTO_ROOM,  L"������� � ������",               18     , L""},
    {9, AT_GOTO_ROOM,  L"�������� �� ���",                24     , L""},
    {9, AT_GOTO_ROOM,  L"����� � ������� ���� ���",       10     , L""},
    {9, AT_GOTO_ROOM,  L"��������� � �������",            5      , L""},
                                                          
    {10, AT_BUY,       L"������",                         9      , L""},
    {10, AT_SELL,      L"�������",                        9      , L""},
    {10, AT_MESSAGE,   L"��������� � ��������",           0      , L"�������� ������� ��������� �� ���"},
    {10, AT_GOTO_ROOM, L"��������� �� ������",            9      , L""},
                                                          
    {11, AT_LOST_ITEM, L"����� � ����",                   USAGE_HEAD, L"���� �� ��������� � ���� ����� ��� �� ������"},
    {11, AT_MESSAGE,   L"��������� � ��������",           0      , L"����� ���� ��� ������ �� ����"},
    {11, AT_GOTO_ROOM, L"����� � ������ �������",         14     , L""},
    {11, AT_GOTO_ROOM, L"����� �� �������� �����",        13     , L""},
    {11, AT_GOTO_ROOM, L"��������� �� ������",            9      , L""},
                                                          
    {12, AT_LOOT,      L"����� �����������",              11     , L""},
    {12, AT_MESSAGE,   L"��������� ����",                 0      , L""},
    {12, AT_LOOT,      L"������ � �������",               6      , L""},
    {12, AT_GOTO_ROOM, L"����� �� ��������",              14     , L""},      
    {12, AT_GOTO_ROOM, L"��������� � ������",             11     , L""},
                                                          
    {13, AT_MESSAGE,   L"������� �� ��������",            0      , L"��� ���� ��������"},
    {13, AT_LOOT,      L"�������� ����",                  61     , L""},
    {13, AT_GOTO_ROOM, L"����� �� ������� �� ����",       16     , L""},
    {13, AT_GOTO_ROOM, L"�������� � ���",                 15     , L""},
    {13, AT_GOTO_ROOM, L"��������� � ������",             11     , L""},
                                                          
    {14, AT_MESSAGE,   L"���������� ���������",           0      , L"����� ������ ���� ��� ������ �� ����"},
    {14, AT_LOOT,      L"������� ��� ������",             54     , L""},
    {14, AT_HEAL,      L"����� �� �����",                 2      , L"�� ���������"},
    {14, AT_GOTO_ROOM, L"������ ������ ������� � �����",  17     , L""},
    {14, AT_GOTO_ROOM, L"��������� � ������",             11     , L""},
                                                          
    {15, AT_HEAL,      L"�������� � ����",                3      , L"�� ������������ ���� ��������"},
    {15, AT_LOOT,      L"��������� ������",               22     , L""},
    {15, AT_MESSAGE,   L"������� � �������",              0      , L"�� ��������, ��� �� ����?"},
    {15, AT_GOTO_ROOM, L"��������� � ��������",           13     , L""},
                                                          
    {16, AT_DAMAGE,    L"����� ����",                     2      , L"�� ������������ ������"},
    {16, AT_LOOT,      L"�������� � ������",              41     , L""},
    {16, AT_HEAL,      L"������� ����� ����� ���",        1      , L"��� ����� ���������"},
    {16, AT_GOTO_ROOM, L"��������� � ��������",           13     , L""},
                                                          
    {17, AT_DAMAGE,    L"����� � ����",                   2      , L"�� ���������"},
    {17, AT_MESSAGE,   L"���������� � �������",           0      , L"�� ������� ������"},
    {17, AT_GOTO_ROOM, L"��������� � ��������",           14     , L""},

    {18, AT_LOOT,      L"���������� �� �����",            76     , L""},
    {18, AT_HEAL,      L"���� �� ����",                   1      , L"���� �� ������, �� �� ���������"},
    {18, AT_GOTO_ROOM, L"������� �������� �����",         19     , L""},
    {18, AT_GOTO_ROOM, L"����� ������� ��� ������",       21     , L""},
    {18, AT_GOTO_ROOM, L"��������� ��� ��������",         20     , L""},
    {18, AT_GOTO_ROOM, L"��������� �� ������",            17     , L""},

    {19, AT_DAMAGE,    L"�������� � �������",             1      , L"��� �������� ��� �� ����� � ������� �� 1 ���"},
    {19, AT_MESSAGE,   L"������� � ��������",             0      , L"� ����� �� ���� ����"},
    {19, AT_GOTO_ROOM, L"��������� � ������",             18     , L""},

    {20, AT_LOOT,      L"���������� �� �������",          72     , L"�������" },
    {20, AT_LOOT,      L"������� �����������",            77     , L"" },
    {20, AT_GET_MONEY, L"��������� ����",                 3      , L"���" },
    {20, AT_GOTO_ROOM, L"����� � ����� ���",              22     , L""},
    {20, AT_GOTO_ROOM, L"����� � �����",                  21     , L""},
    {20, AT_GOTO_ROOM, L"����� � ������",                 18     , L""},

    {21, AT_LOOT,      L"������� �������� ���",           63     , L"" },
    {21, AT_GOTO_ROOM, L"����� � ������",                 18     , L"" },
    {21, AT_GOTO_ROOM, L"��������� � ��������",           20     , L"" },

    {22, AT_MESSAGE,   L"�������",                         0      , L"����������" },
    {22, AT_GOTO_ROOM, L"����� ���������",                23     , L"" },
    {22, AT_GOTO_ROOM, L"��������� � ��������",           20     , L"" },

    {23, AT_GET_MONEY, L"������������ ���������",         3      , L"" },
    {23, AT_MESSAGE,   L"������",                         0      , L"���-�� ������?" },
    {23, AT_LOOT,      L"����������",                     68     , L"" },
    {23, AT_GOTO_ROOM, L"������� ������� � ������",       22     , L"" },
    {23, AT_GOTO_ROOM, L"����� ������",                   9      , L"" },

    {24, AT_MESSAGE,   L"��������",                       0      , L"��� ����� �� �������"},
    {24, AT_GOTO_ROOM, L"����� �� ����� �������",         25     , L"" },
    {24, AT_GOTO_ROOM, L"����� �� ����� ���",             26     , L"" },
    {24, AT_GOTO_ROOM, L"����� �� ������� �� ����",       29     , L"" },
    {24, AT_GOTO_ROOM, L"��������� �� ������",            9      , L"" },      

    {25, AT_LOOT,      L"���������� � �����",             25     , L"" },
    {25, AT_LOOT,      L"������� � ������",               33     , L"" },
    {25, AT_GOTO_ROOM, L"����� �� ���� �� �������",       26     , L"" },
    {25, AT_GOTO_ROOM, L"����� �� ���",                   25     , L"" },

    {26, AT_GET_MONEY, L"���������� � ����",              3      , L"" },
    {26, AT_LOOT,      L"���������� �� ������",           15     , L"" },
    {26, AT_GOTO_ROOM, L"��������� �� ��������",          27     ,  L""   },
    {26, AT_GOTO_ROOM, L"������ �� ����� �����",          28     , L"" },
    {26, AT_GOTO_ROOM, L"������� � �������",              25     , L"" },
    {26, AT_GOTO_ROOM, L"����� �� ���",                   24     , L"" },

    {27, AT_HEAL,      L"���������",                      4      , L"����������" },
    {27, AT_GOTO_ROOM, L"����� �����",                    30     , L"" },
    {27, AT_GOTO_ROOM, L"��������� � ����-������",        26     , L"" },

    {28, AT_MESSAGE,   L"�������",                        0      , L"��������" },
    {28, AT_LOOT,      L"���������� � ������",            34     , L"" },
    {28, AT_GOTO_ROOM, L"��������� � ����-������",        26     , L"" },

    {29, AT_LOOT,      L"������� ������ ������",          42     , L"" },
    {29, AT_GOTO_ROOM, L"���� � ����-������",             26     , L"" },
    {29, AT_GOTO_ROOM, L"����� �� ���",                   24     , L"" },

    {30, AT_LOOT,      L"�������� � ������",              69     , L"���������� ��������" },
    {30, AT_MESSAGE,   L"�������� ������",                0      , L"�� ����� �����" },
    {30, AT_DAMAGE,    L"�������� ������",                2      , L"��� ���� �� �����" },
    {30, AT_GOTO_ROOM, L"��������� � ������� ������",     27     , L"" },

    {31, AT_GOTO_ROOM, L"������� � ��������",            32    , L"" },
    {31, AT_GOTO_ROOM, L"������� � ������",              33    , L"" },
    {31, AT_GOTO_ROOM, L"������� � ���������",           34    , L"" },
    {31, AT_GOTO_ROOM, L"������� � ",                    35    , L"" },
    {31, AT_GOTO_ROOM, L"������� � ",                    36    , L"" },
    {31, AT_GOTO_ROOM, L"��������� �� ������",           9     , L"" },

    //{32, , L"��������� �� ������",           9     , L"" },
    //{32, AT_GOTO_ROOM, L"���������",           31     , L"" },
};

int room_action_complete[action_count];