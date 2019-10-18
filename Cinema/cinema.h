#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Filme.h"
#include "Data.h"
#include "Horario.h"
#include "Sala.h"

class Cinema
{
private:
    std::string nome;

    std::string endereco;

    std::string email;

    std::string cnpj;


public:
	/**
	 * Importante para caso de uso Alocação de assentos
	 */
	void compraIngresso(Filme filme);

	/**
	 * Importante para caso de uso Alocação de assentos
	 */
	void exibeFilmesEmExibicao();

    void registraFilme(std::string nome);

    bool verificaFilmeValido();

	void ExibeFilmesRegistrados();

	void exibeSalasDisponiveis(Data data, Horario horario);

    void addExibicao(Data data, Horario horario, std::string audio, Sala sala);

    void addSala(std::string nome);

};
