// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

//Included with timed robot skeleton
#include <frc/TimedRobot.h>
//Used to interface with xbox controller
#include <frc/XboxController.h>
//used to control talonSRX and falcon500(talonFX)
//must be added as a vendor library improtant
#include <ctre/Phoenix.h>
//output text library
#include <iostream>
//timer library
#include <frc/Timer.h>


class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;
  //written to control left side and right side independantly with one line
  // Drive(Left side speed (-1 to 1), right side speed (-1 to 1))

  void Drive(float left, float right){
  //setting motor speeds to parameters
  m_l1.Set(left);
  m_l2.Set(left);
  m_r1.Set(right);
  m_r2.Set(right);
}
  void upperArm(int in, int out){
    arm_extend.Set(0.2*(in-out));
}
  void lowerArm(float down, float up){
    if((down>0) && (up==0)){
      arm_angle.Set(.3);
    }else if((up>0) && (down==0)){
      arm_angle.Set(-.3);
    }else{
      arm_angle.Set(0);
    }
  }

  void claw(int open,int close){
      m_claw.Set(open-close);
  }


  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  float modifier = 0;
  private:
  //Declaring xbox contoller
  frc::XboxController m_driverController{0};
  //Declaring motors and establishing CAN IDs 
  //use phoenix tuner to get CAN IDs and put them in the brackets
  WPI_TalonFX m_r1{3};
  WPI_TalonFX m_r2{4};

  WPI_TalonFX m_l1{1};
  WPI_TalonFX m_l2{2};

  WPI_VictorSPX arm_extend{6};
  WPI_TalonFX arm_angle{5};
  WPI_TalonSRX m_claw{7};

  //Declaring timer to use for timed events like autonomous
  frc::Timer timer;
};