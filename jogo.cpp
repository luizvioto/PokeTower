#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>

using namespace std;

int aleatorio(int x, int y);
int critico() {
    // Configurar o gerador de números aleatórios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    // Gerar um número aleatório entre 0 e 1
    double randomValue = dis(gen);

    // Determinar o valor com base na probabilidade desejada
    if (randomValue < 0.0625) {
        return 2; // 6,25% de chance
    } else {
        return 1; // 93,75% de chance
    }
}
int efetivo(ataque a, pokemon p){
    int i, j;
    string tipo_ataque, tipo_poke;
    tipo_ataque = a.get_nome();
    tipo_poke = p.get_nome();
    
    if(tipo_ataque == "Normal") i = 0;
    else if(tipo_ataque == "Fogo") i = 1;
    else if(tipo_ataque == "Agua") i = 2;
    else if(tipo_ataque == "Eletrico") i = 3;
    else if(tipo_ataque == "Grama") i = 4;
    else if(tipo_ataque == "Gelo") i = 5;
    else if(tipo_ataque == "Lutador") i = 6;
    else if(tipo_ataque == "Venenoso") i = 7;
    else if(tipo_ataque == "Terrestre") i = 8;
    else if(tipo_ataque == "Voador") i = 9;
    else if(tipo_ataque == "Psiquico") i = 10;
    else if(tipo_ataque == "Inseto") i = 11;
    else if(tipo_ataque == "Pedra") i = 12;
    else if(tipo_ataque == "Fantasma") i = 13;
    else if(tipo_ataque == "Dragao") i = 14;
    else if(tipo_ataque == "Sombrio") i = 15;
    else if(tipo_ataque == "Metal") i = 16;

    if(tipo_poke == "Normal") j = 0;
    else if(tipo_poke == "Fogo") j = 1;
    else if(tipo_poke == "Agua") j = 2;
    else if(tipo_poke == "Eletrico") j = 3;
    else if(tipo_poke == "Grama") j = 4;
    else if(tipo_poke == "Gelo") j = 5;
    else if(tipo_poke == "Lutador") j = 6;
    else if(tipo_poke == "Venenoso") j = 7;
    else if(tipo_poke == "Terrestre") j = 8;
    else if(tipo_poke == "Voador") j = 9;
    else if(tipo_poke == "Psiquico") j = 10;
    else if(tipo_poke == "Inseto") j = 11;
    else if(tipo_poke == "Pedra") j = 12;
    else if(tipo_poke == "Fantasma") j = 13;
    else if(tipo_poke == "Dragao") j = 14;
    else if(tipo_poke == "Sombrio") j = 15;
    else if(tipo_poke == "Metal") j = 16;
    
    
    
    
    float tabela[17][17] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0, 1, 1, 0.5},
        {1, 0.5, 0.5, 1, 2, 2, 1, 1, 1, 1, 1, 2, 0.5, 1, 0.5, 1, 2},
        {1, 2, 0.5, 1, 0.5, 1, 1, 1, 2, 1, 1, 1, 2, 1, 0.5, 1, 1},
        {1, 1, 2, 0.5, 0.5, 1, 1, 1, 0, 2, 1, 1, 1, 1, 0.5, 1, 1},
        {1, 0.5, 2, 1, 0.5, 1, 1, 0.5, 2, 0.5, 1, 0.5, 2, 1, 0.5, 1, 0.5},
        {1, 0.5, 0.5, 1, 2, 0.5, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, 0.5},
        {2, 1, 1, 1, 1, 2, 1, 0.5, 1, 0.5, 0.5, 0.5, 2, 0, 1, 2, 2},
        {1, 1, 1, 1, 2, 1, 1, 0.5, 0.5, 1, 1, 1, 0.5, 0.5, 1, 1, 0},
        {1, 2, 1, 2, 0.5, 1, 1, 2, 1, 0, 1, 0.5, 2, 1, 1, 1, 2},
        {1, 1, 1, 0.5, 2, 1, 2, 1, 1, 1, 1, 2, 0.5, 1, 1, 1, 0.5},
        {1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 0.5, 1, 1, 1, 1, 0, 0.5},
        {1, 0.5, 1, 1, 2, 1, 0.5, 0.5, 1, 0.5, 2, 1, 1, 0.5, 1, 2, 0.5},
        {1, 2, 1, 1, 1, 2, 0.5, 1, 0.5, 2, 1, 2, 1, 1, 1, 1, 0.5},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 0.5, 0.5},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 0.5},
        {1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 2, 1, 1, 2, 1, 0.5, 0.5},
        {1, 0.5, 0.5, 0.5, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0.5},
    };

    return tabela[i][j];

}


