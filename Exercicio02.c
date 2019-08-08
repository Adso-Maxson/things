/* Exercicio 02
Exercício 02(10,0 pontos)
O professor João Puxa-Puxa da UA(University of Alvinópolis), normalmente escorraçado no
ambiente de trabalho por ser um chato de galochas, oportunista, sorrateiro, cruzeirense e bajulador
dos seus superiores, teve uma ideia sem precedentes, só comparável a adoção do dito popular
“CAIU NO HORTO TÁ MORTO” - vale salientar que não se trata de um mero dito popular, mas
sim da mais pura verdade, ou seja, uma tautologia, presenciada por mim in loco. O tal professor
decidiu alcançar o estrelato e virar uma espécie de Daniela Cicarelli, sem, digamos, usar de práticas
pouco ortodoxas e aceitas pela boa e velha moral conservadora em alto mar (faria um trocadilho
sobre o ‘’alto’’ presente ali, mas enfim). A ideia era construir uma estátua do R10, usando única e,
exclusivamente, esferas, paralelepípedos e cilindros. Para ajudar o professor nesta tarefa inglória,
você foi escolhido para implementar um software, usando a linguagem de programação C, para
gerenciar os gastos na construção, bem como emitir relatórios com informações consideradas muito
relevantes. Em Alvinópolis City, existem 4 lojas de lojas de materiais de construção chamadas,
respectivamente, Casa Zé, Casa João, Casa Paulo e Casa Chico. As 4 lojas fornecem todos os tipos
de peças e as mesmas podem ser de alumínio, aço ou bronze. Todas as peças devem ser pintadas, e
o pintor Mané das Tintas, o melhor da cidade, pois consegue pintar qualquer peça dependendo, é
claro, do tipo de material, consumindo uma quantidade constante de tinta por cm2 . O seu software
deverá permitir a entrada de várias peças, uma de cada vez, que irão compor a obra de arte. Para
cada peça devem ser fornecidas as dimensões necessárias para o cálculo da área e do volume, o tipo
de material e a loja onde a mesma foi adquirida. No final do programa apresentar um relatório com
as seguintes informações:
1. O peso total da estátua;
2. A maior peça, em peso, de cada um dos materiais;
3. A maior e o menor peça, em volume, de cada um dos materiais;
4. A quantidade de cada uma das peças compradas em cada uma das lojas;
5. O Número mínimo de latas de tinta necessárias para pintar as peças obtendo o menor
desperdício possível;
6. O valor a ser pago a cada uma das lojas;
7. O maior volume encontrado;
8. O peso médio das esferas de aço, alumínio e bronze;
9. O maior cilindro em volume;
10. O valor total gasto na construção;
11. A loja que obteve o maior volume de vendas em R$.
Obs.
a – Área da esfera =4 π R2 ;
b – Volume da esfera = 4π R3 ;
3
c – Área do paralelepípedo: 2xalturaxlargura+2xalturaxprofundidade+2xlarguraxprofundidade
d – Volume do paralelepípedo: altura x largura x profundidade;
e – Área do cilindro: 2π R2 + 2π Rxaltura;
f – Volume do cilindro: π R2xAltura;
g – Existem latas de tinta de 10, 4 e 1 litros;
Peso Específico:
Aço = 7,8 g/cm3
Alumínio = 2,6 g/cm3
Cobre = 8,8g/cm3
Consumo de tinta:
Aço = 0,02 L/cm2
Alumínio = 0,01 L/cm2
Cobre = 0,015 L/cm2
Material Fornecedor Preço por G
Aço Casa Zé R$ 100
Alumínio Casa Zé R$ 80
Cobre Casa Zé R$ 130
Aço Casa Paulo R$ 110
Alumínio Casa Paulo R$ 75
Cobre Casa Paulo R$ 120
Aço Casa João R$ 150
Alumínio Casa João R$ 90
Cobre Casa João R$ 115
Aço Casa Chico R$ 110printf("\nPeso total da estátua = %.2f");
Alumínio Casa Chico R$ 100
Cobre Casa Chico R$ 160
As medidas serão fornecidas em milímetros e os preços das latas de tinta são iguais em cada uma
das lojas, de acordo com a tabela abaixo.
Volume Preço
Lata de 10 litros R$ 120,5
Lata de 4 litros R$ 70,25
Lata de 4 litros R$ 30,85*/

#include <stdio.h>
#include <math.h>

