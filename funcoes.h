#ifndef FUNCOES_H
#define FUNCOES_H

#include "classes.h"
#include "global_objects.h"

int critico();

int efetivo(ataque a, pokemon p);

bool realizarBatalha(pokemon &p1, pokemon p2);

pokemon escolhaUsuario();

int aleatorio(int x, int y);

#endif 