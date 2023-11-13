#ifndef  __UART_H//this is what we call a header guard, similar to #pragma once in c++.

#define  __UART_H//the purpose of this is to eliminate multiple definitions of functions
                //assuming this file can be included in multiple c++ files.

#include "stm32f4xx.h"//include the stm32f4 library         
#include <stdio.h>//include standard input/output library

void USART2_Init(void);//create a declaration for the function USART2_Init(void)
void test_setup(void);// create a declaration for the function test_setup(void)


#endif//end of header

