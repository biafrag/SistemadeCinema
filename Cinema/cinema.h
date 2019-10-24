#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "filme.h"
//#include "data.h"
//#include "horario.h"
#include "sala.h"
#include "exibicao.h"

class Cinema
{
private:
    std::string nome;

    std::string endereco;

    std::string email;

    std::string cnpj;


public:
	/**
     * @brief Importante para caso de uso Aloca??o de assentos
	 */
	void compraIngresso(Filme filme);

	/**
     * @brief Importante para caso de uso Aloca??o de assentos
	 */
	void exibeFilmesEmExibicao();

	/**
     * @brief Importante para caso de uso Cadastro Exibi?o em Sala
	 */
	void registraFilme(Filme filme);

	/**
     * @brief Importante para caso de uso Cadastro Exibi?o em Sala
	 */
    bool verificaFilmeValido();

    void addExibicao(Data data, Horario horario, std::string audio, Sala sala);

	/**
     * @brief Importante para caso de uso Cadastro Exibi?o em Sala
	 */
	void ExibeFilmesRegistrados();

	/**
     * @brief Importante para caso de uso Cadastro Exibi?o em Sala
	 */
	void exibeSalasDisponiveis(Data data, Horario horario);

	Sala alocaSalaParaExibicao(Exibicao exibicao);

    void addSala(std::string nome);

    bool verificaSala();

};
