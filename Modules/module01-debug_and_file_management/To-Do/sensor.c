#include "sensor.h"  
#include "fake_mcu.h" 

int Sensor_Read(void) {
    int raw_value = MCU_ReadADC();
    
     return raw_value;
}