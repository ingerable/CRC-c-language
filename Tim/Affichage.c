#include "Tim.h"

/**
 * [Affiche un polynome sous la forme Xn+Xn-1+...+1]
 * @param mot [Polynome sur 32 bits à afficher]
 */
void affichagePolynome(uint32_t mot)
{
    uint8_t bit;
    int i;
    for(i = 31 ; i >=0 ; i-- )
    {
        bit = mot >> i & 1;
        if(bit == 0b1 && i == 0)
        {
            printf("%d", 1);
        }
        else if(bit == 0b1)
        {
            printf("%c",'X' );
            printf("%d",i );

            if(i > 1 || (i == 1 && ((mot & 1) != 0)))
            {
              printf("%c", '+');
            }
        }
    }
}

/**
 * [Affiche un polynome sous forme binaire]
 * @param n [Polynome a afficher]
 */
void afficher_binaire(unsigned int n) {
  if (n) {
          afficher_binaire(n >> 1);
          if (n & 1)
            printf("1");
          else
            printf("0");
      }
}

/**
 * [Affiche un texte encode et renvoie un tableau contenant les caracteres encodes]
 * @param  mots [Tableau contenant les mots de 32 bits encodes]
 * @param  size  [Nombre des mots]
 * @return       [Tableau contenant les caracteres encodes]
 */
uint8_t* AffichageEncode(uint32_t* mots, int size){
  uint8_t* msgEncode = malloc(sizeof(uint8_t) * size*4);
  uint8_t byteval[4];
  int i;
  int j;
  for(j = 0; j < size; j++)
  {
    for(i = 3; i >= 0; i--){
      byteval[i] = mots[j] >> (i*8);
      printf("%c", byteval[i]);
      msgEncode[(4*j)+(int)fabs(i-3)] = byteval[i];
    }
  }
  return msgEncode;
}

/**
 * [Affiche un texte decode et renvoie un tableau contenant les caracteres decodes]
 * @param  mots [Tableau contenant les mots de 32 bits decodes]
 * @param  size [Nombre des mots]
 * @return      [Tableau contenant les caracteres decodes]
 */
uint8_t* AffichageDecode(uint32_t* mots, int size){
  uint8_t* msgDecode = malloc(sizeof(uint8_t) * size);
  uint8_t byteval[3];
  int i;
  int j;
  for(j = 0; j < size/4; j++)
  {
    for(i = 0; i < 3; i++){
      byteval[i] = mots[j] >> (i*8);
      printf("%c", byteval[i]);
      msgDecode[(3*j)+i] = byteval[i];
    }
  }
  return msgDecode;
}
