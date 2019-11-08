using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor IntakeLeft;
extern motor IntakeRight;
extern controller Controller1;
extern motor DriveBackRight;
extern motor DriveBackLeft;
extern motor DriveFrontLeft;
extern motor DriveFrontRight;
extern motor CubeTrayAngler;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );