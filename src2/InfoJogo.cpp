#include "InfoJogo.h"
#include "HashInfoJogo.h"
#include "funcoesAuxiliares.h"
#include <iostream>
#include <fstream>

unsigned InfoJogo::getId(){

    return this->id;

}

string InfoJogo::getCategoria(){

    return this->categoria;

}

unsigned InfoJogo::getIdJogo(){

    return this->idJogo;

}

void InfoJogo::setId(unsigned id){

    this->id = id;
}

void InfoJogo::setIdJogo(unsigned idJogo){

    this->idJogo = idJogo;
}

void InfoJogo::setCategoria(string categoria){

    this->categoria = categoria;
}