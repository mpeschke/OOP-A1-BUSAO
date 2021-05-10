/**
    BusaoBLL.hpp
    Purpose: Busao Onibus class

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#pragma once

#include <string>
#include <vector>
#include <fstream>

namespace BLL {

class Onibus {
protected:
    unsigned int m_pontos;
    unsigned int m_bancos;
    unsigned int m_empe;
    Onibus();
    Onibus(const unsigned int pontos, const unsigned int bancos, const unsigned int empe);
public:
    unsigned int get_pontos();
    unsigned int get_bancos();
    unsigned int get_empe();
/**
    Return a vector of all subdirectories inside a directory.

    @return vector of CDirectoy objects.
*/
    static Onibus instantiate(const unsigned int pontos, const unsigned int bancos, const unsigned int empe);
public:
    virtual ~Onibus();
};

} /* namespace BLL */
