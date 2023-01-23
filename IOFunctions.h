#ifndef IOFUNCTIONS_H
#define IOFUNCTIONS_H



#include "mbed.h"

// Define IO pins according to hardware connectivity

#define CAN_RD_PIN p30
#define CAN_TD_PIN p29
#define CRUISE_DEC_PIN p24
#define CRUISE_INC_PIN p23
#define CRUISE_EN_PIN p22
#define BRAKE_PIN p20
#define THROTTLE_PIN p19
#define HORN_PIN p17
#define HAZARDS_PIN p16
#define RIGHT_IND_PIN p15
#define LEFT_IND_PIN p14
#define REAR_FOG_PIN p13
#define FRONT_FOG_PIN p12
#define HEADLIGHTS_PIN p11
#define NITROUS_PIN p10
#define HANDBRAKE_PIN p9
#define REVERSE_PIN p8
#define REGEN_EN_PIN p7
#define SOLAR_PIN p6
#define IGNITION_PIN p5

// Function prototypes

void IOinit(void);
void ReadIO(void);




#endif