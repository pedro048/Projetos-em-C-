#include <iostream>
#include <stdlib.h>  // para usar o rand(), srand(), system()
#include <windows.h> // para usar sleep(), Beep()
#include <conio.h>   // para usar kbhit() e o getch()
#include <time.h>    // para poder usar time(0)
#include <cstring>   // para usar strcpy()
#include <fstream>   // para usar a manipulacao de arquivo
using namespace std;

/*
Nome: Pedro Victor Andrade Alves
Computer engineering student
*/

bool perdeu=false; // essa variavel comeca em falso, porque o usuario ainda nao perdeu
int const largura=20, altura=20; // a altura se refere as linhas e a largura as colunas. Essa e a dimensao da matriz do jogo
int x, y, frutaX, frutaY, extraX, tempo, extraY, pontos, auxPontos=0; /* variaveis para as coordenadas referentes a
                                                                         cabeca da cobra, a fruta, a fruta extra,
                                                                         pontuacao
                                                                        */
int contarCauda, escolhas, nivel, cores, auxPonto2; /* variaveis usadas no crescimento da cauda, escolha das cores,
                                                       inicializacao do jogo, nivel de dificuldade e permutacao da
                                                       pontuacao no rank
                                                    */
enum direcao{parar=0, esquerda, direita, cima, baixo}; // usado na movimentacao da cobra no jogo
direcao pos; // pos pode ser parar, esquerda, direita, cima ou baixo
char auxNomeJ2[20]; // auxilia na permutacao dos nomes no rank
bool tesquer, tdireita, tcima, tbaixo, acabouFextra=false, mostrarCauda; /* variaveis usadas para a cobra nao mudar de sentido (direita ou esquerda) quando estiver na horizontal e
                                                                            permancer na mesmo sentido (cima ou baixo) para o movimento vertical. acabouFextra auxilia quando o tempo
                                                                            da fruta extra termina e mostrarCauda ajuda para colocar espacos vazios quando nao esta sendo mostrada a
                                                                            cabeca da cobra, a fruta, a fruta extra e a cauda da cobra
                                                                            */

struct raboCobra{ // estrutura de dados com o vetor que contem os fragmentos da cauda
 int cauda[100];
};
raboCobra xCobra; // variavel para as coordenadas em x dos fragmentos da cauda
raboCobra yCobra; // variavel para as coordenadas em y dos fragmentos da cauda

//prototipos das funcoes usadas no jogo

void configuracao();
void desenho();
void entrada();
void logica();
void gerarFrutaExtra();

