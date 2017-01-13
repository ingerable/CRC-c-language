#include "Tim.h"

int get_nb_bits(uint32_t nombre)
{
    int bits=0;
    while(nombre)
    {
      if(nombre > 0){
        nombre>>=1;
        bits++;
      }
      else{
        nombre<<=1;
        bits++;
      }
    }
    return bits;
}

uint32_t division(uint32_t dividende, uint32_t diviseur){
  int tailleDiviseur = get_nb_bits(diviseur);
  while(get_nb_bits(dividende) >= tailleDiviseur)
  {
    int diff = get_nb_bits(dividende) - tailleDiviseur;
    uint32_t tempdiviseur = diviseur << diff;
    dividende = dividende ^ tempdiviseur;
  }
  return dividende;
}
