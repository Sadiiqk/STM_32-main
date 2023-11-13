#include "uart.h" 

void USART2_Init(void)
{ 
 
 RCC->APB1ENR  |=  0x20000; //Enable the USART2 clock
 RCC->AHB1ENR   |=0x01; //Enable the GPIOA clock

 
 GPIOA->MODER &=~0x00F0; //Clear bits 4-7 in the GPIOA MODER register 
 GPIOA->MODER |= 0x00A0; //Set bits 5 and 7 in the GPIOA MODER register to set the GPIO pins to alternate function mode


 GPIOA->AFR[0] &= ~0xFF00;
 GPIOA->AFR[0] |= 0x7700;


 USART2->BRR  =  0x0683; //Set the baud rate
 USART2->CR1  =  0x000C; //Configure control register 1
 USART2->CR2  =  0x000; //Configure control register 2 
 USART2->CR3  =  0x000; //Configure control register 3 
 USART2->CR1  |=  0x2000; //Enable UART
	
}

int USART2_write(int ch)
{ 

	while(!(USART2->SR & 0x0080)){}// Wait until the UART2 TDR (Transmit Data Register) is empty
	USART2->DR = (ch & 0xFF);
	
  return ch;// return the character sent to USART2 module
}

int USART2_read(void)
{ 
  while(!(USART2->SR & 0x0020)){}
	return USART2->DR;
}

struct __FILE { int handle; };// create a structure called __FILE containing 1 variable
FILE __stdin  = {0};//declare and initialize a FILE with handle 0
FILE __stdout = {1};// declare and initialize a FILE with handle 1
FILE __stderr = {2};// declare and initialize a FILE with handle 2


//Function to get character from USART2.
//returns character from USART2
//f
int fgetc(FILE *f) 
{ 
    int c;
    c = USART2_read();// read what is sent through USART2          
    if (c == '\r') 
    {        
        USART2_write(c);   
        c = '\n';
    }

    USART2_write(c);// write c to USART2      
    return c;// return the content of c
}


int fputc(int c, FILE *f) 
{ 
    return USART2_write(c);
    //input funktionen 
}


int n;
char str[80];
		
void test_setup(void)
{ 
	printf("please enter a number: ");// print out the string provided to printf
	scanf("%d", &n);// scan for any user input
	printf("the number entered is: %d\r\n", n);// print out the string provided to printf
	printf("please type a character string: ");// print out the string provided to printf
	gets(str);// gets reads a string or text line and saves it into the variable str which is a char array[80]
	printf("the character string entered is: ");// print out the string provided to printf
	puts(str);// puts will write a string or line of text to the output stream
	printf("\r\n");// print a carriage return and new line character
	
}
