/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\AwtyCAD2                                         */
/*    Created:      Sat Nov 02 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
vex::competition Competition;
vex::controller OurController;

motor frd(PORT11, gearSetting::ratio18_1, true); //frd=Front Right Drive motor obviously alex
motor fld(PORT20, gearSetting::ratio18_1, false); //fld=Front Left Drive motor obviously alex
motor brd(PORT2, gearSetting::ratio18_1, true); //brd=Back Right Drive motor duhhhh alexxxxxxxx
motor bld(PORT10, gearSetting::ratio18_1, false); //bld= Back Left Drive motor duhhhhh jeezzz ALEXXXXXX
motor iml(PORT8, gearSetting::ratio18_1, false); //Intake motor left wooooahhhhh really i didnt know alexx 
motor imr(PORT4, gearSetting::ratio18_1, false); //Intake motor right im shook its so NOT OBVIOUS ALEX ALEX Alex drosophilia vfdsigheirwral

const double square_length = 24.0;
const double turn_distance = 8.5;
const double wheel_diameter = 2.5;


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */

/*---------------------------------------------------------------------------*/
double dist(double dista, double diameter) {
  double circumference = diameter*3.14159265368979323846;
  return dista/circumference;
}
void autonomous( void ) {
//vicotry spin
    fld.setVelocity(50, velocityUnits::pct);
    frd.setVelocity(50, velocityUnits::pct);
    brd.setVelocity(50, velocityUnits::pct);
    bld.setVelocity(50, velocityUnits::pct);
    
    //forward
    frd.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev, false);
    fld.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev, false);
    brd.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev, false);
    bld.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev);
   //turn
    frd.rotateFor(dist (turn_distance,wheel_diameter), rotationUnits::rev, false);
    fld.rotateFor(dist (-turn_distance,wheel_diameter), rotationUnits::rev, false);
    brd.rotateFor(dist (turn_distance,wheel_diameter), rotationUnits::rev, false);
    bld.rotateFor(dist (-turn_distance,wheel_diameter), rotationUnits::rev);
    //forward
    frd.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev, false);
    fld.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev, false);
    brd.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev, false);
    bld.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev);
   //turn
    frd.rotateFor(dist (turn_distance,wheel_diameter), rotationUnits::rev, false);
    fld.rotateFor(dist (-turn_distance,wheel_diameter), rotationUnits::rev, false);
    brd.rotateFor(dist (turn_distance,wheel_diameter), rotationUnits::rev, false);
    bld.rotateFor(dist (-turn_distance,wheel_diameter), rotationUnits::rev);
    //forward
    frd.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev, false);
    fld.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev, false);
    brd.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev, false);
    bld.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev);
    //turn
    frd.rotateFor(dist (turn_distance,wheel_diameter), rotationUnits::rev, false);
    fld.rotateFor(dist (-turn_distance,wheel_diameter), rotationUnits::rev, false);
    brd.rotateFor(dist (turn_distance,wheel_diameter), rotationUnits::rev, false);
    bld.rotateFor(dist (-turn_distance,wheel_diameter), rotationUnits::rev);
    //forward
    frd.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev, false);
    fld.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev, false);
    brd.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev, false);
    bld.rotateFor(dist(square_length,wheel_diameter), rotationUnits::rev);
    //turn
    frd.rotateFor(dist (turn_distance,wheel_diameter), rotationUnits::rev, false);
    fld.rotateFor(dist (-turn_distance,wheel_diameter), rotationUnits::rev, false);
    brd.rotateFor(dist (turn_distance,wheel_diameter), rotationUnits::rev, false);
    bld.rotateFor(dist (-turn_distance,wheel_diameter), rotationUnits::rev);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol( void ) {
  // User control code here, inside the loop
  while (1) {
    if(OurController.ButtonA.pressing()){
    iml.spin(directionType::fwd, 50, velocityUnits::pct);
    imr.spin(directionType::fwd, 50, velocityUnits::pct);
    }
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}