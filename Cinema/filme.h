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
    int _ano;
    int _classificacao;
    std::string _nacionalidade;

public:

    Filme();

    Filme(std::string nome);

    Filme(std::string nome, int ano, int classificacao, std::string nacionalidade);

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
    int getAno();
    int getClassificacao();
    std::string getNacionalidade();

};
