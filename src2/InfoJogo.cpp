#include "InfoJogo.h"
#include "HashInfoJogo.h"
#include "funcoesAuxiliares.h"
#include <iostream>
#include <fstream>

// Este arquivo contém os gets e sets relativos à estrutura HashInfoJogo

int InfoJogo::getId(){

    return this->id;

}

string InfoJogo::getCategoria(){

    return this->categoria;

}

unsigned InfoJogo::getIdJogo(){

    return this->idJogo;

}

void InfoJogo::setId(int id){

    this->id = id;
}

void InfoJogo::setIdJogo(unsigned idJogo){

    this->idJogo = idJogo;
}

void InfoJogo::setCategoria(string categoria){

    this->categoria = categoria;
}