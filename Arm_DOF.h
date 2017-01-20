// ---------------------------------------------------------------------------
// Arduino Arm Library - v0.1 - 20/01/2017
//
// AUTHOR/LICENSE:
// Created by Alonso José Lara Plana - alonso.lara.plana@gmail.com
// Copyright 2017 License: GNU GPL v3 http://www.gnu.org/licenses/gpl.html
//
// LINKS:
// Project home:  https://github.com/AlonsoLP/Arduino-Arm-Library
//
// DISCLAIMER:
// This software is furnished "as is", without technical support, and with no
// warranty, express or implied, as to its usefulness for any purpose.
//
// BACKGROUND:
// (To-Do)
//
// FEATURES:
// (To-Do)
//
// CONSTRUCTOR:
// (To-Do)
//
// METHODS:
// (To-Do)
//
// HISTORY:
// 20/01/2017 v0.1 - Initial release.
// ---------------------------------------------------------------------------

#ifndef Arm_DOF_h
#define Arm_DOF_h

class Arm_DOF
{
  public:
    // constructor
    Arm_DOF (uint8_t dof = 6, uint8_t addr = 0x40);
    // simple methods (basic orders)
    void move (uint8_t pos, uint16_t value, boolean update = False)
    void move (uint16_t *pos, boolean update = False);
    void move (uint16_t *pos, uint8_t delay_time);
};

#endif
