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
    std::vector<Filme> filmesExibicao;
    std::vector<Exibicao> exibicoes;
    std::vector<Sala*> salas;


public:

	/**
     * @brief Registra filme no cinema
	 */
    void registraFilme(std::string nome, int ano, int classificacao, std::string nacionalidade);

    /**
     * @brief Retorna todos os nomes de filmes em exibição
     */
    QStringList getnomesFilmesEmExibicao();

    /**
     * @brief Retorna todos os filmes em exibição
     */
    std::vector<Filme> getFilmesEmExibicao();

    /**
     * @brief Retorna todas as salas do cinema
     */
    std::vector<Sala*> getSalas();

    /**
     * @brief Retorna todas as exibicoes de um determinado filme
     */
    std::vector<Exibicao> getExibicoes(std::string nomeFilme);

    /**
     * @brief Retorna as datas e horarios das exibicoes de um determinado filme
     */
    std::vector<std::pair<std::string, std::string> > getDatasHorarios(std::string nomeFilme);

	/**
     * @brief Importante para caso de uso Cadastro Exibi?o em Sala
	 */
    bool verificaFilmeValido();

    /**
     * @brief Adiciona exibicao no cinema
     */
    void addExibicao(QDate data, QTime horario, std::string audio, Sala *sala, Filme filme, float preco);

	/**
     * @brief Verifica as salas disponiveis em determinada data e horario
	 */
    std::vector<Sala*> verificaSalasDisponiveis(QDate data, QTime horario);

    /**
     * @brief Aloca sala para exibicao
     */
	Sala alocaSalaParaExibicao(Exibicao exibicao);

    /**
     * @brief Adiciona sala no cinema
     */
    void addSala(Sala *sala);

    /**
     * @brief Verifica se sala existe, pelo id
     */
    bool verificaSeSalaExiste(std::string nome);

    /**
     * @brief Acha instancia de filme pelo nome
     */
    Filme findFilme(std::string nome);

    /**
     * @brief Acha instancia de sala pelo nome
     */
    Sala *findSala(std::string nome);

    /**
     * @brief Retorna assentos livres de uma determinada exibicao
     */
    std::vector<Assento *> getAssentosLivres(Exibicao exibicao);

    /**
     * @brief Acha instancia de exibicao checando data, horario e sala
     */
    Exibicao findExibicao(QDate data, QTime horario, std::string nomeSala);

    /**
     * @brief Calcula publico de filme
     */
    int calculaPublicoFilme(std::string nomeFilme);

    /**
     * @brief Calcula rendimento de filme
     */
    float calculaRendimentoFilme(std::string nomeFilme);

};
