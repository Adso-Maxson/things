/* Exercicio 01
Hoje, como a tecnologia da informação está muito avançada, nos permite conhecer novas pessoas
independentes da distância. Pedrinho e Maricota se conheceram em uma das redes sociais e logo,
decidiram formar uma família. Escolheram morar em Alvinópolis city, cidade esta, onde as
pessoas são amigas, o clima é agradabilíssimo, não há violência, possui várias fontes de águas
termais. Enfim, uma cidade que deveria fazer parte do roteiro turístico de qualquer pessoa que goze
de perfeitas condições mentais.
Mas como nada é perfeito, o preço da água é muito caro. O casal decidiu manter todos os
seus gastos sob controle. Joãozinho então decidiu medir diariamente o seu consumo de água,
fazendo a leitura do hidrômetro de sua bela casa, e registrando a medida.
Alguns dias Pedrinho efetua a leitura, e em outros a Virgininha. Dessa forma, eles são capazes de
olhar a diferença de consumo entre dois dias consecutivos e saber quanto de água eles gastaram.
Porém em alguns dias eles simplesmente esqueceram de efetuar a leitura, e assim, após um
longo tempo, seu registro de consumo tornou-se incompleto.
Eles têm uma lista de datas e consumo, mas nem todas as datas são consecutivas em virtude dos
dias em que eles não efetuaram a leitura do hidrômetro. Eles desejam levar em conta apenas os dias
onde o consumo pode ser precisamente determinado, e precisam de sua ajuda.
Entrada
A entrada consta de vários casos de teste. A primeira linha de cada caso de teste contém um
único inteiro N indicando o número de medidas que foram efetuadas (2 ≤ N ≤ 10 ). Cada uma das
N linhas seguintes contém 4 inteiros D, M, Y e C, separados por um espaço em branco, indicando
respectivamente o dia (1 ≤ D ≤ 31), mês (1 ≤ M ≤ 12), ano (1900 ≤ Y ≤ 2100), e o consumo (0 ≤ C
≤ 106 ) lido no início de cada dia. As N linhas são ordenadas de forma crescente pela data, e pode
incluir anos bissextos. A seqüência de consumo também é crescente, ou seja, não existem duas
leituras com o mesmo valor. Assuma que t D, M e Y representam uma data válida.
Um ano é bissexto se for divisível por 4 e não divisível por 100.
O final da entrada de dados é indicado por uma linha contenho um zero.
Saída
Para cada caso de , seu programa deve imprimir uma linha contendo dois inteiros separados por um
espaço em branco: o número de déias em que o consumo pode ser precisamente determinado e a
soma do consumo nesses dias.
Exemplo de Entrada
5
9 9 1979 440
29 10 1979 458
30 10 1979 470
1 11 1979 480
2 11 1979 483
3
5 5 2000 6780
6 5 2001 7795
7 5 2002 8201
8
28 2 1978 112
1 3 1978 113
28 2 1980 220
1 3 1980 221
5 11 1980 500
14 11 2008 600
15 11 2008 790
16 12 2008 810
0
Saída para as entradas acima
2 15
0 0
2 191
*/

#include <stdio.h>
#include <math.h>

int main(){
    int N,D,M,Y,C,
    num,/*Loop*/
    dconsect=0,/*Dias consecutivos*/
    dtest=0,/*armazenar dia anterior*/
    consant=0,/*diferênça do consumo anterior*/
    testcon=0,/*armazenar consumo anterior*/
    mtest=0,/*armazenar mês anterior*/
    ytest=0,/*armazenar ano anterior*/
    difcons=0;/*diferênça final de consumo*/
    /*Iniciando Entrada*/
    printf("\nIndique o numero de medidas ou 0(zero)para parar:");
    scanf("%d",&N);
    if(N==0) /*Teste de Execução*/
    return 0;
     for(num=1;num<=N;num++){ /*Iniciando Loop*/
        printf("\nForneca o dia mes ano consumo:");
        scanf("%d %d %d %d",&D,&M,&Y,&C);
        if(num==1||dconsect>0&&(dtest!=D-1&&dtest!=D-30&&dtest!=D-29&&dtest!=28)){/*teste para armazenar variaveis de apoio*/
            dtest=D;
            testcon=C;
            mtest=M;
            ytest=Y;
        }
        if(M<1||M>12)/*Teste mês*/
            printf("\n mes errado");
        if(D<1||D>31) /*Teste dia*/
            printf("\nNumero de dias errado");
        if(Y<1900||Y>2100) /*Teste ano*/
            printf("\nAno invalido");
        if(D==31 && (M==2 || M==4 || M==6 || M==9 || M==11)) /*Teste quantidade de dias do mês*/
            printf("\nData invalida mes nao possui 31 dias!");
        /* Verificação de ano bissexto divisível por 4; não divisível por 100*/
        if(M==2 && D==29 && (Y%4!=0 || (Y%100==0 && Y%400!=0)))
            printf("\nData inválida (fevereiro não possui 29 dias em anos não bissextos)!");
        if(C<0&&C>1000000) /* Verifica o consumo */
            printf("\nErro de consumo! max 1000000");
        if((D==dtest+1||D==dtest-30||D==dtest-29||D==dtest-28)&&(M==mtest&&Y==ytest)){ /*Teste de dias consecutivos e pré calculo do consumo*/
            dconsect++;
            consant=testcon-C;
        }
        else /*teste para armazenar variaveis de apoio*/
            dtest=D;
            testcon=C;
            mtest=M;
            ytest=Y;
        if(difcons==0)/*teste da diferênça do consumo do primeiro dia consecutivo*/
            difcons=consant;
     }
     difcons=difcons+consant;/*cálculo da diferênça de consumo*/
     if(difcons<0)/*tornando diferênça de consumo positivo*/
        difcons=difcons*-1;
     printf("\nDias consecutivos = %d e a diferenca de consumo = %d",dconsect,difcons);
return 0;
}
