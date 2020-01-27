/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/Button.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"
#include "commands/DefaultDrive.h"
#include "commands/ExtendClimber.h"
#include "commands/LogDataToDashboard.h"
#include "commands/HalfSpeedDrive.h"
#include "commands/RetractClimber.h"
#include "commands/Shoot.h"
#include "commands/ControlPanelColor.h"
#include "commands/ControlPanelRotate.h"

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  
  frc::SmartDashboard::PutNumber("Top Motor RPM", 0.0);
  frc::SmartDashboard::PutNumber("Bottom Motor RPM", 0.0);

  // Configure the button bindings
  ConfigureButtonBindings();

  // Set up default drive command
   drive.SetDefaultCommand(DefaultDrive(
       &drive,
       [this] { return driver_controller.GetRawAxis(ConXBOXController::RIGHT_TRIGGER_ID) - driver_controller.GetRawAxis(ConXBOXController::LEFT_TRIGGER_ID); },
       [this] { return driver_controller.GetRawAxis(ConXBOXController::RIGHT_JOYSTICK_X); }));

}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  // Commence Half Speed driving when RB is pressed
  frc2::Button([this] { return driver_controller.GetRawButton(ConXBOXController::RIGHT_BUMPER); }).WhenHeld(new HalfSpeedDrive(&drive));
  // frc2::JoystickButton(&driver_controller, ConXBOXController::RIGHT_BUMPER)
  //     .WhenHeld(new HalfSpeedDrive(&drive));

  // Extend Climber when 'A' button is held.
  frc2::Button([this] {return driver_controller.GetRawButton(ConXBOXController::A); }).WhenHeld(new ExtendClimber(&climb));
  // frc2::JoystickButton(&driverController, ConXBOXController::A)
  //     .WhileHeld(new ExtendClimber(&climb));

  // Retract Climber when 'B' button is held.
  frc2::Button([this] {return driver_controller.GetRawButton(ConXBOXController::B); }).WhenHeld(new RetractClimber(&climb));
  // frc2::JoystickButton(&driverController, ConXBOXController::B)
  //     .WhileHeld(new RetractClimber(&climb));

  frc2::Button([this] {return driver_controller.GetRawButton(ConXBOXController::X); }).WhileHeld(new Shoot(&shoot));
  // frc2::JoystickButton(&driverController, ConXBOXController::X)
  //     .WhileHeld(new Shoot(&shoot));

  // frc2::Button([this] {return driver_controller.GetRawButton(ConXBOXController::Y); }).WhenPressed(new Target(&target));
  frc2::Button([this] {return true;}).WhileHeld(new LogDataToDashboard(&shoot));

  frc2::Button([this] {return driver_controller.GetRawButton(ConXBOXController::SELECT); }).WhenPressed(new ControlPanelColor(&controlpanel));
  frc2::Button([this] {return driver_controller.GetRawButton(ConXBOXController::START); }).WhenPressed(new ControlPanelRotate(&controlpanel));

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &simple_auto;
}
