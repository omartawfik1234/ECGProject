#include <msp430.h> 
int counter = 0;
int total = 0;
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

        P1DIR |= BIT0; // output led
        P1OUT &= ~BIT0; // led off
        P4DIR |= BIT7; // output led
        P4OUT &= ~BIT7; // led off


        P2DIR &= ~BIT5; // p2.5 input
        P2REN |= BIT5; // enable pullup/pulldown resistor
        P2OUT|=BIT5; // set to pullup

        P2IES &= ~BIT5; //triggering at rising edge
        P2IE |= BIT5; // enable interrupt
        P2IFG &= ~BIT5; //clear interrupt flag

        TA0CCR0 |= 65535; //2^16 -1
        TA0CTL |= TASSEL_1 + MC_1 + ID_3 ; //timer configuration

        TA0CCTL0 |= CCIE; //enable interrupt

        __bis_SR_register(GIE); //modified current SR bit
        while(1){ //infinite loop
            ;
        }
}

#pragma vector=PORT2_VECTOR //sets service routine vector
__interrupt void PORT_ISR(void){ //interrupt definition defined at PORT_ISR
    P4OUT ^= BIT7; //led 2 turns on
    counter++; //counter added to itself to count bpm
    P2IFG &= ~BIT5; //clear interrupt flag
}

