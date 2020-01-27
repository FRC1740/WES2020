/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/XboxController.h>
#include <frc2/command/Command.h>
// #include <frc/smartdashboard/SendableChooser.h>

#include "commands/DefaultDrive.h"
#include "commands/DriveDistance.h"
#include "commands/ExtendClimber.h"
#include "commands/HalfSpeedDrive.h"
#include "commands/RetractClimber.h"
#include "commands/Shoot.h"
#include "Constants.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Climber.h"
#include "subsystems/Shooter.h"
#include "subsystems/ControlPanel.h"


/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
 
 // The robot's subsystems
  Drivetrain drive;
  Climber climb;
  Shooter shoot;
  ControlPanel controlpanel;


  // The autonomous routines
  DriveDistance simple_auto{ConAuto::AutoDriveDistanceInches,
                            ConAuto::AutoDriveSpeed,
                            &drive};

  /*
  AutoBasic DriveSquare{ConAuto::AutoDriveSquareSpeed,
                        ConAuto::AutoDriveSquareRotSpeed,
                        ConAuto::AutoDriveSquareSideInches};
  */

  // frc::SendableChooser<frc2::Command*>

  // The driver's controller
  frc::XboxController driver_controller{ConXBOXController::DRIVER_CONTROLLER_PORT};

  void ConfigureButtonBindings();
};
