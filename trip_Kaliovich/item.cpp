#include "item.h"

const Item s_item[item_count] =
{
    //NAME                Usage              Lvl $
    {L"Палка",            USAGE_WEAPON,      1,  1, L""},                   //0+
    {L"Нож",              USAGE_WEAPON,      2,  2, L""},                         //1+
    {L"Трусы",            USAGE_LEGS,        1,  1, L""},                         //2+
    {L"Носки",            USAGE_FOOT,        1,  1, L""},                         //3+
    {L"Косынка",          USAGE_HEAD,        1,  1, L""},                         //4+
    {L"Лепесток",         USAGE_FOOD,        1,  2, L""},                         //5+
    {L"Усики",            USAGE_HEAD,        1,  1, L""},                         //6+
    {L"Консерва",         USAGE_FOOD,        3,  3, L""},                         //7
    {L"Жевачка",          USAGE_FOOD,        1,  1, L""},                         //8
    {L"Хлеб",             USAGE_FOOD,        3,  3, L""},                         //9
    {L"Гречка",           USAGE_FOOD,        4,  4, L""},                         //10
    {L"Сыр",              USAGE_FOOD,        5,  5, L""},                         //11
    {L"Колбаса",          USAGE_FOOD,        6,  6, L""},                         //12
    {L"Огрызок",          USAGE_FOOD,        1,  1, L""},                         //13
    {L"Сосиска",          USAGE_FOOD,        7,  7, L""},                         //14
    {L"Морковь",          USAGE_FOOD,        8,  8, L""},                         //15
    {L"Сандалии",         USAGE_FOOT,        1,  1, L""},                         //16+
    {L"Туфли",            USAGE_FOOT,        2,  2, L""},                         //17+
    {L"Кеды",             USAGE_FOOT,        3,  3, L""},                         //18
    {L"Кросовки",         USAGE_FOOT,        4,  4, L""},                         //19
    {L"Сапоги",           USAGE_FOOT,        5,  5, L""},                         //20
    {L"Берцы",            USAGE_FOOT,        6,  6, L""},                         //21
    {L"Лифчик",           USAGE_BODY,        1,  1, L""},                         //22+
    {L"Майка",            USAGE_BODY,        1,  1, L""},                         //23+
    {L"Футболка",         USAGE_BODY,        2,  2, L""},                         //24+
    {L"Кофта",            USAGE_BODY,        3,  3, L""},                         //25+
    {L"Худи",             USAGE_BODY,        4,  4, L""},                         //26
    {L"Ветровка",         USAGE_BODY,        5,  5, L""},                         //27
    {L"Куртка",           USAGE_BODY,        6,  6, L""},                         //28
    {L"Пальто",           USAGE_BODY,        7,  7, L""},                         //29
    {L"Пуховик",          USAGE_BODY,        8,  8, L""},                         //30
    {L"Кольчуга",         USAGE_BODY,        10,10, L""},                         //31
    {L"Очки",             USAGE_HEAD,        1,  1, L""},                         //32+
    {L"Кепка",            USAGE_HEAD,        2,  2, L""},                         //33+
    {L"Шапка",            USAGE_HEAD,        3,  3, L""},                         //34+
    {L"Самбреро",         USAGE_HEAD,        4,  4, L""},                         //35
    {L"Маска",            USAGE_HEAD,        5,  5, L""},                         //36
    {L"Треуголка",        USAGE_HEAD,        6,  6, L""},                         //37
    {L"Каска",            USAGE_HEAD,        7,  7, L""},                         //38
    {L"Шлем",             USAGE_HEAD,        8,  8, L""},                         //39
    {L"Нитка",            USAGE_NECK,        1,  1, L""},                         //40+
    {L"Веревка",          USAGE_NECK,        2,  2, L""},                         //41+
    {L"Цепочка",          USAGE_NECK,        3,  3, L""},                         //42+
    {L"Проволка",         USAGE_NECK,        4,  4, L""},                         //43
    {L"Кабель",           USAGE_NECK,        5,  5, L""},                         //44
    {L"Цепь",             USAGE_NECK,        6,  6, L""},                         //45
    {L"Трос",             USAGE_NECK,        7,  7, L""},                         //46
    {L"Шарф",             USAGE_NECK,        8,  8, L""},                         //47
    {L"Кольцо",           USAGE_ARMS,        1,  1, L""},                         //48+
    {L"Брастлеты",        USAGE_ARMS,        2,  2, L""},                         //49+
    {L"Рукавички",        USAGE_ARMS,        3,  3, L""},                         //50
    {L"Верхунки",         USAGE_ARMS,        4,  4, L""},                         //51
    {L"Перчатки",         USAGE_ARMS,        5,  5, L""},                         //52
    {L"Подгузник",        USAGE_LEGS,        1,  1, L""},                         //53+
    {L"Стринги",          USAGE_LEGS,        2,  2, L""},                         //54+
    {L"Ласины",           USAGE_LEGS,        3,  3, L""},                         //55+
    {L"Шорты",            USAGE_LEGS,        4,  4, L""},                         //56
    {L"Юпка",             USAGE_LEGS,        5,  5, L""},                         //57
    {L"Брюки",            USAGE_LEGS,        6,  6, L""},                         //58
    {L"Джынсы",           USAGE_LEGS,        7,  7, L""},                         //59   
    {L"Шаровары",         USAGE_LEGS,        8,  8, L""},                         //60    
    {L"Копье",            USAGE_WEAPON,      2,  2, L""},                         //61+    
    {L"Лопата",           USAGE_WEAPON,      3,  3, L""},                         //62+    
    {L"Сковорода",        USAGE_WEAPON,      4,  4, L""},                         //63    
    {L"Топор",            USAGE_WEAPON,      5,  5, L""},                         //64    
    {L"Вилы",             USAGE_WEAPON,      6,  6, L""},                         //65    
    {L"Меч",              USAGE_WEAPON,      7,  7, L""},                         //66
    {L"Диск",             USAGE_NONE,        0,  3, L""},                         //67
    {L"Клавиатура",       USAGE_NONE,        0,  2, L""},                         //68
    {L"Дневник",          USAGE_NONE,        0,  4, L""},                         //69
    {L"Мяч",              USAGE_NONE,        0,  5, L""},                         //70
    {L"Энергетик",        USAGE_INC_HP_MAX,  2,  3, L"Незабываемый в вкус"},      //71
    {L"Сигарета",         USAGE_INC_HP_MAX,  1,  3, L"Вы успокоились"},           //72+
    {L"Стероиды",         USAGE_INC_HP_MAX,  3,  4, L"Положытильный ефект"},      //73
    {L"Аспирин",          USAGE_INC_HP_MAX,  4,  7, L"Прорвало на апельсин"},     //74
    {L"Атоксил",          USAGE_INC_HP_MAX,  4,  8, L"Поноса не будет"},          //75
    {L"Жыжа",             USAGE_POISON,      1,  1, L"Не съедобное"},             //76
    {L"Гниль",            USAGE_POISON,      2,  1, L"У вас жывот заболел"},      //77
    {L"Кишки",            USAGE_POISON,      2,  1, L"Вкус просто ужысный"},      //78
    {L"Мозги",            USAGE_POISON,      3,  1, L"У вас срачка"},             //79
    {L"Ампула",           USAGE_POISON,      4,  1, L"Вы отрубились на 30 минут"},//80
    {L"Яд",               USAGE_POISON,      99, 1, L"Ну как бы"},                //81
    {L"Кизяк",            USAGE_POISON,      1,  1, L"У вас началась рвота"},     //82
    {L"Бензин",           USAGE_POISON,      5, 19, L"Ты не машына"},             //83
};

std::wstring ItemUsageText(int usage)
{
    if (usage == USAGE_WEAPON)
        return L"Оружие";
    if (usage == USAGE_LEGS)
        return L"Ноги";
    if (usage == USAGE_ARMS)
        return L"Руки";
    if (usage == USAGE_NECK)
        return L"Шея";
    if (usage == USAGE_HEAD)
        return L"Голова";
    if (usage == USAGE_BODY)
        return L"Тело";
    if (usage == USAGE_FOOT)
        return L"Стопы";
    if (usage == USAGE_FOOD)
        return L"Еда";
    if (usage == USAGE_NONE)
        return L"Фигня";
    if (usage == USAGE_INC_HP_MAX)
        return L"Апгрейд";
    if (usage == USAGE_POISON)
        return L"Еда";
    return L"**Error**";
}