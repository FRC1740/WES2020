/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ControlPanelColor.h"
// #include "frc/shuffleboard/Shuffleboard.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include <string>
#include <cctype> // for tolower

ControlPanelColor::ControlPanelColor(ControlPanel *controlpanel) : m_controlpanel(controlpanel) {
  // Use AddRequirements() here to declare subsystem dependencies.
  AddRequirements({controlpanel});
}

// Called when the command is initially scheduled.
void ControlPanelColor::Initialize() {
  // Read the target color from Network Tables
  auto table = nt::NetworkTableInstance::GetDefault().GetTable("FMSInfo");
  m_targetColor = table->GetString("GameSpecificMessage", "PURPLE");
  m_controlpanel->SetSpeed(ConControlPanel::MOTOR_SPEED * .5);
}

// Called repeatedly when this Command is scheduled to run
void ControlPanelColor::Execute() {
  // Rotate the ControlPanel
  m_controlpanel->Rotate();
}

// Called once the command ends or is interrupted.
void ControlPanelColor::End(bool interrupted) {}

bool iequals(const std::string& a, const std::string& b) {
  size_t sz = a.size();
  if (sz != b.size())
      return false;
  for (size_t i=0; i<sz; ++i)
      if (std::tolower(a[i]) != std::tolower(b[i]))
          return false;
  return true;
}

// Returns true when the command should end.
bool ControlPanelColor::IsFinished() {

  // if ColorScan = targetcolor return true;
  // Scan for current color
  std::string detectedColor = frc::SmartDashboard::GetString("Detected Color", "Orange");
  if (iequals(detectedColor, m_targetColor)) {
      m_controlpanel->Stop();
      return true;    
  }

  return false;
}
