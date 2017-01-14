#include "Tim.h"

/**
 * [Modifie chaque bit d'un bloc de code avec la probabilité p]
 * @param  p     [Probabilité (0,1) qu'un bit soit modifie]
 * @param  blocs [Tableau contenant les caracteres du code]
 * @param  size  [Nombre de caracteres]
 * @return       [Tableau contenant les caracteres du code apres bruitage]
 */
uint8_t* bruitage(float p, uint8_t* blocs, int size)
{
  uint8_t* msgBruite = blocs;
  srand((unsigned) time(NULL));
  int i;
  int j;

  // pour chaque octet (caractere)
  for(j = 0; j < size; j++){
    //pour chaque bit de l'octet
    for(i = 7; i > 0; i--)
    {
       //random pour pour savoir si on fait la modification
       float proba = (float)rand()/RAND_MAX;
       //si on est entre 0 et p on fait le bruitage
       if(proba < p)
       {
         uint8_t bit = 1;
         bit = bit << i;
         msgBruite[j] = msgBruite[j] ^ bit;
       }
    }

    printf("%c", (uint8_t)msgBruite[j]);
  }
  return msgBruite;
}
