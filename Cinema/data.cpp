#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "data.h"



std::string Data::getDataPadrao()
{
    std::string s = std::to_string(dia) + "/" + std::to_string(mes);
}
