// 10   nlv 50          mewtwo
// 9  - nvl 41-45 	    moltres, zapdos, articuno, dragonite, mew
// 8  - nvl 36-40 	    arcanine, gengar, gyarados, exeggutor, alakazam
// 7  - nvl 31-35	    snorlax, lapras, jolteon, flareon , vaporeon
// 6  - nvl 26-30       nidoking, pidgeot, machamp, rhydon, raichu
// 5  - nvl 21-25	    primeape, dragonair, rapidash, victreebel, muk
// 4  - nvl 16-20 	    onix, hitmonchan, hitmonlee, machoke, golduck
// 3  - nvl 11-15 		haunter, pidgeotto, rhyhorn, arbok, sandslash
// 2  - nvl 6-10 		geodude, nidoran, ekans, pikachu, mankey
// 1  - nvl 1-5 		caterpie, zubat, rattata, pidgey, weedle

//Ainda falta implementar: tipo dos pokemon, sistema de nivel, sistema de evolucao

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class pokemon {

private:
    int ID;   //ID de cada Pokemon
    int HP;    // Health Points
    int Att;    // Strenght Points
    int Def;
    int nvl;   // Nivel
    string nome;
    static int proxID;
    int XP;

public:
    pokemon();
    pokemon(string vnome, int vHP, int vAtt, int vDef, int vNvl); // Construtor Detalhado
    // Destrutor

    // Métodos Set
    void set_HP(int vHP);
    void set_Att(int vAtt);
    void set_nome(string vnome);
    void set_nvl(int vnvl);
    void set_XP(int vXP);
    void set_Def(int vDef);

    // Métodos Get
    int get_HP() const;
    int get_Att() const;
    string get_nome() const;
    int get_nvl() const;
    int get_ID() const;
    int get_XP() const;
    int get_Def() const;

    //Outros Métodos
    int realizarBatalha(pokemon &p1, pokemon &p2);
    pokemon escolhaUsuario();
    void imprime() const;
};

int pokemon::proxID = 1;

pokemon mewtwo("Mewtwo", 106, 110, 90, 50);
pokemon moltres("Moltres", 90, 100, 90, 45);
pokemon zapdos("Zapdos", 90, 90, 85, 44);
pokemon articuno("Articuno", 90, 85, 100, 43);
pokemon dragonite("Dragonite", 91, 100, 95, 42);
pokemon mew("Mew", 100, 100, 100, 41);

pokemon arcanine("Arcanine", 90, 110, 80, 40);
pokemon gengar("Gengar", 60, 110, 60, 39);
pokemon gyarados("Gyarados", 95, 125, 79, 38);
pokemon exeguttor("exeguttor", 95, 95, 85, 37);
pokemon alakazam("Alakazam", 70, 130, 50,36);

pokemon snorlax("Snorlax", 160, 100, 65, 35);
pokemon lapras("Lapras", 130, 95, 80, 34);
pokemon jolteon("Jolteon", 70, 100, 60, 33);
pokemon flareon("Flareon", 70, 100, 60, 32);
pokemon vaporeon("Vaporeon", 70, 100, 60, 31);

pokemon nidoking("Nidoking", 81, 98, 77, 30);
pokemon pidgeot("Pidgeot", 83, 92, 75, 29);
pokemon machamp("Machamp", 90, 94, 80, 28);
pokemon rhydon("Rhydon", 105, 90, 120, 27);
pokemon raichu("Raichu", 60, 88, 55, 26);

pokemon primeape("Primeape", 65, 89, 60, 25);
pokemon dragonair("Dragonair", 61, 84, 65, 24);
pokemon rapidash("Rapidash", 65, 87, 70, 23);
pokemon victreebel("Victreebel", 80, 87, 65, 22);
pokemon muk("Muk", 105, 80, 75, 21);

pokemon onix("Onix", 35, 70, 160, 20);
pokemon hitmonchan("Hitmochan", 50, 100, 53, 19);
pokemon hitmonlee("Hitmonlee", 50, 100, 79, 18);
pokemon machoke("Machoke", 80, 98, 70, 17);
pokemon golduck("Golduck", 80, 82, 78, 16);

pokemon haunter("Haunter", 45, 50, 45, 15);
pokemon pidgeotto("Pidgeotto", 63, 60, 55, 14);
pokemon rhyhorn("Rhyhorn", 80, 85, 95, 13);
pokemon arbok("Arbok", 60, 85, 69, 12);
pokemon sandslash("Sandslah", 75, 70, 90, 11);

pokemon geodude("Geodude", 40, 60, 100, 10);
pokemon nidoran("Nidoran", 46, 57, 40, 9);
pokemon ekans("Ekans", 35, 60, 44, 8);
pokemon pikachu("Pikachu", 35, 60, 44, 7);
pokemon mankey("Mankey", 40, 80, 35, 6);

