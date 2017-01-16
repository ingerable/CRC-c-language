#include "Tim.h"

int main(){
  int keep = 1;
  while(keep){
    printf("\n\n");
    printf("Entrez le numéro de la fonction à exécuter : \n");
    printf("1. Afficher un polynome\n");
    printf("2. Division de deux polynomes\n");
    printf("3. Decoder un fichier\n");
    printf("4. Encoder un fichier\n");
    printf("5. Bruiter un fichier\n");
    printf("------------------- \n");
    printf("9. Quitter\n");

    char fichier[50];
    char source[50];
    char dest[50];
    strcpy(source, "Sources/");

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    int num;
    scanf("%d", &num);

    switch (num) {
      case 1:
        printf("Sous quel format voulez vous passer votre polynome ?\n");
        printf("1. Binaire\n");
        printf("2. Hexadecimal\n");
        int format;
        scanf("%d", &format);

        printf("Entrez le polynome a afficher :\n");
        while ((c = getchar()) != '\n' && c != EOF) { }

        char *bits_str = malloc(40 * sizeof(char));
        fgets(bits_str, 40, stdin);

        uint32_t pol;

        switch (format) {
          case 1:
            pol = strtol(bits_str, NULL, 2);
            break;

          case 2:
            pol = strtol(bits_str, NULL, 16);
            break;

          default:
            printf("Commande inconnue.\n");
            break;
        }
        affichagePolynome(pol);
        break;

      case 2:
        printf("Entrez le polynome a diviser (dividende) sous forme binaire:\n");
        while ((c = getchar()) != '\n' && c != EOF) { }

        char *bits_str_dividende = malloc(40 * sizeof(char));
        fgets(bits_str_dividende, 40, stdin);
        uint32_t dividende = strtol(bits_str_dividende, NULL, 2);

        printf("Entrez le polynome diviseur sous forme binaire:\n");
        char *bits_str_diviseur = malloc(40 * sizeof(char));
        fgets(bits_str_diviseur, 40, stdin);
        uint32_t diviseur = strtol(bits_str_diviseur, NULL, 2);

        printf("Reste de la division : \n");
        uint32_t reste = division(dividende, diviseur);
        afficher_binaire(reste);
        printf("\n");
        affichagePolynome(reste);
        break;

      /*Decodage fichier + écriture dans un fichier*/
      case 3:
        printf("Entrez le nom du fichier a decoder (le fichier doit se trouver dans le dossier Sources) :\n");
        scanf("%s", fichier);

        strcat(source, fichier);

        strcpy(dest,  "Resultats/decodage_");
        strcat(dest, fichier);

        printf("\n\n");
        printf(" ----- Decodage de %s et ecriture du resultat dans %s ----- \n\n", source, dest);
        struct fileContent fichierSansErreur = readFile(source);
        uint32_t* msgDecodeSansErreur = Decodage(fichierSansErreur.content, fichierSansErreur.size);
        uint8_t* msgDecodeSansErreurChar = AffichageDecode(msgDecodeSansErreur, fichierSansErreur.size);
        writeFile(dest, msgDecodeSansErreurChar, fichierSansErreur.size);
        break;

      /*Encodage d'un fichier texte et écriture du message encodé dans un autre fichier*/
      case 4:
        printf("Entrez le nom du fichier a encoder (le fichier doit se trouver dans le dossier Sources) :\n");
        scanf("%s", fichier);

        strcat(source, fichier);

        strcpy(dest,  "Resultats/encodage_");
        strcat(dest, fichier);

        printf("\n\n");
        printf(" ----- Encodage de %s et écriture du message encodé dans %s ----- \n\n", source, dest);
        struct fileContent fichierAEncoder = readFile(source);
        uint32_t* msgEncode = Encodage(fichierAEncoder.content, fichierAEncoder.size);
        uint8_t* msgEncodeChar = AffichageEncode(msgEncode, fichierAEncoder.size);
        writeFile(dest, msgEncodeChar, fichierAEncoder.size);
        break;

      /*Bruitage d'un texte encodé + écriture dans un fichier*/
      case 5:
        printf("Entrez le nom du fichier a bruiter (le fichier doit se trouver dans le dossier Sources) :\n");
        scanf("%s", fichier);

        strcat(source, fichier);

        strcpy(dest,  "Resultats/bruitage_");
        strcat(dest, fichier);

        float bruit;
        printf("Entrez l'importance du bruitage (entre 0 et 1) :\n");
        scanf("%f", &bruit);

        printf("\n\n");
        printf(" ----- Bruitage de %s et ecriture du resultat dans %s ----- \n\n", source, dest);
        struct fileContent fichierABruiter = readFile(source);
        uint8_t* msgBruite = bruitage(bruit, fichierABruiter.content, fichierABruiter.size);
        writeFile(dest, msgBruite, fichierABruiter.size);
        break;

      case 9:
        keep = 0;
        break;

      default:
        printf("Commande inconnue.\n");
        break;
    }
  }

  return 0;
}
