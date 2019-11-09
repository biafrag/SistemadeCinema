#include "situacaoassento.h"
#include "exibicao.h"

SituacaoAssento::SituacaoAssento()
{
}

SituacaoAssento::SituacaoAssento(int num, Exibicao* exibicao)
{
    _assento = new Assento(num);
    _exibicao = exibicao;
}

Exibicao *SituacaoAssento::getExibicao()
{
    return _exibicao;
}

Assento *SituacaoAssento::getAssento()
{
    return _assento;
}

float SituacaoAssento::getPrecoAssentoExibicao()
{
    return _preco;
}

bool SituacaoAssento::getStatusAssentoEmExibicao()
{
    return _status;
}
