#include "Tim.h"

void AffichageEncode(uint32_t* value, int size){
  uint8_t byteval[4];
  int i;
  int j;
  for(j = 0; j < size; j++)
  {
    if(j % 3 == 0){
      for(i = 3; i >= 0; i--){
        byteval[i] = value[j] >> (i*8);
        printf("%c", byteval[i]);
      }
    }
  }
}

void AffichageDecode(uint32_t* value, int size){
  uint8_t byteval[3];
  int i;
  int j;
  for(j = 0; j < size; j++)
  {
    for(i = 0; i < 3; i++){
      byteval[i] = value[j] >> (i*8);
      printf("%c", byteval[i]);
    }
  }
}

int main(){

  /****************/
  /*Tests Division*/
  /****************/

  //division(0b0000000100000001100000100, G);
  //division(0b111111110001000000000100,G);
  //division(0x20304, 0x131);

  /****************/
  /*Tests Encodage*/
  /****************/

/*
  uint8_t tableau[3] = {0b11111111, 0b00010000, 0b00000100};
  Encodage(tableau, 3);
*/

  printf("Test de codage :\n");
  uint8_t tableauEncode[18] = {'"', 'I', 'f', ' ', 'I', ' ', 'h', 'a', 'd', ' ', 'a', ' ', 'w', 'o', 'r', 'l', 'd', ' '};
  uint32_t* msgEncode = Encodage(tableauEncode, 18);
  AffichageEncode(msgEncode, 18);
  printf("\n\n");


  /****************/
  /*Tests Decodage*/
  /****************/

/*
  "If¢ I µhad a ^woršld  of ³my Èown, ever2ything‹ woyuldÞ be» noÔnse$nse$.
  ‰Notõhinëg wÛoul°d b§e wWhatD itÓ isD, because everyvthiWng wou
  ld  be £wha$t iét iésn'Ìt. 1
  And c–ont>rar˜y wˆiseÇ, w±hatD isD, iít wµoul°dn'‹t be. ÓAndó whîat óit ¡wou
  ldn‚'t ¤be,Þ itÓ woyuldÞ.
  ‰Youƒ se!e?"*/

  printf("Test de texte sans erreur :\n");
  int size = 44;
  uint8_t tableauDecode[44] = {'"', 'I', 'f', '¢', ' ', 'I', ' ', 'µ',
  'h', 'a', 'd', '?', ' ', 'a', ' ', '^', 'w', 'o', 'r', 'š', 'l', 'd', ' ', ' ',
  'o', 'f', ' ', '³', 'm', 'y', ' ', 'È', 'o', 'w', 'n', '?', ',', ' ', 'e', '?','v', 'e', 'r', '2'};
  uint32_t* msgDecode = Decodage(tableauDecode, size);
  AffichageDecode(msgDecode, size/4);
  printf("\n" );
  afficher_binaire(10);


/*
  "Yf" I µhad a ^wobšld  of ³my Èiwn, ever2ything‹ woyuddž "e»0noÔnse$nse$.
  ‰Nktõhinëg wÛoul°d b§e wW(atD itÓ isD, becaese åveryvthiWng wo5
  ll  be £wha$t iét iésn'Ìt& 1
  And c–ont:rar˜y wˆiseÇ,$w±hatD icD, iít ÷µoul°dn'‹t be. ÓAndó whîat óit ¡sou
  ldN‚'t ¤be,Þ ivÓ woyuldÞ.
  ‰Youƒ se!e?"+
  -]- LØeWiBs CW!rrµoll, AÒlicŽe's= Ad{venturÐes tin !onÝdmrlanõd &V Thrwbgh Œthe* LoÑokiFng-MOlazss u
*/
/*
  // ((uint8_t)(wchar_t)L'š')
  printf("Test de texte avec erreurs :\n");
  int size = 44;
  uint8_t tableau[44] = {'"', 'Y', 'f', '"', ' ', 'I', ' ', ((wchar_t)L'µ'),
  'h', 'a', 'd', '?', ' ', 'a', ' ', ((wchar_t)L'^'), 'w', 'o', 'b', 'š', 'l', 'd',' ', ' ', 'o', 'f',
   ' ', '³', 'm', 'y', ' ', 'È', 'i', 'w', 'n', '?', ',', ' ', 'e', '?','v', 'e', 'r', '2'};
  uint32_t* msgDecode = Decodage(tableau, size);
*/

  /* Erreur -> ### */
/*
  int size = 4;
  uint8_t tableau[4] = {'"', 'Y', 'f', '"'};
  uint32_t* msgDecode = Decodage(tableau, 4);
*/

  /* Pas d'erreur */
/*
  int size = 4;
  uint8_t tableau[4] = {'"', 'I', 'f', ((wchar_t)L'¢')};
  uint32_t* msgDecode = Decodage(tableau, size);
*/

  /* Erreur :'( */
  //afficher_binaire(((wchar_t)L'š'));
/*
  int size = 4;
  uint8_t tableau[4] = {'w', 'o', 'r', ((wchar_t)L'š')};
  uint32_t* msgDecode = Decodage(tableau, size);
*/


  /***********/
  /*Affichage*/
  /***********/

  printf("\n");



  return 0;
}
