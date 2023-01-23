#include "mbed.h"
#include "IOFunctions.h"

void IOinit(void){
    DigitalIn cruise_dec(CRUISE_DEC_PIN);
    DigitalIn cruise_inc(CRUISE_INC_PIN);
    DigitalIn hazards(HAZARDS_PIN);
    DigitalIn right_ind(RIGHT_IND_PIN);
    DigitalIn left_ind(LEFT_IND_PIN);
    DigitalIn front_fog(FRONT_FOG_PIN);
    DigitalIn rear_fog(REAR_FOG_PIN);
    DigitalIn regen_en(REGEN_EN_PIN);
    DigitalIn solar_en(SOLAR_PIN);
    
    AnalogIn throttle(THROTTLE_PIN);
    AnalogIn brake(BRAKE_PIN);

    InterruptIn cruise_en(CRUISE_EN_PIN);
    InterruptIn ignition(IGNITION_PIN);
    InterruptIn horn(HORN_PIN);
    InterruptIn gear(REVERSE_PIN);
    // InterruptIn mode(DRIVE)

}

void ReadIO(void){
    
}