class ataque {
private:
    string nome;
    int poder;
    string tipo_ataque;

public:
    ataque(){
        nome = "indefinido";
        poder = 0;
        tipo_ataque = "nenhum";
    }
    
    ataque (string vNome, int vPoder, string vTipo_ataque) {
        set_nome(vNome);
        set_poder(vPoder);
        set_tipo_ataque(vTipo_ataque);
    }

    
    
    void set_nome(string vnome){
        nome = vnome;
    }

    void set_poder(int vpoder){
        poder = vpoder;
    }

    void set_tipo_ataque(string vtipo_ataque){
        tipo_ataque = vtipo_ataque;
    }


    string get_nome() const{
        return nome;
    }

    int get_poder() const{
        return poder;
    }

    string get_tipo_ataque() const{
        return tipo_ataque;
    }
}; 

ataque psychic("Psiquico", 40, "Psiquico");
ataque shadowball("Shadow Ball", 40, "Fantasma");
ataque flamethrower("Flamethrower", 40, "Fogo");
ataque hurricane("Hurricane", 40, "Voador");
ataque thunderbolt("Thunderbolt", 40, "Eletrico");
ataque drillpeck("Drill Peck", 40, "Voador");
ataque icebeam("Ice Beam", 40, "Gelo");
ataque outrage("Outrage", 40, "Dragao");
ataque aurasphere("Aura Sphere", 40, "Lutador");
ataque crunch("Crunch", 40, "Sombrio");
ataque hydropump("Hydro Pump", 40, "Agua");
ataque dragonpulse("Dragon Pulse", 40, "Dragao");
ataque solarbeam("Solar Beam", 40, "Grama");
ataque focusblast("Focus Blast", 40, "Lutador");
ataque bodyslam("Body Slam", 40, "Normal");
ataque hyperbeam("Hyper Beam", 40, "Normal");
ataque surf("Surf", 40, "Agua");
ataque aquatail("Aqua Tail", 40, "Agua");
ataque earthquake("Earthquake", 40, "Terrestre");
ataque stoneedge("Stone Edge", 40, "Pedra");
ataque brickbreak("Brick Break", 40, "Lutador");
ataque closecombat("Close Combat", 40, "Lutador");
ataque crosschop("Cross Chop", 40, "Lutador");
ataque highjumpkick("High Jump Kick", 40, "Lutador");
ataque blazekick("Blaze Kick", 40, "Fogo");
ataque dynamicpunch("Dynamic Punch", 40, "Lutador");
ataque gunkshot("Gunk Shot", 40, "Venenoso");
ataque sludgewave("Sludge Wave", 40, "Venenoso");
ataque twister("Twister", 40, "Voador");
ataque poisonfang("Poison Fang", 40, "Venenoso");
ataque hyperfang("Hyper Fang", 40, "Normal");
ataque quickattack("Quick Attack", 40, "Normal");
ataque tackle("Tackle", 40, "Normal");
ataque ember("Ember", 40, "Fogo");
ataque watergun("Water Gun", 40, "Agua");
ataque vinewhip("Vine Whip", 40, "Grama");
ataque fireblast("Fire Blast", 40, "Fogo");
ataque airslash("Air Slash", 40, "Voador");
ataque irontail("Iron Tail", 40, "Metal");
ataque bugbite("Bug Bite", 40, "Inseto");
ataque poisonsting("Poison Sting", 40, "Venenoso");
ataque wingattack("Wing Attack", 40, "Voador");
ataque scratch("Scratch", 40, "Normal");
ataque razorleaf("Razor Leaf", 40, "Grama");
ataque seedbomb("Seed Bomb", 40, "Grama");
ataque bite("Bite", 40, "Sombrio");
ataque sludgebomb("Sludge Bomb", 40, "Venenoso");
ataque aerialace("Aerial Ace", 40, "Voador");
ataque poisonjab("Poison Jab", 40, "Venenoso");
ataque darkpulse("Dark Pulse", 40, "Sombrio");
ataque hornattack("Horn Attack", 40, "Normal");
ataque rockslide("Rock Slide", 40, "Pedra");
ataque icepunch("Ice Punch", 40, "Gelo");
ataque drillrun("Drill Run", 40, "Terrestre");
ataque leafblade("Leaf Blade", 40, "Grama");
ataque dragonclaw("Dragon Claw", 40, "Dragao");



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
    int speed;
    string tipo; //fogo, agua, planta, eletrico, pedra, fantasma, dragao, gelo, lutador, normal, grama, inseto, voador, venenoso, terrestre, sombrio, metal, psiquico
    ataque a1;
    ataque a2;


