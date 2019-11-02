#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "horario.h"
#include "data.h"
#include "ingresso.h"
#include "sala.h"
#include "filme.h"

class Exibicao
{
private:
    Horario _horario;

    std::string _audio;

    Data _dia;

    Sala sala;
    Filme _filme;


public:
    Exibicao(Horario horario, std::string audio, Data dia, Filme filme);

	/**
     * @brief Importante para caso de uso Rendimento/Publico : Calcula Rendimento da exibição
	 */
	float calculaRendimento();

	/**
     * @brief Importante para caso de uso Rendimento/Publico
	 */
	int calculaPublico();

	/**
     * @brief Importante para caso de uso Alocacao de assentos
	 */
	void exibeHorario();

	/**
     * @brief Importante para caso de uso Alocacao de assentos
	 */
	void exibeData();

	/**
     * @brief Importante para caso de uso Alocacao de assentos
	 */
	void exibeAssentosDisponiveis();

    Filme getFilme();

    Horario getHorario();

    Data getData();
	/**
     * @brief Importante para caso de uso Alocacao de assentos
	 */
    void marcaAssento(Assento assento, bool status);

};
