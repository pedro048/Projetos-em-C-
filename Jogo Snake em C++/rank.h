#ifndef RANK_H
#define RANK_H

#endif // RANK_H

#include <iostream>

ifstream pontoEntrada;
ofstream pontoSaida;
char jogador1[20],jogador2[20],jogador3[20]; // variaveis para os nomes do 1,2 e 3 no rank
int ponto1, ponto2, ponto3;                  // variaveis para a pontuacao do 1, 2 e 3 no rank

pontoEntrada.open("rank.txt");
if(pontoEntrada.is_open()){
   pontoEntrada>>jogador1>>ponto1;
   pontoEntrada>>jogador2>>ponto2;
   pontoEntrada>>jogador3>>ponto3;
}else{
   exit(0);
}
pontoEntrada.close();
if(pontos>ponto1){         // a pontuacao do jogador superou a maior pontucao do rank
   system("cls");
   cout<<"###########"<<endl;
   cout<<"# RECORDE #"<<endl;
   cout<<"###########"<<endl;
   cout<<endl;
   cout<<"pontuacao: "<<pontos<<endl;
   cout<<endl;
   system("pause");
}
system("cls");
cout<<"RANK DE PONTUACAO: "<<endl;  // mostra o rank anterior
cout<<endl;
cout<<"1 - "<<jogador1<<" "<<ponto1<<endl;
cout<<"2 - "<<jogador2<<" "<<ponto2<<endl;
cout<<"3 - "<<jogador3<<" "<<ponto3<<endl;
cout<<endl;
if(pontos>ponto1){                 // o jogador deve assumir a 1 posicao no rank
   auxPonto2=ponto2;               // guarda a pontuacao do 2 colocado
   strcpy(auxNomeJ2, jogador2);    // guarda o nome do 2 colocado
   ponto2=ponto1;                  // a pontuacao do 1 colocado passa a ser do 2
   strcpy(jogador2, jogador1);     // o nome do 1 colocado passa a ser do 2
   ponto3=auxPonto2;               // a pontuacao do 2 colocado passa a ser do 3
   strcpy(jogador3, auxNomeJ2);    // o nome do 2 colocado passa a ser do 3
   ponto1=pontos;                  // a pontuacao do jogador passa a ser a do 1 colocado
   cout<<"Digite seu nome: "<<endl;
   cin>>jogador1;                  // o jogador que sera o 1 colocado precisa informar o seu nome

}else if(pontos>ponto2){           // o jogador deve assumir a 2 posicao no rank
   ponto3=ponto2;                  // a pontuacao do 2 colocado passa a ser do 3
   strcpy(jogador3, jogador2);     // o nome do 2 colocado passa a ser do 3
   ponto2=pontos;                  // a pontuacao do jogador passa a ser a do 2 colocado
   cout<<"Digite seu nome: "<<endl;
   cin>>jogador2;                  // o jogador que sera o 2 colocado precisa informar o seu nome

}else if(pontos>ponto3){           // o jogador deve assumir a 3 posicao no rank
   ponto3=pontos;                  // a pontuacao do jogador passa a ser a do 3 colocado
   cout<<"Digite seu nome: "<<endl;
   cin>>jogador3;                  // o jogador que sera o 3 colocado precisa informar o seu nome

}else{
   system("pause");
   goto pularRank;
}
system("cls");
cout<<"RANK DE PONTUACAO: "<<endl;  // mostra o rank atualizado
cout<<endl;
cout<<"1 - "<<jogador1<<" "<<ponto1<<endl;
cout<<"2 - "<<jogador2<<" "<<ponto2<<endl;
cout<<"3 - "<<jogador3<<" "<<ponto3<<endl;
cout<<endl;
system("pause");
pularRank:
pontoSaida.open("rank.txt");
if(pontoSaida.is_open()){
   pontoSaida<<jogador1<<" "<<ponto1<<endl;
   pontoSaida<<jogador2<<" "<<ponto2<<endl;
   pontoSaida<<jogador3<<" "<<ponto3<<endl;
}
pontoSaida.close();
}



