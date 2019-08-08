/* Exercício03
A Associação Brasileira de Tênis, mantém uma lista com os 10 primeiros classificados de cada mês
do ano de 2010 a 2014(a lista dos 10 melhores do mês não tem repetição). Sabe-se que o primeiro
colocado de cada mês recebe 10 pontos, o segundo 9 pontos e assim por diante. Faça um programa
que a partir das listas dos 10 melhores de cada mês, calcule e mostre, o nome do melhor jogador.
Obs.:
a) Os nomes são distintos, ou seja, não há repetição;
b) Considere a situação de ocorrer empate;*/

#include <stdio.h>
#include <string.h>
#define NP 10/*numero de jogadaores*/
#define NC 60/*número de caracteres*/
#define M 12 /*número de meses*/
#define NA 520 /*número total de jogadores*/

int main(){
 int cont,/*contagem de loop*/
 mes,/*contador de mês*/
 maiorpont=0,/*Maior pontuação*/
 ano=2010,
 i,/*contagem de loop*/
 k=0,/*contagem de atletas*/
 achou,
 pont[NA];/*pontuação*/
 char atletas[NA][NC],/*vetor de caractere para todos os atletas*/
 nomes[NP][NC];/*vetor de caractere para nomes*/
for(mes=1;mes<M&&ano<2014;){/*1°-loop mensal*/
printf("\nJogadores de %d de %d",mes,ano);
 for(cont=0;cont<NP;cont++){/*loop para armasenar nome dos jogadores*/
   printf("\nForneca o nome do jogador:");
   fgets(nomes[cont],NA,stdin);
   setbuf(stdin,NULL);
   achou=0;
   pont[k]=NP-cont;
   atletas[k][NC]=nomes[cont][NC];
   k++;
   for(i=0;i<cont&&achou==0;){/*loop para verificar nomes repetidos*/
     if(strcmp(nomes[i],nomes[cont])==0)
       achou=1;
     else
       i++;
   }
   if(achou==1)
     printf("\nERRO NOMES IGUAIS!!!\n");
 }
if(mes>M){
    ano++;
    mes=1;

}else
   mes++;
}
achou=0;
k=0;
for(i=0;i<NA&&achou==0;){/*loop para soma das melhores pontuações*/
    if(strcmp(atletas[k],atletas[i])==0)
       achou=1;
     else
       i++;
    if(i==NA&&achou==0)
        k++;
    if(achou==1)
        pont[i]=pont[i]+pont[NA];
}
printf("\nMaior Pontuacao\n");
for(cont=0;cont<NA;cont++){/*loop para armazenar maior pontuação*/
    if(pont[cont]>maiorpont)
    maiorpont=pont[cont];
}
for(i=0;i<NA;i++){/*loop para exibir jogadores com melhor pontuação*/
    if(pont[i]>=maiorpont)
        printf("\nnome = %s pontuacao = %d",atletas[i],pont[i]);
}
return 0;
}
