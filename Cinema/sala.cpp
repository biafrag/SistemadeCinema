#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include "sala.h"
#include "assento.h"

#include "exibicao.h"
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
    _assentos[id].setStatus(status);
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

bool Sala::checaDataHora(QDate data, QTime hora)
{
    for(unsigned int i = 0; i < _exibicoes.size(); i++)
    {
        Exibicao ex = _exibicoes[i];
        if(ex.getData() == data && ex.getHorario() == hora)
        {
            return true;
        }
        return false;
    }
}

std::string Sala::getID()
{
    return _id;
}

std::string Sala::getName()
{
    return _nome;
}

int Sala::getNumAssentos()
{
    return _numAssentos;
}

void Sala::addExibicao(Exibicao exibicao)
{
    _exibicoes.push_back(exibicao);
}
