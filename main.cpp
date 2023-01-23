#include "mbed.h"
#include "CAN.h"
#include "main.h"
#include "IOFunctions.h"


// Define constants and addresses
#define WHEEL_RADIUS_M 0.275
#define V_MAX_KMH 100.0
#define I_BUS_MAX 122.0
// #define THROTTLE_POT_MIN 0.11             MEASURE DEFINITIONS!
// #define THROTTLE_POT_MAX 0.22
// #define BRAKE_POT_MIN
// #define BRAKE_POT MAX


// Define variables
bool ignition_state = false;
bool cruise_state = false;
bool brake_state =false;
 


// main() runs in its own thread in the OS
int main()
{
    while (true) {

    }
}

