#include "Tim.h"

int numberOfLine(char* fileName)
{
  int numbe
  FILE * file;
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

fileContent readFile(char* fileName)
{
    FILE * file;
    int i = 0;
    char c;
    fileContent res;

    int size = numberOfLine(fileName);

    uint8_t* resTab = malloc(size*sizeof(uint8_t));

    file = fopen( fileName , "r");
    if (file)
    {
      while (fscanf(file, "%c", &c)!=EOF)
      {
        resTab[i]=c;
        i++;
      }
      fclose(file);
    }
    res = {resTab, size};
    return res;
}
