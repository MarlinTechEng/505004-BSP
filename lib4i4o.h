/************************************************************************************************
*  Copyright (c) 2023 Marlin Technologies, Inc.  All rights reserved.                           *
*                                                                                               *
*  File:         lib4i4o.h	                                                                *
*  Description:  Provides mapping of all inputs and outputs to micro Pins			*
*  CPU Type:     PIC18F26K83                                                                    *
*  Compiler:     XC8 v2.40                                                                      *
************************************************************************************************/

#ifndef LIB4I4O_H
#define	LIB4I4O_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>
    
/**************************************************************************************
*                                    CAN Definitions                                  *
**************************************************************************************/
typedef enum
{
    BR_250k,	//Set Baud rate to 250k bits
    BR_500k,	//Set Baud rate to 500k bits
    BR_1000k	//Set Baud rate to 1000k bits
} valid_CAN_baud_rate_t;

#define dSTANDARD_CAN_MSG	    0

#define dEXTENDED_CAN_MSG	    1

/*******************************************************************************************
*                                    CAN Type Definitions                                  *
*******************************************************************************************/
typedef union
{
    struct
    {
        union
        {
            struct
            {
                uint32_t    ID;
		uint8_t	    EXID;
            };
	    struct
	    {
		uint8_t	    SA;
		uint8_t	    PS;
		uint8_t	    PF;
		uint8_t	    DP		:1;
		uint8_t	    EDP		:1;
		uint8_t	    Priority	:6;
		uint8_t	    reserved;
	    }Ext_ID;
        };
        uint8_t	    dlc		:4;
	uint8_t	    reserved_1	:2;
	uint8_t	    RTR		:1;
	uint8_t	    reserved_2	:1;
        union
        {
            struct
            {
                uint8_t	    data0;
                uint8_t	    data1;
                uint8_t	    data2;
                uint8_t	    data3;
                uint8_t	    data4;
                uint8_t	    data5;
                uint8_t	    data6;
                uint8_t	    data7;
            };
            uint8_t data[8];
        };
    } frame;
    uint8_t array[14];
} uCAN_APP_MSG;

/**********************************************************************************************
*                                    CAN Function Prototypes                                  *
**********************************************************************************************/
uint8_t	DequeueMessage( uCAN_APP_MSG *MsgPtr );

uint8_t EnqueueMessage( uCAN_APP_MSG * MsgPtr );

uint8_t ExtractFunctionCode(const uCAN_APP_MSG * MsgPtr);

uint8_t ExtractNodeID(const uCAN_APP_MSG * MsgPtr);

void    setFunctionCode(uCAN_APP_MSG * MsgPtr, uint8_t funcCode);

void    setNodeID(uCAN_APP_MSG * MsgPtr, uint8_t nodeID);

void    CAN_Poll( uint32_t ElapsedTime );

uint8_t get_RXQueueCount(void);

void	setBaudRate(valid_CAN_baud_rate_t baudrate);

uint8_t setSourceAddress(uint8_t newAddress);

uint8_t getSourceAddress(void);

/****************************************************************************************
*                                    Input Definitions                                  *
****************************************************************************************/
#define ADC_INPUT_SCALING                       10.63335    // Input ADC scaling mV/bit

/*********************************************************************************************
*                                    Input Type Definitions                                  *
*********************************************************************************************/
typedef enum
{
    Input_1_SMT,
    Input_2_SMT
} valid_smt_t;

typedef enum
{
    Input_1,
    Input_2,
    Input_3,
    Input_4
} valid_input_t;

typedef enum
{
    Freq_Period_DC,
    Rising_Edge_Count,
    Falling_Edge_Count,
    All_Edges_Count,
    Quadrature_X1,
    Quadrature_X2,
    Quadrature_X4,
} valid_input_config_t;

/************************************************************************************************
*                                    Input Function Prototypes                                  *
************************************************************************************************/
uint16_t Read_Batt(void);

uint16_t Read_Analog_Input(valid_input_t input);

uint8_t Config_Input(valid_input_t input, valid_input_config_t config);

uint8_t Config_Encoder_Input(valid_input_config_t config);

uint32_t Input_Get_Count(valid_input_t input);

uint8_t Input_Set_Count(valid_input_t input, uint32_t newCount);

uint32_t SMT_Collect_Pulse_Width(valid_smt_t channel);

uint32_t SMT_Collect_Period(valid_smt_t channel);

uint32_t SMT_Collect_Frequency(valid_smt_t channel);

uint32_t SMT_Collect_Duty_Cycle(valid_smt_t channel);

uint32_t SMT_Collect_Period_Raw(valid_smt_t channel);

/*****************************************************************************************
*                                    Output Definitions                                  *
*****************************************************************************************/
#define ADC_CURRENT_FEEDBACK_SCALING		3.051757813	// Scaling of A/D value to mA
#define ADC_CURRENT_FEEDBACK_OFFSET             0x0800		// Offset of A/D value

/**********************************************************************************************
*                                    Output Type Definitions                                  *
**********************************************************************************************/
typedef enum
{
    OFF,
    HIGHSIDE,
    LOWSIDE
} valid_switching_side_t;

typedef enum
{
    Output_1,
    Output_2,
    Output_3,
    Output_4,
    OUTPUT_COUNT
} valid_output_t;

/*************************************************************************************************
*                                    Output Function Prototypes                                  *
*************************************************************************************************/
uint8_t Get_Output_Fault_Status(valid_output_t output);

uint8_t Output_Set_Frequency(uint32_t frequency);

uint8_t Output_Set_On_Off(valid_output_t output, uint8_t state);

uint8_t Output_Set_Duty_Cycle(valid_output_t output, uint16_t dutyCycle);

uint8_t Output_Config(valid_output_t output, valid_switching_side_t side);

uint16_t Read_Current_Feedback(valid_output_t output);

/*********************************************************************************************
*                                    LED Control Definition                                  *
**********************************************************************************************/
#define	LED		LATBbits.LB7

/*************************************************************************************************
*                                    EEPROM Function Prototypes                                  *
*************************************************************************************************/
uint8_t write_eeprom(uint16_t Address,uint8_t Data);

uint8_t read_eeprom(uint16_t Address);

/*************************************************************************************************
*                                System Timing Function Prototypes                               *
*************************************************************************************************/
void setTickRate(uint32_t rate);

uint32_t getTickRate(void);

uint32_t getTick(void);

/*********************************************************************************
*                                Sleep Definitions                               *
**********************************************************************************/
#define WAKE_ON_IN1_FALL_EDGE	0b00000001
#define WAKE_ON_IN1_RISE_EDGE	0b00000010
#define WAKE_ON_IN2_FALL_EDGE	0b00000100
#define WAKE_ON_IN2_RISE_EDGE	0b00001000
#define WAKE_ON_CAN		0b00010000

/***************************************************************************
*                          Sleep Function Prototypes                       *
****************************************************************************/
void Goto_Sleep(uint8_t sleepConfig, uCAN_APP_MSG * wakeupMSG);

#endif	/* LIB4I4O_H */

