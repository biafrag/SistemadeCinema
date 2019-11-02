#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "cinema.h"


void Cinema::compraIngresso(Filme filme)
{
}

void Cinema::exibeFilmesEmExibicao()
{
}

void Cinema::registraFilme(std::string nome)
{
    Filme novoFilme(nome);
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

std::vector<Exibicao> Cinema::getExibicoes(std::string nomeFilme)
{
    std::vector<Exibicao> ex;
    Filme filme;
    for(unsigned int i = 0; i < filmesExibicao.size(); i++)
    {
        if(filmesExibicao[i].getNome() == nomeFilme)
        {
            filme = filmesExibicao[i];
            break;
        }
    }

    for(unsigned int i = 0; i < exibicoes.size(); i++)
    {
        if(exibicoes[i].getFilme().getNome() == filme.getNome())
        {
            ex.push_back(exibicoes[i]);
        }
    }


}

std::vector<std::pair<std::string,std::string> > Cinema::getDatasHorarios(std::string nomeFilme)
{
    std::vector<std::pair<Data, Horario>> datas;
    std::vector<Exibicao> ex = getExibicoes(nomeFilme);
    for(unsigned int i = 0; i < ex.size(); i++)
    {
        Exibicao exibicao = ex[i];
        std::string horario = exibicao.getHorario().getHorarioInicio();
        std::string data = exibicao.getData().getDataPadrao();

    }
}

bool Cinema::verificaFilmeValido()
{
	return 0;
}

void Cinema::addExibicao(Data data, Horario horario, std::string audio, Sala sala)
{
    Exibicao e();
}

void Cinema::ExibeFilmesRegistrados()
{
}

void Cinema::exibeSalasDisponiveis(Data data, Horario horario)
{
}

Sala Cinema::alocaSalaParaExibicao(Exibicao exibicao)
{
    //return Sala();
}

void Cinema::addSala(std::string nome)
{
}

bool Cinema::verificaSala()
{
	return 0;
}
