#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>

using namespace std;
#include "classes.h"
#include "global_objects.h"
#include "funcoes.h"

int critico() {
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    
    double randomValue = dis(gen);

    
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

float STAB(pokemon p, ataque a){
    if(p.get_tipo() == a.get_tipo_ataque()){
        return 1.5;
    }else{
        return 1;
    }
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

            dano = (((((2*p1.get_nvl()*critico()) / 5)+2)*poder_atk*(p1.get_Att()/p2.get_Def())/50)+2)*STAB(p1, p1.get_a1());
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


int aleatorio(int x, int y){
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Gera um número aleatório entre x e y
    int numeroAleatorio = std::rand() % y + x;

    return numeroAleatorio;
}
