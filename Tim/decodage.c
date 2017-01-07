#include "Tim.h"

uint32_t* Decodage(uint8_t* msgEncode, int tailleMsg)
{
  int i;
  int j;
  unsigned int wd;
  uint32_t* msgDecode = calloc(tailleMsg, sizeof(uint32_t));

  for(i = 0; i < tailleMsg; i++)
  {
    if(i % 4 == 0)
    {
      uint8_t temp[4];
      for(j = 0; j < 4; j++){
        temp[j] = msgEncode[i+j];
      }
      wd = (((temp[0] << 8) | temp[1]) << 8 | temp[2]) << 8 | temp[3];

      if(division(wd, G) == 0)
      {
        msgDecode[i]  = ((temp[0] << 8) | temp[1]) << 8 | temp[2];

      }else{
        //erreur detecté
        uint8_t d = (uint8_t)'#';
        msgDecode[i]  = ((d << 8) | d) << 8 | d;
      }
    }
  }

  return msgDecode;
}
