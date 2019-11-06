// To complete the VEXcode V5 Text project upgrade process, please follow the
// steps below.
// 
// 1. You can use the Robot Configuration window to recreate your V5 devices
//   - including any motors, sensors, 3-wire devices, and controllers.
// 
// 2. All previous code located in main.cpp has now been commented out. You
//   will need to migrate this code to the new "int main" structure created
//   below and keep in mind any new device names you may have set from the
//   Robot Configuration window. 
// 
// If you would like to go back to your original project, a complete backup
// of your original (pre-upgraded) project was created in a backup folder
// inside of this project's folder.

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// IntakeLeft           motor         8               
// IntakeRight          motor         15              
// Controller1          controller                    
// DriveBackRight       motor         2               
// DriveBackLeft        motor         10              
// DriveFrontLeft       motor         20              
// DriveFrontRight      motor         11              
// CubeTrayAngler       motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  IntakeLeft.setVelocity(50, velocityUnits::pct);
  IntakeRight.setVelocity(50, velocityUnits::pct);
  int k = 0;
  time_t my_time = time(NULL);
  while (1) {
    my_time = time(NULL);
    Brain.Screen.clearScreen();
    Brain.Screen.print("to #");
    Brain.Screen.print(k);
    Brain.Screen.newLine();
    double thrust = Controller1.Axis2.position();
    double rotate = Controller1.Axis4.position();
    DriveFrontRight.spin(directionType::fwd, thrust - rotate, velocityUnits::pct);
    DriveBackLeft.spin(directionType::fwd, thrust + rotate, velocityUnits::pct);
    DriveFrontLeft.spin(directionType::fwd, thrust + rotate, velocityUnits::pct);
    DriveBackRight.spin(directionType::fwd, thrust - rotate, velocityUnits::pct);

    if (Controller1.ButtonL1.pressing()){
      IntakeLeft.spin(directionType::fwd);
    } else {
      IntakeLeft.spin(directionType::fwd, 0.0, percentUnits::pct);
    }

    if(Controller1.ButtonL1.pressing()){
      IntakeRight.spin(directionType::fwd);
    } else {
      IntakeRight.spin(directionType::fwd, 0.0, percentUnits::pct);
    }
    
    if(Controller1.ButtonL2.pressing()){
      CubeTrayAngler.rotateTo(-315, rotationUnits::deg, 50, velocityUnits::pct);
    } else {
      CubeTrayAngler.stop(brakeType::hold);
    }
    
    if(Controller1.ButtonR2.pressing()) {
      CubeTrayAngler.rotateTo(0, rotationUnits::deg, 50, velocityUnits::pct);
    } else {
      CubeTrayAngler.stop(brakeType::hold);
    }

  }
}