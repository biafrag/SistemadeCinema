#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

class Filme
{
private:
    std::string _nome;


public:

    Filme();

    Filme(std::string nome);

	/**
     * @brief Importante para caso de uso Rendimento/P?blico
	 */
	float calculaRendimento();

	/**
     * @brief Importante para caso de uso Rendimento/P?blico
	 */
	int calculaPublico();

	/**
     * @brief Importante para caso de uso Aloca?ao de assentos
	 */
	void mostraExibicoes();

    std::string getNome();

};
