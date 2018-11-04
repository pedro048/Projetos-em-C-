#ifndef ENTRADA_H
#define ENTRADA_H

#endif // ENTRADA_H

void entrada(){ // metodo responsavel por receber os comandos feitos no teclado

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
