/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/
#include "project.h"

/*************************************************************************************************/
/*********************						Variables						**********************/
/*************************************************************************************************/
//array for receiving a word
unsigned char receive[100];
unsigned char data;
unsigned char i=0;
unsigned char j=0;
unsigned char k=0;

//This array initializes communication with MotionStim8(not necessary)
unsigned char init[]={0xFF,0xFF,0x00,0x08,0x08};

/* Examples of configuration (not necessary)
//Configure Channel 1   30 Hz   300 uSec    0 mA
unsigned char script1[]={0xFF,0xFF,0x04,0x01,0x01,0x00,0x01,0x2C,0x33};
unsigned char script2[]={0xFF,0xFF,0x03,0x03,0x01,0x00,0x1E,0x25};

//Configure Channel 2   30 Hz   300 uSec    0 mA
unsigned char script3[]={0xFF,0xFF,0x04,0x01,0x02,0x00,0x01,0x2C,0x34};
unsigned char script4[]={0xFF,0xFF,0x03,0x03,0x02,0x00,0x1E,0x26};

//Configure Channel 3   30 Hz   300 uSec    0 mA
unsigned char script5[]={0xFF,0xFF,0x04,0x01,0x03,0x00,0x01,0x2C,0x35};
unsigned char script6[]={0xFF,0xFF,0x03,0x03,0x03,0x00,0x1E,0x27};
*/

//It is the same for routines on channel 1, what changes is the amplitude
//Routine 1: Configures Channel 1 from 0 mA to 10 mA
//Configure Channel 1   30 Hz   300 uSec    0 mA
unsigned char routine1[]={0xFF,0xFF,0x03,0x03,0x01,0x00,0x1E,0x25};
//Configure routineX_X[]={DM,DM,DM,DM,CHANNEL,AMPLITUDE,DM,DM,CHECKSUM};
unsigned char routine1_0[]={0xFF,0xFF,0x04,0x01,0x01,0x00,0x01,0x2C,0x33};
unsigned char routine1_1[]={0xFF,0xFF,0x04,0x01,0x01,0x01,0x01,0x2C,0x34};
unsigned char routine1_2[]={0xFF,0xFF,0x04,0x01,0x01,0x02,0x01,0x2C,0x35};
unsigned char routine1_3[]={0xFF,0xFF,0x04,0x01,0x01,0x03,0x01,0x2C,0x36};
unsigned char routine1_4[]={0xFF,0xFF,0x04,0x01,0x01,0x04,0x01,0x2C,0x37};
unsigned char routine1_5[]={0xFF,0xFF,0x04,0x01,0x01,0x05,0x01,0x2C,0x38};
unsigned char routine1_6[]={0xFF,0xFF,0x04,0x01,0x01,0x06,0x01,0x2C,0x39};
unsigned char routine1_7[]={0xFF,0xFF,0x04,0x01,0x01,0x07,0x01,0x2C,0x3A};
unsigned char routine1_8[]={0xFF,0xFF,0x04,0x01,0x01,0x08,0x01,0x2C,0x3B};
unsigned char routine1_9[]={0xFF,0xFF,0x04,0x01,0x01,0x09,0x01,0x2C,0x3C};
unsigned char routine1_10[]={0xFF,0xFF,0x04,0x01,0x01,0x0A,0x01,0x2C,0x3D};

