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
    DigitalIn horn(HORN_PIN);

    AnalogIn throttle(THROTTLE_PIN);
    AnalogIn brake(BRAKE_PIN);

    InterruptIn cruise_en(CRUISE_EN_PIN);
    InterruptIn ignition(IGNITION_PIN);
    InterruptIn gear(REVERSE_PIN);
    // InterruptIn mode(DRIVE_)

}

void ReadIO(void){
if(brake >= BRAKE_POT_MIN+0.3){
    brake_state = true;
}
rightIndicatorActive = right_ind | hazards;
leftIndicatorActive = left_ind | hazards;
hornActive = horn;
if(cruise_dec){
    cruiseSetpoint -= 1.0;
}
if(cruise_inc){
    cruiseSetpoint += 1.0;
}
solar_state = solar_en;
}