pokemon caterpie("Caterpie", 45, 30, 35, 5);
pokemon zubat("Zubat", 40, 45, 35, 4);
pokemon rattata("Rattata", 30, 56, 35, 3);
pokemon pidgey("Pidgey", 40, 45, 40, 2);
pokemon weedle("Weedle", 40, 35, 30, 1);

pokemon charmander("Charmander", 39, 52, 43, 1);
pokemon squirtle("Squirtle", 44, 48, 65, 1);
pokemon bulbasaur("Bulbasaur", 45, 49, 49, 1);

pokemon::pokemon():ID(++proxID){
    nome = "Indefinido";
}

pokemon::pokemon(string vnome, int vHP, int vAtt, int vDef ,int vNvl){
    
    ID = proxID++;
    set_nome(vnome);
    set_HP(vHP);
    set_Att(vAtt);
    set_nvl(vNvl);
    set_XP(0);
    set_Def(vDef);
}

int pokemon::get_ID() const {
    return ID;
}

int pokemon::get_HP() const {
    return HP;
}

int pokemon::get_Att() const {
    return Att;
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

int pokemon::get_Def() const {
    return Def;
}

void pokemon::set_HP(int vHP) {
    HP = (vHP >= 0) ? vHP : 0;
}

void pokemon::set_Att(int vAtt) {
    Att = vAtt;
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

void pokemon::set_Def(int vDef) {
    Def = vDef;
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
            cout << endl << p1.get_nome() << " atacou com " << p1.get_Att() << " de dano!" << endl;
            hpP2 -= p1.get_Att();
        } else {
            cout << endl << p2.get_nome() << " atacou com " << p2.get_Att() << " de dano!" << endl;
            hpP1 -= p2.get_Att();
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
    cout << "Att: " << get_Att() << endl;
    cout << "Nivel: " << get_nvl() << endl; 
    cout << "Def: " << get_Def() << endl << endl;
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
            int r;
            topo = -1;
            empilha(mewtwo);
            
            r = aleatorio();
            switch(r){
                case 1: empilha(moltres);
                break;
                case 2: empilha(zapdos);
                break;
                case 3: empilha (articuno);
                break;
                case 4: empilha(dragonite);
                break;
                case 5: empilha(mew);
                break;
            }

            r = aleatorio();
            switch(r){
                case 1: empilha(arcanine);
                break;
                case 2: empilha(gengar);
                break;
                case 3: empilha (gyarados);
                break;
                case 4: empilha(exeguttor);
                break;
                case 5: empilha(alakazam);
                break;
            }

            r = aleatorio();
            switch(r){
                case 1: empilha(snorlax);
                break;
                case 2: empilha(lapras);
                break;
                case 3: empilha (jolteon);
                break;
                case 4: empilha(flareon);
                break;
                case 5: empilha(vaporeon);
                break;
            }

            r = aleatorio();
            switch(r){
                case 1: empilha(nidoking);
                break;
                case 2: empilha(pidgeot);
                break;
                case 3: empilha (machamp);
                break;
                case 4: empilha(rhydon);
                break;
                case 5: empilha(raichu);
                break;
            }

            r = aleatorio();
            switch(r){
                case 1: empilha(primeape);
                break;
                case 2: empilha(dragonair);
                break;
                case 3: empilha (rapidash);
                break;
                case 4: empilha(victreebel);
                break;
                case 5: empilha(muk);
                break;
            }

            r = aleatorio();
            switch(r){
                case 1: empilha(onix);
                break;
                case 2: empilha(hitmonchan);
                break;
                case 3: empilha (hitmonlee);
                break;
                case 4: empilha(machoke);
                break;
                case 5: empilha(golduck);
                break;
            }

            r = aleatorio();
            switch(r){
                case 1: empilha(haunter);
                break;
                case 2: empilha(pidgeotto);
                break;
                case 3: empilha (rhyhorn);
                break;
                case 4: empilha(arbok);
                break;
                case 5: empilha(sandslash);
                break;
            }

            r = aleatorio();
            switch(r){
                case 1: empilha(geodude);
                break;
                case 2: empilha(nidoran);
                break;
                case 3: empilha (ekans);
                break;
                case 4: empilha(pikachu);
                break;
                case 5: empilha(mankey);
                break;
            }

            r = aleatorio();
            switch(r){
                case 1: empilha(caterpie);
                break;
                case 2: empilha(zubat);
                break;
                case 3: empilha (rattata);
                break;
                case 4: empilha(pidgey);
                break;
                case 5: empilha(weedle);
                break;
            }

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

int aleatorio(){
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Gera um número aleatório entre 1 e 5
    int numeroAleatorio = std::rand() % 5 + 1;

    return numeroAleatorio;
}

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