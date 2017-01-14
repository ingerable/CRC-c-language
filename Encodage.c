#include "Tim.h"

/**
 * [Encode un texte]
 * @param  blocs   [Tableau contenant les caracteres du texte a encoder]
 * @param  nbBlocs [Nombre de caracteres]
 * @return         [Tableau contenant les mots encodes sur 32 bits]
 */
uint32_t* Encodage(uint8_t* blocs, int nbBlocs){
  uint32_t* msgEncode = malloc(sizeof(uint32_t) * nbBlocs);

  int i;
  int j;
  int r = get_nb_bits(G)-1; // r = Degré de G
  uint32_t abc;

  // Lecture des caracteres a encoder
  for(i = 0; i < nbBlocs; i++){
    // Debut du traitement a chaque debut de mot
    if(i % 3 == 0){
      uint8_t temp[4];

      for(j = 0; j < 3; j++){
        temp[j] = blocs[i+j];
      }

      // Bits d'information du mot codé: P
      abc = ((temp[0] << 8) | temp[1]) << 8 | temp[2];

      // P * X^r
      uint32_t tempAbc = abc << r;
      // Bit de controle: (X^r * P) / G
      temp[3] = division(tempAbc, G);

      // Mot codé: X^r * P + R
      abc = (abc << 8) | temp[3];

      msgEncode[i/3] = abc;
    }
  }

  return msgEncode;
}
