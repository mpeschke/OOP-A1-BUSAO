/**
    Passageiro.hpp
    Purpose: Busao Passageiro class

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#include "stdafx.h"
#include "Passageiro.hpp"
#include "Exceptions.hpp"

namespace BLL {

static const char* const g_InvalidParameters("Tipo de bilhete tem que ser identificado.");

const Bilhete& Passageiro::get_bilhete() const
{ return this->m_bilhete; }

void Passageiro::set_bilhete(const Bilhete& bilhete)
{ this->m_bilhete = bilhete; }

Passageiro::Passageiro()
{ this->m_bilhete = Bilhete::Indefinido; }

Passageiro::Passageiro(Bilhete bilhete)
{
    this->m_bilhete = bilhete;
    if(this->m_bilhete == Bilhete::Indefinido)
        throw CExcecao(g_InvalidParameters);
}

Passageiro::~Passageiro()
{}

Passageiro Passageiro::instantiate(Bilhete bilhete)
{ return Passageiro(bilhete); }

} /* namespace BLL */
