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
    Instancia um objeto da classe Onibus.

    @return Objeto da classe Onibus.
    @param pontos número de pontos em que o circular pára.
    @param bancos número de bancos máximos para sentar passageiros.
    @param empe número máximo de passageiros em pé no ônibus.
*/
    static Onibus instantiate(const unsigned int pontos, const unsigned int bancos, const unsigned int empe);
public:
    virtual ~Onibus();
};

} /* namespace BLL */
