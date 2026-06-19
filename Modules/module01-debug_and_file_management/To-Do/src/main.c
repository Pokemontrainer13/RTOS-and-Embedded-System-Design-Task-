#include <stdio.h>      
#include "sensor.h"     
#include "battery.h"    
#include "fake_mcu.h"

int main(void) {

    while(1){

        int sensor_val = Sensor_Read();
        int battery_val = Battery_ReadVoltage();
        
        /* 2. Print the information to the screen */
        printf("Reading: Sensor Value = %d | Battery = %d \n", sensor_val, battery_val);
    }
    
    return 0;
}