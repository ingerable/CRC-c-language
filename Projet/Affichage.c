#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void affichagePolynome(uint32_t mot)
{
    uint8_t bit;
    int i;
    for(i = 31 ; i >=0 ; i-- )
    {
        bit = mot >> i & 1;
        if(bit == 0b1 && i == 0)
        {
            printf("%d",1 );
        }
        else if(bit == 0b1)
        {
            printf("%c",'X' );
            printf("%d",i );

            if(i != 0)
            {
              printf("%c",'+' );
            }
        }
    }
    printf("\n");
}
