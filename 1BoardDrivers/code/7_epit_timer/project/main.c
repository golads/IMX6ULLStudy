#include "imx6ul.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_gpio.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_exti.h"
#include "bsp_epit.h"

/*
 * @description	: mian函数
 * @param 		: 无
 * @return 		: 无
 */
int main(void)
{
	int_init();			/* 初始化中断 */
	imx6u_clkinit();	/* 初始化系统时钟 */
	clk_enable();		/* 使能所有的时钟 			*/
	led_init();			/* 初始化led 			*/
	init_beep();		/* 初始化beep */
	init_key();			/* 初始化key */
	//exit_init();			/* 初始化按键中断 */
	epit1_init(0, 66000000/2);

	while(1)			
	{	
		delay(500);
	}

	return 0;
}
