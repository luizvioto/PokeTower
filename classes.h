#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>

class ataque {
private:
    std::string nome;
    int poder;
    std::string tipo_ataque;

public:
    ataque();
    
    ataque (std::string vNome, int vPoder, std::string vTipo_ataque);

    void set_nome(std::string vnome);

    void set_poder(int vpoder);

    void set_tipo_ataque(std::string vtipo_ataque);

    std::string get_nome() const;

    int get_poder() const;

    std::string get_tipo_ataque() const;
}; 

class pokemon {

private:
    int ID;   //ID de cada Pokemon
    int HP;    // Health Points
    int Att;    // Strenght Points
    int Def;
    int nvl;   // Nivel
    int baseXP;
    std::string nome;
    static int proxID;
    int XP;
    int speed;
    int jaEvoluiu[2];
    std::string tipo; //fogo, agua, planta, eletrico, pedra, fantasma, dragao, gelo, lutador, normal, grama, inseto, voador, venenoso, terrestre, sombrio, metal, psiquico
    ataque a1;
    ataque a2;


public:
    pokemon();
    pokemon(std::string vnome, int vHP, int vAtt, int vDef, int vNvl, int vSpeed, std::string vTipo, ataque a1, ataque a2, int vBaseXP); // Construtor Detalhado
    // Destrutor

    // Métodos Set
    void set_HP(int vHP);
    void set_Att(int vAtt);
    void set_nome(std::string vnome);
    void set_nvl(int vnvl);
    void set_XP(int vXP);
    void set_Def(int vDef);
    void set_speed(int vSpeed);
    void set_tipo(std::string vTipo);
    void set_a1(ataque va1);
    void set_a2(ataque va2);
    void set_BaseXP(int vBaseXP);
    void set_jaEvoluiu(int x, int i);

    // Métodos Get
    int get_HP() const;
    int get_Att() const;
    std::string get_nome() const;
    int get_nvl() const;
    int get_ID() const;
    int get_XP() const;
    int get_Def() const;
    int get_speed() const;
    std::string get_tipo() const;
    ataque get_a1() const;
    ataque get_a2() const;
    int get_baseXP() const;
    int get_jaEvoluiu(int i) const;


    //Outros Métodos
    void imprime() const;
    void ganhaXP(int vXP);
    void incrementaNvl();
};

class Pilha{
public:
    pokemon adversario[10];
    int topo;
public:
    pokemon Poketopo();

    Pilha(int x);

    bool cheia() const;
   
    bool vazia() const;
   
    bool empilha(pokemon X);

    bool desempilha(pokemon &X);

};


#endif 