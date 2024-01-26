#ifndef FUNCOES_H
#define FUNCOES_H

#include "classes.h"
#include "global_objects.h"

int critico();

float efetivo(ataque a, pokemon p);

bool realizarBatalha(pokemon &p1, pokemon p2, int &cont, double &secAdd);

pokemon escolhaUsuario();

int aleatorio(int x, int y);

#endif 