#pragma vector=TIMER0_A0_VECTOR //interrupt of timer(duration of timer is 16 seconds)
__interrupt void TIMER0A_ISR(void){
    P1OUT ^= BIT0; //led 1 turned on for duration of reading time(16 seconds)

    total = 3.75 * counter; //total multiplied by 3.75 to calculate bpm
    int disp1=total/10; //left digit derived
    int disp2 = total%10; //right digit derived by dividing by 10 and leaving remainder

        P3DIR |= BIT6; // output led
        P4DIR |= BIT2; // output led
        //P1DIR |= BIT0; // output led
        P3DIR |= BIT5; // output led
        P4DIR |= BIT1; // output led
        P6DIR |= BIT1; // output led
        P3DIR |= BIT3; // output led
        //P1DIR |= BIT0; // output led
        P6DIR |= BIT0; // output led
        P3DIR |= BIT4; // output led

        P2DIR |= BIT3; // output led
        P3DIR |= BIT7; // output led
        //P1DIR |= BIT0; // output led
        P8DIR |= BIT1; // output led
        P8DIR |= BIT2; // output led
        P1DIR |= BIT5; // output led
        P2DIR |= BIT2; // output led
        //P1DIR |= BIT0; // output led
        P2DIR |= BIT4; // output led
        P2DIR |= BIT0; // output led

        switch(disp1){
        case 0 :
            P2OUT &= ~BIT3; // output led
            P3OUT &= ~BIT7; // output led
            P8OUT &= ~BIT1; // output led
            P8OUT &= ~BIT2; // output led
            P1OUT &= ~BIT5; // output led
            P2OUT &= ~BIT2; // output led
            P2OUT &= ~BIT4; // output led
            P2OUT ^= BIT0; // output led
            break;
        case 1 :
            P2OUT ^= BIT3; // output led
            P3OUT ^= BIT7; // output led
            P8OUT &= ~BIT1; // output led
            P8OUT ^= BIT2; // output led
            P1OUT &= ~BIT5; // output led
            P2OUT ^= BIT2; // output led
            P2OUT ^= BIT4; // output led
            P2OUT ^= BIT0; // output led
            break;
        case 2 :
            P2OUT &= ~BIT3; // output led
            P3OUT &= ~BIT7; // output led
            P8OUT ^= BIT1; // output led
            P8OUT &= ~BIT2; // output led
            P1OUT &= ~BIT5; // output led
            P2OUT &= ~BIT2; // output led
            P2OUT ^= BIT4; // output led
            P2OUT &= ~BIT0; // output led
            break;
        case 3 :
            P2OUT ^= BIT3; // output led
            P3OUT &= ~BIT7; // output led
            P8OUT &= ~BIT1; // output led
            P8OUT &= ~BIT2; // output led
            P1OUT &= ~BIT5; // output led
            P2OUT &= ~BIT2; // output led
            P2OUT ^= BIT4; // output led
            P2OUT &= ~BIT0; // output led
            break;
        case 4 :
            P2OUT ^= BIT3; // output led
            P3OUT ^= BIT7; // output led
            P8OUT &= ~BIT1; // output led
            P8OUT &= ~BIT2; // output led
            P1OUT &= ~BIT5; // output led
            P2OUT ^= BIT2; // output led
            P2OUT &= ~BIT4; // output led
            P2OUT &= ~BIT0; // output led
            break;
        case 5 :
            P2OUT ^= BIT3; // output led
            P3OUT &= ~BIT7; // output led
            P8OUT &= ~BIT1; // output led
            P8OUT &= ~BIT2; // output led
            P1OUT ^= BIT5; // output led
            P2OUT &= ~BIT2; // output led
            P2OUT &= ~BIT4; // output led
            P2OUT &= ~BIT0; // output led
            break;
        case 6 :
            P2OUT &= ~BIT3; // output led
            P3OUT &= ~BIT7; // output led
            P8OUT &= ~BIT1; // output led
            P8OUT &= ~BIT2; // output led
            P1OUT ^= BIT5; // output led
            P2OUT &= ~BIT2; // output led
            P2OUT &= ~BIT4; // output led
            P2OUT &= ~BIT0; // output led
            break;
        case 7 :
            P2OUT ^= BIT3; // output led
            P3OUT ^= BIT7; // output led
            P8OUT &= ~BIT1; // output led
            P8OUT &= ~BIT2; // output led
            P1OUT &= ~BIT5; // output led
            P2OUT &= ~BIT2; // output led
            P2OUT ^= BIT4; // output led
            P2OUT ^= BIT0; // output led
            break;
        case 8 :
            P2OUT &= ~BIT3; // output led
            P3OUT &= ~BIT7; // output led
            P8OUT &= ~BIT1; // output led
            P8OUT &= ~BIT2; // output led
            P1OUT &= ~BIT5; // output led
            P2OUT &= ~BIT2; // output led
            P2OUT &= ~BIT4; // output led
            P2OUT &= ~BIT0; // output led
            break;
        case 9 :
            P2OUT ^= BIT3; // output led
            P3OUT &= ~BIT7; // output led
            P8OUT &= ~BIT1; // output led
            P8OUT &= ~BIT2; // output led
            P1OUT &= ~BIT5; // output led
            P2OUT &= ~BIT2; // output led
            P2OUT &= ~BIT4; // output led
            P2OUT &= ~BIT0; // output led
            break;
        case 10:
            P2OUT &= ~BIT3; // output led
            P3OUT ^= BIT7; // output led
            P8OUT &= ~BIT1; // output led
            P8OUT &= ~BIT2; // output led
            P1OUT &= ~BIT5; // output led
            P2OUT &= ~BIT2; // output led
            P2OUT &= ~BIT4; // output led
            P2OUT &= ~BIT0; // output led
            break;
        case 11:
            P2OUT &= ~BIT3; // output led
            P3OUT &= ~BIT7; // output led
            P8OUT &= ~BIT1; // output led
            P8OUT &= ~BIT2; // output led
            P1OUT ^= BIT5; // output led
            P2OUT ^= BIT2; // output led
            P2OUT &= ~BIT4; // output led
            P2OUT &= ~BIT0; // output led
            break;
        case 12 :
            P2OUT &= ~BIT3; // output led
            P3OUT &= ~BIT7; // output led
            P8OUT ^= BIT1; // output led
            P8OUT &= ~BIT2; // output led
            P1OUT ^= BIT5; // output led
            P2OUT &= ~BIT2; // output led
            P2OUT &= ~BIT4; // output led
            P2OUT ^= BIT0; // output led
            break;
        case 13 :
            P2OUT &= ~BIT3; // output led
            P3OUT &= ~BIT7; // output led
            P8OUT &= ~BIT1; // output led
            P8OUT &= ~BIT2; // output led
            P1OUT &= ~BIT5; // output led
            P2OUT ^= BIT2; // output led
            P2OUT ^= BIT4; // output led
            P2OUT &= ~BIT0; // output led
            break;
        case 14 :
            P2OUT &= ~BIT3; // output led
            P3OUT &= ~BIT7; // output led
            P8OUT ^= BIT1; // output led
            P8OUT &= ~BIT2; // output led
            P1OUT ^= BIT5; // output led
            P2OUT &= ~BIT2; // output led
            P2OUT &= ~BIT4; // output led
            P2OUT &= ~BIT0; // output led
            break;
        case 15 :
            P2OUT &= ~BIT3; // output led
            P3OUT ^= BIT7; // output led
            P8OUT ^= BIT1; // output led
            P8OUT &= ~BIT2; // output led
            P1OUT ^= BIT5; // output led
            P2OUT &= ~BIT2; // output led
            P2OUT &= ~BIT4; // output led
            P2OUT &= ~BIT0; // output led
            break;
        }
        switch(disp2){
        case 0 :
            P3OUT &= ~BIT6; // output led
            P4OUT &= ~BIT2; // output led
            P3OUT &= ~BIT5; // output led
            P4OUT &= ~BIT1; // output led
            P6OUT &= ~BIT1; // output led
            P3OUT &= ~BIT3; // output led
            P6OUT &= ~BIT0; // output led
            P3OUT ^= BIT4; // output led
            break;
        case 1 :
            P3OUT ^= BIT6; // output led
            P4OUT ^= BIT2; // output led
            P3OUT &= ~BIT5; // output led
            P4OUT ^= BIT1; // output led
            P6OUT &= ~BIT1; // output led
            P3OUT ^= BIT3; // output led
            P6OUT ^= BIT0; // output led
            P3OUT ^= BIT4; // output led
            break;
        case 2 :
            P3OUT &= ~BIT6; // output led
            P4OUT &= ~BIT2; // output led
            P3OUT ^= BIT5; // output led
            P4OUT &= ~BIT1; // output led
            P6OUT &= ~BIT1; // output led
            P3OUT &= ~BIT3; // output led
            P6OUT ^= BIT0; // output led
            P3OUT &= ~BIT4; // output led
            break;
        case 3 :
            P3OUT ^= BIT6; // output led
            P4OUT &= ~BIT2; // output led
            P3OUT &= ~BIT5; // output led
            P4OUT &= ~BIT1; // output led
            P6OUT &= ~BIT1; // output led
            P3OUT &= ~BIT3; // output led
            P6OUT ^= BIT0; // output led
            P3OUT &= ~BIT4; // output led
            break;
        case 4 :
            P3OUT ^= BIT6; // output led
            P4OUT ^= BIT2; // output led
            P3OUT &= ~BIT5; // output led
            P4OUT &= ~BIT1; // output led
            P6OUT &= ~BIT1; // output led
            P3OUT ^= BIT3; // output led
            P6OUT &= ~BIT0; // output led
            P3OUT &= ~BIT4; // output led
            break;
        case 5 :
            P3OUT ^= BIT6; // output led
            P4OUT &= ~BIT2; // output led
            P3OUT &= ~BIT5; // output led
            P4OUT &= ~BIT1; // output led
            P6OUT ^= BIT1; // output led
            P3OUT &= ~BIT3; // output led
            P6OUT &= ~BIT0; // output led
            P3OUT &= ~BIT4; // output led
            break;
        case 6 :
            P3OUT &= ~BIT6; // output led
            P4OUT &= ~BIT2; // output led
            P3OUT &= ~BIT5; // output led
            P4OUT &= ~BIT1; // output led
            P6OUT ^= BIT1; // output led
            P3OUT &= ~BIT3; // output led
            P6OUT &= ~BIT0; // output led
            P3OUT &= ~BIT4; // output led
            break;
        case 7 :
            P3OUT ^= BIT6; // output led
            P4OUT ^= BIT2; // output led
            P3OUT &= ~BIT5; // output led
            P4OUT &= ~BIT1; // output led
            P6OUT &= ~BIT1; // output led
            P3OUT &= ~BIT3; // output led
            P6OUT ^= BIT0; // output led
            P3OUT ^= BIT4; // output led
            break;
        case 8 :
            P3OUT &= ~BIT6; // output led
            P4OUT &= ~BIT2; // output led
            P3OUT &= ~BIT5; // output led
            P4OUT &= ~BIT1; // output led
            P6OUT &= ~BIT1; // output led
            P3OUT &= ~BIT3; // output led
            P6OUT &= ~BIT0; // output led
            P3OUT &= ~BIT4; // output led
            break;
        case 9 :
            P3OUT ^= BIT6; // output led
            P4OUT &= ~BIT2; // output led
            P3OUT &= ~BIT5; // output led
            P4OUT &= ~BIT1; // output led
            P6OUT &= ~BIT1; // output led
            P3OUT &= ~BIT3; // output led
            P6OUT &= ~BIT0; // output led
            P3OUT &= ~BIT4; // output led
            break;
        }
        counter = 0; //counter set to zero

}



