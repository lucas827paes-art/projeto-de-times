#include <stdio.h>
#include <locale.h>
#include <string.h>

int organizador (int cn, int colo[10], int crit[10][3])
{
 int z, j;

for(z = 0; z < cn; z++)
        colo[z] = 0;

    for(z = 0; z < cn; z++) {
        for(j = 0; j < cn; j++) {
            if(z != j) { 
                if(crit[z][0] < crit[j][0])
                    colo[z]++;
                else if(crit[z][0] == crit[j][0]) {
                    if(crit[z][1] < crit[j][1])
                        colo[z]++;
                    else if(crit[z][1] == crit[j][1]) {
                        if(crit[z][2] < crit[j][2])
                            colo[z]++;
                    }
                }
            }
        }
    }
}

int verificador (int cn, int au)
 {
	if(cn == 0 || au == 0){
	printf("dê as informações do time primeiro\n");
	return 0;	
	}
	return 1;
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	int opcoes,contadornomes = 0,cc = 0,co, dadostimes[10][5] = {0}, encontrado,criteriopodio[10][3] = {0},c,c1,c2,colocacao[10] = {0};
	int posicao = 0, auxiliar, aux, aux1;
	char nome[10][20], procurador[20], pesquisa[20];
	
 	do{
 	puts("  *___________________________________________*");
	puts(" /|--{          -Tabela de jogos-          }--|");
	puts("| |-{       Nomes dos times digite 1        }-|");
	puts("| |--{         Resultados digite 2         }--|");
	puts("| |-{        Classificação digite 3         }-|");	
	puts("| |--{      TOP 5 colocados digite 4       }--|");	
	puts("| |-{     Zona de rebaixamento digite 5     }-|");	
	puts("| |--{       Escolher time digite 6        }--|");	
	puts("| |-{            Sair digite 7              }-|");
	puts("| |___________________________________________|");
	puts("|/____________________________________________/");
	
	scanf("%i",&opcoes);
	while (getchar() != '\n');
	
	switch(opcoes){
		case 1:
			
    		if(contadornomes == 10){
        	 puts("Você não pode mais colocar times");
			break;	
   			}
   			
  	    	puts("Digite os nomes dos times (máximo 10)");
 		    puts("Digite 'sair' para encerrar");

           while (contadornomes < 10) {
           	
            printf("digite aqui -> ");
            fgets(nome[contadornomes], sizeof(nome[contadornomes]), stdin);

			nome[contadornomes][strcspn(nome[contadornomes], "\n")] = '\0';

           if (strcmp(nome[contadornomes], "sair") == 0)
            break;
         else
        contadornomes++;	
		
    }
    if(contadornomes == 10)
	puts("Você não pode mais colocar times");
		break;
		case 2:
			
			if(contadornomes == 0){
		puts("dê os nomes do time primeiro");
		break;	
		}	
		strcpy(procurador,"");
			while(strcmp(procurador, "sair") != 0){
			co = 0;
			encontrado = 0;
		      printf("digite o time que você quer adicionar os dados ");
		      puts("Digite 'sair' para encerrar");
		      
		      fgets(procurador, sizeof(procurador), stdin);
		      
		      procurador[strcspn(procurador, "\n")] = '\0';
		      
    		 	if (strcmp(procurador, "sair") == 0) break;	
				
		      while(co < contadornomes && encontrado == 0){
		      	if(strcmp(nome[co], procurador) == 0){
		      encontrado = 1;
		      }else{
		      co++;
		  }
	}
			  if(!encontrado){
   				 puts("Nome inválido");
				} else {		
		       printf("digite o número de vitórias, empates, derrotas,e gols(marcados e sofridos) do %s:\n",nome[co]);
			  for(cc = 0; cc < 5; cc++){
			   scanf("%i", &dadostimes[co][cc]);
			   aux++;
			   if(cc == 0){
			   criteriopodio[co][0] = dadostimes[co][cc] * 3;
			   criteriopodio[co][2] = dadostimes[co][cc];
		}
			    if(cc == 1)
			    criteriopodio[co][0] += dadostimes[co][cc];
			    
			     if(cc == 4)
			     criteriopodio[co][1] = dadostimes[co][3] - dadostimes[co][cc];
		    }
		printf("\n"); 
		while (getchar() != '\n');
	}
}
		break;
		case 3:
	if (verificador(contadornomes, aux)){
	
			puts("aqui estão os times respectivamente em 'nome, vitórias, empates, derrotas, gols(marcados, sofrido e saldo) e pontos'");
			for(c = 0; c < contadornomes; c++){
			 printf("%s, ",nome[c]);
			 
				for(c1 = 0; c1 < 5; c1++)
				 printf("%i, ",dadostimes[c][c1]);
				 
				 	 printf("%i, %i\n",criteriopodio[c][1], criteriopodio[c][0]);
	}
}
		break;
case 4:
	if(verificador(contadornomes, aux)){
	
 organizador(contadornomes, colocacao, criteriopodio);
 
     puts("Top 5 times por pontos, saldo de gols e número de vitórias");
    posicao = 0;

    for(c2 = 0; c2 < contadornomes; c2++) {     
        for(c = 0; c < contadornomes; c++) {      
            if(colocacao[c] == c2) {  
                printf("%i, %s, %i, %i, %i\n", posicao + 1, nome[c], criteriopodio[c][0], criteriopodio[c][1], criteriopodio[c][2]);
                posicao++;
            }
        }
        if(posicao == 5) break; 
    }
}
		break;
		case 5:
	if(verificador(contadornomes, aux)){
	
	if(contadornomes < 9){
	puts("times insuficientes (minimo 9)");
	break;	
	}
	
 organizador(contadornomes, colocacao, criteriopodio);
 
     puts("4 times na zona de rebaixamento por pontos, saldo de gols e número de vitórias");
    posicao = contadornomes;
    auxiliar = 0; 
    for(c2 = contadornomes; c2 >= 5; c2--) {      
        for(c = 0; c < contadornomes; c++) {     
            if(colocacao[c] == c2) {   
                printf("%i, %s, %i, %i, %i\n", posicao, nome[c], criteriopodio[c][0], criteriopodio[c][1], criteriopodio[c][2]);
                posicao--;
                auxiliar++; 
            }
        }
        if(auxiliar == 4) break; 
    }	
}
		break;
		case 6:
	if(verificador(contadornomes, aux)){

 organizador(contadornomes, colocacao, criteriopodio);

		strcpy(pesquisa,"");
		 
			while(strcmp(pesquisa, "sair") != 0){

	puts("digite o nome do time que você quer as informações");
	printf("->");
	fgets(pesquisa, sizeof(pesquisa), stdin);
	aux1 = 0;
	
	pesquisa[strcspn(pesquisa, "\n")] = '\0';
	
	if(strcmp(pesquisa, "sair") == 0) break;
	
	  for(c = 0; c <= contadornomes; c++){    
            if(strcmp(pesquisa, nome[c]) == 0){   
             printf("vitórias : %i, empates : %i e derrotas : %i\n",dadostimes[c][0], dadostimes[c][1], dadostimes[c][2]);
             printf("gols marcados : %i, sofrido : %i e saldo : %i\n",dadostimes[c][3], dadostimes[c][4], criteriopodio[c][1]);
             printf("pontos : %i e colocação : %i\n", criteriopodio[c][0], colocacao[c] + 1);
			aux1++;		
		}
	}
	if(aux1 == 0){
	puts("nome inválido!"); 
	break;
	}
}
}
		break;
		
		default:
		break;	
	}
	if(opcoes > 7 || opcoes == 0)
	puts("digite um número que está na tabela!");	
	}while(opcoes != 7);

	return 0;
}
