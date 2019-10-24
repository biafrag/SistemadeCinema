#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "assento.h"
class Sala
{
private:
    std::string _nome;

    std::string _id;

    int _numAssentos;

    std::vector<Assento> _assentos;


public:
    Sala();
    Sala(std::string nome, std::string id, int num);

    void marcaAssento(int id, bool status);

    void marcaTodoOsAssentos(bool status);

    void inicializaAssentos(int num);

};
