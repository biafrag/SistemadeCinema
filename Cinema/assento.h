#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

class Assento
{
private:
    /**
     * @brief Precisa ser que nem da modelagem?
     */
    int _numero;

    /**
     * @brief Precisa mesmo?
     */
    std::string _tipo;

    bool _status;

public:

    Assento(int numero,std::string tipo =  "Normal",bool status = true);

    /**
     * @brief Retorna o numero do assento
     */
    int getNumero();

    /**
     * @brief Retorna o status do assento
     */
    bool getStatus();

    /**
     * @brief Seta o status do assento
     */
    void setStatus(bool status);




};

