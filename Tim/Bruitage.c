#include "Tim.h"

void bruitage(float p, uint8_t* blocs)
{
    srand((unsigned) time(NULL));
    int i;
    uint8_t bit;
    //pour chaque bit de l'octet
    for(i = 7; i > 0; i--)
    {
      //on récupère le bit
       bit = *blocs >> i & 1;
       //random pour pour savoir si on fait la modification
       float proba = (float)rand()/RAND_MAX;
       //si on est entre 0 et p on fait le bruitage
       if(proba<p)
       {
            bit ^= 1;
       }
    }
}
