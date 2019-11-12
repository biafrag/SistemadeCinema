#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "exibicao.h"
#include "filme.h"
#include "assento.h"
#include "sala.h"
#include "situacaoassento.h"

Exibicao::Exibicao()
{

}

Exibicao::Exibicao(QTime horario, std::string audio, QDate dia, Sala* sala, Filme filme, float preco):
    _horario(horario),
    _audio(audio),
    _dia(dia),
    _filme(filme),
    _sala(sala),
    _preco(preco)
{
    for(unsigned int i = 0; i < sala->getNumAssentos(); i++)
    {
        SituacaoAssento* s = new SituacaoAssento(i,this);
        situacao.push_back(s);
    }
}

float Exibicao::calculaRendimento()
{

}

int Exibicao::calculaPublico()
{
	return 0;
}

Filme Exibicao::getFilme()
{
    return _filme;
}

QTime Exibicao::getHorario()
{
    return _horario;
}

QDate Exibicao::getData()
{
    return _dia;
}

std::string Exibicao::getSalaNome()
{
    return _sala->getName();
}

float Exibicao::getPreco()
{
    return _preco;
}

std::string Exibicao::getAudio()
{
    return _audio;
}

int Exibicao::getPublico()
{
    int cont = 0;
    for(unsigned int i = 0; i < situacao.size(); i++)
    {
        SituacaoAssento* s = situacao[i];
        Assento* assento = s->getAssento();
        //Se for true quer dizer que esta livre
        if(!s->getStatusAssentoEmExibicao())
        {
            cont++;
        }
    }
    return cont;
}

float Exibicao::getRendimento()
{
    float soma = 0;

    for(unsigned int i = 0; i < situacao.size(); i++)
    {
        SituacaoAssento* s = situacao[i];
        Assento* assento = s->getAssento();
        //Se for true quer dizer que esta livre
        if(s->getStatusAssentoEmExibicao() == false)
        {
            bool tipo = s->getTipoAssento();
            //inteira
            if(tipo)
            {
                soma += _preco;
            }
            else
            {
                soma += _preco/2.0;
            }
        }
    }
    return soma;
}

std::vector<SituacaoAssento *> Exibicao::getSituacaoAssentos()
{
    return situacao;
}

void Exibicao::marcaAssento(int indice, bool status, bool tipoAssento)
{
    for(unsigned int i = 0; i < situacao.size(); i++)
    {
        SituacaoAssento* s = situacao[i];
        Assento* assento = s->getAssento();
        //Se for true quer dizer que esta livre
        if(assento->getNumero() == indice)
        {
            //assento->setStatus(status);
            s->setStatusAssento(status);
            s->setTipoAssento(tipoAssento);
        }
    }
}

std::vector<Assento*> Exibicao::getAssentosLivres()
{
    std::vector<Assento*> assentos;
    for(unsigned int i = 0; i < situacao.size(); i++)
    {
        SituacaoAssento* s = situacao[i];
        Assento* assento = s->getAssento();
        //Se for true quer dizer que esta livre
        if(s->getStatusAssentoEmExibicao())
        {
            assentos.push_back(assento);
        }
    }
    return assentos;
}