//It is the same for routines on channel 1, what changes is the amplitude
//Routine 2: Configures Channel 2 from 0 mA to 10 mA
//Configure Channel 2   30 Hz   300 uSec    0 mA
unsigned char routine2[]={0xFF,0xFF,0x03,0x03,0x02,0x00,0x1E,0x26};
//routineX_X[]={DM,DM,DM,DM,CHANNEL,AMPLITUDE,DM,DM,CHECKSUM};
unsigned char routine2_0[]={0xFF,0xFF,0x04,0x01,0x02,0x00,0x01,0x2C,0x34};
unsigned char routine2_1[]={0xFF,0xFF,0x04,0x01,0x02,0x01,0x01,0x2C,0x35};
unsigned char routine2_2[]={0xFF,0xFF,0x04,0x01,0x02,0x02,0x01,0x2C,0x36};
unsigned char routine2_3[]={0xFF,0xFF,0x04,0x01,0x02,0x03,0x01,0x2C,0x37};
unsigned char routine2_4[]={0xFF,0xFF,0x04,0x01,0x02,0x04,0x01,0x2C,0x38};
unsigned char routine2_5[]={0xFF,0xFF,0x04,0x01,0x02,0x05,0x01,0x2C,0x39};
unsigned char routine2_6[]={0xFF,0xFF,0x04,0x01,0x02,0x06,0x01,0x2C,0x3A};
unsigned char routine2_7[]={0xFF,0xFF,0x04,0x01,0x02,0x07,0x01,0x2C,0x3B};
unsigned char routine2_8[]={0xFF,0xFF,0x04,0x01,0x02,0x08,0x01,0x2C,0x3C};
unsigned char routine2_9[]={0xFF,0xFF,0x04,0x01,0x02,0x09,0x01,0x2C,0x3D};
unsigned char routine2_10[]={0xFF,0xFF,0x04,0x01,0x02,0x0A,0x01,0x2C,0x3E};

//Routine 3: Configures Channel 1 from 0 mA to 18 mA
unsigned char routine3[]={0xFF,0xFF,0x03,0x03,0x01,0x00,0x1E,0x25};
unsigned char routine3_0[]={0xFF,0xFF,0x04,0x01,0x01,0x00,0x01,0x2C,0x33};
unsigned char routine3_1[]={0xFF,0xFF,0x04,0x01,0x01,0x01,0x01,0x2C,0x34};
unsigned char routine3_2[]={0xFF,0xFF,0x04,0x01,0x01,0x02,0x01,0x2C,0x35};
unsigned char routine3_3[]={0xFF,0xFF,0x04,0x01,0x01,0x03,0x01,0x2C,0x36};
unsigned char routine3_4[]={0xFF,0xFF,0x04,0x01,0x01,0x04,0x01,0x2C,0x37};
unsigned char routine3_5[]={0xFF,0xFF,0x04,0x01,0x01,0x05,0x01,0x2C,0x38};
unsigned char routine3_6[]={0xFF,0xFF,0x04,0x01,0x01,0x06,0x01,0x2C,0x39};
unsigned char routine3_7[]={0xFF,0xFF,0x04,0x01,0x01,0x07,0x01,0x2C,0x3A};
unsigned char routine3_8[]={0xFF,0xFF,0x04,0x01,0x01,0x08,0x01,0x2C,0x3B};
unsigned char routine3_9[]={0xFF,0xFF,0x04,0x01,0x01,0x09,0x01,0x2C,0x3C};
unsigned char routine3_10[]={0xFF,0xFF,0x04,0x01,0x01,0x0A,0x01,0x2C,0x3D};
unsigned char routine3_11[]={0xFF,0xFF,0x04,0x01,0x01,0x0B,0x01,0x2C,0x3E};
unsigned char routine3_12[]={0xFF,0xFF,0x04,0x01,0x01,0x0C,0x01,0x2C,0x3F};
unsigned char routine3_13[]={0xFF,0xFF,0x04,0x01,0x01,0x0D,0x01,0x2C,0x40};
unsigned char routine3_14[]={0xFF,0xFF,0x04,0x01,0x01,0x0E,0x01,0x2C,0x41};
unsigned char routine3_15[]={0xFF,0xFF,0x04,0x01,0x01,0x0F,0x01,0x2C,0x42};
unsigned char routine3_16[]={0xFF,0xFF,0x04,0x01,0x01,0x10,0x01,0x2C,0x43};
unsigned char routine3_17[]={0xFF,0xFF,0x04,0x01,0x01,0x11,0x01,0x2C,0x44};
unsigned char routine3_18[]={0xFF,0xFF,0x04,0x01,0x01,0x12,0x01,0x2C,0x45};

