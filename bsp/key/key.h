#ifndef _KEY_H
#define _KEY_H

typedef enum {
    KEY_PRESSED = 0,
    KEY_RELEASED = 1,
}KEY_STATUS;

void key_init(void);
KEY_STATUS get_key_status(void);

#endif /* _KEY_H */