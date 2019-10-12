#include "funcoesAuxiliares.h"

unsigned converterStringUnsigned(char* str){

    unsigned valorString = 0;

    for(unsigned  i = 0; str[i] != '\0'; i++)
        valorString += str[i];

    return valorString;

}