//Routine 4: Configures Channel 2 from 0 mA to 10 mA
unsigned char routine4[]={0xFF,0xFF,0x03,0x03,0x02,0x00,0x1E,0x26};
unsigned char routine4_0[]={0xFF,0xFF,0x04,0x01,0x02,0x00,0x01,0x2C,0x34};
unsigned char routine4_1[]={0xFF,0xFF,0x04,0x01,0x02,0x01,0x01,0x2C,0x35};
unsigned char routine4_2[]={0xFF,0xFF,0x04,0x01,0x02,0x02,0x01,0x2C,0x36};
unsigned char routine4_3[]={0xFF,0xFF,0x04,0x01,0x02,0x03,0x01,0x2C,0x37};
unsigned char routine4_4[]={0xFF,0xFF,0x04,0x01,0x02,0x04,0x01,0x2C,0x38};
unsigned char routine4_5[]={0xFF,0xFF,0x04,0x01,0x02,0x05,0x01,0x2C,0x39};
unsigned char routine4_6[]={0xFF,0xFF,0x04,0x01,0x02,0x06,0x01,0x2C,0x3A};
unsigned char routine4_7[]={0xFF,0xFF,0x04,0x01,0x02,0x07,0x01,0x2C,0x3B};
unsigned char routine4_8[]={0xFF,0xFF,0x04,0x01,0x02,0x08,0x01,0x2C,0x3C};
unsigned char routine4_9[]={0xFF,0xFF,0x04,0x01,0x02,0x09,0x01,0x2C,0x3D};
unsigned char routine4_10[]={0xFF,0xFF,0x04,0x01,0x02,0x0A,0x01,0x2C,0x3E};
unsigned char routine4_11[]={0xFF,0xFF,0x04,0x01,0x02,0x0B,0x01,0x2C,0x3F};
unsigned char routine4_12[]={0xFF,0xFF,0x04,0x01,0x02,0x0C,0x01,0x2C,0x40};
unsigned char routine4_13[]={0xFF,0xFF,0x04,0x01,0x02,0x0D,0x01,0x2C,0x41};
unsigned char routine4_14[]={0xFF,0xFF,0x04,0x01,0x02,0x0E,0x01,0x2C,0x42};
unsigned char routine4_15[]={0xFF,0xFF,0x04,0x01,0x02,0x0F,0x01,0x2C,0x43};
unsigned char routine4_16[]={0xFF,0xFF,0x04,0x01,0x02,0x10,0x01,0x2C,0x44};
unsigned char routine4_17[]={0xFF,0xFF,0x04,0x01,0x02,0x11,0x01,0x2C,0x45};
unsigned char routine4_18[]={0xFF,0xFF,0x04,0x01,0x02,0x12,0x01,0x2C,0x46};

//Routine 5: Configures Channel 1 from 0 mA to 12 mA
unsigned char routine5[]={0xFF,0xFF,0x03,0x03,0x01,0x00,0x1E,0x25};
unsigned char routine5_0[]={0xFF,0xFF,0x04,0x01,0x01,0x00,0x01,0x2C,0x33};
unsigned char routine5_1[]={0xFF,0xFF,0x04,0x01,0x01,0x01,0x01,0x2C,0x34};
unsigned char routine5_2[]={0xFF,0xFF,0x04,0x01,0x01,0x02,0x01,0x2C,0x35};
unsigned char routine5_3[]={0xFF,0xFF,0x04,0x01,0x01,0x03,0x01,0x2C,0x36};
unsigned char routine5_4[]={0xFF,0xFF,0x04,0x01,0x01,0x04,0x01,0x2C,0x37};
unsigned char routine5_5[]={0xFF,0xFF,0x04,0x01,0x01,0x05,0x01,0x2C,0x38};
unsigned char routine5_6[]={0xFF,0xFF,0x04,0x01,0x01,0x06,0x01,0x2C,0x39};
unsigned char routine5_7[]={0xFF,0xFF,0x04,0x01,0x01,0x07,0x01,0x2C,0x3A};
unsigned char routine5_8[]={0xFF,0xFF,0x04,0x01,0x01,0x08,0x01,0x2C,0x3B};
unsigned char routine5_9[]={0xFF,0xFF,0x04,0x01,0x01,0x09,0x01,0x2C,0x3C};
unsigned char routine5_10[]={0xFF,0xFF,0x04,0x01,0x01,0x0A,0x01,0x2C,0x3D};
unsigned char routine5_11[]={0xFF,0xFF,0x04,0x01,0x01,0x0B,0x01,0x2C,0x3E};
unsigned char routine5_12[]={0xFF,0xFF,0x04,0x01,0x01,0x0C,0x01,0x2C,0x3F};

