#include <msp430.h>

/* USER CODE START (section: InterruptVectors_init_c_prologue) */
/* User defined includes, defines, global variables and functions */
/* USER CODE END (section: InterruptVectors_init_c_prologue) */

/*
 *  ======== InterruptVectors_graceInit ========
 */
void InterruptVectors_graceInit(void)
{
}


/* Interrupt Function Prototypes */



/*
 *  ======== Timer0_A3 Interrupt Service Routine ======== 
 */
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR_HOOK(void)
{
    /* USER CODE START (section: TIMER0_A0_ISR_HOOK) */
    /* replace this comment with your code */
    /* USER CODE END (section: TIMER0_A0_ISR_HOOK) */
}

