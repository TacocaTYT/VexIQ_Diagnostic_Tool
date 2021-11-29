//THIS CODE FOR DIAGNOSTIC OF THE IQ SENSORS
//
//DEVELOPED BY KATTE
//
//https://github.com/TacocaTYT/VexIQ_Diagnostic_Tool
//
//
//MADE ON 29/11/2021

#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START IQ MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END IQ MACROS


// Robot configuration code.
bumper Bumper3 = bumper(PORT3);
bumper Bumper9 = bumper(PORT9);
gyro Gyro4 = gyro(PORT4);
colorsensor Color6 = colorsensor(PORT6);
sonar Distance1 = sonar(PORT1);
#pragma endregion VEXcode Generated Robot Configuration
// Include the IQ Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

int Brain_precision = 0;

float myVariable;

// Used to find the format string for printing numbers with the
// desired number of decimal places
const char* printToBrain_numberFormat() {
  // look at the current precision setting to find the format string
  switch(Brain_precision){
    case 0:  return "%.0f"; // 0 decimal places (1)
    case 1:  return "%.1f"; // 1 decimal place  (0.1)
    case 2:  return "%.2f"; // 2 decimal places (0.01)
    case 3:  return "%.3f"; // 3 decimal places (0.001)
    default: return "%f"; // use the print system default for everthing else
  }
}

// "when started" hat block
int whenStarted1() {
  wait(1.0, seconds);
  Brain_precision = 0;
  Color6.setLight(100, percent);
  while (true) {
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(4, 12);
    Brain.Screen.print("Battery:");
    Brain.Screen.setCursor(4, 20);
    Brain.Screen.print(printToBrain_numberFormat(), static_cast<float>(Brain.Battery.capacity(percent)));
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Distance:");
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print("LBump:");
    Brain.Screen.setCursor(5, 1);
    Brain.Screen.print("Bright:");
    Brain.Screen.setCursor(5, 12);
    Brain.Screen.print("Hue:");
    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print("RBump:");
    Brain.Screen.setCursor(4, 1);
    Brain.Screen.print("Heading:");
    Brain.Screen.setCursor(1, 10);
    Brain_precision = -1;
    Brain.Screen.print(printToBrain_numberFormat(), static_cast<float>(Distance1.distance(mm)));
    Brain_precision = 0;
    Brain.Screen.setCursor(4, 9);
    Brain.Screen.print(printToBrain_numberFormat(), static_cast<float>(Gyro4.heading()));
    Brain.Screen.setCursor(5, 8);
    Brain.Screen.print(printToBrain_numberFormat(), static_cast<float>(static_cast<float>(Color6.brightness())));
    Brain.Screen.setCursor(5, 16);
    Brain.Screen.print(printToBrain_numberFormat(), static_cast<float>(Color6.hue()));
    if (Bumper3.pressing()) {
      Brain.Screen.setCursor(2, 7);
      Brain.Screen.print("Pressed");
    }
    if (Bumper9.pressing()) {
      Brain.Screen.setCursor(3, 7);
      Brain.Screen.print("Pressed");
    }
  wait(20, msec);
  }
  return 0;
}


int main() {
  whenStarted1();
}
