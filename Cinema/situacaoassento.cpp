#include "situacaoassento.h"
#include "exibicao.h"

SituacaoAssento::SituacaoAssento()
{
}

SituacaoAssento::SituacaoAssento(int num, Exibicao* exibicao, bool tipoAssento, bool status)
{
    _assento = new Assento(num);
    _exibicao = exibicao;
    _tipoAssento = tipoAssento;
    _status = status;
}

Exibicao *SituacaoAssento::getExibicao()
{
    return _exibicao;
}

Assento *SituacaoAssento::getAssento()
{
    return _assento;
}


bool SituacaoAssento::getStatusAssentoEmExibicao()
{
    return _status;
}

bool SituacaoAssento::getTipoAssento()
{
    return _tipoAssento;
}

void SituacaoAssento::setTipoAssento(bool tipo)
{
    _tipoAssento = tipo;
}

void SituacaoAssento::setStatusAssento(bool status)
{
    _status = status;
}
