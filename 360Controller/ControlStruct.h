/*
 MICE Xbox 360 Controller driver for Mac OS X
 Copyright (C) 2006-2013 Colin Munro

 ControlStruct.h - Structures used by the device

 This file is part of Xbox360Controller.

 Xbox360Controller is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 Xbox360Controller is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Foobar; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
# pragma once

#define Xbox360_Prepare(x,t)      {memset(&x,0,sizeof(x));x.header.command=t;x.header.size=sizeof(x);}
#define PACKED __attribute__((__packed__))

namespace Controller {
  typedef UInt8 Xbox360_Byte;
  typedef UInt16 Xbox360_Short;
  typedef SInt16 Xbox360_SShort;

  // Common structure format
  struct XBOX360_PACKET {
    Xbox360_Byte command;
    Xbox360_Byte size;
  } PACKED;
  // Analog stick format
  struct XBOX360_HAT {
    Xbox360_SShort x,y;
  } PACKED;

  // Structure describing the report had back from the controller
  struct XBOX360_IN_REPORT {
    XBOX360_PACKET header;
    Xbox360_Short buttons;
    Xbox360_Byte trigL,trigR;
    XBOX360_HAT left,right;
    Xbox360_Byte reserved[6];
  } PACKED;
  // Structure describing the command to change LED status
  struct XBOX360_OUT_LED {
    XBOX360_PACKET header;
    Xbox360_Byte pattern;
  } PACKED;

  // Structure describing the command to change rumble motor status
  struct XBOX360_OUT_RUMBLE {
    XBOX360_PACKET header;
    Xbox360_Byte reserved1;
    Xbox360_Byte big,little;
    Xbox360_Byte reserved[3];
  } PACKED;

  // Enumeration of command types
  enum CommandTypes {
    // In
    inReport  = 0,
    // Out
    outRumble = 0,
    outLed    = 1
  };

  // Button bits
  enum ButtonBits {
    btnHatRight      = 0x8000,
    btnHatLeft       = 0x4000,
    btnBack          = 0x2000,
    btnStart         = 0x1000,
    btnDigiRight     = 0x0800,
    btnDigiLeft      = 0x0400,
    btnDigiDown      = 0x0200,
    btnDigiUp        = 0x0100,
    btnY             = 0x0080,
    btnX             = 0x0040,
    btnB             = 0x0020,
    btnA             = 0x0010,
    btnReserved1     = 0x0008,  // Unused?
    btnXbox          = 0x0004,
    btnShoulderRight = 0x0002,
    btnShoulderLeft  = 0x0001
  };

  // LED values
  enum LEDValues {
    ledOff          = 0x00,
    ledBlinkingAll  = 0x01,
    ledFlashOn1     = 0x02,
    ledFlashOn2     = 0x03,
    ledFlashOn3     = 0x04,
    ledFlashOn4     = 0x05,
    ledOn1          = 0x06,
    ledOn2          = 0x07,
    ledOn3          = 0x08,
    ledOn4          = 0x09,
    ledRotating     = 0x0a,
    ledBlinking     = 0x0b, // Blinking of previously enabled LED (e.g. from 0x01-0x09)
    ledBlinkingSlow = 0x0c, // As above
    ldAlternating   = 0x0d  // 1+4, 2+3, then back to previous after a short time
  };


}
