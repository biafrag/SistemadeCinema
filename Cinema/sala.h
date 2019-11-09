#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "assento.h"
#include "exibicao.h"
#include <QDate>
#include<QTime>

class Sala
{
private:
    std::string _nome;

    int _numAssentos;

    std::vector<Assento> _assentos;

    std::vector<Exibicao> _exibicoes;



public:
    Sala();
    Sala(std::string nome, int num);

    void marcaAssento(int id, bool status);

    void marcaTodoOsAssentos(bool status);

    void inicializaAssentos(int num);

    bool checaDataHora(QDate data, QTime hora);

    void addExibicao(Exibicao exibicao);

    std::string getName();
    int getNumAssentos();

};
