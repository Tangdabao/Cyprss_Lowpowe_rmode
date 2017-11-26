/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

//********LSD*******************///
//低功耗之Sleep模式测试工程//
//        说明：
//降低功耗可能遇到的问题：
//1.漏电流的产生。
//2.降低频率
//3.修改System的DEBUG模式的SWD为GPIO
//4.进入此模式之后，再次唤醒在睡眠模式之后开始执行

#include "project.h"

#define OFF 1u
#define ON  0u

int main(void)
{
	//uint32 status;
	
	LED_Status_Write(OFF);
	CyDelay(200);
    LED_Status_Write(ON);
	CyDelay(200);
	LED_Status_Write(OFF);
	//反馈出从哪个模式唤醒；
	//status=CySysPmGetResetReason();
	
    CyGlobalIntEnable; /* Enable global interrupts. */
	
	isr_Sw_Start();
	
	#if 0
	CySysClkImoStop();
    #endif
	
	//设置高阻态模式///
	#if 0
	CY_SET_REG32((void *)(CYREG_GPIO_PRT2_PC), 0x00012492u);
	//#else
	//模拟高阻态
	CY_SET_REG32((void *)(CYREG_GPIO_PRT0_PC), 0x03000000u);
	CY_SET_REG32((void *)(CYREG_GPIO_PRT1_PC), 0x03000000u);
	CY_SET_REG32((void *)(CYREG_GPIO_PRT2_PC), 0x03000000u);
	CY_SET_REG32((void *)(CYREG_GPIO_PRT3_PC), 0x03000000u);
	CY_SET_REG32((void *)(CYREG_GPIO_PRT4_PC), 0x03000000u);
	CY_SET_REG32((void *)(CYREG_GPIO_PRT5_PC), 0x03000000u);
	
	//CySysPmSleep();
	
	CyDelay(200);
	CyDelay(200);
	CyDelay(200);
	CyDelay(200);
	
	CySysClkEcoStop();

	//此处 开关用来测试，当睡眠模式唤醒之后在什么位置再次执行
     SW_Sleep();
	 LED_Status_Sleep();
	 CySysPmSleep();
     
	 CyDelay(200);
     CyDelay(200);
     CyDelay(200);
	 CyDelay(200);
	 LED_Status_Write(ON);
     CyDelay(200);
     LED_Status_Write(OFF);
	 CyDelay(200);
	 LED_Status_Write(ON);
     CyDelay(200);
     LED_Status_Write(OFF);
	 CyDelay(200);
	 LED_Status_Write(ON);
     CyDelay(200);
     LED_Status_Write(OFF);
	 CyDelay(200);
		
	#endif
    for(;;)
    {
	     SW_Sleep();
		 LED_Status_Sleep();
		 CySysPmSleep();
    }
}

/* [] END OF FILE */
