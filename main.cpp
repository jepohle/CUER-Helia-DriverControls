#include "mbed.h"
#include "CAN.h"
#include "main.h"
#include "IOFunctions.h"
#include <cstdint>


// Define constants and addresses
#define WHEEL_RADIUS_M 0.275
#define V_MAX_KMH 100.0
#define I_BUS_MAX 122.0
#define THROTTLE_POT_MIN 0.11         //    MEASURE DEFINITIONS!
#define THROTTLE_POT_MAX 0.22
#define BRAKE_POT_MIN 0.11
#define BRAKE_POT_MAX 0.22


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

float speedSetpoint;
float motorCurrentSetpoint;
float maxBusCurrentSetpoint;
float currentSpeed;
float currentMotorCurrent;
float currentBusCurrent;
float cruiseSetpoint;

// Define useful flags
bool IOStateChangeFlag;


// define empty CAN Messages
CANMessage TxMessage;
CANMessage RxMessage;

// Function prototypes              IMPLEMENT THESE!
void calculateThrottle(void);
void CANIT_Callback(void);
void sendDriveCommand(float, float, float, int);
void ignitionIT_Callback(void);
void gearIT_Callback(void);
void cruiseIT_Callback(void);
void modeIT_Callback(void);


// main() runs in its own thread in the OS
int main()
{
    // setup CAN interface:
    CAN CAN1(CAN_RD_PIN, CAN_TD_PIN, 500000);
    CAN1.attach(&CANIT_Callback);

    // initialise IOs
    IOinit();
    ignition.rise(&ignitionIT_Callback);
    gear.rise(&gearIT_Callback);
    cruise_en.rise(&cruiseIT_Callback);
    mode.rise(&modeIT_Callback);





    while (true) {

    }
}

void calculateThrottle(void){

}

void CANIT_Callback(void){

}

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
    TxMessage = CANMessage(CAN_DRIVER_CONTROLS_BASE, 0b10000000, 1);
    while(1){
        CAN1.write(TxMessage);
    }
}