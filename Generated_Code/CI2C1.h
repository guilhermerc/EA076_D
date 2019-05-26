/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : CI2C1.h
**     Project     : EA076_PE
**     Processor   : MKL25Z128VLK4
**     Component   : I2C_LDD
**     Version     : Component 01.016, Driver 01.07, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-05-25, 23:52, # CodeGen: 287
**     Abstract    :
**          This component encapsulates the internal I2C communication
**          interface. The implementation of the interface is based
**          on the Philips I2C-bus specification version 2.0.
**          Interface features:
**          MASTER mode
**            - Multi master communication
**            - The combined format of communication possible
**              (see SendStop parameter in MasterSend/ReceiveBlock method)
**            - 7-bit slave addressing (10-bit addressing can be made as well)
**            - Acknowledge polling provided
**            - No wait state initiated when a slave device holds the SCL line low
**            - Holding of the SCL line low by slave device recognized as 'not available bus'
**            - Invalid start/stop condition detection provided
**          SLAVE mode
**            - 7-bit slave addressing
**            - General call address detection provided
**     Settings    :
**          Component name                                 : CI2C1
**          I2C channel                                    : I2C1
**          Interrupt service                              : Enabled
**            Interrupt                                    : INT_I2C1
**            Interrupt priority                           : medium priority
**          Settings                                       : 
**            Mode selection                               : MASTER
**            MASTER mode                                  : Enabled
**              Initialization                             : 
**                Address mode                             : 7-bit addressing
**                Target slave address init                : 0
**            SLAVE mode                                   : Disabled
**            Pins                                         : 
**              SDA pin                                    : 
**                SDA pin                                  : PTC11/I2C1_SDA
**                SDA pin signal                           : 
**              SCL pin                                    : 
**                SCL pin                                  : PTC10/I2C1_SCL
**                SCL pin signal                           : 
**              High drive select                          : Disabled
**              Input Glitch filter                        : 0
**            Internal frequency (multiplier factor)       : 20.97152 MHz
**            Bits 0-2 of Frequency divider register       : 111
**            Bits 3-5 of Frequency divider register       : 011
**            SCL frequency                                : 87.381 kHz
**            SDA Hold                                     : 1.574 us
**            SCL start Hold                               : 5.627 us
**            SCL stop Hold                                : 5.77 us
**            Control acknowledge bit                      : Disabled
**            Low timeout                                  : Disabled
**          Initialization                                 : 
**            Enabled in init code                         : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnMasterBlockSent                          : Enabled
**              OnMasterBlockReceived                      : Enabled
**              OnMasterByteReceived                       : Disabled
**              OnSlaveBlockSent                           : Disabled
**              OnSlaveBlockReceived                       : Disabled
**              OnSlaveByteReceived                        : Disabled
**              OnSlaveRxRequest                           : Disabled
**              OnSlaveTxRequest                           : Disabled
**              OnSlaveGeneralCallAddr                     : Disabled
**              OnSlaveSmBusCallAddr                       : Disabled
**              OnSlaveSmBusAlertResponse                  : Disabled
**              OnError                                    : Disabled
**              OnBusStopDetected                          : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init                         - LDD_TDeviceData* CI2C1_Init(LDD_TUserData *UserDataPtr);
**         Deinit                       - void CI2C1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SetEventMask                 - LDD_TError CI2C1_SetEventMask(LDD_TDeviceData *DeviceDataPtr, LDD_TEventMask...
**         GetEventMask                 - LDD_TEventMask CI2C1_GetEventMask(LDD_TDeviceData *DeviceDataPtr);
**         MasterSendBlock              - LDD_TError CI2C1_MasterSendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         MasterGetBlockSentStatus     - bool CI2C1_MasterGetBlockSentStatus(LDD_TDeviceData *DeviceDataPtr);
**         MasterGetSentDataNum         - LDD_I2C_TSize CI2C1_MasterGetSentDataNum(LDD_TDeviceData *DeviceDataPtr);
**         MasterReceiveBlock           - LDD_TError CI2C1_MasterReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         MasterGetBlockReceivedStatus - bool CI2C1_MasterGetBlockReceivedStatus(LDD_TDeviceData *DeviceDataPtr);
**         MasterGetReceivedDataNum     - LDD_I2C_TSize CI2C1_MasterGetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);
**         MasterUpdateReceiveBlockSize - LDD_TError CI2C1_MasterUpdateReceiveBlockSize(LDD_TDeviceData *DeviceDataPtr,...
**         SelectSlaveDevice            - LDD_TError CI2C1_SelectSlaveDevice(LDD_TDeviceData *DeviceDataPtr,...
**         CheckBus                     - LDD_TError CI2C1_CheckBus(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TBusState...
**         GetStats                     - LDD_I2C_TStats CI2C1_GetStats(LDD_TDeviceData *DeviceDataPtr);
**         ClearStats                   - void CI2C1_ClearStats(LDD_TDeviceData *DeviceDataPtr);
**         ConnectPin                   - LDD_TError CI2C1_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask...
**         SetOperationMode             - LDD_TError CI2C1_SetOperationMode(LDD_TDeviceData *DeviceDataPtr,...
**         GetDriverState               - LDD_TDriverState CI2C1_GetDriverState(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file CI2C1.h
** @version 01.07
** @brief
**          This component encapsulates the internal I2C communication
**          interface. The implementation of the interface is based
**          on the Philips I2C-bus specification version 2.0.
**          Interface features:
**          MASTER mode
**            - Multi master communication
**            - The combined format of communication possible
**              (see SendStop parameter in MasterSend/ReceiveBlock method)
**            - 7-bit slave addressing (10-bit addressing can be made as well)
**            - Acknowledge polling provided
**            - No wait state initiated when a slave device holds the SCL line low
**            - Holding of the SCL line low by slave device recognized as 'not available bus'
**            - Invalid start/stop condition detection provided
**          SLAVE mode
**            - 7-bit slave addressing
**            - General call address detection provided
*/         
/*!
**  @addtogroup CI2C1_module CI2C1 module documentation
**  @{
*/         

#ifndef __CI2C1_H
#define __CI2C1_H

/* MODULE CI2C1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited components */

#include "CPU.h"

#ifdef __cplusplus
extern "C" {
#endif 


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define CI2C1_PRPH_BASE_ADDRESS  0x40067000U
  
/*! Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define CI2C1_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_CI2C1_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define CI2C1_Init_METHOD_ENABLED      /*!< Init method of the component CI2C1 is enabled (generated) */
#define CI2C1_Deinit_METHOD_ENABLED    /*!< Deinit method of the component CI2C1 is enabled (generated) */
#define CI2C1_SetEventMask_METHOD_ENABLED /*!< SetEventMask method of the component CI2C1 is enabled (generated) */
#define CI2C1_GetEventMask_METHOD_ENABLED /*!< GetEventMask method of the component CI2C1 is enabled (generated) */
#define CI2C1_MasterSendBlock_METHOD_ENABLED /*!< MasterSendBlock method of the component CI2C1 is enabled (generated) */
#define CI2C1_MasterGetBlockSentStatus_METHOD_ENABLED /*!< MasterGetBlockSentStatus method of the component CI2C1 is enabled (generated) */
#define CI2C1_MasterGetSentDataNum_METHOD_ENABLED /*!< MasterGetSentDataNum method of the component CI2C1 is enabled (generated) */
#define CI2C1_MasterReceiveBlock_METHOD_ENABLED /*!< MasterReceiveBlock method of the component CI2C1 is enabled (generated) */
#define CI2C1_MasterGetBlockReceivedStatus_METHOD_ENABLED /*!< MasterGetBlockReceivedStatus method of the component CI2C1 is enabled (generated) */
#define CI2C1_MasterGetReceivedDataNum_METHOD_ENABLED /*!< MasterGetReceivedDataNum method of the component CI2C1 is enabled (generated) */
#define CI2C1_MasterUpdateReceiveBlockSize_METHOD_ENABLED /*!< MasterUpdateReceiveBlockSize method of the component CI2C1 is enabled (generated) */
#define CI2C1_SelectSlaveDevice_METHOD_ENABLED /*!< SelectSlaveDevice method of the component CI2C1 is enabled (generated) */
#define CI2C1_CheckBus_METHOD_ENABLED  /*!< CheckBus method of the component CI2C1 is enabled (generated) */
#define CI2C1_GetStats_METHOD_ENABLED  /*!< GetStats method of the component CI2C1 is enabled (generated) */
#define CI2C1_ClearStats_METHOD_ENABLED /*!< ClearStats method of the component CI2C1 is enabled (generated) */
#define CI2C1_ConnectPin_METHOD_ENABLED /*!< ConnectPin method of the component CI2C1 is enabled (generated) */
#define CI2C1_SetOperationMode_METHOD_ENABLED /*!< SetOperationMode method of the component CI2C1 is enabled (generated) */
#define CI2C1_GetDriverState_METHOD_ENABLED /*!< GetDriverState method of the component CI2C1 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define CI2C1_OnMasterBlockSent_EVENT_ENABLED /*!< OnMasterBlockSent event of the component CI2C1 is enabled (generated) */
#define CI2C1_OnMasterBlockReceived_EVENT_ENABLED /*!< OnMasterBlockReceived event of the component CI2C1 is enabled (generated) */



/*
** ===================================================================
**     Method      :  CI2C1_Init (component I2C_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the device data structure. 
*/
/* ===================================================================*/
LDD_TDeviceData* CI2C1_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  CI2C1_Deinit (component I2C_LDD)
*/
/*!
**     @brief
**         Deinitializes the device. Switches off the device, frees the
**         device data structure memory, interrupts vectors, etc.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void CI2C1_Deinit(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  CI2C1_SetEventMask (component I2C_LDD)
*/
/*!
**     @brief
**         Enables/Disables events. This method is available if at
**         least one event is enabled. Pair method to GetEventMask().
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         EventMask       - Event mask, e.g.
**                           LDD_I2C_ON_MASTER_BLOCK_SENT.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_PARAM_MASK - Event mask not valid
*/
/* ===================================================================*/
LDD_TError CI2C1_SetEventMask(LDD_TDeviceData *DeviceDataPtr, LDD_TEventMask EventMask);

/*
** ===================================================================
**     Method      :  CI2C1_GetEventMask (component I2C_LDD)
*/
/*!
**     @brief
**         Returns current event mask, e.g.
**         LDD_I2C_ON_MASTER_BLOCK_SENT. This method is available if at
**         least one event is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Current event mask.
*/
/* ===================================================================*/
LDD_TEventMask CI2C1_GetEventMask(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  CI2C1_MasterSendBlock (component I2C_LDD)
*/
/*!
**     @brief
**         This method writes one (7-bit addressing) or two (10-bit
**         addressing) slave address bytes inclusive of R/W bit = 0 to
**         the I2C bus and then writes the block of characters to the
**         bus. The slave address must be specified before, by the
**         "SelectSlaveDevice" method or in component initialization
**         section, "Target slave address init" property. If the method
**         returns ERR_OK, it doesn't mean that transmission was
**         successful. The state of transmission is detectable by means
**         of events (OnMasterSendComplete or OnError). Data to be sent
**         are not copied to an internal buffer and remains in the
**         original location. Therefore the content of the buffer
**         should not be changed until the transmission is complete.
**         Event "OnMasterBlockSent"can be used to detect the end of
**         the transmission. This method is available only for the
**         MASTER or MASTER - SLAVE mode.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to the block of data
**                           to send.
**     @param
**         Size            - Size of the data block.
**     @param
**         SendStop        - Parameter for generating I2C
**                           Stop condition
**                           LDD_I2C_SEND_STOP - Stop condition is
**                           generated on end transmission.
**                           LDD_I2C_NO_SEND_STOP - Stop condition isn't
**                           generated on end transmission.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_BUSY - The I2C device is now running
*/
/* ===================================================================*/
LDD_TError CI2C1_MasterSendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, LDD_I2C_TSize Size, LDD_I2C_TSendStop SendStop);

/*
** ===================================================================
**     Method      :  CI2C1_MasterGetBlockSentStatus (component I2C_LDD)
*/
/*!
**     @brief
**         This method returns current state of MasterSendBlock method.
**         This method is available only for the MASTER mode and if
**         method MasterSendBlock is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Return value:
**                           <true> - data block is completely
**                           transmitted.
**                           <false> - data block isn't completely
**                           transmitted.
*/
/* ===================================================================*/
bool CI2C1_MasterGetBlockSentStatus(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  CI2C1_MasterGetSentDataNum (component I2C_LDD)
*/
/*!
**     @brief
**         This method returns the number of transmitted characters
**         from the transmit buffer. This method is available only for
**         the MASTER mode and if method MasterSendBlock is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - The number of sent characters.
*/
/* ===================================================================*/
LDD_I2C_TSize CI2C1_MasterGetSentDataNum(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  CI2C1_MasterReceiveBlock (component I2C_LDD)
*/
/*!
**     @brief
**         This method writes one (7-bit addressing) or two (10-bit
**         addressing) slave address bytes inclusive of R/W bit = 1 to
**         the I2C bus and then receives the block of characters from
**         the bus. The slave address must be specified before, by the
**         "SelectSlaveDevice" method or in component initialization
**         section, "Target slave address init" property. If the method
**         returns ERR_OK, it doesn't mean that reception was
**         successful. The state of reception is detectable by means of
**         events (OnMasterSendComplete  or OnError). Data to be
**         received are not copied to an internal buffer and remains in
**         the original location. Therefore the content of the buffer
**         should not be changed until the transmission is complete.
**         Event "OnMasterBlockReceived"can be used to detect the end
**         of the reception. This method is available only for the
**         MASTER or MASTER - SLAVE mode.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to a buffer where
**                           received characters will be stored.
**     @param
**         Size            - The size of the block.
**     @param
**         SendStop        - Parameter for generating I2C
**                           Stop condition
**                           LDD_I2C_SEND_STOP - Stop condition is
**                           generated on end transmission.
**                           LDD_I2C_NO_SEND_STOP - Stop condition isn't
**                           generated on end transmission.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_BUSY - The master device is busy
**                           ERR_NOTAVAIL - It is not possible to
**                           receive data if general call address is set.
**                           ERR_PARAM_MODE -  Stop condition isn't
**                           possible generated on end transmission.
*/
/* ===================================================================*/
LDD_TError CI2C1_MasterReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, LDD_I2C_TSize Size, LDD_I2C_TSendStop SendStop);

/*
** ===================================================================
**     Method      :  CI2C1_MasterUpdateReceiveBlockSize (component I2C_LDD)
*/
/*!
**     @brief
**         This method updates received block size in master mode. For
**         correct function must this method called in
**         OnMasterByteReceived. This method is available only for the
**         MASTER or MASTER - SLAVE mode.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Size            - The size of the block.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_NOTAVAIL - It is not possible set new
**                           value receive block size, master is not
**                           receive block.
**                           ERR_PARAM_SIZE -  Value of block size is
**                           out of range.
*/
/* ===================================================================*/
LDD_TError CI2C1_MasterUpdateReceiveBlockSize(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TSize Size);

/*
** ===================================================================
**     Method      :  CI2C1_MasterGetBlockReceivedStatus (component I2C_LDD)
*/
/*!
**     @brief
**         This method returns current state of MasterReceiveBlock
**         method. This method is available only for the MASTER mode
**         and if method MasterReceiveBlock is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Return value:
**                           <true> - data block is completely received.
**                           <false> - data block isn't completely
**                           received.
*/
/* ===================================================================*/
bool CI2C1_MasterGetBlockReceivedStatus(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  CI2C1_MasterGetReceivedDataNum (component I2C_LDD)
*/
/*!
**     @brief
**         This method returns the number of received characters in the
**         receive buffer. This method is available only for the MASTER
**         mode and if method MasterReceiveBlock is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - The number of characters in the input
**                           buffer.
*/
/* ===================================================================*/
LDD_I2C_TSize CI2C1_MasterGetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  CI2C1_SelectSlaveDevice (component I2C_LDD)
*/
/*!
**     @brief
**         This method selects a new slave for communication by its
**         7-bit slave, 10-bit address or general call value. Any send
**         or receive method directs to or from selected device, until
**         a new slave device is selected by this method. This method
**         is available for the MASTER mode.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         AddrType        - Specify type of slave address
**                           (7bit, 10bit or general call address), e.g.
**                           LDD_I2C_ADDRTYPE_7BITS.
**     @param
**         Addr            - 7bit or 10bit slave address value.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_BUSY - The device is busy, wait until
**                           the current operation is finished.
**                           ERR_DISABLED -  The device is disabled.
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_PARAM_ADDRESS_TYPE -  Invalid address
**                           type.
**                           ERR_PARAM_ADDRESS -  Invalid address value.
*/
/* ===================================================================*/
LDD_TError CI2C1_SelectSlaveDevice(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TAddrType AddrType, LDD_I2C_TAddr Addr);

/*
** ===================================================================
**     Method      :  CI2C1_CheckBus (component I2C_LDD)
*/
/*!
**     @brief
**         This method returns the status of the bus. If the START
**         condition has been detected, the method returns LDD_I2C_BUSY.
**         If the STOP condition has been detected, the method returns
**         LDD_I2C_IDLE.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BusStatePtr     - Pointer to a variable,
**                           where value of status is stored.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError CI2C1_CheckBus(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TBusState *BusStatePtr);

/*
** ===================================================================
**     Method      :  CI2C1_GetStats (component I2C_LDD)
*/
/*!
**     @brief
**         Returns receive/transmit statistics.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Device receive/transmit statistics since the
**                           device initialization or since the
**                           statistical information has been cleared.
*/
/* ===================================================================*/
LDD_I2C_TStats CI2C1_GetStats(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  CI2C1_ClearStats (component I2C_LDD)
*/
/*!
**     @brief
**         Clears the receive/transmit statistics. This method is
**         available only when GetStats methos is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void CI2C1_ClearStats(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  CI2C1_Interrupt (component I2C_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(CI2C1_Interrupt);

/*
** ===================================================================
**     Method      :  CI2C1_ConnectPin (component I2C_LDD)
*/
/*!
**     @brief
**         This method reconnects the requested pin associated with the
**         selected peripheral in this component. This method is only
**         available for CPU derivatives and peripherals that support
**         the runtime pin sharing with other internal on-chip
**         peripherals.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         PinMask         - Mask for the requested pins. The
**                           peripheral pins are reconnected according
**                           to this mask.
**                           Possible parameters:
**                           LDD_I2C_SDA_PIN - Data pin
**                           LDD_I2C_SCL_PIN - Clock pin
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_PARAM_MASK - Invalid PinMask value.
*/
/* ===================================================================*/
LDD_TError CI2C1_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask PinMask);

/*
** ===================================================================
**     Method      :  CI2C1_GetDriverState (component I2C_LDD)
*/
/*!
**     @brief
**         This method returns the current driver status.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - The current driver status mask.
**                           Following status masks defined in PE_Types.h
**                           can be used to check the current driver
**                           status.
**                           PE_LDD_DRIVER_DISABLED_IN_CLOCK_CONFIGURATIO
**                           N - 1 - Driver is disabled in the current
**                           mode; 0 - Driver is enabled in the current
**                           mode.  
**                           PE_LDD_DRIVER_DISABLED_BY_USER - 1 - Driver
**                           is disabled by the user; 0 - Driver is
**                           enabled by the user.        
**                           PE_LDD_DRIVER_BUSY - 1 - Driver is the BUSY
**                           state; 0 - Driver is in the IDLE state.
*/
/* ===================================================================*/
LDD_TDriverState CI2C1_GetDriverState(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  CI2C1_SetOperationMode (component I2C_LDD)
*/
/*!
**     @brief
**         This method requests to change the component's operation
**         mode. Upon a request to change the operation mode, the
**         component will finish a pending job first and then notify a
**         caller that an operation mode has been changed. When no job
**         is pending (ERR_OK), the component changes an operation mode
**         immediately and notify a caller about this change. 
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         OperationMode   - Requested driver
**                           operation mode.
**     @param
**         ModeChangeCallback - Callback to
**                           notify the upper layer once a mode has been
**                           changed.
**     @param
**         ModeChangeCallbackParamPtr 
**                           - Pointer to callback parameter to notify
**                           the upper layer once a mode has been
**                           changed.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - The change operation mode request
**                           has been accepted, callback will notify an
**                           application as soon as the mode is changed.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - This component is disabled
**                           by user.
**                           ERR_PARAM_MODE - Invalid operation mode.
**                           ERR_BUSY - Job is running and the driver
**                           can't detect job end by itself. The
**                           approximate end of the job can be detected
**                           by method GetDriverState. The real
**                           transmission/reception finishes later. It
**                           depends on component settings (data width,
**                           timing, size of buffer, etc.).
*/
/* ===================================================================*/
LDD_TError CI2C1_SetOperationMode(LDD_TDeviceData *DeviceDataPtr, LDD_TDriverOperationMode OperationMode, LDD_TCallback ModeChangeCallback, LDD_TCallbackParam *ModeChangeCallbackParamPtr);

/* END CI2C1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __CI2C1_H */
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