//Routine 6: Configures Channel 2 from 0 mA to 12 mA
unsigned char routine6[]={0xFF,0xFF,0x03,0x03,0x02,0x00,0x1E,0x26};
unsigned char routine6_0[]={0xFF,0xFF,0x04,0x01,0x02,0x00,0x01,0x2C,0x34};
unsigned char routine6_1[]={0xFF,0xFF,0x04,0x01,0x02,0x01,0x01,0x2C,0x35};
unsigned char routine6_2[]={0xFF,0xFF,0x04,0x01,0x02,0x02,0x01,0x2C,0x36};
unsigned char routine6_3[]={0xFF,0xFF,0x04,0x01,0x02,0x03,0x01,0x2C,0x37};
unsigned char routine6_4[]={0xFF,0xFF,0x04,0x01,0x02,0x04,0x01,0x2C,0x38};
unsigned char routine6_5[]={0xFF,0xFF,0x04,0x01,0x02,0x05,0x01,0x2C,0x39};
unsigned char routine6_6[]={0xFF,0xFF,0x04,0x01,0x02,0x06,0x01,0x2C,0x3A};
unsigned char routine6_7[]={0xFF,0xFF,0x04,0x01,0x02,0x07,0x01,0x2C,0x3B};
unsigned char routine6_8[]={0xFF,0xFF,0x04,0x01,0x02,0x08,0x01,0x2C,0x3C};
unsigned char routine6_9[]={0xFF,0xFF,0x04,0x01,0x02,0x09,0x01,0x2C,0x3D};
unsigned char routine6_10[]={0xFF,0xFF,0x04,0x01,0x02,0x0A,0x01,0x2C,0x3E};
unsigned char routine6_11[]={0xFF,0xFF,0x04,0x01,0x02,0x0B,0x01,0x2C,0x3F};
unsigned char routine6_12[]={0xFF,0xFF,0x04,0x01,0x02,0x0C,0x01,0x2C,0x40};

/*************************************************************************************************/
/*********************						Interruptions					**********************/
/*************************************************************************************************/
CY_ISR(RX_ISR)
{
    //Clears the flag of the interruption
    RX_ISR_ClearPending();
    //Stores the byte recieved by UART
    data = UART_GetByte();
    //Stores the byte in the recieve array 
    receive[i] = data;
    //Continues conunting for the next space in the array
    i++;
    //If the next byte received is the ASCII of an "Enter", I is reseted
    if (data == '\n')
    {
        i = 0; 
    }
}

/*************************************************************************************************/
/*********************						Functions   					**********************/
/*************************************************************************************************/

//This function sends the init array to establish communication with the MotionStim8, plus a 10 second delay(not necessary)
void Send_Init(void)
{
    UART_PutArray(init,5);
    CyDelay(10000);
}

/*This function sends the arrays to configure channels 1, 2 and 3 (Is not Used)
void Send_Script(void)
{
    UART_PutArray(script1,9);
    CyDelay(1000);
    UART_PutArray(script2,8);
    CyDelay(1000);
    UART_PutArray(script3,9);
    CyDelay(1000);
    UART_PutArray(script4,8);
    CyDelay(1000);
    UART_PutArray(script5,9);
    CyDelay(1000);
    UART_PutArray(script6,8);
}
*/

