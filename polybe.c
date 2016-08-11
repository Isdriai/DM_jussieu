#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char carre[7][6] = 
{
	{'A','D','F','G','V','X'},
	{'c','1','o','f','w','j'},
	{'y','m','t','5','b','4'},
	{'i','7','a','2','8','s'},
	{'p','3','0','q','h','x'},
	{'k','e','u','l','6','d'},
	{'v','r','g','z','n','9'}
};

void traduction(int permut[], const char *argv, int const taille){
	for (int i = 0; i < taille; ++i)
	{
		permut[i]=(int)argv[i]-48;
	}
}

void conversion_tableau(char const *init, char res[]){
	int const limite=strlen(init);
	for(int k= 0; k < limite; k++){
		int trouve=0;
		for (int i = 1; i < 7 && trouve!=1; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				char test=carre[i][j];
				if ((char)tolower((int)init[k])==test)
				{
					res[k*2]=carre[0][i-1];
					res[k*2+1]=carre[0][j];
					trouve=1;
				}
			}
		}
	}
}

int division_sup(int num, int div){
	int res=num/div;
	if (num%div!=0)
	{
		return res+1;
	}
	else{
		return res;
	}
}

void remplissage(char res[], char *transcription[], int const lignes, int const col, int const taille_res){
	for (int i = 0; i < col ; ++i)
	{
		transcription[i]=malloc(sizeof(char)*lignes);
		for (int j = 0; j < lignes; ++j)
		{
			if (i+j*col < taille_res)
			{
				
				transcription[i][j]=res[i+j*col];
			}
			else{
				transcription[i][j]='X';
			}
		}
	}
}

void echange(int permutation[], char *transcription[], char *resultat[], int const taille_permut, int const lignes){
	for (int i = 0; i < taille_permut; ++i)
	{
		resultat[permutation[i]-1]=transcription[i];
	}
}

void affiche(char *transcription[], int const col){
	for (int i = 0; i < col; ++i)
	{
		printf("%s\n", transcription[i]);
	}
	printf("\n");
}

void chiffrement(char const *permut, char const *message){
	// init de la permutation et verification
	int taille_permut=strlen(permut);
	int permutation[taille_permut];
	traduction(permutation, permut, taille_permut);
	
	// message et sa traduction par ADFGVX sans permut
	int taille_message=strlen(message);
			
	int taille_res=taille_message*2;
	char res[taille_res];
	
	conversion_tableau(message, res);

	// application de la permut
	int nbr_lignes=division_sup(taille_message*2, taille_permut);
	char (*transcription)[nbr_lignes];
	transcription=malloc(sizeof(int)*nbr_lignes*taille_permut);

	remplissage(res, transcription, nbr_lignes, taille_permut, taille_res);

	char *resultat[nbr_lignes];
	echange(permutation, transcription, resultat, taille_permut, nbr_lignes);

	affiche(resultat, taille_permut);
}

void dechiffrement(char const *permut, char const *chiffre){
	// init de la permutation
	int taille_permut=strlen(permut);
	int *permutation=malloc(taille_permut*sizeof(int));
	traduction(permutation, permut, taille_permut);
}

int main(int argc, char const *argv[])
{
	if (strcmp(argv[1], "-c")==0){
		chiffrement(argv[2], argv[3]);
	}
	else if (strcmp(argv[1], "-d")==0)
	{
		dechiffrement(argv[2], argv[3]);
	}
	else{
		printf("relancez le programme en choisissant le chiffrement '-c' ou le dechiffrement 'd'\n");
	}
}