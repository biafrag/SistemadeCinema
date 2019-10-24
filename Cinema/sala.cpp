#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "sala.h"


Sala::Sala()
{

}



Sala::Sala(std::string nome, std::string id, int num)
{
    _nome = nome;
    _id = id;
    _numAssentos = num;
    inicializaAssentos(num);
}



void Sala::marcaAssento(int id, bool status)
{
    _assentos[id - 1].setStatus(status);
}



void Sala::marcaTodoOsAssentos(bool status)
{
    for(unsigned int i = 0; i < _numAssentos; i++)
    {
        _assentos[i].setStatus(status);
    }
}



void Sala::inicializaAssentos(int num)
{
    for(unsigned int i = 0; i < num; i++)
    {
        _assentos.push_back(Assento(i + 1));
    }
}
