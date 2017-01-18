Programme : Main.o Affichage.o Bruitage.o Decodage.o Division.o Encodage.o ReadFile.o WriteFile.o Tim.h
		gcc Main.o Affichage.o Bruitage.o Decodage.o Division.o Encodage.o ReadFile.o WriteFile.o -o Programme

Main.o : Main.c Affichage.c Bruitage.c Decodage.c Division.c Encodage.c ReadFile.c WriteFile.c Tim.h
		gcc -c Main.c -o Main.o

Affichage.o : Affichage.c Tim.h
		gcc -c Affichage.c -o Affichage.o

Bruitage.o : Bruitage.c Tim.h
		gcc -c Bruitage.c -o Bruitage.o

Decodage.o : Decodage.c Tim.h
		gcc -c Decodage.c -o Decodage.o

Division.o : Division.c Tim.h
		gcc -c Division.c -o Division.o

Encodage.o : Encodage.c Tim.h
		gcc -c Encodage.c -o Encodage.o

ReadFile.o : ReadFile.c Tim.h
		gcc -c ReadFile.c -o ReadFile.o

WriteFile.o : WriteFile.c Tim.h
		gcc -c WriteFile.c -o WriteFile.o
