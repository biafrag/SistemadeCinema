#pragma once

#include "assento.h"

class Exibicao;
class SituacaoAssento
{
private:
    bool _status;
    float _preco;
    Assento* _assento;
    Exibicao* _exibicao;

public:
    SituacaoAssento();
    SituacaoAssento(int num, Exibicao *exibicao);
    Exibicao* getExibicao();
    Assento* getAssento();
    float getPrecoAssentoExibicao();
    bool getStatusAssentoEmExibicao();

};

