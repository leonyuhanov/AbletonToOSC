#include "osc.h"


osc::osc()
{  
  packetBuffer = new char[maxBufferSize];
  clearBuffer();
  note=0;
  velocity=0;
  id=0;
  isChanged=0;
}

void osc::parseData()
{
 /*
      Packet form Ableton
      "/N10,iii0000000<000d000255"
   0000 000< 000d 000255
   Note Velocity ID
   */
   index = charAt(packetBuffer, maxBufferSize, 0, 5);
   if( index!=-1 )
   {
      isChanged = 1;
      note = packetBuffer[index+3];
      velocity = packetBuffer[index+7];
      id = packetBuffer[index+11];
   }
}

short int osc::charAt(char *haystack, short int length, char needle, byte needleCount)
{
  found=0;
  for(hCnt=0; hCnt<length; hCnt++)
  {
    if( haystack[hCnt]==needle && found==needleCount)
    {
      return hCnt;
    }
    else if( haystack[hCnt]==needle && found!=needleCount )
    {
      found++;
    }
  }
  return -1;
}
void osc::clearBuffer()
{
  for(index=0; index<maxBufferSize; index++)
  {
    packetBuffer[index]=0;
  }
}
