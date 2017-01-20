// ---------------------------------------------------------------------------
// Created by Alonso José Lara Plana - alonso.lara.plana@gmail.com
// Copyright 2016 License: GNU GPL v3 http://www.gnu.org/licenses/gpl.html
//
// See "Arm_DOF.h" for purpose, syntax, version history, links, and more.
// ---------------------------------------------------------------------------

#include "Arm_DOF.h"
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver PWM;
uint16_t *CURRENT;
uint8_t DOF;


// ---------------------------------------------------------------------------
// Arm_DOF constructor
// ---------------------------------------------------------------------------

Arm_DOF::Arm_DOF(uint8_t dof = 6, uint8_t addr = 0x40)
{
  PWM = Adafruit_PWMServoDriver(addr);
  PWM.begin();
  PWM.setPWMFreq(60);
  CURRENT = new uint16_t[dof];
  DOF = dof;
}


// ---------------------------------------------------------------------------
// Arm_DOF Simple Methods (Function overloading)
// ---------------------------------------------------------------------------

void Arm_DOF::move (uint8_t pos, uint16_t value, boolean update = False)
{
  PWM.setPWM(pos, 0, value);
  if (update) CURRENT[pos] = value;
}

void Arm_DOF::move (uint16_t *pos, boolean update = False)
{
  for (uint8_t i=0; i<DOF; i++) PWM.setPWM(i, 0, pos[i]);
  if (update) memcpy(CURRENT, pos, sizeof(uint16_t)*DOF);
}

void Arm_DOF::move (uint16_t *pos, uint8_t delay_time)
{
  uint16_t diff, max = 0, i;
  
  for (i=0; i<DOF; i++)
  {
    if (CURRENT[i] > pos[i])
      diff = CURRENT[i] - pos[i];
    else
      diff = pos[i] - CURRENT[i];

    if (diff > max) max = diff;
  }

  for (uint16_t j=0; j<max; j++)
  {
    for (i=0; i<DOF; i++)
    {
      if (CURRENT[i] < pos[i])
        CURRENT[i]++;
      else if (CURRENT[i] > pos[i])
        CURRENT[i]--;
    }
    this->move (CURRENT);
    delay(delay_time);
  }
}
