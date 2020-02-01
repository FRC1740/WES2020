/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveDistance.h"

#include <cmath>

DriveDistance::DriveDistance(double inches, double speed,
                             Drivetrain* subsystem)
    : drive(subsystem), distance(inches), speed(speed) {
  AddRequirements({subsystem});
}

void DriveDistance::Initialize() {
  drive->ResetEncoders();
}

void DriveDistance::Execute() {
  drive->ArcadeDrive(speed, 0);
  std::cout << "Right " << std::to_string(drive->GetRightEncoder()) << "\n";
  std::cout << "Left " << std::to_string(drive->GetLeftEncoder()) << "\n";
}

void DriveDistance::End(bool interrupted) { drive->ArcadeDrive(0, 0); }

bool DriveDistance::IsFinished() {
  return (std::abs(drive->GetAverageEncoderDistance()) >= distance);
}