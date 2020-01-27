/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Rotate.h"

Rotate::Rotate(double degrees, double speed,
                             Drivetrain* subsystem)
    : drive(subsystem), degrees(degrees), speed(speed) {
  AddRequirements({subsystem});
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Rotate::Initialize() {
  drive->ResetEncoders();
  drive->ArcadeDrive(0, speed);
}

// Called repeatedly when this Command is scheduled to run
void Rotate::Execute() {
  drive->ArcadeDrive(0, speed);
}

// Called once the command ends or is interrupted.
void Rotate::End(bool interrupted) {}

// Returns true when the command should end.
bool Rotate::IsFinished() { return false; }
