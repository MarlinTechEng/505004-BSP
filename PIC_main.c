
/********************************************************************************
*	                        	 Include Files                               	*
********************************************************************************/
#include <xc.h>
#include "lib4i4o.h"

/*****  User Includes Begin  *****/

/*****   User Includes End   *****/

/*****  User Defines Begin  *****/

/*****   User Defines End   *****/

/********************************************************************************
*                                 Variables										*
********************************************************************************/
/*****   User Variables Begin   *****/
long SW_NUM = 123456;
unsigned char SW_REV[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
/*****    User Variables End    *****/

/********************************************************************************
*                       Private Function Prototypes								*
********************************************************************************/
void CHK_CAN(void);

/*****   User Prototypes Begin   *****/

/*****    User Prototypes End    *****/

/************************************************************************************************
*  Name:        PICC_MAIN                                                                       *
*  Description: Main Loop for Functionality of the Module                                       *
*  Parameters:  N/A																				*
*  Returns:     N/A																				*
*                                                                                               *
************************************************************************************************/
void picc_main(void)
{
    /**************************/
	/***** Initialization *****/
	/**************************/
    
	while (1)
	{
		CLRWDT();       // Clear WatchDog Timer
        CHK_CAN();      // Check for new CAN messages and process if there is one
	}
}

/************************************************************************************************
*  Name:        CHK_CAN                                                                         *
*  Description: Process received CAN messages                                                   *
*  Parameters:  N/A                                                                             *
*  Returns:     N/A                                                                             *
*                                                                                               *
*  NOTES:                                                                                       *
*                                                                                               *
************************************************************************************************/
void CHK_CAN(void)
{
    uCAN_APP_MSG Msg = {0};
	
	while (get_RXQueueCount() > 0)          //Check if there are any CAN message
	{        
		DequeueMessage(&Msg);         //Get next CAN message from buffer
		
		/*****************************/
		/*****  User Code Begin  *****/
		/*****************************/
		
		/***************************/
		/*****  User Code End  *****/
		/***************************/
	}
}
