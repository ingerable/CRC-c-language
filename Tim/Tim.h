#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#define G 0b00000000000000000000000100110001

uint32_t division(uint32_t nombre, uint32_t diviseur);
int get_nb_bits(int nombre);

void afficher_binaire(unsigned int n);
uint32_t* Encodage(uint8_t* blocs, int nbBlocs);
