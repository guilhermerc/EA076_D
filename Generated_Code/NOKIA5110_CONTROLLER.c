/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : NOKIA5110_CONTROLLER.c
**     Project     : EA076_PE
**     Processor   : MKL25Z128VLK4
**     Component   : PDC8544
**     Version     : Component 01.006, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-05-04, 20:20, # CodeGen: 138
**     Abstract    :
**
**     Settings    :
**          Component name                                 : NOKIA5110_CONTROLLER
**          Properties                                     : 
**            Width                                        : 84
**            Height                                       : 48
**            Bytes in rows                                : no
**            Bytes in x direction                         : yes
**            MSB first                                    : no
**            Bits per pixel                               : 1
**            Window capability                            : no
**            Display Memory Write                         : no
**            use RAM Buffer                               : yes
**          Type                                           : LPH7366
**          Invert Display                                 : no
**          Initialize contrast                            : Enabled
**            Contrast                                     : 60
**          Mode                                           : normal
**          Voltage                                        : V3
**          HW non-LDD                                     : Disabled
**          HW LDD                                         : Enabled
**            RES                                          : RESLDD
**            SCE                                          : SCELDD
**            D_C                                          : D_CLDD
**            SPI                                          : SM1
**          System                                         : 
**            Wait                                         : WAIT1
**            Initialize on Init                           : no
**     Contents    :
**         GetWidth              - NOKIA5110_CONTROLLER_PixelDim NOKIA5110_CONTROLLER_GetWidth(void);
**         GetHeight             - NOKIA5110_CONTROLLER_PixelDim NOKIA5110_CONTROLLER_GetHeight(void);
**         GetLongerSide         - NOKIA5110_CONTROLLER_PixelDim NOKIA5110_CONTROLLER_GetLongerSide(void);
**         GetShorterSide        - NOKIA5110_CONTROLLER_PixelDim NOKIA5110_CONTROLLER_GetShorterSide(void);
**         SetDisplayOrientation - void NOKIA5110_CONTROLLER_SetDisplayOri...
**         GetDisplayOrientation - NOKIA5110_CONTROLLER_DisplayOrientation...
**         SetPos                - void NOKIA5110_CONTROLLER_SetPos(NOKIA5110_CONTROLLER_PixelDim x,...
**         Clear                 - void NOKIA5110_CONTROLLER_Clear(void);
**         ClearLine             - void NOKIA5110_CONTROLLER_ClearLine(uint8_t lineNumber);
**         WriteChar             - void NOKIA5110_CONTROLLER_WriteChar(uint8_t ch);
**         WriteString           - void NOKIA5110_CONTROLLER_WriteString(uint8_t *str);
**         WriteLineStr          - void NOKIA5110_CONTROLLER_WriteLineStr(uint8_t line, uint8_t *str);
**         SetContrast           - void NOKIA5110_CONTROLLER_SetContrast(uint8_t contrast);
**         SetMode               - void NOKIA5110_CONTROLLER_SetMode(bool inverted);
**         UpdateFull            - void NOKIA5110_CONTROLLER_UpdateFull(void);
**         UpdateRegion          - void NOKIA5110_CONTROLLER_UpdateRegion(NOKIA5110_CONTROLLER_PixelDim x,...
**         GetLCD                - void NOKIA5110_CONTROLLER_GetLCD(void);
**         GiveLCD               - void NOKIA5110_CONTROLLER_GiveLCD(void);
**         Init                  - void NOKIA5110_CONTROLLER_Init(void);
**         Deinit                - void NOKIA5110_CONTROLLER_Deinit(void);
**
**     * Copyright (c) 2014-2016, Erich Styger
**      * Web:         https://mcuoneclipse.com
**      * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**      * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**      * All rights reserved.
**      *
**      * Redistribution and use in source and binary forms, with or without modification,
**      * are permitted provided that the following conditions are met:
**      *
**      * - Redistributions of source code must retain the above copyright notice, this list
**      *   of conditions and the following disclaimer.
**      *
**      * - Redistributions in binary form must reproduce the above copyright notice, this
**      *   list of conditions and the following disclaimer in the documentation and/or
**      *   other materials provided with the distribution.
**      *
**      * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**      * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**      * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**      * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**      * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**      * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**      * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**      * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**      * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**      * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file NOKIA5110_CONTROLLER.c
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup NOKIA5110_CONTROLLER_module NOKIA5110_CONTROLLER module documentation
**  @{
*/         

/* MODULE NOKIA5110_CONTROLLER. */

#include "NOKIA5110_CONTROLLER.h"


uint8_t NOKIA5110_CONTROLLER_DisplayBuf[((NOKIA5110_CONTROLLER_DISPLAY_HW_NOF_ROWS-1)/8)+1][NOKIA5110_CONTROLLER_DISPLAY_HW_NOF_COLUMNS]; /* buffer for the display */

static LDD_TDeviceData *RES_DeviceData; /* device handle for RES pin */
static LDD_TDeviceData *SCE_DeviceData; /* device handle for SCE pin */
static LDD_TDeviceData *D_C_DeviceData; /* device handle for D_C pin */

/* some aspects of the protocol are pretty timing sensitive... */
#define SET_SCE()   \
    WAIT1_Waitns(500); \
    SCEpin1_SetVal(SCE_DeviceData); /* set bit */ \
    WAIT1_Waitns(500);

#define CLR_SCE()   \
    WAIT1_Waitns(100); \
    SCEpin1_ClrVal(SCE_DeviceData); /* clr bit */ \
    WAIT1_Waitns(100);

#define CLR_D_C()   D_Cpin1_ClrVal(D_C_DeviceData) /* clr bit */
#define SET_D_C()   D_Cpin1_SetVal(D_C_DeviceData) /* set bit */

#define CLR_RES()   RESpin1_ClrVal(RES_DeviceData) /* clr bit */
#define SET_RES()   RESpin1_SetVal(RES_DeviceData) /* set bit */

static volatile bool NOKIA5110_CONTROLLER_DataReceivedFlag = FALSE;

/* ASCII table for LCD: 96 rows * 5 bytes = 480 bytes
   Note that this is the same set of codes for character you
   would find on a HD44780 based character LCD.
   Also, given the size of the LCD (84 pixels by 48 pixels),
   the maximum number of characters per row is only 14. */
#define NOKIA5110_CONTROLLER_FONT_COLUMNS_PER_CHAR   5 /* number of font data columns rows per character */
#define NOKIA5110_CONTROLLER_FONT_ROWS_PER_CHAR      8 /* number of font data rows lines per character */
#define NOKIA5110_CONTROLLER_SPACE_COLUMNS_PER_CHAR  1 /* number of space rows after a character */
#define NOKIA5110_CONTROLLER_MAX_CHARS_PER_LINE      (NOKIA5110_CONTROLLER_DISPLAY_HW_NOF_COLUMNS/(NOKIA5110_CONTROLLER_FONT_COLUMNS_PER_CHAR+NOKIA5110_CONTROLLER_SPACE_COLUMNS_PER_CHAR)) /* maximum number of character per line */
#define NOKIA5110_CONTROLLER_MAX_LINES_FOR_DISPLAY   (NOKIA5110_CONTROLLER_DISPLAY_HW_NOF_ROWS/NOKIA5110_CONTROLLER_FONT_ROWS_PER_CHAR) /* maximum number of lines for the display */

static const char table[480] =
 {0x00,0x00,0x00,0x00,0x00, /* 20 space */
  0x00,0x00,0x5f,0x00,0x00, /* 21 ! */
  0x00,0x07,0x00,0x07,0x00, /* 22 " */
  0x14,0x7f,0x14,0x7f,0x14, /* 23 # */
  0x24,0x2a,0x7f,0x2a,0x12, /* 24 $ */
  0x23,0x13,0x08,0x64,0x62, /* 25 % */
  0x36,0x49,0x55,0x22,0x50, /* 26 & */
  0x00,0x05,0x03,0x00,0x00, /* 27 ' */
  0x00,0x1c,0x22,0x41,0x00, /* 28 ( */
  0x00,0x41,0x22,0x1c,0x00, /* 29 ) */
  0x14,0x08,0x3e,0x08,0x14, /* 2a * */
  0x08,0x08,0x3e,0x08,0x08, /* 2b + */
  0x00,0x50,0x30,0x00,0x00, /* 2c , */
  0x08,0x08,0x08,0x08,0x08, /* 2d - */
  0x00,0x60,0x60,0x00,0x00, /* 2e . */
  0x20,0x10,0x08,0x04,0x02, /* 2f / */
  0x3e,0x51,0x49,0x45,0x3e, /* 30 0 */
  0x00,0x42,0x7f,0x40,0x00, /* 31 1 */
  0x42,0x61,0x51,0x49,0x46, /* 32 2 */
  0x21,0x41,0x45,0x4b,0x31, /* 33 3 */
  0x18,0x14,0x12,0x7f,0x10, /* 34 4 */
  0x27,0x45,0x45,0x45,0x39, /* 35 5 */
  0x3c,0x4a,0x49,0x49,0x30, /* 36 6 */
  0x01,0x71,0x09,0x05,0x03, /* 37 7 */
  0x36,0x49,0x49,0x49,0x36, /* 38 8 */
  0x06,0x49,0x49,0x29,0x1e, /* 39 9 */
  0x00,0x36,0x36,0x00,0x00, /* 3a : */
  0x00,0x56,0x36,0x00,0x00, /* 3b ; */
  0x08,0x14,0x22,0x41,0x00, /* 3c < */
  0x14,0x14,0x14,0x14,0x14, /* 3d = */
  0x00,0x41,0x22,0x14,0x08, /* 3e > */
  0x02,0x01,0x51,0x09,0x06, /* 3f ? */
  0x32,0x49,0x79,0x41,0x3e, /* 40 @ */
  0x7e,0x11,0x11,0x11,0x7e, /* 41 A */
  0x7f,0x49,0x49,0x49,0x36, /* 42 B */
  0x3e,0x41,0x41,0x41,0x22, /* 43 C */
  0x7f,0x41,0x41,0x22,0x1c, /* 44 D */
  0x7f,0x49,0x49,0x49,0x41, /* 45 E */
  0x7f,0x09,0x09,0x09,0x01, /* 46 F */
  0x3e,0x41,0x49,0x49,0x7a, /* 47 G */
  0x7f,0x08,0x08,0x08,0x7f, /* 48 H */
  0x00,0x41,0x7f,0x41,0x00, /* 49 I */
  0x20,0x40,0x41,0x3f,0x01, /* 4a J */
  0x7f,0x08,0x14,0x22,0x41, /* 4b K */
  0x7f,0x40,0x40,0x40,0x40, /* 4c L */
  0x7f,0x02,0x0c,0x02,0x7f, /* 4d M */
  0x7f,0x04,0x08,0x10,0x7f, /* 4e N */
  0x3e,0x41,0x41,0x41,0x3e, /* 4f O */
  0x7f,0x09,0x09,0x09,0x06, /* 50 P */
  0x3e,0x41,0x51,0x21,0x5e, /* 51 Q */
  0x7f,0x09,0x19,0x29,0x46, /* 52 R */
  0x46,0x49,0x49,0x49,0x31, /* 53 S */
  0x01,0x01,0x7f,0x01,0x01, /* 54 T */
  0x3f,0x40,0x40,0x40,0x3f, /* 55 U */
  0x1f,0x20,0x40,0x20,0x1f, /* 56 V */
  0x3f,0x40,0x38,0x40,0x3f, /* 57 W */
  0x63,0x14,0x08,0x14,0x63, /* 58 X */
  0x07,0x08,0x70,0x08,0x07, /* 59 Y */
  0x61,0x51,0x49,0x45,0x43, /* 5a Z */
  0x00,0x7f,0x41,0x41,0x00, /* 5b [ */
  0x02,0x04,0x08,0x10,0x20, /* 5c Yen Currency Sign */
  0x00,0x41,0x41,0x7f,0x00, /* 5d ] */
  0x04,0x02,0x01,0x02,0x04, /* 5e ^ */
  0x40,0x40,0x40,0x40,0x40, /* 5f _ */
  0x00,0x01,0x02,0x04,0x00, /* 60 ` */
  0x20,0x54,0x54,0x54,0x78, /* 61 a */
  0x7f,0x48,0x44,0x44,0x38, /* 62 b */
  0x38,0x44,0x44,0x44,0x20, /* 63 c */
  0x38,0x44,0x44,0x48,0x7f, /* 64 d */
  0x38,0x54,0x54,0x54,0x18, /* 65 e */
  0x08,0x7e,0x09,0x01,0x02, /* 66 f */
  0x0c,0x52,0x52,0x52,0x3e, /* 67 g */
  0x7f,0x08,0x04,0x04,0x78, /* 68 h */
  0x00,0x44,0x7d,0x40,0x00, /* 69 i */
  0x20,0x40,0x44,0x3d,0x00, /* 6a j */
  0x7f,0x10,0x28,0x44,0x00, /* 6b k */
  0x00,0x41,0x7f,0x40,0x00, /* 6c l */
  0x7c,0x04,0x18,0x04,0x78, /* 6d m */
  0x7c,0x08,0x04,0x04,0x78, /* 6e n */
  0x38,0x44,0x44,0x44,0x38, /* 6f o */
  0x7c,0x14,0x14,0x14,0x08, /* 70 p */
  0x08,0x14,0x14,0x18,0x7c, /* 71 q */
  0x7c,0x08,0x04,0x04,0x08, /* 72 r */
  0x48,0x54,0x54,0x54,0x20, /* 73 s */
  0x04,0x3f,0x44,0x40,0x20, /* 74 t */
  0x3c,0x40,0x40,0x20,0x7c, /* 75 u */
  0x1c,0x20,0x40,0x20,0x1c, /* 76 v */
  0x3c,0x40,0x30,0x40,0x3c, /* 77 w */
  0x44,0x28,0x10,0x28,0x44, /* 78 x */
  0x0c,0x50,0x50,0x50,0x3c, /* 79 y */
  0x44,0x64,0x54,0x4c,0x44, /* 7a z */
  0x00,0x08,0x36,0x41,0x00, /* 7b < */
  0x00,0x00,0x7f,0x00,0x00, /* 7c | */
  0x00,0x41,0x36,0x08,0x00, /* 7d > */
  0x10,0x08,0x08,0x10,0x08, /* 7e Right Arrow -> */
  0x78,0x46,0x41,0x46,0x78};/* 7f Left Arrow  <- */


/* Internal method prototypes */
static void WriteCmd(uint8_t cmd);
static void WriteData(uint8_t data);

/*
** ===================================================================
**     Method      :  WriteCmd (component PDC8544)
**
**     Description :
**         Writes a command to the display
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void WriteCmd(uint8_t cmd)
{
  uint8_t dummy;

  CLR_D_C();                           /* D_C low: select command mode */
  CLR_SCE();                           /* SCE low: select device */
  NOKIA5110_CONTROLLER_DataReceivedFlag = FALSE;
  SM1_ReceiveBlock(SM1_DeviceData, &dummy, 1);
  SM1_SendBlock(SM1_DeviceData, &cmd, 1);
  while (!NOKIA5110_CONTROLLER_DataReceivedFlag) {};                            /* Wait until data block is transmitted/received */
  SET_SCE();                           /* CE high: deselect device */
}

/*
** ===================================================================
**     Method      :  WriteData (component PDC8544)
**
**     Description :
**         Write a data byte to the display
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void WriteData(uint8_t data)
{
  uint8_t dummy;

  SET_D_C();                           /* D_C high: select data mode */
  CLR_SCE();                           /* SCE low: select device */
  NOKIA5110_CONTROLLER_DataReceivedFlag = FALSE;
  SM1_ReceiveBlock(SM1_DeviceData, &dummy, 1);
  SM1_SendBlock(SM1_DeviceData, &data, 1);
  while (!NOKIA5110_CONTROLLER_DataReceivedFlag) {};                            /* Wait until data block is transmitted/received */
  SET_SCE();                           /* CE high: deselect device */
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_SetPos (component PDC8544)
**     Description :
**         Sets the cursor to the given position
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - The column number (in bits). In the range
**                           of 0...83.
**         y               - The row number (byte rows), in the range of
**                           0..5.
**     Returns     : Nothing
** ===================================================================
*/
void NOKIA5110_CONTROLLER_SetPos(NOKIA5110_CONTROLLER_PixelDim x, NOKIA5110_CONTROLLER_PixelDim y)
{
  WriteCmd((uint8_t)(0x40|(y&0x07)));   /* Y axis */
  WriteCmd((uint8_t)(0x80|(x&(NOKIA5110_CONTROLLER_DISPLAY_HW_NOF_COLUMNS-1)))); /* X axis */
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_Clear (component PDC8544)
**     Description :
**         Clears the whole display memory.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void NOKIA5110_CONTROLLER_Clear(void)
{
  short ddram;

  NOKIA5110_CONTROLLER_SetPos(0, 0);    /* move cursor to beginning of line */
  for (ddram=NOKIA5110_CONTROLLER_DISPLAY_HW_NOF_COLUMNS*(NOKIA5110_CONTROLLER_DISPLAY_HW_NOF_ROWS/8); ddram>0; ddram--) {
    WriteData(0);                       /* clear actual line */
  }
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_ClearLine (component PDC8544)
**     Description :
**         Clears a character line on the display
**     Parameters  :
**         NAME            - DESCRIPTION
**         lineNumber      - the line number of the line
**                           to be cleared.
**     Returns     : Nothing
** ===================================================================
*/
void NOKIA5110_CONTROLLER_ClearLine(uint8_t lineNumber)
{
  uint8_t ddram;

  NOKIA5110_CONTROLLER_SetPos(0, (NOKIA5110_CONTROLLER_PixelDim)lineNumber); /* move cursor to beginning of line */
  for (ddram=NOKIA5110_CONTROLLER_DISPLAY_HW_NOF_COLUMNS; ddram>0; ddram--) {
    WriteData(0);                       /* clear actual line */
  }
  NOKIA5110_CONTROLLER_SetPos(0,0);     /* move cursor home */
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_Init (component PDC8544)
**     Description :
**         Display driver initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void NOKIA5110_CONTROLLER_Init(void)
{
  RES_DeviceData = RESpin1_Init(NULL); /* device handle for RES pin */
  SCE_DeviceData = SCEpin1_Init(NULL); /* device handle for SCE pin */
  D_C_DeviceData = D_Cpin1_Init(NULL); /* device handle for D_C pin */
  /* boot display */
  SET_RES();                            /* RES high: start reset sequence */
  SET_SCE();                            /* CS high: Disable device */
  WAIT1_Waitms(10);                     /* wait at least 10ms */
  CLR_RES();                            /* Reset line low */
  WAIT1_Waitms(100);                    /* wait at least 100ms */
  SET_RES();                            /* Awake LCD from RESET state. */

  /* initialize display */
  WriteCmd(0x21);                       /* Activate Chip and H=1 */
  WriteCmd(0xC8);                       /* Set LCD Voltage; Vop v1: 0xc8 (for 3V), v2: 0xa0 (for 3V), v3: 0xc2 (2.6V-5V) */
  WriteCmd(0x13);                       /* Adjust voltage bias */
  WriteCmd(0x20);                       /* Horizontal addressing and H=0 */
  WriteCmd(0x09);                       /* Activate all segments */
  WAIT1_Waitms(20);                     /* added some delay, as some displays might not work otherwise */
  NOKIA5110_CONTROLLER_Clear();         /* Erase all pixel on the DDRAM */
  WriteCmd(0x08);                       /* Blank the Display */
  WriteCmd(0x0C);                       /* Normal display mode */

  NOKIA5110_CONTROLLER_SetContrast(60);
  NOKIA5110_CONTROLLER_SetPos(0,0);     /* Cursor Home */
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_WriteChar (component PDC8544)
**     Description :
**         Writes a single character to the display at the current
**         position.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ch              - Char to be written to the display.
**     Returns     : Nothing
** ===================================================================
*/
void NOKIA5110_CONTROLLER_WriteChar(uint8_t ch)
{
  int tablept = 0;
  int count = 0;
  int char_column = 0;

  if ((ch<0x20)||(ch>0x7f)) {          /* check for valid character */
    return;
  }
  tablept = (NOKIA5110_CONTROLLER_FONT_COLUMNS_PER_CHAR*((int)ch))-160; /* find character bitmap */
  for (count=NOKIA5110_CONTROLLER_FONT_COLUMNS_PER_CHAR;count>0;count--) { /* draw the columns to print the character */
    char_column = table[tablept];
    WriteData((uint8_t)char_column);
    tablept++;
  }
  for(count=NOKIA5110_CONTROLLER_SPACE_COLUMNS_PER_CHAR;count>0;count--) {
    WriteData(0x00);                   /* create 1-pixel spacing per character */
  }
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_WriteString (component PDC8544)
**     Description :
**         Writes a zero byte terminated string to the display at the
**         current cursor position.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * str             - Pointer to string to be written to the
**                           display.
**     Returns     : Nothing
** ===================================================================
*/
void NOKIA5110_CONTROLLER_WriteString(uint8_t *str)
{
  while(*str != '\0') {
    NOKIA5110_CONTROLLER_WriteChar(*(str++)); /*Points to one ASCII to be written one at a time */
  }
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_WriteLineStr (component PDC8544)
**     Description :
**         Writes a string to the given line position.
**     Parameters  :
**         NAME            - DESCRIPTION
**         line            - The line number, starting with 1.
**       * str             - Pointer to zero byte terminated string
**     Returns     : Nothing
** ===================================================================
*/
void NOKIA5110_CONTROLLER_WriteLineStr(uint8_t line, uint8_t *str)
{
  uint8_t i;

  if (line==0 || line>NOKIA5110_CONTROLLER_MAX_LINES_FOR_DISPLAY) {
    return; /* invalid line number */
  }
  NOKIA5110_CONTROLLER_SetPos(0, (NOKIA5110_CONTROLLER_PixelDim)(line-1));
  for(i=0; i<NOKIA5110_CONTROLLER_MAX_CHARS_PER_LINE && *str != '\0'; i++) { /* only write as much characters as there is space on the line */
    NOKIA5110_CONTROLLER_WriteChar(*(str++)); /* write character */
  }
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_UpdateRegion (component PDC8544)
**     Description :
**         Updates a region of the display
**     Parameters  :
**         NAME            - DESCRIPTION
**         x               - x coordinate
**         y               - y coordinate
**         w               - width of the region
**         h               - height of the region
**     Returns     : Nothing
** ===================================================================
*/
void NOKIA5110_CONTROLLER_UpdateRegion(NOKIA5110_CONTROLLER_PixelDim x, NOKIA5110_CONTROLLER_PixelDim y, NOKIA5110_CONTROLLER_PixelDim w, NOKIA5110_CONTROLLER_PixelDim h)
{
  (void)x; (void)y; (void)w; (void)h;
  NOKIA5110_CONTROLLER_UpdateFull();    /* NYI, we simply refresh everything :-( */
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_UpdateFull (component PDC8544)
**     Description :
**         Updates the whole display
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void NOKIA5110_CONTROLLER_UpdateFull(void)
{
  uint16_t numBytes = sizeof(NOKIA5110_CONTROLLER_DisplayBuf);
  uint8_t *data = (uint8_t*)NOKIA5110_CONTROLLER_DisplayBuf;

  NOKIA5110_CONTROLLER_SetPos(0, 0);    /* move cursor to beginning of display */
  while(numBytes>0) {
    WriteData(*data++);                 /* write data */
    numBytes--;
  }
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_SetContrast (component PDC8544)
**     Description :
**         Sets the display contrast.
**     Parameters  :
**         NAME            - DESCRIPTION
**         contrast        - Contrast value, must be in the
**                           range of  0 >= x < 128
**     Returns     : Nothing
** ===================================================================
*/
void NOKIA5110_CONTROLLER_SetContrast(uint8_t contrast)
{
  if (contrast < 128) { /* check for valid contrast values */
    WriteCmd(0x21);
    WriteCmd((uint8_t)(0x80|contrast));
    WriteCmd(0x20);
  }
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_SetMode (component PDC8544)
**     Description :
**         Sets the mode of the display (if inverted or not).
**     Parameters  :
**         NAME            - DESCRIPTION
**         inverted        - Pass TRUE to have the display
**                           operate in inverted mode, FALSE for normal
**                           mode.
**     Returns     : Nothing
** ===================================================================
*/
void NOKIA5110_CONTROLLER_SetMode(bool inverted)
{
  if (inverted) {
    WriteCmd(0x0C|1);                   /* Inverted display mode */
  } else {
    WriteCmd(0x0C);                     /* Normal display mode */
  }
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_GetDisplayOrientation (component PDC8544)
**     Description :
**         Returns the current display orientation
**     Parameters  : None
**     Returns     :
**         ---             - current display orientation
** ===================================================================
*/
NOKIA5110_CONTROLLER_DisplayOrientation NOKIA5110_CONTROLLER_GetDisplayOrientation(void)
{
  return NOKIA5110_CONTROLLER_ORIENTATION_LANDSCAPE; /* Landscape mode */
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_GetWidth (component PDC8544)
**     Description :
**         Returns the width of the display in pixels
**     Parameters  : None
**     Returns     :
**         ---             - width of display
** ===================================================================
*/
/*
NOKIA5110_CONTROLLER_PixelDim NOKIA5110_CONTROLLER_GetWidth(void)
{
  *** Method is implemented as macro in NOKIA5110_CONTROLLER.h
}
*/

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_GetHeight (component PDC8544)
**     Description :
**         Returns the height of the display in pixels
**     Parameters  : None
**     Returns     :
**         ---             - height of display
** ===================================================================
*/
/*
NOKIA5110_CONTROLLER_PixelDim NOKIA5110_CONTROLLER_GetHeight(void)
{
  *** Method is implemented as macro in NOKIA5110_CONTROLLER.h
}
*/

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_GetLongerSide (component PDC8544)
**     Description :
**         Returns the longer side of the display in pixels
**     Parameters  : None
**     Returns     :
**         ---             - longer side of display
** ===================================================================
*/
/*
NOKIA5110_CONTROLLER_PixelDim NOKIA5110_CONTROLLER_GetLongerSide(void)
{
  *** Method is implemented as macro in NOKIA5110_CONTROLLER.h
}
*/

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_GetShorterSide (component PDC8544)
**     Description :
**         Returns the shorter side of the display in pixels
**     Parameters  : None
**     Returns     :
**         ---             - shorter side of display
** ===================================================================
*/
/*
NOKIA5110_CONTROLLER_PixelDim NOKIA5110_CONTROLLER_GetShorterSide(void)
{
  *** Method is implemented as macro in NOKIA5110_CONTROLLER.h
}
*/

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_SetDisplayOrientation (component PDC8544)
**     Description :
**         Sets current display orientation
**     Parameters  :
**         NAME            - DESCRIPTION
**         newOrientation  - the new orientation
**                           for the display
**     Returns     : Nothing
** ===================================================================
*/
void NOKIA5110_CONTROLLER_SetDisplayOrientation(NOKIA5110_CONTROLLER_DisplayOrientation newOrientation)
{
  (void)newOrientation; /* setting the display orientation is not implemented yet */
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_GetLCD (component PDC8544)
**     Description :
**         Method to be called for mutual exclusive access to the LCD
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void NOKIA5110_CONTROLLER_GetLCD(void)
{
  /* If you see this comment in generated code, it means that method is not implemented yet ... */
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_GiveLCD (component PDC8544)
**     Description :
**         Method to be called for mutual exclusive access to the LCD
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void NOKIA5110_CONTROLLER_GiveLCD(void)
{
  /* If you see this comment in generated code, it means that method is not implemented yet ... */
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_OnBlockReceived (component PDC8544)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void SM1_OnBlockReceived(LDD_TUserData *UserDataPtr)
{
  NOKIA5110_CONTROLLER_DataReceivedFlag = TRUE;
  /* Calling inherited event */
}

/*
** ===================================================================
**     Method      :  NOKIA5110_CONTROLLER_Deinit (component PDC8544)
**     Description :
**         Module Deinitialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void NOKIA5110_CONTROLLER_Deinit(void)
{
  RESpin1_Deinit(RES_DeviceData); /* device handle for RES pin */
  SCEpin1_Deinit(SCE_DeviceData); /* device handle for SCE pin */
  D_Cpin1_Deinit(D_C_DeviceData); /* device handle for D_C pin */
}

/* END NOKIA5110_CONTROLLER. */

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