int main(){
    srand(time(0));   // usundo o relogio do computador para auxiliar na obtencao de numeros aleatorios
    if(perdeu==true){ /* se o jogador perdeu esta no momento de apresentar o rank e verificar se a sua
                         pontuacao foi suficiente para ficar entre os tres melhores
                      */
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
    configuracao(); // essa funcao e chamada para configurar os elementos do jogo
    system("cls");
    cout<<"########### JOGO SNAKE #############"<<endl;
    cout<<"#                                  #"<<endl;
    cout<<"# Escolha a coloracao do jogo:     #"<<endl;
    cout<<"#                                  #"<<endl;
    cout<<"# 1 - azul         2 - verde       #"<<endl;
    cout<<"# 3 - vermelho     4 - amarelo     #"<<endl;
    cout<<"# 5 - branco       6 - cinza       #"<<endl;
    cout<<"# 7 - lilas        8 - verde-agua  #"<<endl;
    cout<<"#                                  #"<<endl;
    cout<<"####################################"<<endl;
    cout<<endl;
    volta1:
    cout<<"insira o valor referente a cor desejada: "<<endl;
    cin>>cores;
    switch(cores){
    case 1:
        system("color 09");
        break;
    case 2:
        system("color A");
        break;
    case 3:
        system("color C");
        break;
    case 4:
        system("color E");
        break;
    case 5:
        system("color F");
        break;
    case 6:
        system("color 08");
        break;
    case 7:
        system("color D");
        break;
    case 8:
        system("color B");
        break;
    default:
        system("cls");
        cout<<"Essa cor nao e valida!"<<endl;
        cout<<"Escolha novamente"<<endl;
        goto volta1;
    }
    system("cls");
    cout<<"######## JOGO SNAKE #########"<<endl;
    cout<<"#                           #"<<endl;
    cout<<"# - 0 - iniciar             #"<<endl;
    cout<<"# - 1 - sair                #"<<endl;
    cout<<"#                           #"<<endl;
    cout<<"# Niveis de dificuldade:    #"<<endl;
    cout<<"#                           #"<<endl;
    cout<<"# - 1 - nivel 1             #"<<endl;
    cout<<"# - 2 - nivel 2             #"<<endl;
    cout<<"# - 3 - nivel 3             #"<<endl;
    cout<<"#                           #"<<endl;
    cout<<"#***************************#"<<endl;
    cout<<"# A tecla f reinicia o jogo #"<<endl;
    cout<<"#                           #"<<endl;
    cout<<"# A tecla p paralisa o jogo #"<<endl;
    cout<<"#***************************#"<<endl;
    cout<<"#                           #"<<endl;
    cout<<"############################"<<endl;
    cout<<endl;
    volta3:
    cout<<"iniciar ou sair: "<<endl;
    cin>>escolhas;
    volta2:
    if(escolhas!=1){
        cout<<"escolha o nivel de dificuldade: "<<endl;
        cin>>nivel;
    }
    switch(escolhas){
    case 0:
        while(perdeu==false){ // enquanto o usuario nao perdeu o jogo continua
            desenho();
            entrada();
            logica();
            if(perdeu==true){
                system("cls");
                cout<<"####################"<<endl;
                cout<<"##                ##"<<endl;
                cout<<"##                ##"<<endl;
                cout<<"##   GAME OVER!   ##"<<endl;
                cout<<"##                ##"<<endl;
                cout<<"##                ##"<<endl;
                cout<<"####################"<<endl;
                cout<<endl;
                system("pause");
                system("cls");
                main();
                if(escolhas==1){
                    goto sair;
                }
                perdeu=false;
            }
            switch(nivel){
            case 1:
                Sleep(500); // atraso de 1/2 segundo
                break;
            case 2:
                Sleep(250); // atraso de 1/4 de segundo
                break;
            case 3:
                Sleep(75);  // atraso muito pequeno
                break;
            default:
                 system("cls");
                 cout<<"Esse nivel nao e valido!"<<endl;
                 cout<<"Escolha novamente"<<endl;
                 cout<<endl;
                 goto volta2;
            }
        }
        break;
    case 1:
        sair:
        system("cls");
        return 0;
    default:
        system("cls");
        cout<<"E necessario inserir 0 para iniciar ou 1 para sair!"<<endl;
        cout<<"informe um nivel valido"<<endl;
        cout<<endl;
        goto volta3;
    }
    return 0;
}

void configuracao(){ // funcao responsavel pelas configuracoes iniciais do jogo

    x=largura/2; // a cabeca da cobra inicia centralizada em x
    y=altura/2;  // a cabeca da cobra inicia centralizada em y
    frutaX=(rand()%(largura-3))+1; // gera uma coordenada aleatoria em x para a fruta
    frutaY=(rand()%(altura-3))+1;  // gera uma coordenada aleatoria em y para a fruta
    extraX=(rand()%(largura-3))+1; // gera uma coordenada aleatoria em x para a fruta extra
    extraY=(rand()%(altura-3))+1;  // gera uma coordenada aleatoria em y para a fruta extra
    contarCauda=0; //o crescimento da cauda comeca em 0
    pos=parar; // a cabeca da cobra comeca parada
    pontos=0; // o jogo inicia com a pontuacao zerada
    tempo=0; // o tempo da fruta extra inicia zerado, porque o jogador ainda nao esta com a pontuacao adequada
    tesquer=false;
    tdireita=false;
    tcima=false;
    tbaixo=false;
}

void desenho(){ // funcao responsavel pela parte visual do jogo

    system("cls"); // limpa a tela
    cout<<"pontuacao: "<<pontos<<endl; // mostra a pontuacao
    cout<<"tempo da fruta extra: "<<tempo<<endl; // mostra o tempo da fruta extra
    cout<<endl;
    for(int i=0; i<largura+1; i++){ // mostra os quadrados da parte de cima da matriz
        cout<<char(176);
    }
    // percorre a matriz do jogo
    for(int i=0; i<altura; i++){
        for(int j=0; j<largura; j++){
            //formacao das paredes da matriz do jogo
            if(j==0 || j==largura-1){         // colocar um quadrado na primeira e na ultima posicao de cada linha
                if(i!=0){
                    cout<<char(176);
                }
            }
            if(j==x && i==y){                 //desenha a cabeca da cobra na posicao indicada por suas coordenadas
                cout<<char(219);
            }else if(j==frutaX && i==frutaY){ //desenha a fruta na posicao indicada por suas coordenadas
                cout<<char(184);
            }else if(pontos!=0 && pontos%50==0 && tempo<=50 && acabouFextra==false && j==extraX && i==extraY){  /*  condicoes para a fruta extra aparecer
                                                                                                                   (a cada 50 pontos, a contagem ser menor que 50 e a contagem nao ter estourado)
                                                                                                                */
                    cout<<char(206);
                    tempo++;                        // contagem do tempo em que a fruta extra fica disponivel

            }else{                                  /* quando nao estiver desenhando a cabeca da cobra, a fruta, a fruta extra
                                                       é verificado se a cauda da cobra precisa ser desenhada caso não precise é
                                                       colocado um espaco vazio na posicao, pois isso preenche o campo em torno da cobra,
                                                       fruta e fruta extra com espacos vazios dando forma a matriz que sera percorrida
                                                    */

                mostrarCauda=false;                /* inicialmente nao precisa mostrar a cauda, porque pode ser que ela nao exista
                                                      ou nao esteja no momento
                                                   */
                for(int p=0; p<contarCauda; p++){
                    if(xCobra.cauda[p]==j && yCobra.cauda[p]==i){
                        cout<<char(219);             // desenha a cauda da cobra
                        mostrarCauda=true;           // foi necessario mostrar a cauda

                    }
                }

                if(mostrarCauda==false){           // coloca espacos vazios quando nao e preciso mostar a cobra, fruta e fruta extra

                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }
    for(int i=0; i<largura+1; i++){ // mostra os quadrados da parte de baixo da matriz do jogo
        cout<<char(176);
    }
    cout<<endl;
}

void entrada(){ // funcao responsavel por receber os comandos feitos no teclado
    if(kbhit()){ // verifica se alguma tecla foi acionada
        switch(getch()){ // identifica qual tecla foi acionada
        case 'a': // a tecla a direciona a cobra para a esquerda
            if(tdireita==true){    /*
                                   caso esteja se movimentando para a direita continua mesmo
                                   se o usuario pretender movimentar para a esquerda
                                   */
                pos=direita;
            }else{                // caso nao esteja se movendo para a direita atende o comando e se move para a esquerda
                pos=esquerda;
                tesquer=true;
            }
            if(tcima==true){      // se estava se movendo para cima para de se mover nessa posicao
                tcima=false;
            }
            if(tbaixo==true){     // se estava se movendo para baixo para de se mover nessa posicao
                tbaixo=false;
            }
            break;
        case 'd':
            if(tesquer==true){      /*
                                   caso esteja se movimentando para a esquerda continua mesmo
                                   se o usuario pretender movimentar para a direita
                                   */
               pos=esquerda;
            }else{                  // caso nao esteja se movendo para a esquerda atende o comando e se move para a direita
                pos=direita;
                tdireita=true;
            }
            if(tcima==true){        // se estava se movendo para cima para de se mover nessa posicao
                tcima=false;
            }
            if(tbaixo==true){       // se estava se movendo para baixo para de se mover nessa posicao
                tbaixo=false;
            }
            break;
        case 'w':
            if(tesquer==true){       // se estava se movendo para a esquerda para de se mover nessa posicao
                tesquer=false;
            }
            if(tdireita==true){      // se estava se movendo para a direita para de se mover nessa posicao
                tdireita=false;
            }
            if(tbaixo==true){      /*
                                   caso esteja se movimentando para baixo continua mesmo
                                   se o usuario pretender movimentar para cima
                                   */

                pos=baixo;
            }else{                 // caso nao esteja se movendo para baixo atende o comando e se move para cima
                pos=cima;
                tcima=true;
            }
            break;
        case 's':
            if(tesquer==true){      // se estava se movendo para a esquerda para de se mover nessa posicao
                tesquer=false;
            }
            if(tdireita==true){     // se estava se movendo para a direita para de se mover nessa posicao
                tdireita=false;
            }
            if(tcima==true){        /*
                                   caso esteja se movimentando para cima continua mesmo
                                   se o usuario pretender movimentar para baixo
                                   */
                pos=cima;
            }else{                 // caso nao esteja se movendo para cima atende o comando e se move para baixo
                pos=baixo;
                tbaixo=true;
            }
            break;
        case 'f':                   // finaliza a partida
            perdeu=true;
            break;
        case 'p':                   // paralisa o jogo
            system("pause");
            Sleep(1500);
            break;
        default:
            break;
        }
    }
}

void logica(){ // funcao responsavel
    //formacao da cauda
    int guardar1X, guardar1Y, guardar2X, guardar2Y;
    for(int i=0; i<=contarCauda; i++){
        if(i==0){ // analise do 1 fragmento da cauda
            guardar1X=xCobra.cauda[i]; // guarda a posicao em x do 1 fragmento da cauda
            guardar1Y=yCobra.cauda[i]; // guarda a posicao em y do 1 fragmento da cauda
            xCobra.cauda[i]=x;         // o 1 fragmento da cauda recebe a posicao em x da cabeca da cobra
            yCobra.cauda[i]=y;         // o 1 fragmento da cauda recebe a posicao em y da cabeca da cobra
        }else{
            guardar2X=xCobra.cauda[i]; // guarda a posicao em x de qualquer fragmento da cauda que nao seja o 1
            guardar2Y=yCobra.cauda[i]; // guarda a posicao em y de qualquer fragmento da cauda que nao seja o 1
            xCobra.cauda[i]=guardar1X; /* qualquer fragmento da cauda que nao seja o 1 recebe a posicao em x
                                          do fragmento anterior
                                        */
            yCobra.cauda[i]=guardar1Y;  /* qualquer fragmento da cauda que nao seja o 1 recebe a posicao em y
                                          do fragmento anterior
                                        */
            guardar1X=guardar2X;        /* a posicao em x do fragmento em analise e guardada para ser recebida pelo
                                           fragmento posterior
                                        */
            guardar1Y=guardar2Y;        /* a posicao em y do fragmento em analise e guardada para ser recebida pelo
                                           fragmento posterior
                                        */
        }
    }
    switch(pos){
    case esquerda: // para a cobra se mover para a esquerda e preciso decrementar os valores da linha
        x--;
        break;
    case direita:  // para a cobra se mover para a direita e preciso incrementar os valores da linha
        x++;
        break;
    case cima:     // para a cobra se mover para cima e preciso decrementar os valores da coluna
        y--;
        break;
    case baixo:    // para a cobra se mover para baixo e preciso incrementar os valores da coluna
        y++;
    }
// atravessa as paredes laterais

    if(x>=largura-1){ /* Se a coordenada em x da cabeca da cobra chegar ao fim de
                         uma linha da matriz esse sua coordenada retornara para o
                         inicio da linha
                      */
        x=0;
    }else if(x<0){     /* Se a coordenada em x da cabeca da cobra for menor que
                         a primeira posicao de uma linha da matriz esse sua coordenada
                         ira para o fim da linha
                      */
        x=largura-2;
    }
// atravessa as paredes de cima e de baixo

    if(y<=0){           /* Se a coordenada em y da cabeca da cobra for quase menor
                         ou igual a primeira posicao de uma coluna da matriz essa coor
                         denada ira para a ultima posicao da coluna
                        */
        y=altura-1;
    }else if(y>=altura){ /* Se a coordenada em y da cabeca da cobra chegar ao fim da
                            coluna da matriz essa coordenada ira para o inicio da co
                            luna
                        */
        y=1;
    }

// se a cabeca da cobra tocar o corpo o jogador sera derrotado
    for(int i=0; i<contarCauda; i++){
        if(xCobra.cauda[i]==x && yCobra.cauda[i]==y){
            Beep(250, 1000); //(frequencia, duracao) produz um som depois que a cobra tocar nela mesma
            perdeu=true;
        }
    }
// quando a cobra come a fruta
    if(x==frutaX && y==frutaY){
        if(tempo==0){           // a cobra comeu uma fruta quando nao tinha fruta extra no campo
            Beep(1000, 250);    //(frequencia, duracao) produz um som depois que a cobra comer uma fruta
            pontos+=10;         // incrementa a pontuacao, porque a cobra comeu a fruta

        }else{                  // como a variavel tempo nao esta em 0 a cobra comeu uma fruta quando a fruta extra esta no campo
            Beep(1000, 250);
            auxPontos+=10;      // acumula a pontuacao referente as frutas normais enquanto a fruta extra ainda esta no campo
        }
        contarCauda++;          // cada vez que a cobra come uma fruta a sua cauda cresce
        outraPos1:
        frutaX=(rand()%(largura-3))+1; // gera uma nova fruta com coordenadas x e y aleatorias
        frutaY=(rand()%(altura-3))+1;
        for(int i=0; i<contarCauda; i++){
            if(xCobra.cauda[i]==frutaX && yCobra.cauda[i]==frutaY)
                goto outraPos1;
        }
        acabouFextra=false;           // o tempo da fruta extra ainda nao terminou
    }
    if(pontos!=0 && pontos%50==0 && tempo<=50 && acabouFextra==false){ // verifica as condicoes para ter fruta extra no campo
         for(int i=0; i<contarCauda; i++){
                if(xCobra.cauda[i]==extraX && yCobra.cauda[i]==extraY){
                   gerarFrutaExtra();
                }
            }
        if(x==extraX && y==extraY){ // verifica se a cobra comeu uma fruta extra
            Beep(1000, 250);
            pontos+=20;             // recebe uma pontucao maior que o normal
            contarCauda++;          // incrementa a cauda
            tempo=0;                // zera o tempo da fruta extra, porque ela deve desaparecer tendo em vista que a cobra ja comeu
            outraPos2:
            extraX=(rand()%(largura-3))+1;  // gera uma posicao aleatoria para a nova fruta extra, mas ela so aparecera quando os criterios forem cumpridos
            extraY=(rand()%(altura-3))+1;
            for(int i=0; i<contarCauda; i++){
                if(xCobra.cauda[i]==extraX && yCobra.cauda[i]==extraY){
                    goto outraPos2;
                }
            }
        }
    }
    if(tempo>50){ // o tempo da fruta extra estourou, porque vai ate 50
        tempo=0;  // zera a variavel tempo
        pontos+=auxPontos; /*a variavel pontos recebe a pontuacao das frutas normais comidas durando o tempo em que a fruta extra
                            estava no campo
                            */
        auxPontos=0;
        acabouFextra=true;  // o tempo da fruta extra estar em jogo acabou
    }
}
void gerarFrutaExtra(){
    extraX=(rand()%(largura-3))+1; // gera uma coordenada aleatoria em x para a fruta extra
    extraY=(rand()%(altura-3))+1;  // gera uma coordenada aleatoria em y para a fruta extra
}

