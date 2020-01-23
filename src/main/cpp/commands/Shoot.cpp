/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/smartdashboard/SmartDashboard.h>

#include "commands/Shoot.h"

Shoot::Shoot(Shooter* m_shooter) : shoot{m_shooter} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_shooter});
}

// Called when the command is initially scheduled.
void Shoot::Execute() {

  // Use 
  shoot->SetBottomMotorSpeed(frc::SmartDashboard::GetNumber("Bottom Motor RPM", 0.0));
  shoot->SetTopMotorSpeed(frc::SmartDashboard::GetNumber("Top Motor RPM", 0.0));
}

// Returns true when the command should end.
// bool Shoot::IsFinished() { return true; }
void Shoot::End(bool interupted) {
  shoot->SetBottomMotorSpeed(0.0);
  shoot->SetTopMotorSpeed(0.0);
}