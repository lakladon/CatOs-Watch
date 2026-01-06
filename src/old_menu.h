#include "Arduino.h"
// Структура для пункта меню
struct MenuItem {
  const char* name;
  void (*action)();
};

// Структура для меню
struct Menu {
  const char* title;
  bool showTime;
  MenuItem* items;
  uint8_t itemCount;
};

// Глобальные переменные
int8_t pointer = 0;
int8_t top_item = 0;
Menu* currentMenu = nullptr;
Menu* previousMenu = nullptr;

#define VISIBLE_ITEMS 7
// Пункты главного меню
MenuItem mainMenuItems[] = {
  {" Игры", games_menu},
  {" Настройки", custom_apps_menu},
  {" Утилиты", utilities_menu},
  {" Wifi-точка", select_wifi_mode},
  {" Выход", nullptr}
};

// Пункты меню игр
MenuItem gamesMenuItems[] = {
  {" Ардуино дино", dinosaurGame},
  {" CatOsGotchi", pet_menu},
  {" Рулетка", rouletteGame},
  {" Змейка", snakeGame},
  {" Назад", main_menu}
};

MenuItem selectWifiModeItems[] = {
  {" Загрузка файлов", create_settings},
  {" Синхранизация времени", time_sync_menu},
  {" Назад", main_menu}
};

MenuItem utilitiesMenuItems[] = {
  {" Читалка", ShowFilesLittleFS},
  {" Калькулятор", calc},
  {" Секундомер", stopwatch},
  {" Таймер", timer},
  {" Будильник", alarm_menu},
  {" Назад", main_menu}
};

// Создание меню
Menu mainMenu = {"Главное меню", true, mainMenuItems, 5};
Menu gamesMenu = {"Игры", true, gamesMenuItems, 3};
Menu selectWifiMode = {"Выбор Wifi", true, selectWifiModeItems, 3};
Menu utilitiesMenu = {"Утилиты", true, utilitiesMenuItems, 6};