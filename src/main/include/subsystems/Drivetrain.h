/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"


class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  /**
   * Drives the robot using arcade controls.
   *
   * @param speed the commanded forward movement
   * @param rot the commanded rotation
   */
  void ArcadeDrive(double speed, double rot);
  
  void TankDrive(double left, double right);
  
  void SetMaxOutput(double speed);

  double GetAverageEncoderDistance();

  double GetRightEncoder();

  double GetLeftEncoder();

  void ResetEncoders();
  
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

    // Neo motor controllers
  rev::CANSparkMax right{ConDrivetrain::RIGHT_MOTOR, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax left{ConDrivetrain::LEFT_MOTOR, rev::CANSparkMax::MotorType::kBrushless};

  // Drive encoders
  rev::CANEncoder right_encoder = right.GetEncoder();
  rev::CANEncoder left_encoder = left.GetEncoder();

  // Robot Drive
  frc::DifferentialDrive drive{left, right};

  // Dead zone correction for Xbox controllers
  double DeadZoneCorrection(double axis_value);

};
