Programme : Main.o Affichage.o Bruitage.o Decodage.o Division.o Encodage.o ReadFile.o WriteFile.o
		gcc Main.o Affichage.o Bruitage.o Decodage.o Division.o Encodage.o ReadFile.o WriteFile.o -o Programme

Main.o : Main.c Affichage.c Bruitage.c Decodage.c Division.c Encodage.c ReadFile.c WriteFile.c
		gcc -c Main.c -o Main.o

Affichage.o : Affichage.c
		gcc -c Affichage.c -o Affichage.o

Bruitage.o : Bruitage.c
		gcc -c Bruitage.c -o Bruitage.o

Decodage.o : Decodage.c
		gcc -c Decodage.c -o Decodage.o

Division.o : Division.c
		gcc -c Division.c -o Division.o

Encodage.o : Encodage.c
		gcc -c Encodage.c -o Encodage.o

ReadFile.o : ReadFile.c
		gcc -c ReadFile.c -o ReadFile.o

WriteFile.o : WriteFile.c
		gcc -c WriteFile.c -o WriteFile.o