//This function sends Routine 1
void Send_Routine1(void)
{
    //Sends the 8 bytes of the routine1 array (It is the same for the other routines)
    UART_PutArray(routine1,8);
    //Delay of 1 second
    CyDelay(1000);
    //Sends the 9 bytes of the routine1_0 array (It is the same for the other routines)
    UART_PutArray(routine1_0,9);
    CyDelay(1000);
    UART_PutArray(routine1_1,9);
    CyDelay(1000);
    UART_PutArray(routine1_2,9);
    CyDelay(1000);
    UART_PutArray(routine1_3,9);
    CyDelay(1000);
    UART_PutArray(routine1_4,9);
    CyDelay(1000);
    UART_PutArray(routine1_5,9);
    CyDelay(1000);
    UART_PutArray(routine1_6,9);
    CyDelay(1000);
    UART_PutArray(routine1_7,9);
    CyDelay(1000);
    UART_PutArray(routine1_8,9);
    CyDelay(1000);
    UART_PutArray(routine1_9,9);
    CyDelay(1000);
    UART_PutArray(routine1_10,9);
    CyDelay(1000);
    UART_PutArray(routine1_9,9);
    CyDelay(1000);
    UART_PutArray(routine1_8,9);
    CyDelay(1000);
    UART_PutArray(routine1_7,9);
    CyDelay(1000);
    UART_PutArray(routine1_6,9);
    CyDelay(1000);
    UART_PutArray(routine1_5,9);
    CyDelay(1000);
    UART_PutArray(routine1_4,9);
    CyDelay(1000);
    UART_PutArray(routine1_3,9);
    CyDelay(1000);
    UART_PutArray(routine1_2,9);
    CyDelay(1000);
    UART_PutArray(routine1_1,9);
    CyDelay(1000);
    UART_PutArray(routine1_0,9);
    CyDelay(1000);
}

//This functions sends Routine 2
void Send_Routine2(void)
{
    UART_PutArray(routine2,8);
    CyDelay(1000);
    UART_PutArray(routine2_0,9);
    CyDelay(1000);
    UART_PutArray(routine2_1,9);
    CyDelay(1000);
    UART_PutArray(routine2_2,9);
    CyDelay(1000);
    UART_PutArray(routine2_3,9);
    CyDelay(1000);
    UART_PutArray(routine2_4,9);
    CyDelay(1000);
    UART_PutArray(routine2_5,9);
    CyDelay(1000);
    UART_PutArray(routine2_6,9);
    CyDelay(1000);
    UART_PutArray(routine2_7,9);
    CyDelay(1000);
    UART_PutArray(routine2_8,9);
    CyDelay(1000);
    UART_PutArray(routine2_9,9);
    CyDelay(1000);
    UART_PutArray(routine2_10,9);
    CyDelay(1000);
    UART_PutArray(routine2_9,9);
    CyDelay(1000);
    UART_PutArray(routine2_8,9);
    CyDelay(1000);
    UART_PutArray(routine2_7,9);
    CyDelay(1000);
    UART_PutArray(routine2_6,9);
    CyDelay(1000);
    UART_PutArray(routine2_5,9);
    CyDelay(1000);
    UART_PutArray(routine2_4,9);
    CyDelay(1000);
    UART_PutArray(routine2_3,9);
    CyDelay(1000);
    UART_PutArray(routine2_2,9);
    CyDelay(1000);
    UART_PutArray(routine2_1,9);
    CyDelay(1000);
    UART_PutArray(routine2_0,9);
    CyDelay(1000);
}


