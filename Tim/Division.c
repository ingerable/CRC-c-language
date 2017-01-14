#include "Tim.h"

/**
 * [Indique le nombre de bits sur lequel est code un nombre (Degre d'un polynome + 1)]
 * @param  nombre [Nombre source]
 * @return        [Nombre de bits]
 */
int get_nb_bits(uint32_t nombre)
{
    int bits = 0;
    while(nombre)
    {
      if(nombre > 0){
        nombre >>= 1;
        bits++;
      }
      else{
        nombre <<= 1;
        bits++;
      }
    }
    return bits;
}

/**
 * [Realise la division euclidienne de 2 polynomes]
 * @param  dividende [Polynome a diviser]
 * @param  diviseur  [Polynome diviseur]
 * @return           [Le reste de la division]
 */
uint32_t division(uint32_t dividende, uint32_t diviseur){
  int tailleDiviseur = get_nb_bits(diviseur);
  // Tant que le degre du dividende est superieur ou egal a celui du diviseur
  while(get_nb_bits(dividende) >= tailleDiviseur)
  {
    int diff = get_nb_bits(dividende) - tailleDiviseur;
    uint32_t tempdiviseur = diviseur << diff;
    // dividende = Operation XOR entre dividende et diviseur
    dividende = dividende ^ tempdiviseur;
  }
  return dividende;
}
