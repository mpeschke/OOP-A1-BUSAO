/**
    BusaoBLL.cpp
    Purpose: Busao Onibus class

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#include "stdafx.h"
#include "BusaoBLL.hpp"
#include "Exceptions.hpp"

namespace BLL {

static const char* const g_InvalidParameters("Valor tem que ser maior que zero.");

unsigned int Onibus::get_pontos()
{ return this->m_pontos; }

unsigned int Onibus::get_bancos()
{ return this->m_bancos; }

unsigned int Onibus::get_empe()
{ return this->m_empe; }

Onibus::Onibus()
    : m_pontos(0U), m_bancos(0U), m_empe(0U)
{}

Onibus::Onibus(const unsigned int pontos, const unsigned int bancos, const unsigned int empe)
    : m_pontos(pontos), m_bancos(bancos), m_empe(empe)
{
    if(this->m_pontos < 1U)
        throw CExcecao(g_InvalidParameters);
    if(this->m_bancos < 1U)
        throw CExcecao(g_InvalidParameters);
    if(this->m_empe < 1U)
        throw CExcecao(g_InvalidParameters);
}

Onibus::~Onibus()
{}

Onibus Onibus::instantiate(const unsigned int pontos, const unsigned int bancos, const unsigned int empe)
{ return Onibus(pontos, bancos, empe); }

} /* namespace BLL */