//This function sends Routine 3
void Send_Routine3(void)
{
    UART_PutArray(routine3,8);
    CyDelay(1000);
    UART_PutArray(routine3_0,9);
    CyDelay(1000);
    UART_PutArray(routine3_1,9);
    CyDelay(1000);
    UART_PutArray(routine3_2,9);
    CyDelay(1000);
    UART_PutArray(routine3_3,9);
    CyDelay(1000);
    UART_PutArray(routine3_4,9);
    CyDelay(1000);
    UART_PutArray(routine3_5,9);
    CyDelay(1000);
    UART_PutArray(routine3_6,9);
    CyDelay(1000);
    UART_PutArray(routine3_7,9);
    CyDelay(1000);
    UART_PutArray(routine3_8,9);
    CyDelay(1000);
    UART_PutArray(routine3_9,9);
    CyDelay(1000);
    UART_PutArray(routine3_10,9);
    CyDelay(1000);
    UART_PutArray(routine3_11,9);
    CyDelay(1000);
    UART_PutArray(routine3_12,9);
    CyDelay(1000);
    UART_PutArray(routine3_13,9);
    CyDelay(1000);
    UART_PutArray(routine3_14,9);
    CyDelay(1000);
    UART_PutArray(routine3_15,9);
    CyDelay(1000);
    UART_PutArray(routine3_16,9);
    CyDelay(1000);
    UART_PutArray(routine3_17,9);
    CyDelay(1000);
    UART_PutArray(routine3_18,9);
    CyDelay(1000);
    UART_PutArray(routine3_17,9);
    CyDelay(1000);
    UART_PutArray(routine3_16,9);
    CyDelay(1000);
    UART_PutArray(routine3_15,9);
    CyDelay(1000);
    UART_PutArray(routine3_14,9);
    CyDelay(1000);
    UART_PutArray(routine3_13,9);
    CyDelay(1000);
    UART_PutArray(routine3_12,9);
    CyDelay(1000);
    UART_PutArray(routine3_11,9);
    CyDelay(1000);
    UART_PutArray(routine3_10,9);
    CyDelay(1000);
    UART_PutArray(routine3_9,9);
    CyDelay(1000);
    UART_PutArray(routine3_8,9);
    CyDelay(1000);
    UART_PutArray(routine3_7,9);
    CyDelay(1000);
    UART_PutArray(routine3_6,9);
    CyDelay(1000);
    UART_PutArray(routine3_5,9);
    CyDelay(1000);
    UART_PutArray(routine3_4,9);
    CyDelay(1000);
    UART_PutArray(routine3_3,9);
    CyDelay(1000);
    UART_PutArray(routine3_2,9);
    CyDelay(1000);
    UART_PutArray(routine3_1,9);
    CyDelay(1000);
    UART_PutArray(routine3_0,9);
    CyDelay(1000);
}

//This function sends Routine 4
void Send_Routine4(void)
{
    UART_PutArray(routine4,8);
    CyDelay(1000);
    UART_PutArray(routine4_0,9);
    CyDelay(1000);
    UART_PutArray(routine4_1,9);
    CyDelay(1000);
    UART_PutArray(routine4_2,9);
    CyDelay(1000);
    UART_PutArray(routine4_3,9);
    CyDelay(1000);
    UART_PutArray(routine4_4,9);
    CyDelay(1000);
    UART_PutArray(routine4_5,9);
    CyDelay(1000);
    UART_PutArray(routine4_6,9);
    CyDelay(1000);
    UART_PutArray(routine4_7,9);
    CyDelay(1000);
    UART_PutArray(routine4_8,9);
    CyDelay(1000);
    UART_PutArray(routine4_9,9);
    CyDelay(1000);
    UART_PutArray(routine4_10,9);
    CyDelay(1000);
    UART_PutArray(routine4_11,9);
    CyDelay(1000);
    UART_PutArray(routine4_12,9);
    CyDelay(1000);
    UART_PutArray(routine4_13,9);
    CyDelay(1000);
    UART_PutArray(routine4_14,9);
    CyDelay(1000);
    UART_PutArray(routine4_15,9);
    CyDelay(1000);
    UART_PutArray(routine4_16,9);
    CyDelay(1000);
    UART_PutArray(routine4_17,9);
    CyDelay(1000);
    UART_PutArray(routine4_18,9);
    CyDelay(1000);
    UART_PutArray(routine4_17,9);
    CyDelay(1000);
    UART_PutArray(routine4_16,9);
    CyDelay(1000);
    UART_PutArray(routine4_15,9);
    CyDelay(1000);
    UART_PutArray(routine4_14,9);
    CyDelay(1000);
    UART_PutArray(routine4_13,9);
    CyDelay(1000);
    UART_PutArray(routine4_12,9);
    CyDelay(1000);
    UART_PutArray(routine4_11,9);
    CyDelay(1000);
    UART_PutArray(routine4_10,9);
    CyDelay(1000);
    UART_PutArray(routine4_9,9);
    CyDelay(1000);
    UART_PutArray(routine4_8,9);
    CyDelay(1000);
    UART_PutArray(routine4_7,9);
    CyDelay(1000);
    UART_PutArray(routine4_6,9);
    CyDelay(1000);
    UART_PutArray(routine4_5,9);
    CyDelay(1000);
    UART_PutArray(routine4_4,9);
    CyDelay(1000);
    UART_PutArray(routine4_3,9);
    CyDelay(1000);
    UART_PutArray(routine4_2,9);
    CyDelay(1000);
    UART_PutArray(routine4_1,9);
    CyDelay(1000);
    UART_PutArray(routine4_0,9);
    CyDelay(1000);
}

