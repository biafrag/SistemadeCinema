#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "horario.h"
#include "data.h"
#include "assento.h"

class Exibicao
{
private:
	Horario horario;

    int publico;

    std::string audio;

    float rendimentoExibicao;

	Data dia;


public:
    Exibicao(Horario horario, std::string audio, Data dia);

	/**
     * Importante para caso de uso Rendimento/Publico
	 */
	float calculaRendimento();

	/**
     * Importante para caso de uso Rendimento/Publico
	 */
	int calculaPublico();

	/**
     * Importante para caso de uso Alocacao de assentos
	 */
	void exibeHorario();

	/**
     * Importante para caso de uso Alocacao de assentos
	 */
	void exibeData();

	/**
     * Importante para caso de uso Alocacao de assentos
	 */
	void exibeAssentosDisponiveis();

	/**
     * Importante para caso de uso Alocacao de assentos
	 */
    void marcaAssento(Assento assento, bool status);

};
