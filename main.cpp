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
    clock_t start, end;
    start = clock();
    int cont=0;
    double secAdd=0;
    bool i = true;
    int qtd_reinicios=0;
    
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
            if(realizarBatalha(jogador, PilhaDeBatalha->Poketopo(), cont,secAdd)){
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
            qtd_reinicios++;
            while(!PilhaDeDerrotas.vazia()){
                pokemon x;
                PilhaDeDerrotas.desempilha(x);
                PilhaDeBatalha->empilha(x);
                delete PilhaDeBatalha;
                PilhaDeBatalha = new Pilha(1);
            }
            
        }
    }   
    
    cout << "contador de movimentos realizados pelo usuario: " << cont << endl;
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    time_taken = time_taken + secAdd;
    std::cout << "Time taken by program is : " << time_taken << " seconds" << std::endl;
    cout << "Quantidade de reinicios: " << qtd_reinicios << endl;
    return 0;
}