//This function sends Routine 5
void Send_Routine5(void)
{
    UART_PutArray(routine5,8);
    CyDelay(1000);
    UART_PutArray(routine5_0,9);
    CyDelay(1000);
    UART_PutArray(routine5_1,9);
    CyDelay(1000);
    UART_PutArray(routine5_2,9);
    CyDelay(1000);
    UART_PutArray(routine5_3,9);
    CyDelay(1000);
    UART_PutArray(routine5_4,9);
    CyDelay(1000);
    UART_PutArray(routine5_5,9);
    CyDelay(1000);
    UART_PutArray(routine5_6,9);
    CyDelay(1000);
    UART_PutArray(routine5_7,9);
    CyDelay(1000);
    UART_PutArray(routine5_8,9);
    CyDelay(1000);
    UART_PutArray(routine5_9,9);
    CyDelay(1000);
    UART_PutArray(routine5_10,9);
    CyDelay(1000);
    UART_PutArray(routine5_11,9);
    CyDelay(1000);
    UART_PutArray(routine5_12,9);
    CyDelay(1000);
    UART_PutArray(routine5_11,9);
    CyDelay(1000);
    UART_PutArray(routine5_10,9);
    CyDelay(1000);
    UART_PutArray(routine5_9,9);
    CyDelay(1000);
    UART_PutArray(routine5_8,9);
    CyDelay(1000);
    UART_PutArray(routine5_7,9);
    CyDelay(1000);
    UART_PutArray(routine5_6,9);
    CyDelay(1000);
    UART_PutArray(routine5_5,9);
    CyDelay(1000);
    UART_PutArray(routine5_4,9);
    CyDelay(1000);
    UART_PutArray(routine5_3,9);
    CyDelay(1000);
    UART_PutArray(routine5_2,9);
    CyDelay(1000);
    UART_PutArray(routine5_1,9);
    CyDelay(1000);
    UART_PutArray(routine5_0,9);
    CyDelay(1000);
}

//This function sends Routine 6
void Send_Routine6(void)
{
    UART_PutArray(routine6,8);
    CyDelay(1000);
    UART_PutArray(routine6_0,9);
    CyDelay(1000);
    UART_PutArray(routine6_1,9);
    CyDelay(1000);
    UART_PutArray(routine6_2,9);
    CyDelay(1000);
    UART_PutArray(routine6_3,9);
    CyDelay(1000);
    UART_PutArray(routine6_4,9);
    CyDelay(1000);
    UART_PutArray(routine6_5,9);
    CyDelay(1000);
    UART_PutArray(routine6_6,9);
    CyDelay(1000);
    UART_PutArray(routine6_7,9);
    CyDelay(1000);
    UART_PutArray(routine6_8,9);
    CyDelay(1000);
    UART_PutArray(routine6_9,9);
    CyDelay(1000);
    UART_PutArray(routine6_10,9);
    CyDelay(1000);
    UART_PutArray(routine6_11,9);
    CyDelay(1000);
    UART_PutArray(routine6_12,9);
    CyDelay(1000);
    UART_PutArray(routine6_11,9);
    CyDelay(1000);
    UART_PutArray(routine6_10,9);
    CyDelay(1000);
    UART_PutArray(routine6_9,9);
    CyDelay(1000);
    UART_PutArray(routine6_8,9);
    CyDelay(1000);
    UART_PutArray(routine6_7,9);
    CyDelay(1000);
    UART_PutArray(routine6_6,9);
    CyDelay(1000);
    UART_PutArray(routine6_5,9);
    CyDelay(1000);
    UART_PutArray(routine6_4,9);
    CyDelay(1000);
    UART_PutArray(routine6_3,9);
    CyDelay(1000);
    UART_PutArray(routine6_2,9);
    CyDelay(1000);
    UART_PutArray(routine6_1,9);
    CyDelay(1000);
    UART_PutArray(routine6_0,9);
    CyDelay(1000);
}


