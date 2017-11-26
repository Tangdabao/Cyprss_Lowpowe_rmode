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

/*********************************/
//********LSD*******************///
//低功耗之Hibernate模式测试工程//
//        说明：
//降低功耗可能遇到的问题：
//1.漏电流的产生。
//2.降低频率
//3.修改System的DEBUG模式的SWD为GPIO
//4.进入此模式之前，把不使用的GPIO设置为高阻态。（参见手册）
//5.所有IO翻转频率不超过10KHz


#include "project.h"

#define OFF 1u
#define ON  0u

int main(void)
{
	
	//作为指示灯
    LED_Status_Write(OFF);
	CyDelay(200);
    LED_Status_Write(ON);
	CyDelay(200);
	LED_Status_Write(OFF);
    //反馈出从哪个模式唤醒；
	//status=CySysPmGetResetReason();
	
    CyGlobalIntEnable; /* Enable global interrupts. */
	
	isr_Sw_Start();
  

    for(;;)
    {
      CySysPmHibernate();	  
		
    }
}

/* [] END OF FILE */
