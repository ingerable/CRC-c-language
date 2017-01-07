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
  uint32_t res[nbBlocs/4];
  int i;
  int j;
  unsigned int wd;

  for(i = 0; i < nbBlocs; i++){
    uint8_t temp[4];
    for(j = 0; j < 3; j++){
      temp[j] = blocs[i+j];
    }
    wd = ((blocs[0] << 8) | blocs[1]) << 8 | blocs[2];
    temp[4] = division(wd, G);
    wd = (wd << 8) | temp[4];

  }

  afficher_binaire(wd);


  printf("\n");
  return 0;
}
