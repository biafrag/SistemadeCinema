#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <QStringList>

#include "filme.h"
#include "sala.h"
#include "exibicao.h"

class Cinema
{
private:
    std::string nome;

    std::string endereco;

    std::string email;

    std::string cnpj;

    std::vector<Filme> filmesExibicao;
    std::vector<Exibicao> exibicoes;
    std::vector<Sala*> salas;


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
    void registraFilme(std::string nome, int ano, int classificacao, std::string nacionalidade);

    QStringList getnomesFilmesEmExibicao();

    std::vector<Exibicao> getExibicoes(std::string nomeFilme);

    std::vector<std::pair<std::string, std::string> > getDatasHorarios(std::string nomeFilme);
	/**
     * @brief Importante para caso de uso Cadastro Exibi?o em Sala
	 */
    bool verificaFilmeValido();

    void addExibicao(QDate data, QTime horario, std::string audio, Sala *sala, Filme filme, float preco);

	/**
     * @brief Importante para caso de uso Cadastro Exibi?o em Sala
	 */
	void ExibeFilmesRegistrados();

	/**
     * @brief Importante para caso de uso Cadastro Exibi?o em Sala
	 */
    std::vector<Sala*> verificaSalasDisponiveis(QDate data, QTime horario);

	Sala alocaSalaParaExibicao(Exibicao exibicao);

    void addSala(Sala *sala);

    bool verificaSeSalaExiste(std::string id);

    Filme findFilme(std::string nome);

    Sala *findSala(std::string nome);

    std::vector<Assento *> getAssentosLivres(Exibicao exibicao);

    Exibicao findExibicao(QDate data, QTime horario, std::string nomeSala);

    int calculaPublicoFilme(std::string nomeFilme);

    float calculaRendimentoFilme(std::string nomeFilme);

};
