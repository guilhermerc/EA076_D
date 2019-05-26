/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : AT24C164.h
**     Project     : EA076_PE
**     Processor   : MKL25Z128VLK4
**     Component   : 24AA_EEPROM
**     Version     : Component 01.032, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-05-26, 17:08, # CodeGen: 300
**     Abstract    :
**         Driver for Microchip 24_AA/LC EEPROMs
**     Settings    :
**          Component name                                 : AT24C164
**          Device                                         : 16
**          Initial Device Address                         : 0x0
**          Block buffer size                              : 16
**          Acknowledge Polling                            : Disabled
**          Connection                                     : 
**            I2C                                          : GI2C1
**            Write Protection Pin                         : Disabled
**          Timeout                                        : Disabled
**          Shell                                          : Disabled
**     Contents    :
**         ReadByte          - byte AT24C164_ReadByte(AT24C164_Address addr, byte *data);
**         WriteByte         - byte AT24C164_WriteByte(AT24C164_Address addr, byte data);
**         ReadBlock         - byte AT24C164_ReadBlock(AT24C164_Address addr, byte *data, word dataSize);
**         WriteBlock        - byte AT24C164_WriteBlock(AT24C164_Address addr, byte *data, word dataSize);
**         SelectDevice      - byte AT24C164_SelectDevice(byte addrI2C);
**         GetSelectedDevice - byte AT24C164_GetSelectedDevice(void);
**
**Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**All Rights Reserved.
**
**Redistribution and use in source and binary forms, with or without modification,
**are permitted provided that the following conditions are met:
**
**o Redistributions of source code must retain the above copyright notice, this list
**  of conditions and the following disclaimer.
**
**o Redistributions in binary form must reproduce the above copyright notice, this
**  list of conditions and the following disclaimer in the documentation and/or
**  other materials provided with the distribution.
**
**o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**  contributors may be used to endorse or promote products derived from this
**  software without specific prior written permission.
**
**THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**http: www.freescale.com
**mail: support@freescale.com
** ###################################################################*/
/*!
** @file AT24C164.h
** @version 01.00
** @brief
**         Driver for Microchip 24_AA/LC EEPROMs
*/         
/*!
**  @addtogroup AT24C164_module AT24C164 module documentation
**  @{
*/         

#ifndef __AT24C164_H
#define __AT24C164_H

/* MODULE AT24C164. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited components */
#include "GI2C1.h"

#include "CPU.h"

/* supported device ID's */
#define AT24C164_DEVICE_ID_8       8 /* 24AA08, 24LC08 */
#define AT24C164_DEVICE_ID_16     16 /* 24AA16, 24LC16 */
#define AT24C164_DEVICE_ID_32     32 /* 24AA32, 24LC32 */
#define AT24C164_DEVICE_ID_256   256 /* 24AA256, 24LC256, 24FC256 */
#define AT24C164_DEVICE_ID_512   512 /* 24AA512, 24LC512, 24FC256 */
#define AT24C164_DEVICE_ID_1025 1025 /* 24AA1025, 24LC1025, 24FC1025 */
/* actual device */
#define AT24C164_DEVICE_ID      AT24C164_DEVICE_ID_16

#define AT24C164_BLOCK_BUF_SIZE 16      /* buffer used for block read/write. Max is 128. Keep it small to reduce stack consumption. */

#if AT24C164_DEVICE_ID==AT24C164_DEVICE_ID_8
  #define AT24C164_MAX_I2C_ADDR_MASK 0  /* A2|A1|A0 are not used */
  #define AT24C164_MAX_ADDRESS       0x03FF /* 8 kBit is 1KByte */
  #define AT24C164_ADDRT             word /* a word/16bit is enough to hold the address */
  #define AT24C164_PAGE_SIZE         16 /* maximum page size (for page/block operation) */
#elif AT24C164_DEVICE_ID==AT24C164_DEVICE_ID_16
  #define AT24C164_MAX_I2C_ADDR_MASK 0  /* A2|A1|A0 are not used */
  #define AT24C164_MAX_ADDRESS       0x07FF /* 16 kBit is 2KByte */
  #define AT24C164_ADDRT             word /* a word/16bit is enough to hold the address */
  #define AT24C164_PAGE_SIZE         16 /* maximum page size (for page/block operation) */
#elif AT24C164_DEVICE_ID==AT24C164_DEVICE_ID_32
  #define AT24C164_MAX_I2C_ADDR_MASK 7  /* A2|A1|A0 form the I2C device address => address cannot be more than 7 (8 devices) */
  #define AT24C164_MAX_ADDRESS       0x0FFF /* 32 kBit are 4KByte */
  #define AT24C164_ADDRT             word /* a word/16bit is enough to hold the address */
  #define AT24C164_PAGE_SIZE         8  /* maximum page size (for page/block operation) */
#elif AT24C164_DEVICE_ID==AT24C164_DEVICE_ID_256
  #define AT24C164_MAX_I2C_ADDR_MASK 7  /* A2|A1|A0 form the I2C device address => address cannot be more than 7 (8 devices) */
  #define AT24C164_MAX_ADDRESS       0x7FFF /* 256 kBit are 32KByte */
  #define AT24C164_ADDRT             word /* a word/16bit is enough to hold the address */
  #define AT24C164_PAGE_SIZE         64 /* maximum page size (for page/block operation) */