public:
    pokemon();
    pokemon(string vnome, int vHP, int vAtt, int vDef, int vNvl, int vSpeed, string vTipo, ataque a1, ataque a2); // Construtor Detalhado
    // Destrutor

    // Métodos Set
    void set_HP(int vHP);
    void set_Att(int vAtt);
    void set_nome(string vnome);
    void set_nvl(int vnvl);
    void set_XP(int vXP);
    void set_Def(int vDef);
    void set_speed(int vSpeed);
    void set_tipo(string vTipo);
    void set_a1(ataque va1);
    void set_a2(ataque va2);

    // Métodos Get
    int get_HP() const;
    int get_Att() const;
    string get_nome() const;
    int get_nvl() const;
    int get_ID() const;
    int get_XP() const;
    int get_Def() const;
    int get_speed() const;
    string get_tipo() const;
    ataque get_a1() const;
    ataque get_a2() const;


    //Outros Métodos
    void imprime() const;
    void ganhaXP(int vXP);
    void incrementaNvl();
};

int pokemon::proxID = 1;

  
    pokemon mewtwo("Mewtwo", 106, 110, 90, 50, 130, "Psiquico",psychic,shadowball);
    pokemon moltres("Moltres", 90, 100, 90, 45, 90,"Fogo",flamethrower,hurricane);
    pokemon zapdos("Zapdos", 90, 90, 85, 44, 100,"Eletrico",thunderbolt,drillpeck);
    pokemon articuno("Articuno", 90, 85, 100, 43, 85,"Gelo",icebeam,hurricane);
    pokemon dragonite("Dragonite", 91, 100, 95, 42, 80,"Dragao",dragonclaw,outrage);
    pokemon mew("Mew", 100, 100, 100, 41, 100,"Psiquico",psychic,aurasphere);

    pokemon arcanine("Arcanine", 90, 110, 80, 40, 95,"Fogo",flamethrower,crunch);
    pokemon gengar("Gengar", 60, 110, 60, 39, 110,"Fantasma",shadowball,sludgebomb);
    pokemon gyarados("Gyarados", 95, 125, 79, 38, 81,"Agua",hydropump,dragonpulse);
    pokemon exegguttor("Exegguttor", 95, 95, 85, 37, 55,"Grama",psychic,solarbeam);
    pokemon alakazam("Alakazam", 70, 130, 50, 36, 120,"Psiquico",psychic,focusblast);

    pokemon snorlax("Snorlax", 160, 100, 65, 35, 30,"Normal",bodyslam,hyperbeam);
    pokemon lapras("Lapras", 130, 95, 80, 34, 60,"Agua",icebeam,surf);
    pokemon jolteon("Jolteon", 70, 100, 60, 33, 130,"Eletrico",thunderbolt,shadowball);
    pokemon flareon("Flareon", 70, 100, 60, 32, 65,"Fogo",flamethrower,fireblast);
    pokemon vaporeon("Vaporeon", 70, 100, 60, 31, 65,"Agua",hydropump,aquatail);

    pokemon nidoking("Nidoking", 81, 98, 77, 30, 85,"Venenoso",earthquake,poisonjab);
    pokemon pidgeot("Pidgeot", 83, 92, 75, 29, 101,"Voador",aerialace,hurricane);
    pokemon machamp("Machamp", 90, 94, 80, 28, 55,"Lutador",dynamicpunch,crosschop);
    pokemon rhydon("Rhydon", 105, 90, 120, 27, 40,"Terrestre",earthquake,stoneedge);
    pokemon raichu("Raichu", 60, 88, 55, 26, 110,"Eletrico",thunderbolt,brickbreak);

    pokemon primeape("Primeape", 65, 89, 60, 25, 95,"Lutador",closecombat,crosschop);
    pokemon dragonair("Dragonair", 61, 84, 65, 24, 70,"Dragao",dragonpulse,aquatail);
    pokemon rapidash("Rapidash", 65, 87, 70, 23, 105,"Fogo",fireblast,drillrun);
    pokemon victreebel("Victreebel", 80, 87, 65, 22, 70,"Grama",leafblade,sludgebomb);
    pokemon muk("Muk", 105, 80, 75, 21, 50,"Venenoso",gunkshot,sludgewave);

    pokemon onix("Onix", 35, 70, 160, 20, 70,"Pedra",earthquake,stoneedge);
    pokemon hitmonchan("Hitmochan", 50, 100, 53, 19, 76,"Lutador",closecombat,icepunch);
    pokemon hitmonlee("Hitmonlee", 50, 100, 79, 18, 87,"Lutador",highjumpkick,blazekick);
    pokemon machoke("Machoke", 80, 98, 70, 17, 45,"Lutador",dynamicpunch,crosschop);
    pokemon golduck("Golduck", 80, 82, 78, 16, 85, "Agua",surf,icebeam);

    pokemon haunter("Haunter", 45, 50, 45, 15, 95,"Fantasma",shadowball,sludgebomb);
    pokemon pidgeotto("Pidgeotto", 63, 60, 55, 14, 71,"Voador",aerialace,twister);
    pokemon rhyhorn("Rhyhorn", 80, 85, 95, 13, 25,"Terrestre",earthquake,stoneedge);
    pokemon arbok("Arbok", 60, 85, 69, 12, 80,"Venenoso",gunkshot,earthquake);
    pokemon sandslash("Sandslash", 75, 70, 90, 11, 65,"Terrestre",earthquake,stoneedge);

    pokemon geodude("Geodude", 40, 60, 100, 10, 20,"Pedra",earthquake,rockslide);
    pokemon nidoran("Nidoran", 46, 57, 40, 9, 40,"Venenoso",poisonjab,hornattack);
    pokemon ekans("Ekans", 35, 60, 44, 8, 55,"Venenoso",poisonjab,darkpulse);
    pokemon pikachu("Pikachu", 35, 60, 44, 7, 90,"Eletrico",thunderbolt,irontail);
    pokemon mankey("Mankey", 40, 80, 35, 6, 70,"Lutador",closecombat,crosschop);

    pokemon caterpie("Caterpie", 45, 30, 35, 5, 42,"Inseto",bugbite,tackle);
    pokemon zubat("Zubat", 40, 45, 35, 4, 55, "Venenoso",wingattack,poisonfang);
    pokemon rattata("Rattata", 30, 56, 35, 3, 72,"Normal",hyperfang,quickattack);
    pokemon pidgey("Pidgey", 40, 45, 40, 2, 56, "Voador",twister,aerialace);
    pokemon weedle("Weedle", 40, 35, 30, 1, 50,"Inseto",bugbite,poisonsting);

    pokemon charizard("Charizard", 100, 200, 10000, 32, 65,"Fogo",fireblast,airslash);
    pokemon blastoise("Blastoise", 79, 83, 100, 32, 78,"Agua",hydropump,icebeam);
    pokemon venusaur("Venusaur", 80, 82, 83, 32, 80,"Grama",solarbeam,sludgebomb);

    pokemon charmeleon("Charmeleon", 100, 200, 10000, 15, 65,"Fogo",flamethrower,dragonclaw);
    pokemon wartortle("Wartortle", 59, 63, 80, 15, 58,"Agua",aquatail,bite);
    pokemon ivysaur("Ivysaur", 60, 62, 63, 15, 60,"Grama",razorleaf,seedbomb);

    pokemon charmander("Charmander", 100, 200, 10000, 14, 65,"Fogo",ember,scratch);
    pokemon squirtle("Squirtle", 44, 48, 65, 1, 43,"Agua",watergun,tackle);
    pokemon bulbasaur("Bulbasaur", 45, 49, 49, 1, 45,"Grama",vinewhip,tackle);



