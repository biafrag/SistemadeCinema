#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "filme.h"
#include "assento.h"

#include <QDate>
#include <QTime>
class Sala;
class SituacaoAssento;
class Exibicao
{
private:
    QTime _horario;

    std::string _audio;

    QDate _dia;

    Sala* _sala;

    Filme _filme;

    float _preco;

    std::vector<SituacaoAssento*> situacao;

public:

    Exibicao();

    Exibicao(QTime horario, std::string audio, QDate dia, Sala *sala, Filme filme, float preco);

	/**
     * @brief Importante para caso de uso Rendimento/Publico : Calcula Rendimento da exibição
	 */
	float calculaRendimento();

	/**
     * @brief Importante para caso de uso Rendimento/Publico
	 */
	int calculaPublico();

    Filme getFilme();

    QTime getHorario();

    QDate getData();

    std::string getSalaNome();

    float getPreco();

    std::string getAudio();

    int getPublico();

	/**
     * @brief Importante para caso de uso Alocacao de assentos
	 */
    void marcaAssento(int indice, bool status);

    std::vector<Assento *> getAssentosLivres();

};