#elif AT24C164_DEVICE_ID==AT24C164_DEVICE_ID_512
  #define AT24C164_MAX_I2C_ADDR_MASK 7  /* A2|A1|A0 form the I2C device address => address cannot be more than 7 (8 devices) */
  #define AT24C164_MAX_ADDRESS       0xFFFF /* 512 kBit are 64KByte */
  #define AT24C164_ADDRT             word /* a word/16bit is enough to hold the address */
  #define AT24C164_PAGE_SIZE         128 /* maximum page size (for page/block operation) */
#elif AT24C164_DEVICE_ID==AT24C164_DEVICE_ID_1025
  #define AT24C164_MAX_I2C_ADDR_MASK 3  /* A1|A0 form the I2C device address => address cannot be more than 3 (4 devices) */
  #define AT24C164_MAX_ADDRESS       0x1FFFF /* 1024 kBit are 128KByte */
  #define AT24C164_ADDRT             dword /* a longword/32bit is needed to hold the address */
  #define AT24C164_PAGE_SIZE         128 /* maximum page size (for page/block operation) */
#else
  #error "unknown device?"
#endif

#define AT24C164_DO_ACKNOWLEDGE_POLLING    0 /* No acknowledge polling in the driver */

#ifndef __BWUserType_AT24C164_Address
#define __BWUserType_AT24C164_Address
  typedef  AT24C164_ADDRT AT24C164_Address; /* A type large enought to hold the address, depending on the EEPROM used. */
#endif

#define AT24C164_PARSE_COMMAND_ENABLED  0 /* set to 1 if method ParseCommand() is present, 0 otherwise */

byte AT24C164_WriteByte(AT24C164_Address addr, byte data);
/*
** ===================================================================
**     Method      :  AT24C164_WriteByte (component 24AA_EEPROM)
**     Description :
**         Writes a single byte to specified address
**     Parameters  :
**         NAME            - DESCRIPTION
**         addr            - The address inside the EEPROM
**         data            - The data value to write
**     Returns     :
**         ---             - Error code, possible values
**                           ERR_OK - OK
**                           otherwise it can return an error code of
**                           the underlying communication protocol.
** ===================================================================
*/

byte AT24C164_ReadByte(AT24C164_Address addr, byte *data);
/*
** ===================================================================
**     Method      :  AT24C164_ReadByte (component 24AA_EEPROM)
**     Description :
**         Reads a single byte from the given memory address
**     Parameters  :
**         NAME            - DESCRIPTION
**         addr            - The address where to read from memory.
**       * data            - Pointer to a location where to store the
**                           data
**     Returns     :
**         ---             - Error code, possible values
**                           ERR_OK - OK
**                           otherwise it can return an error code of
**                           the underlying communication protocol.
** ===================================================================
*/

byte AT24C164_ReadBlock(AT24C164_Address addr, byte *data, word dataSize);
/*
** ===================================================================
**     Method      :  AT24C164_ReadBlock (component 24AA_EEPROM)
**     Description :
**         Read a block of memory.
**     Parameters  :
**         NAME            - DESCRIPTION
**         addr            - Address where to read the memory
**       * data            - Pointer to a buffer where to store the
**                           data
**         dataSize        - Size of buffer the data pointer
**                           is pointing to
**     Returns     :
**         ---             - Error code, possible values
**                           ERR_OK - OK
**                           otherwise it can return an error code of
**                           the underlying communication protocol.
** ===================================================================
*/

byte AT24C164_WriteBlock(AT24C164_Address addr, byte *data, word dataSize);
/*
** ===================================================================
**     Method      :  AT24C164_WriteBlock (component 24AA_EEPROM)
**     Description :
**         Writes a block of data to the EEPROM
**     Parameters  :
**         NAME            - DESCRIPTION
**         addr            - Address of memory
**       * data            - Pointer to the data
**         dataSize        - Size of data
**     Returns     :
**         ---             - Error code, possible values
**                           ERR_OK - OK
**                           ERR_OVERFLOW - data block passed has either
**                           size of zero or exceeds internal buffer
**                           size
**                           otherwise it can return an error code of
**                           the underlying communication protocol.
** ===================================================================
*/

byte AT24C164_SelectDevice(byte addrI2C);
/*
** ===================================================================
**     Method      :  AT24C164_SelectDevice (component 24AA_EEPROM)
**     Description :
**         Configures the I2C address to be used for the memory. With
**         this multiple devices attached to the bus can be addressed.
**     Parameters  :
**         NAME            - DESCRIPTION
**         addrI2C         - I2C Address of the memory device,
**                           formed by the address pins.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_VALUE - address exceeds address pins of
**                           device type used
** ===================================================================
*/

byte AT24C164_GetSelectedDevice(void);
/*
** ===================================================================
**     Method      :  AT24C164_GetSelectedDevice (component 24AA_EEPROM)
**     Description :
**         Returns the currently used I2C address (e.g. set with
**         SelectDevice()).
**     Parameters  : None
**     Returns     :
**         ---             - I2C device address
** ===================================================================
*/

byte AT24C164_WriteBlockPage(AT24C164_Address addr, byte *data, word dataSize);
/*
** ===================================================================
**     Method      :  AT24C164_WriteBlockPage (component 24AA_EEPROM)
**
**     Description :
**         Writes a block with pages of data to the EEPROM
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END AT24C164. */

#endif
/* ifndef __AT24C164_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
