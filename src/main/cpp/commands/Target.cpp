/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Target.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
Target::Target(units::degrees target, Drivetrain* drive)
    : CommandHelper(frc2::PIDController(0, 0, 0),
                    // This should return the measurement
                    [] { return 0; },
                    // [drive] { return drive->GetHeading().to<double>(); },
                    // VisionX.GetDouble(0.0);

                    // This should return the setpoint (can also be a constant)
                    // Vision Target "Center" should be 0
                    [] { return 0; },

                    // This uses the output
                    [drive](double output) {
                       // Use the output here
                      drive->ArcadeDrive(0, output); },

                    {drive}) {


                    AddRequirements({drive});

                    }

// Returns true when the command should end.
bool Target::IsFinished() { return false; }
