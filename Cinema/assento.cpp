#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "assento.h"



Assento::Assento(int numero, std::string tipo, bool status):
    _numero(numero),
    _tipo(tipo),
    _status(status)
{
}



int Assento::getNumero()
{
    return _numero;
}



bool Assento::getStatus()
{
    return _status;
}



void Assento::setStatus(bool status)
{
    _status = status;
}
