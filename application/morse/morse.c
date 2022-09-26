#include "commont.h"
#include "morse.h"
#include "clock.h"
#include "led.h"
#include "beep.h"

unsigned char morse_code[][10] = {
    {MORSE_DOT, MORSE_LINE, MORSE_END},     // A
    {MORSE_LINE, MORSE_DOT, MORSE_DOT, MORSE_DOT, MORSE_END}, //B
    {MORSE_LINE, MORSE_DOT, MORSE_LINE, MORSE_DOT, MORSE_END}, //B
    {MORSE_LINE, MORSE_DOT, MORSE_DOT, MORSE_END}, //D
    {MORSE_DOT, MORSE_END},   //E
    {MORSE_DOT, MORSE_DOT, MORSE_LINE, MORSE_DOT, MORSE_END}, //F
    {MORSE_LINE, MORSE_LINE, MORSE_DOT, MORSE_END}, //G
    {MORSE_DOT, MORSE_DOT, MORSE_DOT, MORSE_DOT, MORSE_END}, //H
    {MORSE_DOT, MORSE_DOT, MORSE_END}, //I
    {MORSE_DOT, MORSE_LINE, MORSE_LINE, MORSE_LINE, MORSE_END}, //J
    {MORSE_LINE, MORSE_DOT, MORSE_LINE, MORSE_END}, //K
    {MORSE_DOT, MORSE_LINE, MORSE_DOT, MORSE_DOT, MORSE_END}, //L
    {MORSE_LINE, MORSE_LINE, MORSE_END},    //M
    {MORSE_LINE, MORSE_DOT, MORSE_END}, //N
    {MORSE_LINE, MORSE_LINE, MORSE_LINE, MORSE_END},    //O
    {MORSE_DOT, MORSE_LINE, MORSE_LINE, MORSE_DOT, MORSE_END}, //P
    {MORSE_LINE, MORSE_LINE, MORSE_DOT, MORSE_LINE, MORSE_END}, //Q
    {MORSE_DOT, MORSE_LINE, MORSE_DOT, MORSE_END},  //R
    {MORSE_DOT, MORSE_DOT, MORSE_DOT, MORSE_END}, //S
    {MORSE_LINE, MORSE_END}, //T
    {MORSE_DOT, MORSE_DOT, MORSE_LINE, MORSE_END}, //U
    {MORSE_DOT, MORSE_DOT, MORSE_DOT, MORSE_LINE, MORSE_END}, //V
    {MORSE_DOT, MORSE_LINE, MORSE_LINE, MORSE_END}, //W
    {MORSE_LINE, MORSE_DOT, MORSE_DOT, MORSE_LINE, MORSE_END}, //X
    {MORSE_LINE, MORSE_DOT, MORSE_LINE, MORSE_LINE, MORSE_END}, //Y
    {MORSE_LINE, MORSE_LINE, MORSE_DOT, MORSE_DOT, MORSE_END}, //Z
};

void morse_dot(void)
{
    led_on();
    beep_on();
    delay_ms(DOT);
    led_off();
    beep_off();
}

void morse_line(void)
{
    led_on();
    beep_on();
    delay_ms(LINE);
    led_off();
    beep_off();
}

void morse_gap_in_char(void)
{
    led_off();
    beep_off();
    delay_ms(GAP_IN_CHAR);
    led_off();
    beep_off();
}

void morse_gap_bet_char(void)
{
    led_off();
    beep_off();
    delay_ms(GAP_BET_CHAR);
    led_off();
    beep_off();
}

void morse_xfer(char *msg)
{
    char val = 0;
    int i = 0;
    int j = 0;
    unsigned char *morse_ele = 0;
    int idx = 0;

    while (msg[i] != '\0') {
        val = msg[i];
        idx = val - 'a';
        morse_ele = (unsigned char *)&morse_code[idx];
        j = 0;
        while (morse_ele[j] != MORSE_END) {
            switch (morse_ele[j]) {
                case MORSE_DOT:
                    morse_dot();
                    morse_gap_in_char();
                    break;
                case MORSE_LINE:
                    morse_line();
                    morse_gap_in_char();
                    break;
                default:
                    break;
            }
            j++;
        }
        morse_gap_bet_char();
        i++;
    }   
}