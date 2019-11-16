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
// IntakeArm            motor         9               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

competition Competition;

#define PI 3.14159265358979323846
#define WHEEL_DIAMETER 3
#define INTAKE_SPEED 100
#define CTA_SPEED 15
#define REVS_PER_DEGREES 0.02

bool trayUp = false;

// Utilities //
float revsPerDegrees (float degrees){
  return degrees * REVS_PER_DEGREES;
}
float revsPerInches(float wheelDiameter, float inches) {
  return inches / (wheelDiameter * PI);
}

void setSpeed(int speed) {
  DriveFrontLeft.setVelocity(speed, velocityUnits::pct);
  DriveFrontRight.setVelocity(speed, velocityUnits::pct);
  DriveBackLeft.setVelocity(speed, velocityUnits::pct);
  DriveBackRight.setVelocity(speed, velocityUnits::pct);
}
void driveInches(float inches) {
  const float revs = revsPerInches(WHEEL_DIAMETER, inches);
  DriveFrontLeft.rotateFor(revs, rotationUnits::rev, false);
  DriveFrontRight.rotateFor(revs, rotationUnits::rev, false);
  DriveBackLeft.rotateFor(revs, rotationUnits::rev, false);
  DriveBackRight.rotateFor(revs, rotationUnits::rev);
}
void rotateDegrees(int degrees) {
  const float revs = revsPerDegrees(degrees);
  DriveFrontLeft.rotateFor(revs, rotationUnits::rev, false);
  DriveFrontRight.rotateFor(revs, rotationUnits::rev, false);
  DriveBackLeft.rotateFor(-revs, rotationUnits::rev, false);
  DriveBackRight.rotateFor(-revs, rotationUnits::rev);
}
void setTray(bool up) {
  trayUp = up;
  const int ang = (up) ? -450 : 0;
  CubeTrayAngler.rotateTo(ang, rotationUnits::deg, CTA_SPEED, velocityUnits::pct, false);
}
void toggleTray() {
  setTray(!trayUp);
}

// Autonomous //
void autonomous() {

  // start intake motors
  // IntakeLeft.spin(directionType::fwd, INTAKE_SPEED, velocityUnits::pct);
  // IntakeRight.spin(directionType::fwd, INTAKE_SPEED, velocityUnits::pct);

  // // lift intake arm
  // IntakeArm.rotateFor(1000, timeUnits::msec);

  // move around
  setSpeed(75);
  driveInches(20);
  driveInches(-20);
  // rotateDegrees(180);
  } 

// Driver Control //
//         Controls               //
//     Axis 2 | Forward/Back      //
//     Axis 4 | Left/Right        //
//  Button L1 | Intake            //
//  Button L2 | Cube Tray Toggle  //
//  Button R1 |                   //
//  Button R2 |                   //
void usercontrol(void){
  // init
  Controller1.ButtonL2.pressed(toggleTray);

  // loop
  while (1) {
    double thrust = Controller1.Axis2.position();
    double rotate = Controller1.Axis4.position();
    DriveFrontRight.spin(directionType::fwd, thrust - rotate, velocityUnits::pct);
    DriveBackLeft.spin(directionType::fwd, thrust + rotate, velocityUnits::pct);
    DriveFrontLeft.spin(directionType::fwd, thrust + rotate, velocityUnits::pct);
    DriveBackRight.spin(directionType::fwd, thrust - rotate, velocityUnits::pct);

    // if(Controller1.ButtonL1.pressing()){
    //   IntakeLeft.spin(directionType::fwd, INTAKE_SPEED, velocityUnits::pct);
    // } else {
    //   IntakeLeft.spin(directionType::fwd, 0.0, velocityUnits::pct);
    // }
    // if(Controller1.ButtonL1.pressing()){
    //   IntakeRight.spin(directionType::fwd, INTAKE_SPEED, velocityUnits::pct);
    // } else {
    //   IntakeRight.spin(directionType::fwd, 0.0, velocityUnits::pct);
    // }

    if(Controller1.ButtonR1.pressing())
      {
        IntakeLeft.spin(directionType::fwd, 127, velocityUnits::pct);
      
      }
    else if (Controller1.ButtonR2.pressing()) {
      IntakeLeft.spin(directionType::rev, 127, velocityUnits::pct);
    } else {
      IntakeLeft.stop(brakeType::hold);
    }

    if(Controller1.ButtonR1.pressing())
      {
        IntakeRight.spin(directionType::fwd, 127, velocityUnits::pct);
      
      }
    else if (Controller1.ButtonR2.pressing()) {
      IntakeRight.spin(directionType::rev, 127, velocityUnits::pct);
    } else {
      IntakeRight.stop(brakeType::hold);
    }

    // if(Controller1.ButtonR1.pressing()){
    //   IntakeLeft.spin(directionType::rev, INTAKE_SPEED, velocityUnits::pct);
    // } else {
    //   IntakeLeft.spin(directionType::fwd, 0.0, velocityUnits::pct);
    // }
    // // if(Controller1.ButtonR1.pressing()){
    //   IntakeRight.spin(directionType::rev, INTAKE_SPEED, velocityUnits::pct);
    // } else {
    //   IntakeRight.spin(directionType::fwd, 0.0, velocityUnits::pct);
    // }

    if(Controller1.ButtonUp.pressing()) {
      IntakeArm.spin(directionType::fwd, 127, velocityUnits::pct);
    } else if(Controller1.ButtonDown.pressing()) {
      IntakeArm.spin(directionType::rev, 127, velocityUnits::pct);
    } else {
      IntakeArm.stop(brakeType::hold);
    }
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  //*
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  //*/
  // autonomous();
}