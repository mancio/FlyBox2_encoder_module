#ifndef PORTSETUP_h
#define PORTSETUP_h

#define ENC1_CLK 3
#define ENC1_DT 2
#define ENC1_SW 5

#define ENC1_right 21
#define ENC1_left 20
#define ENC1_SW_OUT 19

/**
 * set input and output (use inside setup() in main) 
 */
void setPins();

void setPort();

void resetEnc();



#endif