pokemon::pokemon():ID(++proxID){
    nome = "Indefinido";
}

pokemon::pokemon(string vnome, int vHP, int vAtt, int vDef , int vNvl, int vSpeed, string vTipo, ataque va1, ataque va2){
    
    ID = proxID++;
    set_nome(vnome);
    set_HP(vHP);
    set_Att(vAtt);
    set_nvl(vNvl);
    set_XP(0);
    set_Def(vDef);
    set_speed(vSpeed);
    set_tipo(vTipo);
    set_a1(va1);
    set_a2(va2);
    
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

int pokemon::get_speed() const {
    return speed;
}

string pokemon::get_tipo() const {
    return tipo;
}

ataque pokemon::get_a1() const{
    return a1;
}
ataque pokemon::get_a2() const{
    return a2;
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

void pokemon::set_speed(int vSpeed) {
    speed = vSpeed;
}

void pokemon::set_tipo(string vTipo) {
    tipo = vTipo;
}

void pokemon::set_a1(ataque va1){
    a1 = va1;
}
void pokemon::set_a2(ataque va2){
    a2 = va2;
}

void pokemon::incrementaNvl(){
    nvl++;
}

bool realizarBatalha(pokemon &p1, pokemon p2) {
    int rand;
    
    int hpP1 = p1.get_HP();
    int hpP2 = p2.get_HP();

    while ((hpP1 > 0) && (hpP2 > 0)) {
        int maisRapido;
        int poder_atk_adv, poder_atk, atk_escolhido;
        maisRapido = (p1.get_speed() >= p2.get_speed()) ? 1 : 2;

        int dano; // (((2*NVL*ATT)/DEF)/50 + 2) * multiplicador aleatorio(de 0.85 a 1.00) * multiplicador de tipo(0.5, 1.0 ou 2.0) -> antigo
                  // ((2*nivel*critico)/5 + 2) * 40 * att do usuario/def do adversario -> novo
                  //critico - > 6,25% de chance de ser 2, senao, 1

        if (maisRapido == 1) {
            cout << "Selecione o ataque de " << p1.get_nome() << " :" << endl;
            cout << p1.get_a1().get_nome() << "(1)" << endl << p1.get_a2().get_nome() << "(2)" << endl;
            cin >> atk_escolhido;
            if(atk_escolhido == 1)
                poder_atk = p1.get_a1().get_poder();
            else
                poder_atk = p1.get_a2().get_poder();

            dano = (((((2 * p1.get_nvl() * 1)/5) +2) * 40 * (p1.get_Att()/p2.get_Def()))/50) + 2 + poder_atk/2;
            cout << endl << p1.get_nome() << " atacou com " << dano << " de dano!" << endl;
            hpP2 -= dano;
            if(hpP2<0) hpP2 = 0;

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

            cout << ".";
            //Sleep(1000);
            cout << ".";
            //Sleep(1000);
            cout << ".";
            //Sleep(1000);
            cout << endl;

            if(hpP2 > 0) {
                rand = aleatorio(1, 2);
                if(rand==1){
                    poder_atk_adv = p2.get_a1().get_poder();
                }else{
                    poder_atk_adv = p2.get_a2().get_poder();
                }
                dano = (((((2 * p2.get_nvl() * 1)/5) +2) * 40 * (p2.get_Att()/p1.get_Def()))/50) + 2 + poder_atk_adv/2;
                cout << endl << p2.get_nome() << " atacou com " << dano << " de dano!" << endl;
                hpP1 -= dano;
                if(hpP1<0) hpP1 = 0;
                cout << ".";

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
                
                cout << ".";
                //Sleep(1000);
                cout << ".";
                //Sleep(1000);
                cout << ".";
                //Sleep(1000);
                cout << endl;
            }
        } 
        
        else {
            rand = aleatorio(1, 2);
                if(rand==1){
                    poder_atk_adv = p2.get_a1().get_poder();
                }else{
                    poder_atk_adv = p2.get_a2().get_poder();
                }
            
            dano = (((((2 * p2.get_nvl() * 1)/5) +2) * 40 * (p2.get_Att()/p1.get_Def()))/50) + 2 + poder_atk_adv/2;
            cout << endl << p2.get_nome() << " atacou com " << dano << " de dano!" << endl;
            hpP1 -= dano;
            if(hpP1<0) hpP1 = 0;

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

            cout << ".";
            //Sleep(1000);
            cout << ".";
            //Sleep(1000);
            cout << ".";
            //Sleep(1000);
            cout << endl;

            if(hpP1 > 0) {
                cout << "Selecione o ataque de " << p1.get_nome() << " :" << endl;
                cout << p1.get_a1().get_nome() << "(1)" << endl << p1.get_a2().get_nome() << "(2)" << endl;
                cin >> atk_escolhido;
                if(atk_escolhido == 1)
                    poder_atk = p1.get_a1().get_poder();
                else
                    poder_atk = p1.get_a2().get_poder();

                dano = (((((2 * p1.get_nvl() * 1)/5) +2) * 40 * (p1.get_Att()/p2.get_Def()))/50) + 2 + poder_atk/2;
                cout << endl << p1.get_nome() << " atacou com " << dano << " de dano!" << endl;
                hpP2 -= dano;
                if(hpP2<0) hpP2 = 0;
                cout << ".";

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
                
                cout << ".";
                //Sleep(1000);
                cout << ".";
                //Sleep(1000);
                cout << ".";
                //Sleep(1000);
                cout << endl;
            }
        }
    }

    cout << endl;
    cout << "Fim da Batalha!" << endl;
    

    if (hpP1 <= 0) { 
        cout << p2.get_nome() << " venceu!" << endl ;

        int reiniciar;
        do {
        cout << "Digite (1) para reiniciar o desafio!" << endl;
        cin >> reiniciar;
        } while(reiniciar != 1);

        cout << "Reiniciando o desafio";
        cout << ".";
        //Sleep(2000);
        cout << ".";
        //Sleep(2000);
        cout << ".";
        //Sleep(2000);
        
        return false;
    }

    else { //Vitoria do Usuario
        cout << p1.get_nome() << " venceu!" << endl;

        int XPganho = (p2.get_Att() + p2.get_Def())/20 + p2.get_nvl();
        p1.ganhaXP(XPganho);
        
        if(p1.get_nvl()==15){
            if(p1.get_nome() == "Charmander"){
                //Sleep(1000);
                cout << "Seu pokemon esta evoluindo!!" << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << p1.get_nome() << " evoluiu para";
                p1 = charmeleon;
                cout << " " << p1.get_nome() << "!!\n";
            }
            if(p1.get_nome() == "Bulbasaur"){
                //Sleep(1000);
                cout << "Seu pokemon esta evoluindo!!" << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << p1.get_nome() << " evoluiu para";
                p1 = ivysaur;
                cout << " " << p1.get_nome() << "!!\n";
            }
            if(p1.get_nome() == "Squirtle"){
                //Sleep(1000);
                cout << "Seu pokemon esta evoluindo!!" << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << p1.get_nome() << " evoluiu para";
                p1 = wartortle;
                cout << " " << p1.get_nome() << "!!\n";
            }
        }

        if(p1.get_nvl()==32){
            if(p1.get_nome() == "Charmeleon"){
                //Sleep(1000);
                cout << "Seu pokemon esta evoluindo!!" << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << p1.get_nome() << " evoluiu para";
                p1 = charizard;
                cout << " " << p1.get_nome() << "!!\n";
            }
            if(p1.get_nome() == "Ivysaur"){
                //Sleep(1000);
                cout << "Seu pokemon esta evoluindo!!" << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << p1.get_nome() << " evoluiu para";
                p1 = venusaur;
                cout << " " << p1.get_nome() << "!!\n";
            }
            if(p1.get_nome() == "Wartortle"){
                //Sleep(1000);
                cout << "Seu pokemon esta evoluindo!!" << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << "." << endl;
                //Sleep(1000);
                cout << p1.get_nome() << " evoluiu para";
                p1 = blastoise;
                cout << " " << p1.get_nome() << "!!\n";
            }
        }

        int proximaBatalha;
        
        do {
        cout << "Digite (1) para continuar" << endl;
        cin >> proximaBatalha;
        } while(proximaBatalha != 1);
        


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

    return charmander;
}


void pokemon::ganhaXP(int vXP) {
    int nivelAnterior = nvl;
    int proxNVL = pow(nvl, 2) + 5;   //XP necessario para o proximo nivel
    int XP_res = vXP + XP;           //XP da batalha + XP de antes

    while (XP_res>=proxNVL) {
        nvl++;
        XP_res -= proxNVL;
        proxNVL = pow(nvl, 2) + 5;
    }
    XP = XP_res;
    
    int nivelAtual = nvl;

    cout << "XP atual: " << XP << "/" << proxNVL << endl;
    cout << "Nivel atual: " << nvl << endl;

    if(nivelAnterior!=nivelAtual)
        for(int i = nivelAnterior; i < nivelAtual; i++) {
            HP += 3;
            Att += 3;
            Def += 3;
        }
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
            
            r = aleatorio(1,5);
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

            r = aleatorio(1,5);
            switch(r){
                case 1: empilha(arcanine);
                break;
                case 2: empilha(gengar);
                break;
                case 3: empilha (gyarados);
                break;
                case 4: empilha(exegguttor);
                break;
                case 5: empilha(alakazam);
                break;
            }

            r = aleatorio(1,5);
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

            r = aleatorio(1,5);
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

            r = aleatorio(1,5);
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

            r = aleatorio(1,5);
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

            r = aleatorio(1,5);
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

            r = aleatorio(1,5);
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

            r = aleatorio(1,5);
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

int aleatorio(int x, int y){
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Gera um número aleatório entre x e y
    int numeroAleatorio = std::rand() % y + x;

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
