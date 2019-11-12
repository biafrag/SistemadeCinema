#pragma once

#include "assento.h"

class Exibicao;
class SituacaoAssento
{
private:
    bool _status;
    bool _tipoAssento;
    Assento* _assento;
    Exibicao* _exibicao;

public:
    SituacaoAssento();
    SituacaoAssento(int num, Exibicao *exibicao, bool tipoAssento = true, bool status = true);
    Exibicao* getExibicao();
    Assento* getAssento();
    bool getStatusAssentoEmExibicao();


    bool getTipoAssento();
    void setTipoAssento(bool tipo);
    void setStatusAssento(bool status);
};

