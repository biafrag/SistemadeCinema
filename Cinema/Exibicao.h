#pragma once
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Horario.h"
#include "Data.h"
#include "Assento.h"

class Exibicao
{
private:
	Horario horario;

    int publico;

    std::string audio;

    float rendimentoExibicao;

	Data dia;


public:
	/**
	 * Importante para caso de uso Rendimento/Público
	 */
	float calculaRendimento();

	/**
	 * Importante para caso de uso Alocação de assentos
	 */
	void exibeHorario();

	/**
	 * Importante para caso de uso Alocação de assentos
	 */
	void exibeAssentosDisponiveis();

	/**
	 * Importante para caso de uso Alocação de assentos
	 */
	void marcaAssentoOcupado(Assento assento);

	/**
	 * Importante para caso de uso Rendimento/Público
	 */
	int calculaPublico();

	/**
	 * Importante para caso de uso Alocação de assentos
	 */
	void exibeData();

};
