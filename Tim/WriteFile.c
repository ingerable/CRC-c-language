#include "Tim.h"

/**
 * [Ecrit du texte dans un fichier]
 * @param fileName  [Nom du fichier où ecrire]
 * @param texteCode [Tableau contenant les caracteres a imprimer]
 * @param size      [Nombre de caracteres a imprimer]
 */
void writeFile(char* fileName, uint8_t* texteCode, int size)
{
  FILE * file;

  file = fopen(fileName, "w");

  int i;
  if(file != NULL){
    for(i = 0; i < size ; i++)
    {
      fprintf(file, "%c", texteCode[i]);
    }
    fclose(file);
  }
}
