#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>
#include<windows.h>

using namespace std;
#include "classes.h"
#include "global_objects.h"
#include "funcoes.h"

using namespace std;

ataque::ataque(){
        nome = "indefinido";
        poder = 0;
        tipo_ataque = "nenhum";
}

void ataque::set_nome(string vnome){
    nome = vnome;
} 

ataque::ataque(string vNome, int vPoder, string vTipo_ataque) {
    set_nome(vNome);
    set_poder(vPoder);
    set_tipo_ataque(vTipo_ataque);
}

void ataque::set_poder(int vpoder){
    poder = vpoder;
}

void ataque::set_tipo_ataque(string vtipo_ataque){
    tipo_ataque = vtipo_ataque;
}

string ataque::get_nome() const{
    return nome;
}

int ataque::get_poder() const{
    return poder;
}

string ataque::get_tipo_ataque() const{
    return tipo_ataque;
}



Pilha::Pilha(int x){
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

pokemon Pilha::Poketopo(){
    return adversario[topo];
}

bool Pilha::cheia() const{
    if(topo == 9){
        return true;
    }else{
        return false;
    }
}

bool Pilha::vazia() const{
    if(topo == -1){
        return true;
    }else{
        return false;
    }
}

bool Pilha::empilha(pokemon X){
    if(cheia()){
        return false;
    }else{
        topo++;
        adversario[topo] = X;
        return true;
    }
}

bool Pilha::desempilha(pokemon &X){
    if(vazia()){
        return false;
    }else{
        X = adversario[topo];
        topo--;
        return true;
    }
}

pokemon::pokemon():ID(++proxID){
    nome = "Indefinido";
}

pokemon::pokemon(string vnome, int vHP, int vAtt, int vDef , int vNvl, int vSpeed, string vTipo, ataque va1, ataque va2, int vBaseXP){
    
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
    set_BaseXP(vBaseXP);
    jaEvoluiu[0]=0;
    jaEvoluiu[1]=0;
    
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

int pokemon::get_baseXP() const{
    return baseXP;
}

ataque pokemon::get_a2() const{
    return a2;
}

int pokemon::get_jaEvoluiu(int i) const{
    return jaEvoluiu[i];
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

void pokemon::set_BaseXP(int vBaseXP){
    baseXP = vBaseXP; 
}

void pokemon::set_jaEvoluiu(int x, int i){
    jaEvoluiu[i] = x;
}

void pokemon::incrementaNvl(){
    nvl++;
}



void pokemon::imprime() const {
    cout << "ID: " << get_ID() << endl;
    cout << "Nome: " << get_nome() << endl;
    cout << "HP: " << get_HP() << endl;
    cout << "Att: " << get_Att() << endl;
    cout << "Nivel: " << get_nvl() << endl; 
    cout << "Def: " << get_Def() << endl;
    cout << "BaseXP: " << get_baseXP() << endl << endl;
}

void pokemon::ganhaXP(int vXP) {
    int nivelAnterior = nvl;
    int proxNVL = pow(nvl, 2);   //XP necessario para o proximo nivel
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

int pokemon::proxID = 1;