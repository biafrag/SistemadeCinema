#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "cinema.h"

void Cinema::registraFilme(std::string nome, int ano, int classificacao, std::string nacionalidade)
{
    Filme novoFilme(nome,ano,classificacao,nacionalidade);
    filmesExibicao.push_back(novoFilme);
}

QStringList Cinema::getnomesFilmesEmExibicao()
{
    QStringList lista;
    for(unsigned int i = 0; i < filmesExibicao.size(); i++)
    {
        std::string e = filmesExibicao[i].getNome();
        QString s(e.c_str());
        lista.append(s);
    }
    return lista;
}

std::vector<Filme> Cinema::getFilmesEmExibicao()
{
    return filmesExibicao;
}

std::vector<Sala *> Cinema::getSalas()
{
    return salas;
}

std::vector<Exibicao> Cinema::getExibicoes(std::string nomeFilme)
{
    std::vector<Exibicao> ex;
    Filme filme;
    filme = findFilme(nomeFilme);
    for(unsigned int i = 0; i < exibicoes.size(); i++)
    {
        if(exibicoes[i].getFilme().getNome() == filme.getNome())
        {
            ex.push_back(exibicoes[i]);
        }
    }
    return ex;

}

std::vector<std::pair<std::string,std::string> > Cinema::getDatasHorarios(std::string nomeFilme)
{
    std::vector<std::pair<std::string,std::string>> datas;
    std::vector<Exibicao> ex = getExibicoes(nomeFilme);
    if(ex.size() > 0)
    {
        for(unsigned int i = 0; i < ex.size(); i++)
        {
            Exibicao exibicao = ex[i];
            std::string horario = exibicao.getHorario().toString().toStdString();
            std::string data = exibicao.getData().toString().toStdString();
            datas.push_back(std::make_pair(data,horario));
        }
    }
    return datas;
}

bool Cinema::verificaFilmeValido()
{
	return 0;
}

void Cinema::addExibicao(QDate data, QTime horario, std::string audio, Sala* sala, Filme filme, float preco)
{
    Exibicao e(horario,audio,data,sala,filme,preco);
    exibicoes.push_back(e);
    sala->addExibicao(e);
}

std::vector<Sala*> Cinema::verificaSalasDisponiveis(QDate data, QTime horario)
{
    std::vector<Sala*> salasLivres;
    for(unsigned int i = 0; i < salas.size(); i++)
    {
        Sala* sala = salas[i];
        if(!sala->checaDataHora(data,horario))
        {
            salasLivres.push_back(sala);
        }
    }
    return salasLivres;
}

Sala Cinema::alocaSalaParaExibicao(Exibicao exibicao)
{
    //return Sala();
}

void Cinema::addSala(Sala* sala)
{
    salas.push_back(sala);
}

bool Cinema::verificaSeSalaExiste(std::string nome)
{
    for(unsigned int i = 0; i < salas.size(); i++)
    {
        if(nome == salas[i]->getName())
        {
            return true;
        }
    }
    return false;
}

Filme Cinema::findFilme(std::string nome)
{
    Filme filme;
    for(unsigned int i = 0; i < filmesExibicao.size(); i++)
    {
        if(filmesExibicao[i].getNome() == nome)
        {
            filme = filmesExibicao[i];
            return filme;
        }
    }
}

Sala* Cinema::findSala(std::string nome)
{
    Sala* sala;
    for(unsigned int i = 0; i < salas.size(); i++)
    {
        if(salas[i]->getName() == nome)
        {
            sala = salas[i];
            return sala;
        }
    }
}

std::vector<Assento*> Cinema::getAssentosLivres(Exibicao exibicao)
{
    return exibicao.getAssentosLivres();

}

Exibicao Cinema::findExibicao(QDate data, QTime horario, std::string nomeSala)
{
    for(unsigned int i = 0; i < exibicoes.size(); i++)
    {
        Exibicao ex = exibicoes[i];
        if(ex.getData() == data && ex.getHorario() == horario && ex.getSalaNome() == nomeSala)
        {
            return ex;
        }
    }
}

int Cinema::calculaPublicoFilme(std::string nomeFilme)
{
    Filme filme = findFilme(nomeFilme);
    std::vector<Exibicao> exs = getExibicoes(nomeFilme);

    int soma = 0;
    for(unsigned int i = 0; i < exs.size(); i++)
    {
        Exibicao ex = exs[i];
        int p = ex.getPublico();
        soma += p;
    }

    return soma;

}

float Cinema::calculaRendimentoFilme(std::string nomeFilme)
{
    Filme filme = findFilme(nomeFilme);
    std::vector<Exibicao> exs = getExibicoes(nomeFilme);

    float soma = 0;
    for(unsigned int i = 0; i < exs.size(); i++)
    {
        Exibicao ex = exs[i];
        float r = ex.getRendimento();
        soma += r;
    }

    return soma;
}
