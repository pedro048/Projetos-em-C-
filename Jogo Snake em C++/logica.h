#ifndef LOGICA_H
#define LOGICA_H

#endif // LOGICA_H

void logica(){ // metodo responsavel pela formação da cauda

    int guardar1X, guardar1Y, guardar2X, guardar2Y;
    for(int i=0; i<=contarCauda; i++){
        if(i==0){ // analise do 1 fragmento da cauda
            guardar1X=caudax[i]; // guarda a posicao em x do 1 fragmento da cauda
            guardar1Y=cauday[i]; // guarda a posicao em y do 1 fragmento da cauda
            caudax[i]=x;         // o 1 fragmento da cauda recebe a posicao em x da cabeca da cobra
            cauday[i]=y;         // o 1 fragmento da cauda recebe a posicao em y da cabeca da cobra
        }else{
            guardar2X=caudax[i]; // guarda a posicao em x de qualquer fragmento da cauda que nao seja o 1
            guardar2Y=cauday[i]; // guarda a posicao em y de qualquer fragmento da cauda que nao seja o 1
            caudax[i]=guardar1X; /* qualquer fragmento da cauda que nao seja o 1 recebe a posicao em x
                                          do fragmento anterior
                                        */
            cauday[i]=guardar1Y;  /* qualquer fragmento da cauda que nao seja o 1 recebe a posicao em y
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
        if(caudax[i]==x && cauday[i]==y){
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
            if(caudax[i]==frutaX && cauday[i]==frutaY)
                goto outraPos1;
        }
        acabouFextra=false;           // o tempo da fruta extra ainda nao terminou
    }
    if(pontos!=0 && pontos%50==0 && tempo<=50 && acabouFextra==false){ // verifica as condicoes para ter fruta extra no campo
         for(int i=0; i<contarCauda; i++){
                if(caudax[i]==extraX && cauday[i]==extraY){
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
                if(caudax[i]==extraX && cauday[i]==extraY){
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
