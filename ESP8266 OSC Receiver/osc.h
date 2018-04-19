#ifndef osc_h
#define osc_h
#include "Arduino.h"

class osc
{
  public:
    osc();
    void parseData();
    short int charAt(char *haystack, short int length, char needle, byte needleCount);
    void clearBuffer();
    
    char* packetBuffer;    
    byte note;
    byte velocity;
    unsigned short int id;
    byte isChanged;
    
  private:   
    byte maxBufferSize = 50;
    float returnData;
    unsigned char *pc;
    short int index;
    short int found;
    short int hCnt;
};

#endif
