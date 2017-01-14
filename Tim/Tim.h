#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>

#define G 0b100110001

// Division
int get_nb_bits(uint32_t nombre);
uint32_t division(uint32_t dividende, uint32_t diviseur);

// Encodage
uint32_t* Encodage(uint8_t* blocs, int nbBlocs);

// Affichage
uint8_t* AffichageEncode(uint32_t* value, int size);
uint8_t* AffichageDecode(uint32_t* value, int size);
void affichagePolynome(uint32_t mot);
void afficher_binaire(unsigned int n);

// Decodage
uint32_t* Decodage(uint8_t* msgEncode, int tailleMsg);

// Lecture et ecriture de fichier
int numberOfLine(char* fileName);
struct fileContent readFile(char* fileName);
void writeFile(char* fileName, uint8_t* texteCode, int size);

struct fileContent
{
  uint8_t* content;
  int size;
};

// Bruitage
uint8_t* bruitage(float p, uint8_t* blocs, int size);
