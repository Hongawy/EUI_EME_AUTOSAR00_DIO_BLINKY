#include "A_DIO.h"

void DIO_Init(uint8_t PORT,uint8_t OUTPUT_PINS,uint8_t INPUT_PINS);
void delay_ms(unsigned int n);

void main(void)
{
    DIO_Init(PORTF,0x0E,0x11);
    while(1)
    {
        /*GBR 321
         * RED = PORTF_PIN1 ==> ID = 40+1 = 41
         * BLUE = PORTF_PIN2 ==> ID = 40+2 = 42
         * GREEN = PORTF_PIN3 ==> ID = 40+3 = 43*/
        Dio_WriteChannel (41, STD_HIGH);
        Dio_WriteChannel (42, STD_HIGH);
        Dio_WriteChannel (43, STD_HIGH);
        delay_ms(500); //500ms delay
        Dio_WriteChannel (41, STD_LOW);
        Dio_WriteChannel (42, STD_LOW);
        Dio_WriteChannel (43, STD_LOW);
        delay_ms(500); //500ms delay
    }
}












void delay_ms(unsigned int n)
{
    int i,j;
    for(i=0;i<n;i++){for(j=0;j<3180;j++);}
}


/**DIO_Init: FUNCTION THAT INITIALIZES THE PORT WITH THE REQUIRED INPUT AND OUTPUT PINS**/
void DIO_Init(uint8_t PORT,uint8_t OUTPUT_PINS,uint8_t INPUT_PINS){

    switch(PORT){
    case(PORTA):
                    SYSCTL_RCGCGPIO_R |= 0x00000001;
    while(SYSCTL_RCGCGPIO_R&0x00000001==0){};
    GPIO_PORTA_LOCK_R =0x4C4F434B;
    GPIO_PORTA_CR_R=(OUTPUT_PINS|INPUT_PINS);
    GPIO_PORTA_DIR_R|=(OUTPUT_PINS);
    GPIO_PORTA_DIR_R&=~(INPUT_PINS);
    GPIO_PORTA_PUR_R|=(INPUT_PINS);
    GPIO_PORTA_DEN_R=(OUTPUT_PINS|INPUT_PINS);
    break;
    case(PORTB):
                    SYSCTL_RCGCGPIO_R |= 0x00000002;
    while(SYSCTL_RCGCGPIO_R&0x00000002==0){};
    GPIO_PORTB_LOCK_R =0x4C4F434B;
    GPIO_PORTB_CR_R=(OUTPUT_PINS|INPUT_PINS);
    GPIO_PORTB_DIR_R|=(OUTPUT_PINS);
    GPIO_PORTB_DIR_R&=~(INPUT_PINS);
    GPIO_PORTB_PUR_R|=(INPUT_PINS);
    GPIO_PORTB_DEN_R=(OUTPUT_PINS|INPUT_PINS);
    break;
    case(PORTC):
                    SYSCTL_RCGCGPIO_R |= 0x00000004;
    while(SYSCTL_RCGCGPIO_R&0x00000004==0){};
    GPIO_PORTC_LOCK_R =0x4C4F434B;
    GPIO_PORTC_CR_R=(OUTPUT_PINS|INPUT_PINS);
    GPIO_PORTC_DIR_R|=(OUTPUT_PINS);
    GPIO_PORTC_DIR_R&=~(INPUT_PINS);
    GPIO_PORTC_PUR_R|=(INPUT_PINS);
    GPIO_PORTC_DEN_R=(OUTPUT_PINS|INPUT_PINS);
    break;
    case(PORTD):
                    SYSCTL_RCGCGPIO_R |= 0x00000008;
    while(SYSCTL_RCGCGPIO_R&0x00000008==0){};
    GPIO_PORTD_LOCK_R =0x4C4F434B;
    GPIO_PORTD_CR_R=(OUTPUT_PINS|INPUT_PINS);
    GPIO_PORTD_DIR_R|=(OUTPUT_PINS);
    GPIO_PORTD_DIR_R&=~(INPUT_PINS);
    GPIO_PORTD_PUR_R|=(INPUT_PINS);
    GPIO_PORTD_DEN_R=(OUTPUT_PINS|INPUT_PINS);
    break;
    case(PORTE):
                    SYSCTL_RCGCGPIO_R |= 0x00000010;
    while(SYSCTL_RCGCGPIO_R&0x00000010==0){};
    GPIO_PORTE_LOCK_R =0x4C4F434B;
    GPIO_PORTE_CR_R=(OUTPUT_PINS|INPUT_PINS);
    GPIO_PORTE_DIR_R|=(OUTPUT_PINS);
    GPIO_PORTE_DIR_R&=~(INPUT_PINS);
    GPIO_PORTE_PUR_R|=(INPUT_PINS);
    GPIO_PORTE_DEN_R=(OUTPUT_PINS|INPUT_PINS);
    break;
    case(PORTF):
                    SYSCTL_RCGCGPIO_R |= 0x00000020;
    while(SYSCTL_RCGCGPIO_R&0x00000020==0){};
    GPIO_PORTF_LOCK_R =0x4C4F434B;
    GPIO_PORTF_CR_R=(OUTPUT_PINS|INPUT_PINS);
    GPIO_PORTF_DIR_R|=(OUTPUT_PINS);
    GPIO_PORTF_DIR_R&=~(INPUT_PINS);
    GPIO_PORTF_PUR_R|=(INPUT_PINS);
    GPIO_PORTF_DEN_R=(OUTPUT_PINS|INPUT_PINS);
    break;
    default:
        break;
    }
}
