// 10   nlv 50          mewtwo
// 9  - nvl 41-45 	    articuno, zapdos, moltres, dragonite, arcanine
// 8  - nvl 36-40 	    alakazam, gengar, gyarados, alakazam, gengar
// 7  - nvl 31-35	    jolteon, flareon , vaporeon, snorlax, lapras
// 6  - nvl 26-30       pidgeot, raichu, rhydon, machamp, nidoking
// 5  - nvl 21-25	    golduck, victreebel, rapidash, muk, primeape
// 4  - nvl 16-20 	    onix, , hitmonchan, hitmonlee, machoke, dragonair
// 3  - nvl 11-15 		pidgeotto, sandslash, arbok, haunter, rhyhorn
// 2  - nvl 6-10 		geodude, nidoran, ekans, pikachu, mankey
// 1  - nvl 1-5 		caterpie, zubat, rattata, pidgey, weedle

//Ainda falta implementar: tipo dos pokemon, sistema de nivel, sistema de evolucao

#include <iostream>
#include <windows.h>
using namespace std;

class pokemon {

private:
    int ID;   //ID de cada Pokemon
    int HP;    // Health Points
    int SP;    // Strenght Points
    int nvl;   // Nivel
    string nome;
    static int proxID;
    int XP;

public:
    pokemon();
    pokemon(string vnome, int vHP, int vSP, int vNvl); // Construtor Detalhado
    // Destrutor

    // Métodos Set
    void set_HP(int vHP);
    void set_SP(int vSP);
    void set_nome(string vnome);
    void set_nvl(int vnvl);
    void set_XP(int vXP);

    // Métodos Get
    int get_HP() const;
    int get_SP() const;
    string get_nome() const;
    int get_nvl() const;
    int get_ID() const;
    int get_XP() const;

    //Outros Métodos
    int realizarBatalha(pokemon &p1, pokemon &p2);
    pokemon escolhaUsuario();
    void imprime() const;
};

int pokemon::proxID = 1;

pokemon caterpie("caterpie", 20, 4, 2);
pokemon geodude("geodude", 30, 6, 5);
pokemon pidgeotto("pidgeotto", 50, 10, 8);
pokemon arbok("arbok", 70, 15, 13);
pokemon haunter("haunter", 90, 23, 20);
pokemon onix("onix", 100, 28, 25);
pokemon lapras("lapras", 120, 35, 35);
pokemon dragonite("dragonite", 140, 50, 50);
pokemon moltres("moltres", 180, 60, 70);
pokemon mewtwo("mewtwo", 200, 90, 100);

pokemon charmander("Charmander", 12, 200, 1);
pokemon squirtle("Squirtle", 20, 3, 1);
pokemon bulbasaur("Bulbasaur", 16, 4, 1);

pokemon::pokemon():ID(++proxID){
    nome = "Indefinido";
}

pokemon::pokemon(string vnome, int vHP, int vSP, int vNvl){
    
    ID = proxID++;
    set_nome(vnome);
    set_HP(vHP);
    set_SP(vSP);
    set_nvl(vNvl);
    set_XP(0);
}

int pokemon::get_ID() const {
    return ID;
}

int pokemon::get_HP() const {
    return HP;
}

int pokemon::get_SP() const {
    return SP;
}

string pokemon::get_nome() const {
    return nome;
}

int pokemon::get_nvl() const {
    return nvl;
}

int pokemon::get_XP() const {
    return XP;
}

void pokemon::set_HP(int vHP) {
    HP = (vHP >= 0) ? vHP : 0;
}

void pokemon::set_SP(int vSP) {
    SP = vSP;
}

void pokemon::set_nome(string vnome) {
    nome = vnome;
}

void pokemon::set_nvl(int vnvl) {
    nvl = vnvl;
}

void pokemon::set_XP(int vXP) {
    XP = vXP;
}


bool realizarBatalha(pokemon p1, pokemon p2) {
    int hpP1 = p1.get_HP();
    int hpP2 = p2.get_HP();

    while ((hpP1 > 0) && (hpP2 > 0)) {
        int atacante;

        cout << endl << "HP de " << p1.get_nome() << ": " << hpP1 << " / " << p1.get_HP() << endl;
        cout << "|";
        for(int i = 0; i<hpP1; i++) cout << "x";
        for(int i = 0; i<(p1.get_HP()-hpP1);i++) cout << "_";
        cout << "|" << endl;

        cout << endl << "HP de " << p2.get_nome() << ": " << hpP2 << " / " << p2.get_HP() << endl;
        cout << "|";
        for(int i = 0; i<hpP2; i++) cout << "x";
        for(int i = 0; i<(p2.get_HP()-hpP2);i++) cout << "_";
        cout << "|" << endl;

        cout << "Quem esta atacando? (1 para " << p1.get_nome() << " e 2 para " << p2.get_nome() << ")" << endl;
        cin >> atacante;

        if (atacante == 1) {
            cout << endl << p1.get_nome() << " atacou com " << p1.get_SP() << " de dano!" << endl;
            hpP2 -= p1.get_SP();
        } else {
            cout << endl << p2.get_nome() << " atacou com " << p2.get_SP() << " de dano!" << endl;
            hpP1 -= p2.get_SP();
        }
    }

    cout << endl;
    cout << "Fim da Batalha!" << endl;
    

    if (hpP1 <= 0) { 
        cout << p2.get_nome() << " venceu!" << endl ;
        
        cout << "Voce perdeu." << endl << endl;
        return false;
    } 
    else { //Vitoria do Usuario
        cout << p1.get_nome() << " venceu!" << endl;
        
        cout << "Voce venceu!" << endl << endl;
        return true;

    }
}

