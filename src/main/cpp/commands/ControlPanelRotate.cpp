/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ControlPanelRotate.h"
#include "frc/smartdashboard/SmartDashboard.h"
//#include <networktables/NetworkTable.h>
//#include <networktables/NetworkTableInstance.h>

ControlPanelRotate::ControlPanelRotate(ControlPanel *controlpanel) : m_controlpanel(controlpanel) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({controlpanel});
  frc::SmartDashboard::PutNumber("Rotation: ", 28);  // Best guess for number of color transitions sensed per 3 rotations
 }

// Called when the command is initially scheduled.
void ControlPanelRotate::Initialize() {
  m_transitions = 0;
  // Read the current color from the smart dashboard
  m_currentColor = frc::SmartDashboard::GetString("Detected Color", "Purple");
}

// Called repeatedly when this Command is scheduled to run
void ControlPanelRotate::Execute() {
  m_controlpanel->Rotate();
  std::string newColor = frc::SmartDashboard::GetString("Detected Color", "Purple"); 
  if (newColor != m_currentColor) {
    m_currentColor = newColor;
    m_transitions++; 
    frc::SmartDashboard::PutNumber("Rotation Count: ", m_transitions);
  }
}

// Called once the command ends or is interrupted.
void ControlPanelRotate::End(bool interrupted) {}

// Returns true when the command should end.
bool ControlPanelRotate::IsFinished() {
  int targetCount = frc::SmartDashboard::GetNumber("Rotation: ", 28);
  if (m_transitions > targetCount) { // HACK: We are UNDERcounting. Catching abt 6 changes per rotation
    m_controlpanel->Stop();
    m_transitions=0;
    return true;
  }
  return false;
}