int main(){
    int quantp,/* quantidade de peças*/
    escolha=0,/* escolha de mais peças*/
    num,/*Variavel para 1° Loop */
    numpeca,/*numero de escolha de peça*/
    numforma,/*numero de escolha da forma da peça */
    quant_ze=0,/*quantidade de vendas loja zé */
    quant_joao=0,/*quantidade de vendas loja joao */
    quant_paulo=0,/*quantidade de vendas loja paulo */
    x,/*contagem loop dde tintas*/
    quant_chico=0,/*quantidade de vendas loja chico */
    tipotinta=0,/*tipo de tinta*/
    quantlatas=0;/*quantidade de latas de tinta*/
    float peso_total=0,/*peso total da estátua */
    volume=0,
    area=0,
    altura=0,
    diametro=0,
    profundidade=0,
    peso=0,
    pesomed=0,/*quantidade das peças para calcular peso médio*/
    maiorpeso=0,/*Peça mais pesada*/
    maiorpeca=0,/*maior peça em volume*/
    menorpeca=0,/*menor peça em volume*/
    cons_tinta=0,/*consumo total de tinta*/
    maiorcilindro=0,/*maior cilindro em volume*/
    valor=0,/* valor total*/
    casa_ze=0,/* valor casa zé */
    casa_joao=0,/* valor casa joão*/
    casa_paulo=0,/* valor casa paulo*/
    casa_chico=0,/* valor casa chico*/
    maiorvolvend=0;/* maior volume de vendas*/
for(quantp=1;quantp!=0;){/*1° Loop */
        printf("\nEscolha a loja 1-Casa Ze, 2-Casa Joao, 3-Casa Paulo e 4-Casa Chico: ");
        scanf("%d",&num);
    if(num>4||num<1){
            printf("\n!!!Operacaoo invalida!!!");
    }
    else
    switch (num){
    case 1:printf("\nCasa ze\nEscolha o tipo de pecas 1-aluminio R$90, 2-aco R$150 ou 3-bronze R$130:");
           scanf("%d",&numpeca);
           quant_ze++;
           if(numpeca>3||numpeca<1)
                printf("\n!!!Operacaoo invalida!!!");
           else{
           switch (numpeca){
           case 1:casa_ze=casa_ze+80;
                  volume=volume+2,6;
                  cons_tinta=cons_tinta+0,01;
                  peso=peso+2,6;
                  break;
           case 2:casa_ze=casa_ze+100;
                  volume=volume+7,8;
                  cons_tinta=cons_tinta+0,02;
                  peso=peso+7,8;
                  break;
           case 3:casa_ze=casa_ze+130;
                  volume=volume+8,8;
                  cons_tinta=cons_tinta+0,015;
                  peso=peso+8,8;
                  break;
           }
           printf("\nEscolha a forma da peca 1-esferas, 2-paralelepipedos e 3-cilindros:");
           scanf("%d",&numforma);
           if(numforma>3||numforma<1)
                printf("\n!!!Operacaoo invalida!!!");
            else{
             printf("\nForneca o tamanho da peca em cm(centimetros)ex: altura diametro:");
             scanf("%f %f",&altura,&diametro);
            switch(numforma){
            case 1:area=area+3,14*(diametro/2)*(diametro/2);
                   volume=volume+(4/3)*3,14*(diametro/2)*(diametro/2)*(diametro/2);
                   peso=peso+area;
                   break;
            case 2:printf("\nForneca a profundidade do paralelepipedo em cm(centimetros):");
                   scanf("%f",&profundidade);
                   area=area+2*(altura*diametro)+2*(altura*profundidade)+2*(diametro*profundidade);
                   volume=volume+altura*diametro*profundidade;
                   peso=peso+area;
                   break;
            case 3:area=area+2*3,14*(diametro/2)*(diametro/2)+2*3,14*(diametro/2)*altura;
                   volume=volume+3,14*(diametro/2)*(diametro/2)*altura;
                   peso=peso+area;
                   if(volume>maiorcilindro)
                    maiorcilindro=volume;
                   break;
            }
            peso_total=peso_total+peso;
            }
           }
           break;
    case 2:printf("\nCasa Joao\nEscolha o tipo de peca 1-aluminio R$100, 2-aco R$80 ou 3-bronze R$115:");
           scanf("%d",&numpeca);
           quant_joao++;
           if(numpeca>3||numpeca<1)
                printf("\n!!!Operacaoo invalida!!!");
            else{
            switch (numpeca){
            case 1:casa_joao=casa_joao+100;
                  volume=volume+2,6;
                  cons_tinta=cons_tinta+0,01;
                  peso=peso+2,6;
                  break;
            case 2:casa_joao=casa_joao+80;
                   volume=volume+7,8;
                   cons_tinta=cons_tinta+0,02;
                   peso=peso+7,8;
                   break;
            case 3:casa_joao=casa_joao+115;
                   volume=volume+8,8;
                   cons_tinta=cons_tinta+0,015;
                   peso=peso+8,8;
                   break;
            }
            printf("\nEscolha a forma da poca 1-esferas, 2-paralelepipedos e 3-cilindros:");
            scanf("%d",&numforma);
            if(numforma>3||numforma<1)
                printf("\n!!!Operacaoo invalida!!!");
             else{
             printf("\nForneca o tamanho da peca em cm(centimetros)ex: altura diametro:");
             scanf("%f %f",&altura,&diametro);
             switch(numforma){
             case 1:area=area+3,14*(diametro/2)*(diametro/2);
                    volume=volume+(4/3)*3,14*(diametro/2)*(diametro/2)*(diametro/2);
                    peso=peso+area;
                    break;
             case 2:printf("\nForneça a profundidade do paralelepipedo em cm(centimetros):");
                    scanf("%f",&profundidade);
                    area=area+2*(altura*diametro)+2*(altura*profundidade)+2*(diametro*profundidade);
                    volume=volume+altura*diametro*profundidade;
                    peso=peso+area;
                    break;
             case 3:area=area+2*3,14*(diametro/2)*(diametro/2)+2*3,14*(diametro/2)*altura;
                    volume=volume+3,14*(diametro/2)*(diametro/2)*altura;
                    peso=peso+area;
                    if(volume>maiorcilindro)
                     maiorcilindro=volume;
                    break;
             }
             peso_total=peso_total+peso;
             }
            }
            break;
    case 3:printf("\nCasa Paulo\nEscolha o tipo de pecas 1-aluminio R$75, 2-aco R$110 ou 3-bronze R$120:");
           scanf("%d",&numpeca);
           quant_paulo++;
           if(numpeca>3||numpeca<1)
                printf("\n!!!Operacaoo invalida!!!");
           else{
           switch(numpeca){
           case 1:casa_paulo=casa_paulo+75;
                  volume=volume+2,6;
                  cons_tinta=cons_tinta+0,01;
                  peso=peso+2,6;
                  break;
           case 2:casa_paulo=casa_paulo+110;
                  volume=volume+7,8;
                  cons_tinta=cons_tinta+0,02;
                  peso=peso+7,8;
                  break;
           case 3:casa_paulo=casa_paulo+120;
                  volume=volume+8,8;
                  cons_tinta=cons_tinta+0,015;
                  peso=peso+8,8;
                  break;
           }
           printf("\nEscolha a forma da peca 1-esferas, 2-paralelepipedos e 3-cilindros:");
           scanf("%d",&numforma);
           if(numforma>3||numforma<1)
                printf("\n!!!Operacaoo invalida!!!");
            else{
            printf("\nForneça o tamanho da peca em cm(centimetros)ex: altura diametro:");
            scanf("%f %f",&altura,&diametro);
            switch(numforma){
            case 1:area=area+3,14*(diametro/2)*(diametro/2);
                   volume=volume+(4/3)*3,14*(diametro/2)*(diametro/2)*(diametro/2);
                   peso=peso+area;
                   break;
            case 2:printf("\nForneça a profundidade do paralelepipedo em cm(centimetros):");
                   scanf("%f",&profundidade);
                   area=area+2*(altura*diametro)+2*(altura*profundidade)+2*(diametro*profundidade);
                   volume=volume+altura*diametro*profundidade;
                   peso=peso+area;
                   break;
            case 3:area=area+2*3,14*(diametro/2)*(diametro/2)+2*3,14*(diametro/2)*altura;
                   volume=volume+3,14*(diametro/2)*(diametro/2)*altura;
                   peso=peso+area;
                   if(volume>maiorcilindro)
                    maiorcilindro=volume;
                   break;
            }
            peso_total=peso_total+peso;
            }
           }
           break;
    case 4:printf("\nCasa Chico\nEscolha o tipo de peca 1-aluminio R$100, 2-aco R$110 ou 3-bronze R$160:");
           scanf("%d",&numpeca);
           quant_chico++;
        if(numpeca>3||numpeca<1)
                printf("\n!!!Operacaoo invalida!!!");
         else{
         switch (numpeca){
         case 1:casa_chico=casa_chico+100;
                volume=volume+2,6;
                cons_tinta=cons_tinta+0,01;
                peso=peso+2,6;
                break;
         case 2:casa_chico=casa_chico+110;
                volume=volume+7,8;
                peso=peso+7,8;
                cons_tinta=cons_tinta+0,02;
                break;
         case 3:casa_chico=casa_chico+160;
                volume=volume+8,8;
                cons_tinta=cons_tinta+0,015;
                peso=peso+8,8;
                break;
         }
         printf("\nEscolha a forma da peca 1-esferas, 2-paralelepipedos e 3-cilindros:");
         scanf("%d",&numforma);
         if(numforma>3||numforma<1)
                printf("\n!!!Operacaoo invalida!!!");
          else{
          printf("\nForneca o tamanho da peca em cm(centimetros)ex: altura diametro:");
          scanf("%f %f",&altura,&diametro);
          switch(numforma){
          case 1:area=area+3,14*(diametro/2)*(diametro/2);
                 volume=volume+(4/3)*3,14*(diametro/2)*(diametro/2)*(diametro/2);
                 peso=peso+area;
                 break;
          case 2:printf("\nForneca a profundidade do paralelepipedo em cm(centimetros):");
                 scanf("%f",&profundidade);
                 area=area+2*(altura*diametro)+2*(altura*profundidade)+2*(diametro*profundidade);
                 volume=volume+altura*diametro*profundidade;
                 peso=peso+area;
                 break;
          case 3:area=area+2*3,14*(diametro/2)*(diametro/2)+2*3,14*(diametro/2)*altura;
                 volume=volume+3,14*(diametro/2)*(diametro/2)*altura;
                 peso=peso+area;
                 if(volume>maiorcilindro)
                  maiorcilindro=volume;
                 break;
          }
          peso_total=peso_total+peso;
          }
         }
         break;
    }
    if(quantp==1){
      maiorpeca=volume;
      menorpeca=volume;
      maiorpeso=peso;
    }else{
      if(volume>maiorpeca)
        maiorpeca=volume;
      else{
       if(volume<menorpeca)
         menorpeca=volume;
      }
      if(peso>maiorpeso)
        maiorpeso=peso;
    }
    cons_tinta=cons_tinta/area;
    switch(num){
    case 1:printf("\nEscolha o tipo da tinta: 1)Lata de 10 litros R$ 120,5 \n 2)Lata de 6 litros R$ 70,25 \n 3)Lata de 4 litros R$ 30,85:");
             scanf("%d",&tipotinta);
             if(tipotinta>3||tipotinta<1)
                printf("\n!!!Operacaoo invalida!!!");
             else{
              switch(tipotinta){
              case 1:casa_ze=casa_ze+valor+120,5;
                    quantlatas=10;
                    for(x=0;quantlatas<=cons_tinta;quantlatas+quantlatas){
                    x++;
                    }
                    break;
              case 2:casa_ze=casa_ze+valor+70,25;
                    quantlatas=6;
                    for(x=0;quantlatas<=cons_tinta;quantlatas+quantlatas){
                    x++;
                    }
                    break;
              case 3:casa_ze=casa_ze+valor+30,85;
                    quantlatas=4;
                    for(x=0;quantlatas<=cons_tinta;quantlatas+quantlatas){
                    x++;
                    }
                    break;
              }
             }
             break;
    case 2:printf("\nEscolha o tipo da tinta: 1)Lata de 10 litros R$ 120,5 \n 2)Lata de 6 litros R$ 70,25 \n 3)Lata de 4 litros R$ 30,85:");
           scanf("%d",&tipotinta);
           if(tipotinta>3||tipotinta<1)
                printf("\n!!!Operacaoo invalida!!!");
           else{
              switch(tipotinta){
              case 1:casa_joao=casa_joao+valor+120,5;
                     quantlatas=10;
                     for(x=0;quantlatas<=cons_tinta;quantlatas+quantlatas){
                     x++;
                     }
                     break;
             case 2:casa_joao=casa_joao+valor+70,25;
                    quantlatas=6;
                    for(x=0;quantlatas<=cons_tinta;quantlatas+quantlatas){
                    x++;
                    }
                    break;
             case 3:casa_joao=casa_joao+valor+30,85;
                    quantlatas=4;
                    for(x=0;quantlatas<=cons_tinta;quantlatas+quantlatas){
                    x++;
                    }
                    break;
              }
           }
           break;
    case 3:printf("\nEscolha o tipo da tinta: 1)Lata de 10 litros R$ 120,5 \n 2)Lata de 6 litros R$ 70,25 \n 3)Lata de 4 litros R$ 30,85:");
           scanf("%d",&tipotinta);
           if(tipotinta>3||tipotinta<1)
                printf("\n!!!Operacaoo invalida!!!");
           else{
              switch(tipotinta){
              case 1:casa_paulo=casa_paulo+valor+120,5;
                     quantlatas=10;
                     for(x=0;quantlatas<=cons_tinta;quantlatas+quantlatas){
                     x++;
                     }
                     break;
              case 2:casa_paulo=casa_paulo+valor+70,25;
                     quantlatas=6;
                     for(x=0;quantlatas<=cons_tinta;quantlatas+quantlatas){
                     x++;
                     }
                     break;
              case 3:casa_paulo=casa_paulo+valor+30,85;
                     quantlatas=4;
                     for(x=0;quantlatas<=cons_tinta;quantlatas+quantlatas){
                     x++;
                     }
                     break;
              }
           }
           break;
    case 4:printf("\nEscolha o tipo da tinta: 1)Lata de 10 litros R$ 120,5 \n 2)Lata de 6 litros R$ 70,25 \n 3)Lata de 4 litros R$ 30,85:");
           scanf("%d",&tipotinta);
           if(tipotinta>3&&tipotinta<1)
                printf("\n!!!Operacaoo invalida!!!");
           else{
              switch(tipotinta){
              case 1:casa_chico=casa_chico+valor+120,5;
                     quantlatas=10;
                     for(x=0;quantlatas<=cons_tinta;quantlatas+quantlatas){
                     x++;
                     }
                     break;
              case 2:casa_chico=casa_chico+valor+70,25;
                     quantlatas=6;
                     for(x=0;quantlatas<=cons_tinta;quantlatas+quantlatas){
                     x++;
                     }
                     break;
              case 3:casa_chico=casa_chico+valor+30,85;
                     quantlatas=4;
                     for(x=0;quantlatas<=cons_tinta;quantlatas+quantlatas){
                     x++;
                     }
                     break;
              }
           }
           break;
    }
    valor=valor+casa_chico+casa_joao+casa_paulo+casa_ze;/* soma valor final*/
    printf("\nNecessita de mais alguma peca? 1= sim e 2= nao");
    scanf("%d",&escolha);
    if(escolha==1){/*teste para continuar a receber peças*/
        quantp++;
        peso=0;/*zerando valores*/
        area=0;
        volume=0;
        tipotinta=0;
        profundidade=0;
        num=0;
        numpeca=0;
        numforma=0;
    }
    else{
       pesomed=quantp;
       quantp=0;
    }
}
printf("\nPeso total da estatua = %.2f",peso_total);
printf("\nA peca mais pesada = %.2f /cm cubicos",maiorpeso);
printf("\nA maior %.2f e a menor %.2f em volume",maiorpeca,menorpeca);
printf("\nQuantidade de pecas compradas em cada loja\nCasa Ze = %d \nCasa Joao = %d \nCasa Paulo = %d \nCasa Chico = %d",quant_ze,quant_joao,quant_paulo,quant_chico);
printf("\nNumero minimo de latas necessarias para pintar = %d latas de %d litros",x,quantlatas);
printf("\nValor a ser pago para cada loja \nCasa Ze = %.2f \nCasa Joao = %.2f \nCasa Paulo = %.2f \nCasa Chico = %.2f",casa_ze,casa_joao,casa_paulo,casa_chico);
printf("\nO peso medio das esferas de aco, aluminio e bronze = %.2f",peso_total/pesomed);
printf("\nO maior cilindro em volume = %.2f",maiorcilindro);
printf("\nO valor total gasto na construcao = %.2f",valor);
maiorvolvend=casa_ze;
if(casa_chico>maiorvolvend)
    maiorvolvend=casa_chico;
if(casa_joao>maiorvolvend)
    maiorvolvend=casa_joao;
if(casa_paulo>maiorvolvend)
    maiorvolvend=casa_paulo;
if(casa_ze>maiorvolvend)
    maiorvolvend=casa_ze;
printf("\nO A loja que obteve o maior volume de vendas em R$ = %.2f",maiorvolvend);
return 0;
}
