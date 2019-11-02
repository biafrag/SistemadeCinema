#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "filme.h"


Filme::Filme()
{

}

Filme::Filme(std::string nome) : _nome(nome)
{

}

float Filme::calculaRendimento()
{
	return 0;
}

int Filme::calculaPublico()
{
	return 0;
}

void Filme::mostraExibicoes()
{
}

std::string Filme::getNome()
{
    return _nome;
}

