#include "Arduino.h"
struct CustomApp {
    String filename;
    String name;
    uint8_t icon[72]; //24x24 пикселя = 72 байта
    bool hasIcon = false;
    bool isValid = false;
};

CustomApp currentApp;
CustomApp prevApp;
CustomApp nextApp;
int catAppCount = 0;
int currentCatAppIndex = 0;
String* catFilenames = nullptr;