#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "lcd.h"
#include "switch.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	static int cnt =0 ;
	char str[16];
	SystemInit();
	LcdInit();
	SwitchInit(SWITCH);
	//LcdPuts(LCD_LINE1, "DESD @ SUNBEAM");
	//LcdPuts(LCD_LINE2, "GOD BLESS YOU!");


	  while(1) {
			// wait until switch interrupt generated
			while(exti0_flag == 0)
				;
			//lcd display

            {
			sprintf(str,"%d",cnt);
			LcdPuts(LCD_LINE1,str);
			cnt++;
            }
			exti0_flag = 0;
		}

		return 0;

}




