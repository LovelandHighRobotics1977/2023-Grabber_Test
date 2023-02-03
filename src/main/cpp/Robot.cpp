// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() {
  Drive(0,0);
  arm_angle.SetNeutralMode(NeutralMode::Brake);
  arm_extend.SetNeutralMode(NeutralMode::Brake);
  m_claw.SetNeutralMode(NeutralMode::Coast);
}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  Drive(0,0);
  //reseting and starting timer from zero every time autonomous is run
  timer.Reset();
  timer.Start();
}
void Robot::AutonomousPeriodic() {
  std::cout<<"Starting Autonomous Routine"<<std::endl;

  std::cout<<"Autonomous Routine Complete"<<std::endl;
}

void Robot::TeleopInit() {
  Drive(0,0);
}
void Robot::TeleopPeriodic() {
  //calling drive with xbox stick input
  Drive(.5*-m_driverController.GetLeftY(),.5*m_driverController.GetRightY());
  upperArm(m_driverController.GetLeftBumper(),m_driverController.GetRightBumper());
  lowerArm(m_driverController.GetLeftTriggerAxis(),m_driverController.GetRightTriggerAxis());
  claw(m_driverController.GetYButton(),m_driverController.GetBButton());
}

void Robot::DisabledInit() {
  Drive(0,0);
}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}







#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif