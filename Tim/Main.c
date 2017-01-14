#include "Tim.h"

int main(){

  /*Afficha d'un polynome*/
  //affichagePolynome(0b101010);


  /*******************************************/
  /*Tests Decodage + écriture dans un fichier*/
  /*******************************************/

  /*Decodage fichier test sans erreur + écriture dans un fichier*/

  printf("\n");
  struct fileContent fichierSansErreur = readFile("alice_0x131");
  uint32_t* msgDecodeSansErreur = Decodage(fichierSansErreur.content, fichierSansErreur.size);
  uint8_t* msgDecodeSansErreurChar = AffichageDecode(msgDecodeSansErreur, fichierSansErreur.size);
  writeFile("TestDecodagePropre", msgDecodeSansErreurChar, fichierSansErreur.size);
  printf("\n");


  /*Decodage fichier test avec erreurs + écriture dans un fichier*/

  printf("\n");
  struct fileContent fichierAvecErreurs = readFile("alice_0x131_0.01");
  uint32_t* msgDecodeAvecErreurs = Decodage(fichierAvecErreurs.content, fichierAvecErreurs.size);
  uint8_t* msgDecodeAvecErreursChar = AffichageDecode(msgDecodeAvecErreurs, fichierAvecErreurs.size);
  writeFile("TestDecodageSale", msgDecodeAvecErreursChar, fichierAvecErreurs.size);
  printf("\n");


  /*****************************************************/
  /*Lecture fichier + Encodage + ecriture dans fichier*/
  /*****************************************************/

  /*Encodage d'un fichier texte et écriture du message encodé dans un autre fichier*/

  printf("\n");
  struct fileContent fichierAEncoder = readFile("TestDecodagePropre");
  uint32_t* msgEncode = Encodage(fichierAEncoder.content, fichierAEncoder.size);
  uint8_t* msgEncodeChar = AffichageEncode(msgEncode, fichierAEncoder.size);
  writeFile("TestEncodage", msgEncodeChar, fichierAEncoder.size);
  printf("\n");

  /*Decodage du fichier encode et ecriture du texte decode dans un fichier*/

  printf("\n");
  struct fileContent fichierEncode = readFile("TestEncodage");
  uint32_t* msgEncodeDecode = Decodage(fichierEncode.content, fichierEncode.size);
  uint8_t* msgEncodeDecodeChar = AffichageDecode(msgEncodeDecode, fichierEncode.size);
  writeFile("TestDecodageEncode", msgEncodeDecodeChar, fichierEncode.size);
  printf("\n");


  /*******************************************/
  /*Tests Bruitage + écriture dans un fichier*/
  /*******************************************/

  /*Bruitage d'un texte encodé + écriture dans un fichier*/

  printf("\n");
  struct fileContent fichierABruiter = readFile("alice_0x131");
  uint8_t* msgBruite = bruitage(0.01, fichierABruiter.content, fichierABruiter.size);
  writeFile("TestBruitage", msgBruite, fichierABruiter.size);
  printf("\n");


  /*Decodage du texte bruité + écriture dans un fichier*/

  printf("\n");
  struct fileContent fichierBruite = readFile("TestBruitage");
  uint32_t* msgBruiteDecode = Decodage(fichierBruite.content, fichierBruite.size);
  uint8_t* msgBruiteDecodeChar = AffichageDecode(msgBruiteDecode, fichierBruite.size);
  writeFile("TestDecodageBruite", msgBruiteDecodeChar, fichierBruite.size);
  printf("\n");





  printf("\n" );
  return 0;
}
