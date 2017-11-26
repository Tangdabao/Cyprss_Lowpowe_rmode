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
//低功耗之DeepSleep模式测试工程//
//        说明：
//降低功耗可能遇到的问题：
//1.漏电流的产生。
//2.降低频率
//3.修改System的DEBUG模式的SWD为GPIO
//4.进入此模式之后，再次唤醒在睡眠模式之后开始执行
//5.ilo时钟可选关闭，如果关闭进一步降低功耗--0.3uA

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
	
	isr_SW_Start();
    for(;;)
    {
		SW_Sleep();
		LED_Status_Sleep();
        CySysClkEcoStop();
		#if 0
		CySysClkIloStop();//关闭ilo，进一步降低功耗--0.3uA
        #endif
		CySysPmDeepSleep();//进入深度睡眠，功耗为1.0uA
    }
}
/* [] END OF FILE */