void pokemon::imprime() const {
    cout << "ID: " << get_ID() << endl;
    cout << "Nome: " << get_nome() << endl;
    cout << "HP: " << get_HP() << endl;
    cout << "SP: " << get_SP() << endl;
    cout << "Nivel: " << get_nvl() << endl << endl;
}

pokemon escolhaUsuario() {
    int escolha;
        
    do{
        cout << endl << "Escolha seu pokemon: " << endl
            << "Charmander (1)" << endl
            << "Squirtle (2)" << endl
            << "Bulbasaur (3)" << endl;

        cin >> escolha;

        if(escolha>=1 && escolha<=3){
            switch (escolha) {
                case 1: {
                    
                    cout << "Charmander foi escolhido!" << endl;
                    return charmander;
                }
                case 2: {
                    
                    cout << "Squirtle foi escolhido!" << endl;
                    return squirtle;
                }
                case 3: {
                    
                    cout << "Bulbasaur foi escolhido!" << endl;
                    return bulbasaur;
                }
            }        
        }else{
            cout << "escolha invalida. Tente novamente" << endl;
        }
    }while(escolha !=1 && escolha !=2 && escolha !=3);
}

class Pilha{
    public:
    pokemon adversario[10];
    int topo;

    public:
    
    pokemon Poketopo(){
        return adversario[topo];
    }

    Pilha(int x){
        if(x==1){ //criar pilha de batalha, parametro = 1
            topo = -1;
            empilha(mewtwo);
            empilha(moltres);
            empilha(dragonite);
            empilha(lapras);
            empilha(onix);
            empilha(haunter);
            empilha(arbok);
            empilha(pidgeotto);
            empilha(geodude);
            empilha(caterpie);
        }else{
            if(x==0){
                topo = -1; //cria pilha vazia, parametro = 0
            }
        }
    }

    bool cheia(){
        if(topo == 9){
            return true;
        }else{
            return false;
        }
    }
   
    bool vazia(){
        if(topo == -1){
            return true;
        }else{
            return false;
        }
    }
   
    bool empilha(pokemon X){
        if(cheia()==true){
            return false;
        }else{
            topo++;
            adversario[topo] = X;
            return true;
        }
    }

    bool desempilha(pokemon &X){
        if(vazia()==true){
            return false;
        }else{
            X = adversario[topo];
            topo--;
            return true;
        }
    }


};

int main() {
    bool i = true;
    
    cout << "Seja bem vindo a torre de batalha pokemon, comece escolhendo o pokemon que ira te acompanhar nas batalhas" << endl;

    pokemon jogador = escolhaUsuario();

    cout << endl;
  
    cout << "O jogo funciona da seguinte forma: existem 10 pokemons em uma torre de batalha, voce ira batalhar com cada um deles ate conseguir derrotar o chefe final" << endl;    
    cout << "Toda vez que seu pokemon for derrotado a torre sera resetada para voce tentar novamente" << endl;    
    cout << "Boa sorte!" << endl;
    
    
    Pilha PilhaDeBatalha(1);
    Pilha PilhaDeDerrotas(0);
 
    while(i){
        while(!PilhaDeBatalha.vazia()){
            if(realizarBatalha(jogador, PilhaDeBatalha.Poketopo())){
                pokemon derrotado;
                PilhaDeBatalha.desempilha(derrotado);
                PilhaDeDerrotas.empilha(derrotado);
            }else
                break;
        }

        if(PilhaDeBatalha.vazia()){
            cout << "Parabens. Voce ganhou o jogo!!" << endl;
            i = false;
        }else{
            cout << "Resetando torre de batalha..." << endl;
            while(!PilhaDeDerrotas.vazia()){
                pokemon x;
                PilhaDeDerrotas.desempilha(x);
                PilhaDeBatalha.empilha(x);
            }
            
        }
    }   
    
    
    return 0;
}