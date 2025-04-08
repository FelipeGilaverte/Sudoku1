/* atividade L2 */
/*
  Arquivo: Felipe_GilaverteATL2.c
  Autor: Felipe Caliope das Merces Nascimento Gilaverte,Murilo Carvalho Giroto, William da Silva Marques
  Date: 19/03/2025 20:22
  Descricao: verificar existencia de duplicatas em uma matriz do pequeno sudoku
*/	



#include <stdio.h>
#include "Booleano.h"
#include <string.h> 

bool verificarRepetido(unsigned char V[]);
void mostrarMatriz(unsigned char M[10][10]);


int main(){
    unsigned char M[10][10]; 
    unsigned char linha[20];   
	unsigned char temp[10];  
    FILE *entrada;
    int i,lin,col,n,ok;
    bool CanRun = TRUE;
    
	entrada = fopen("SUDOKU.txt","r");
	
    if (entrada == NULL)  {
		printf("\n nao encontrado \n");
		ok = 0;
    }else {
        ok = 1;
         
        lin = 0; 
             
        while(fscanf(entrada, "%20s", linha)==1){
        	
            lin = lin + 1;		
            
			for (i = 0; i <= 8; i++){
				M[lin][i+1] = linha[i];
			
			}
			
        } 
             
       	fclose(entrada); 
    } 
    
   mostrarMatriz(M);

lin = 1;
while (lin <= 9 && CanRun == TRUE) {
    i = 0;
    col = 1;
    while (col <= 9 && CanRun == TRUE) {
        temp[i] = M[lin][col];
        i++;
        col++;
    }
        
    if (verificarRepetido(temp) == TRUE) {
        CanRun = FALSE;
    }
    lin++;
}

col = 1;
if (CanRun == TRUE) {
    while (col <= 9 && CanRun == TRUE){
		i = 0;
		lin = 1;
		while (lin <= 9 && CanRun == TRUE){
			temp[i] = M[lin][col];
			i++;
			lin++;
			
		}
		if (verificarRepetido(temp) == TRUE) {
	            CanRun = FALSE;
	        }
		col++;
	}
}

	

if (CanRun == TRUE){
	printf("\nCORRETO");
}else if (CanRun == FALSE){
	printf("\nINCORRETO");
}	
    return 0;	
}

bool verificarRepetido(unsigned char V[]) {
	int j = 0, p;
	bool rep = FALSE;
	while ((j < 8) && (rep == FALSE)) {
		p = j + 1;
		while ((p < 9) && (rep == FALSE)) {
			if (V[j] == V[p]) {
				rep = TRUE;
			}
			p++;
		}
		j++;
	}
	return rep;
}

void mostrarMatriz(unsigned char M[10][10]){
	int i,j;
	for(i=1; i <= 9; i++){
        for(j=1; j <= 9; j++){
            printf(" %c",M[i][j]); 
        }
       	printf("\n");
    } 
}

