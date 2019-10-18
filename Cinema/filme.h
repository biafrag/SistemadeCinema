#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

class Filme
{
private:
    std::string nome;

    float rendimento;


public:
	/**
	 * Importante para caso de uso Rendimento/P?blico
	 */
	float calculaRendimento();

	/**
	 * Importante para caso de uso Rendimento/P?blico
	 */
	int calculaPublico();

	/**
	 * Importante para caso de uso Aloca?ao de assentos
	 */
	void mostraExibicoes();

};
