#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>

#include "funcoes.h"
#include "classes.h"
#include "global_objects.h"

using namespace std;


int main() {
    
    bool i = true;
    
    cout << "Seja bem vindo a torre de batalha pokemon, comece escolhendo o pokemon que ira te acompanhar nas batalhas" << endl;

    pokemon jogador = escolhaUsuario();

    cout << endl;
  
    cout << "O jogo funciona da seguinte forma: existem 10 pokemons em uma torre de batalha, voce ira batalhar com cada um deles ate conseguir derrotar o chefe final" << endl;    
    cout << "Toda vez que seu pokemon for derrotado a torre sera resetada para voce tentar novamente" << endl;    
    cout << "Boa sorte!" << endl;
    
    Pilha *PilhaDeBatalha = new Pilha(1);
    Pilha PilhaDeDerrotas(0);
 
    while(i){
        while(!PilhaDeBatalha->vazia()){
            if(realizarBatalha(jogador, PilhaDeBatalha->Poketopo())){
                pokemon derrotado;
                PilhaDeBatalha->desempilha(derrotado);
                PilhaDeDerrotas.empilha(derrotado);
            }else
                break;
        }

        if(PilhaDeBatalha->vazia()){
            cout << "Parabens. Voce ganhou o jogo!!" << endl;
            i = false;
        }else{
            cout << "Resetando torre de batalha..." << endl;
            while(!PilhaDeDerrotas.vazia()){
                pokemon x;
                PilhaDeDerrotas.desempilha(x);
                PilhaDeBatalha->empilha(x);
                delete PilhaDeBatalha;
                PilhaDeBatalha = new Pilha(1);
            }
            
        }
    }   
    
    
    return 0;
}
