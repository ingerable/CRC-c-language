#include "Tim.h"

int main(){
  //division(0b111111110001000000000100, 0b00000000000000000000000100110001);
/*
  uint8_t tableau[3] = {0b11111111, 0b00010000, 0b00000100};
  Encodage(tableau, 3);
*/

  /*"If¢ I µhad a ^woršld  of ³my Èown, ever2ything‹ woyuldÞ be» noÔnse$nse$.
  ‰Notõhinëg wÛoul°d b§e wWhatD itÓ isD, because everyvthiWng wou
  ld  be £wha$t iét iésn'Ìt. 1
  And c–ont>rar˜y wˆiseÇ, w±hatD isD, iít wµoul°dn'‹t be. ÓAndó whîat óit ¡wou
  ldn‚'t ¤be,Þ itÓ woyuldÞ.
  ‰Youƒ se!e?"*/

/*
  uint8_t tableau[4] = {(uint8_t)' ', (uint8_t)'I', (uint8_t)' ', (uint8_t)((wchar_t)L'µ')};
                                                                  // les carac spéciaux font chier
  uint32_t msgDecode[1] = { Decodage(tableau, 4) };
  afficher_binaire(msgDecode[0]);
*/

  uint8_t tableau[4] = {0b00001100, 0b00001000, 0b00000010, 0b00000001};
  uint32_t msgDecode[1] = { Decodage(tableau, 4) };
  afficher_binaire(msgDecode[0]);


  printf("\n");
  return 0;

}
