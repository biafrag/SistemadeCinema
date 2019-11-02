#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "exibicao.h"


Exibicao::Exibicao(Horario horario, std::string audio, Data dia, Filme filme):
    _horario(horario),
    _audio(audio),
    _dia(dia),
    _filme(filme)
{

}

float Exibicao::calculaRendimento()
{

}

int Exibicao::calculaPublico()
{
	return 0;
}

void Exibicao::exibeHorario()
{
}

void Exibicao::exibeData()
{
}

void Exibicao::exibeAssentosDisponiveis()
{
}

Filme Exibicao::getFilme()
{
    return _filme;
}

Horario Exibicao::getHorario()
{
    return _horario;
}

Data Exibicao::getData()
{
    return _dia;
}

void Exibicao::marcaAssento(Assento assento, bool status)
{
}
