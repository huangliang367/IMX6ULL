#ifndef _MORSE_H
#define _MORSE_H

#define UNIT_DELAY      (60)
#define DOT             UNIT_DELAY
#define LINE            (3 * (UNIT_DELAY))
#define GAP_IN_CHAR     (2 * UNIT_DELAY)
#define GAP_BET_CHAR    (7 * UNIT_DELAY)

typedef enum {
    MORSE_DOT = 0,
    MORSE_LINE,
    MORSE_GAP_IN_CHAR,
    MORSE_GAP_BET_CHAR,
    MORSE_END,
}MORSE_ELEMENT;

void morse_xfer(char *msg);

#endif /* _MORSE_H */