/*************************************************************************************************/
/*********************						Main        					**********************/
/*************************************************************************************************/
int main(void)
{
    // Enable global interrupts.
    CyGlobalIntEnable; 
    
    //Interruption of the receptor
    RX_ISR_StartEx(RX_ISR);
    
    //Initialization of UART
    UART_Start();
   
    for(;;)
    {
        //according to the ASCII received, the microcontroller will execute a script
        if (receive[0] == 'D' && receive[1] == 'e' && receive[2] == 'r' && receive[3] == 'e' && 
            receive[4] == 'c' && receive[5] == 'h' && receive[6] == 'a' && receive[7] == '1' ) 
        {
            //Sends a routine(It is the same for the other routines)
            Send_Routine1();
            //Clears the receive array (It is the same for the other routines)
            receive[0] = 0x00; 
            receive[1] = 0x00; 
            receive[2] = 0x00; 
            receive[3] = 0x00; 
            receive[4] = 0x00; 
            receive[5] = 0x00;
            receive[6] = 0x00; 
            receive[7] = 0x00; 
        }
    
        if (receive[0] == 'I' && receive[1] == 'z' && receive[2] == 'q' && receive[3] == 'u' && 
            receive[4] == 'i' && receive[5] == 'e' && receive[6] == 'r' && receive[7] == 'd' && receive[8] == 'a' && receive[9] == '1' ) 
        {
            Send_Routine2();
            receive[0] = 0x00; 
            receive[1] = 0x00; 
            receive[2] = 0x00; 
            receive[3] = 0x00; 
            receive[4] = 0x00; 
            receive[5] = 0x00;
            receive[6] = 0x00; 
            receive[7] = 0x00; 
            receive[8] = 0x00; 
            receive[9] = 0x00; 
        }
        
        if (receive[0] == 'D' && receive[1] == 'e' && receive[2] == 'r' && receive[3] == 'e' && 
            receive[4] == 'c' && receive[5] == 'h' && receive[6] == 'a' && receive[7] == '2' ) 
        {
            Send_Routine3();
            receive[0] = 0x00; 
            receive[1] = 0x00; 
            receive[2] = 0x00; 
            receive[3] = 0x00; 
            receive[4] = 0x00; 
            receive[5] = 0x00;
            receive[6] = 0x00; 
            receive[7] = 0x00; 
        }
    
        if (receive[0] == 'I' && receive[1] == 'z' && receive[2] == 'q' && receive[3] == 'u' && 
            receive[4] == 'i' && receive[5] == 'e' && receive[6] == 'r' && receive[7] == 'd' && receive[8] == 'a' && receive[9] == '2' ) 
        {
            Send_Routine4();
            receive[0] = 0x00; 
            receive[1] = 0x00; 
            receive[2] = 0x00; 
            receive[3] = 0x00; 
            receive[4] = 0x00; 
            receive[5] = 0x00;
            receive[6] = 0x00; 
            receive[7] = 0x00; 
            receive[8] = 0x00; 
            receive[9] = 0x00; 
        }
        if (receive[0] == 'D' && receive[1] == 'e' && receive[2] == 'r' && receive[3] == 'e' && 
            receive[4] == 'c' && receive[5] == 'h' && receive[6] == 'a' && receive[7] == '3' ) 
        {
            Send_Routine5();
            receive[0] = 0x00; 
            receive[1] = 0x00; 
            receive[2] = 0x00; 
            receive[3] = 0x00; 
            receive[4] = 0x00; 
            receive[5] = 0x00;
            receive[6] = 0x00; 
            receive[7] = 0x00; 
        }
    
        if (receive[0] == 'I' && receive[1] == 'z' && receive[2] == 'q' && receive[3] == 'u' && 
            receive[4] == 'i' && receive[5] == 'e' && receive[6] == 'r' && receive[7] == 'd' && receive[8] == 'a' && receive[9] == '3' ) 
        {
            Send_Routine6();
            receive[0] = 0x00; 
            receive[1] = 0x00; 
            receive[2] = 0x00; 
            receive[3] = 0x00; 
            receive[4] = 0x00; 
            receive[5] = 0x00;
            receive[6] = 0x00; 
            receive[7] = 0x00; 
            receive[8] = 0x00; 
            receive[9] = 0x00; 
        }
        
    }
        
}