

#ifndef _18F26K83                    //Processor being used for project
#define _18F26K83
#endif


//Set CONFIG WORD 1L (30 0000h)
#pragma config FEXTOSC   = HS           // External Oscillator (LP/XT/HS/OFF/ECL/ECM/ECH)   (HS) crystal oscillator above 8MHz; PFM set to high power
#pragma config RSTOSC    = EXTOSC_4PLL  // Reset Oscillator (HFINTOSC_64MHZ/EXTOSC_4PLL/SOSC/LFINTOSC/HFINTOSC_1MHZ/EXTOSC) (EXTOSC_4PLL) External Osc w/ 4xPLL per FEXTOSC bits
//Set CONFIG WORD 1H (30 0001h)
#pragma config CLKOUTEN  = OFF          // Clock Out Enable (ON/OFF)                        (OFF)CLKOUT function is disabled; I/O or oscillator function on OSC2
#pragma config PR1WAY    = ON           // PRLOCKED One-Way Set (ON/OFF)                    (ON)can be cleared/set only once
#pragma config CSWEN     = ON           // Clock Switch Enable (ON/OFF)                     (ON)Writing to NOSC and NDIV is allowed
#pragma config FCMEN     = OFF          // Fail-Safe Clock Monitor Enable (ON/OFF)          (OFF)Disabled - [NOTE: Crystal doesn't start up fast enough to use this!!!]

//Set CONFIG WORD 2L (30 0002h)
#pragma config MCLRE     = EXTMCLR      // MCLR Enable Bit(EXTMCLR/INTMCLR)                 (EXTMCLR)External pin IS MCLR
#pragma config PWRTS     = PWRT_1       // Power-Up Timer Selection(PWRT_OFF/PWRT_64/PWRT_16/PWRT_1)    (PWRT_64)Power-Up Timer delay of 64mS
#pragma config MVECEN    = OFF          // Multi-Vector Enable (ON/OFF)                     (OFF)Legacy interrupt behavior (not vector table or multi-vector enabled )
#pragma config IVT1WAY   = OFF           // IVTLOCK Oneway set (ON/OFF)                      (ON)bit can be cleared/set only once
#pragma config LPBOREN   = OFF          // Low Power BOR enable (ON/OFF)                    (OFF)disabled
#pragma config BOREN     = SBORDIS      // Brown-Out Reset enable (SBORDIS/NOSLP/ON/OFF)    (SBORDIS)enabled, SBOREN is ignored
//Set CONFIG WORD 2H (30 0003h)
#pragma config BORV      = VBOR_2P45    // BOR Voltage Select (VBOR_2P45/VBOR_/VBOR_/VBOR_) (VBOR_2P45) BOR set at 2.45V
#pragma config ZCD       = OFF          // ZCD Disable Bit (ON/OFF)                         (OFF) Disabled.  Can be enabled by setting ZCDCON.ZCDSEN
#pragma config PPS1WAY   = OFF          // PPSLOCK oneway set enable (ON/OFF)               (OFF) cleared/set multiple times
#pragma config STVREN    = ON           // Stack Full/Underflow reset enable (ON/OFF)       (ON) will cause reset
#pragma config DEBUG     = OFF          // Debugger Enable (ON/OFF)                         (OFF)Background debugger disabled
#pragma config XINST     = OFF          // Extended Instruction Set enable (ON/OFF)         (OFF)Disabled
//Set CONFIG WORD 3L (30 0004h)
#pragma config WDTCPS    = WDTCPS_31    // WDT Period (WDTCPS_0 thru _31)                   (WDTCPS_31) Divider ratio 1:65536, software control of WDTCP
#pragma config WDTE      = ON       // WDT operating mode (OFF/SWDTEN/NSLEEP/ON)        (SWDTEN) WDT enabled/disabled by SWDTEN bit
//Set CONFIG WORD 3H (30 0005h)
#pragma config WDTCWS    = WDTCWS_7     // WDT window select(WDTCWS_0 thru _7)              (WDTCWS_7) Window aways open (100%) software control, keyed access not required
#pragma config WDTCCS    = LFINTOSC           // WDT clock selector (LFINTOSC/MFINTOSC/SOSC/SC)   (SC) Software Control
//Set CONFIG WORD 4L (30 0006h)
#pragma config BBSIZE    = BBSIZE_512   // Boot Block Size (BBSIZE_512/_1024/2048/4096/8192/16384)  (BBSIZE_512) Boot Block size is 512 words
#pragma config BBEN      = OFF          // Boot Block Enable (ON/OFF)                       (OFF) Boot Block disabled
#pragma config SAFEN     = OFF          // Storage Area Flash (ON/OFF)                      (OFF) SAF disabled
#pragma config WRTAPP    = OFF          // Appl Block write protect (ON/OFF)                (OFF) App Block not write protected
//Set CONFIG WORD 4H (30 0007h)
#pragma config WRTB      = OFF          // Config Reg Write Protection (ON/OFF)             (OFF) Config Reg not write protected
#pragma config WRTC      = OFF          // Boot Block Write Protection (ON/OFF)             (OFF) Boot Block not write protected
#pragma config WRTD      = OFF          // Storage Area Write Protection (ON/OFF)           (OFF) Storage Area not write protected
#pragma config WRTSAF    = OFF          // SAF Write Protection (ON/OFF)                    (OFF) SAF not write protected
#pragma config LVP       = ON           // Low Voltage Programming Enable (ON/OFF)          (ON) Low volt programming enabled MCLR/VPP is MCLR. MCLRE bit is ignored
//Set CONFIG WORD 5L (30 0008h)
#pragma config CP        = OFF          // PFM and Data EEPROM code protection (ON/OFF)     (OFF) PFM and Data EEPROM code protection disabled
//Set CONFIG WORD 5H (30 0009h)
