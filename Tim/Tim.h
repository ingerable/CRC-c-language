#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#define G 0b100110001


uint32_t division(uint32_t dividende, uint32_t diviseur);
int get_nb_bits(uint32_t nombre);

void afficher_binaire(unsigned int n);
uint32_t* Encodage(uint8_t* blocs, int nbBlocs);

void AffichageEncode(uint32_t* value, int size);
void AffichageDecode(uint32_t* value, int size);

uint32_t* Decodage(uint8_t* msgEncode, int tailleMsg);
