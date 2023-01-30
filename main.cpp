#include "mbed.h"
#include <cstdint>

/**
*@file CUER-Helia-Driver-Controls-2023
*@brief A rewrite of the CUER Helia driver controls firmware, started in January 2023. Aims to increase documentation and 
*reliability as well as safety of Helia's software package.
*@author Jeremias Pohle
*Contact: jep78@cam.ac.uk
*/



// Define vehicle, safety and other useful constants
#define WHEEL_RADIUS_M 0.275
#define V_MAX_KMH 100.0
#define I_BUS_MAX 122.0
#define THROTTLE_POT_MIN 0.11         //    MEASURE DEFINITIONS!
#define THROTTLE_POT_MAX 0.22
#define BRAKE_POT_MIN 0.11
#define BRAKE_POT_MAX 0.22

// define CAN addresses according to CAN bus guidelines
#define CAN_DRIVER_CONTROLS_BASE 0x500
#define CAN_MOTOR_CONTROLLER_L_TX 0x200
#define CAN_MOTOR_CONTROLLER_R_TX 0x220
#define CAN_MOTOR_CONTROLLER_L_RX 0x300
#define CAN_MOTOR_CONTROLLER_R_RX 0x320
#define CAN_MOTOR_CONTROLLER_DRIVE_TX 0x1
#define CAN_MOTOR_CONTROLLER_BUS_TX 0x2
#define CAN_BMU_BASE 0x550
#define CAN_FRONT_PCU 0x570
#define CAN_REAR_PCU 0x590
#define CAN_LIGHTS 0x730
#define CAN_CHARGER_TX 0x1806E5F4
#define CAN_CHARGER_RX 0x18FF50E5
#define CAN_FRONT_IVT 0x520
#define CAN_REAR_IVT 0x530
#define CAN_IVT_Current 0x1
#define CAN_IVT_Voltage 0x2
#define CAN_IVT_Temp 0x5
#define CAN_IVT_Energy 0x8
#define CAN_MPPT_POWER_TX 0x202
#define CAN_MPPT_INPUT_RX 0x180
#define CAN_MPPT_OUTPUT_RX 0x280
#define CAN_MPPT_TEMP_RX 0x480

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






// Define variables
bool ignition_state = false;
bool cruise_state = false;
bool brake_state = false;
bool solar_state = false;
bool rightIndicatorActive = false;
bool leftIndicatorActive = false;
bool hornActive = false;

int driveMode = 0;    //Modes correspond to 0: regular torque controlled full throw driving
                  //                    1: low power single motor drive, motor allocated randomly, unless error in one motor controller
                  //                    2: no regen, just coast to stop when throttle lifted
                  //                    3: 
// int cruise_dec;
// int cruise_inc;
// int hazards;
// int right_ind;
// int left_ind;
// int front_fog;
// int rear_fog;
// int regen_en;
// int solar_en;
// int horn;

// float throttle;
// float brake;
float speedSetpoint;
float motorCurrentSetpoint;
float maxBusCurrentSetpoint;
float currentSpeed;
float currentMotorCurrent;
float currentBusCurrent;
float cruiseSetpoint;

// Define useful flags
bool IOStateChangeFlag;


// define empty CAN Messages and create CAN Object
CAN CAN1(CAN_RD_PIN, CAN_TD_PIN, 500000);
CANMessage TxMessage;
CANMessage RxMessage;



//Function prototypes below, sorted after category.

// IO Function prototypes
void ReadIO(void);

// Function prototypes              IMPLEMENT THESE!
void calculateThrottle(void);
// void CANIT_Callback(void);
void sendDriveCommand(float, float, float, int);
void ignitionIT_Callback(void);
void gearIT_Callback(void);
void cruiseIT_Callback(void);
void modeIT_Callback(void);



// Initialise all IO
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







// main() runs in its own thread in the OS
int main()
{
    // setup CAN interface:
    CAN1.reset();
    // CAN1.attach(&CANIT_Callback);

    // start and attach button interrupts
    ignition.rise(&ignitionIT_Callback);
    gear.rise(&gearIT_Callback);
    cruise_en.rise(&cruiseIT_Callback);
    // mode.rise(&modeIT_Callback);






    while (true) {

    }
}

void calculateThrottle(void){

}

// void CANIT_Callback(void){

// }

void sendDriveCommand(float, float, float, int){

}

void ignitionIT_Callback(void){

}

void gearIT_Callback(void){

}

void cruiseIT_Callback(void){

}

void modeIT_Callback(void){

}

void Error_Handler(void){
    // Enter infinite loop of sending 
    TxMessage.format = CANStandard;
    TxMessage.id = CAN_DRIVER_CONTROLS_BASE;
    TxMessage.data[0] = 0b10000000;
    TxMessage.len = 1;   
    while(1){
        CAN1.write(TxMessage);
    }
}

// Function to set flags according to IO states.
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