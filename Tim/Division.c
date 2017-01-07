#include "Tim.h"

uint32_t division(uint32_t nombre, uint32_t diviseur){
  uint8_t bit = 0;           //variable qui servira pour le bit a ajouter a chaque étapes de la division
  int taillenombre=0;       //nombre de bits du nombre a diviser (calculé au début de la fonction)
  int nombreadiviser=0;     //variable qui servira a stocker le nombre a diviser durant l'opération
  int resultat =0;          //variable qui stockera les résultats
  int reste = 0;             //variable qui stockera les restes

  taillenombre=get_nb_bits(nombre);

  while(taillenombre+1 > 0)
  {

      bit = nombre >> (taillenombre - 1);
      bit &= 0x01;
      if(nombreadiviser >= diviseur)
      {
          reste = nombreadiviser-diviseur;
          resultat<<=1;
          resultat += 1;
      }
      else
      {
          resultat <<=1;
      }
      if(taillenombre != 0)
      {
          reste<<=1;
          reste += bit;
          nombreadiviser = reste;
      }
      taillenombre--;
  }

  /*printf("Nombre à diviser: %d\n", nombre);
  printf("Nombre diviseur: %d\n", diviseur);

  printf("Resultat: %d\n", resultat);
  printf("Reste: %d\n", reste);*/

  return reste;
}

int get_nb_bits(int nombre)
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
