///////////////////////////////////////////////////////////////////////////////////////
//																	 				 //
// 	Auteur: Picot Rodolphe												 			 //
//																	 				 //
//	Le programme s'utilise de la facon suivante:						 			 //
//																	 				 //
// 		Le premier argument est l'option,'-c' pour chiffrer et 			 			 //
// 		'-d' pour déchiffrer											 			 //
//																	 				 //
// 		Le deuxieme argument est la permutation, attention,				 			 //
// 		La permutaiton doit contenir tous les entiers entre 			 			 //
// 		1 et N											 			 				 //
//																	 				 //
// 		Le troisieme argument est le message à chifrer/déchiffrer		 			 //
//																		 			 //
// 		La ligne de compilation est :										 		 //
//																		 			 //
//	 	'gcc -o exe *.c -lm'														 //
// 																					 //
// 		Exemple d'utilisation: 														 //
// 																					 //
//		 ./exe -c 3,1,2,4 attaquesurparisle12 										 //
//																					 //
// 																					 //
// 			FFGDFADXDGDFVFXFFVAXFDGVVGXFVFFFFXDFAGDX 								 //
// 																					 //
// 		 ./exe -d 3,1,2,4 FFGDFADXDGDFVFXFFVAXFDGVVGXFVFFFFXDFAGDX 					 //
// 																					 //
// 			attaquesurparisle129 													 //
//																					 //
//	Note: il se peut que le chiffrement rajoute des '9' au message initial,			 //
//	pour différencier les '9' légitimes des autres, on peut mettre le mot 			 //
//	"stop" à la fin du message à chiffrer.											 //
//								 													 //
///////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include "entree.h"
#include "chiffrement.h"
#include "dechiffrement.h"


int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		printf("Il n'y a pas le bon nombre d'arguments\n");
		return 0;
	}
	int taille_message=strlen(argv[3]);
	char message[taille_message];
	memcpy(message, argv[3], sizeof(char)*taille_message);
	int taille_permut=length_permut(argv[2]);
	int permut[taille_permut];
	if(traduction(permut, argv[2], strlen(argv[2])) !=0 ){
		printf("La permutation n'est composé que de nombres\n");
		return 0;
	}
	if (verification(permut, taille_permut) != 0)
	{
		printf("la permutation n'est pas bonne, il n'y a pas tous les entiers de 1 à n\n");
		return 0;
	}
	if (strcmp(argv[1], "-c")==0){
		if (chiffrement(permut, taille_permut, argv[3], taille_message) != 0)
		{
			printf("le message à chiffrer n'est pas bon, il ne faut que des lettres\n");
			return 0;
		}
	}
	else if (strcmp(argv[1], "-d")==0)
	{
		if (taille_message%taille_permut!=0 || dechiffrement(permut, taille_permut, message, taille_message) != 0 )
		{
			printf("le message à déchiffrer n'est pas bon, il ne faut que des lettres légitimes\n");
			return 0;
		}
	}
	else{
		printf("relancez le programme en choisissant le chiffrement '-c' ou le dechiffrement '-d'\n");
	}
}
