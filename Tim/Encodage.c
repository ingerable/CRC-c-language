#include "Tim.h"

void afficher_binaire(unsigned int n) {
  if (n) {
          afficher_binaire(n >> 1);
          if (n & 1)
            printf("1");
          else
            printf("0");
      }
}

uint32_t* Encodage(uint8_t* blocs, int nbBlocs){
  uint32_t* msgEncode = malloc(sizeof(uint32_t) * nbBlocs/3);

  int i;
  int j;
  uint32_t wd;

  for(i = 0; i < nbBlocs; i++){
    if(i % 3 == 0){
      uint8_t temp[4];

      for(j = 0; j < 3; j++){
        temp[j] = blocs[i+j];
      }
      wd = ((temp[0] << 8) | temp[1]) << 8 | temp[2];

      temp[3] = division(wd, G);
      wd = (wd << 8) | temp[3];

      msgEncode[i] = wd;
    }
  }

  return msgEncode;
}
