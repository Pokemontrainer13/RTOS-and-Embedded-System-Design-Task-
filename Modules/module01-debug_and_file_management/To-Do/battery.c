#include "battery.h"
#include "fake_mcu.h"

int Battery_ReadVoltage(void) {
    int voltage = MCU_ReadBatteryVoltage();
    
    return voltage;
}