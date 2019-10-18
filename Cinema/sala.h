#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

class Sala
{
private:
    std::string nome;

    std::string id;

	int numAssentos;


public:
    Sala(std::string nome, std::string id, int num);

    void marcaAssento(bool status);

    void marcaTodoOsAssentos(bool status);

};
