#include <stdio.h>
#include <stdlib.h>
#include <windows.h >


int main(){
	char tabuleiro[8][8];
	char save_tabuleiro[8][8];
	int i,k;
	int c,l;
	int parou;
	
	
	
	for(i=0; i<8;i++){
		for(k=0;k<8;k++){			
		
			tabuleiro[i][k] = ' ';
					
		}
		
	}
	// pe�as pretas//
	
	
	tabuleiro[0][0] = 't';
	tabuleiro[0][7] = 't';
	tabuleiro[0][1] = 'c';
	tabuleiro[0][6] = 'c';
	tabuleiro[0][2] = 'b';
	tabuleiro[0][5] = 'b';
	tabuleiro[0][3] = 'r';
	tabuleiro[0][4] = 'd';
	
	tabuleiro[1][0] = 'p';
	tabuleiro[1][1] = 'p';
	tabuleiro[1][2] = 'p';
	tabuleiro[1][3] = 'p';
	tabuleiro[1][4] = 'p';
	tabuleiro[1][5] = 'p';
	tabuleiro[1][6] = 'p';
	tabuleiro[1][7] = 'p';
	
	
	//pe�as brancas//
	
	tabuleiro[7][0] = 'T';
	tabuleiro[7][7] = 'T';
	tabuleiro[7][1] = 'C';
	tabuleiro[7][6] = 'C';
	tabuleiro[7][2] = 'B';
	tabuleiro[7][5] = 'B';
	tabuleiro[7][4] = 'R';
	tabuleiro[7][3] = 'D';
	
	tabuleiro[6][0] = 'P';
	tabuleiro[6][1] = 'P';
	tabuleiro[6][2] = 'P';
	tabuleiro[6][3] = 'P';
	tabuleiro[6][4] = 'P';
	tabuleiro[6][5] = 'P';
	tabuleiro[6][6] = 'P';
	tabuleiro[6][7] = 'P';
	
	
	
	
	
		// jogo...
		do{
			parou = 1;
				printf("\n\n\n");
		printf("\t");
		for(i=0;i<8;i++){
			printf("  %d", i+1);
		}
		printf("\n\t-------------------------\n");
		for(i=0; i<8;i++){
			printf("%d\t ", i+1);
			for(k=0;k<8;k++){
				printf("| ");
				printf("%c", tabuleiro[i][k]);
				
				
			}
			printf("|");
			printf("\n");	
			printf("\t-------------------------\n");
			
		}
		
			printf("\nVoce e as Brancas\nEscolha a peca que deseja mexer...\nlinha...:");
			scanf("%d", &l);
			printf("coluna..:");
			scanf("%d", &c);
			c = c - 1;
			l= l - 1;
			if(tabuleiro[l][c]==' '){
				
				printf("\ncasa vazia porfavor selecione uma casa valida");
				parou = 0;
			}else{
				//Peoes//
				if(tabuleiro[l][c]=='P'){
					printf("Digite para onde deseja ir..:");
					
					printf("\nLinha..:");
					tabuleiro[l][c] = ' ';									 
					scanf("%d", &l);
								
					if(l==5 || l==6){
						
						l= l-1;
						tabuleiro[l][c] = 'P';
						
					}else{
						
						printf("\nNao possivel mover a pessa para esse local..");
						Sleep(2000);
					
				    }
				    //cavalo//
				}else if(tabuleiro[l][c]=='C'){
					for(i=0;i<8;i++){
						for(k=0;k<8;k++){
							save_tabuleiro[i][k] = tabuleiro[i][k];
						}
					}
 					printf("\nCavalo select..:\n");
					printf("\nlinha:");
					tabuleiro[l][c] =' ';
					scanf("%d", &l);
					printf("\ncoluna:");
					scanf("%d", &c);
					//verifica��o para saber se a pe�a n�o esta escolhendo uma posi��o fora do tabuleiro//
					if((l>0 && l<8) && (c>0 && c<8)){
						l=l-1;
						c=c-1;
						
						if((tabuleiro[l][c]==' ' || tabuleiro[l][c]=='p' || tabuleiro[l][c]=='c' || tabuleiro[l][c]=='b' || tabuleiro[l][c]=='t' || tabuleiro[l][c]=='d') && (tabuleiro[l][c]!='P' || tabuleiro[l][c]!='T' || tabuleiro[l][c]!='C' || tabuleiro[l][c]!='B' || tabuleiro[l][c]!='D' || tabuleiro[l][c]!='R' )){
							tabuleiro[l][c]='C';
						}else{
							
							printf("ERRO!!!!");
							
							for(i=0;i<8;i++){
								for(k=0;k<8;k++){
									tabuleiro[i][k] = save_tabuleiro[i][k];
								}
							}
						}
						
					}
				//torre//	
				}else if(tabuleiro[i][k]=='B'){
					tabuleiro[l][c]	= ' ';
					printf("Bispo Select:");
					printf("Digite Para onde deseja ir..\nLinha..:");
					scanf("%d", &l);
					printf("\nColuna...:");
					scanf("%d", &c);
					l=1-l;
					c=c-1;
					
					if(tabuleiro[l][c]==' ' || tabuleiro[l][c]=='p' || tabuleiro[l][c]=='b' || tabuleiro[l][c]=='t' || tabuleiro[l][c]=='c' || tabuleiro[l][c]=='d'){
						tabuleiro[l][c]	= 'B';
					}else{
						printf("\nErro ao mover para essa op");
					}
				}
						
					 
			}
				 
						
			
		 system("cls");
		}while(parou !=0);
		
	
	return 0;
}
