#include "Tim.h"

/**
 * [Calcule le nombre de caracteres d'un fichier]
 * @param  fileName [Nom du fichier a lire]
 * @return          [Nombre de caracteres]
 */
int numberOfLine(char* fileName)
{
  int numberOfLine = 0;
  FILE* file;
  char c;
  file = fopen( fileName , "r");
  if (file)
  {
    while (fscanf(file, "%c", &c)!=EOF)
    {
      numberOfLine++;
    }
    fclose(file);
  }
  return numberOfLine;
}

/**
 * [Renvoie un tableau contenant les caracteres d'un fichier ainsi que le nombre de caracteres]
 * @param  fileName [Nom du fichier a lire]
 * @return          [Structure contenant le tableau de caracteres et leur nombre]
 */
struct fileContent readFile(char* fileName)
{
    FILE * file;
    int i = 0;
    char c;
    struct fileContent res;

    int size = numberOfLine(fileName);

    uint8_t* resTab = malloc(size*sizeof(uint8_t));

    file = fopen(fileName, "r");
    if (file)
    {
      while (fscanf(file, "%c", &c)!=EOF)
      {
        resTab[i] = c;
        i++;
      }
      fclose(file);
    }

    res.content = resTab;
    res.size = size;

    return res;
}
