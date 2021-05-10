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
static const char* const g_LotacaoAtingida("Lotação do ônibus foi atingida.");
static const char* const g_NinguemParaDescer("Não há passageiros para descer no ponto.");

unsigned int Onibus::get_pontos()
{ return this->m_pontos; }

unsigned int Onibus::get_bancos()
{ return this->m_bancos; }

unsigned int Onibus::get_empe()
{ return this->m_empe; }

const std::vector<Passageiro>& Onibus::get_passageiros() const
{ return this->m_passageiros; }

const std::list<Bilhete>& Onibus::get_bilhetes() const
{ return this->m_bilhetes; }

void Onibus::Entrar(const Passageiro& passageiro)
{
    // Lotação atingida.
    if((this->m_bancos + this->m_empe) <= this->m_passageiros.size())
        throw CExcecao(g_LotacaoAtingida);
    
    this->m_passageiros.push_back(passageiro);
    this->m_bilhetes.push_back(passageiro.get_bilhete());
}

void Onibus::Sair(const Passageiro& passageiro)
{
    // Realmente não importa qual passageiro desceu. Remover o último do vetor.
    if(this->m_passageiros.size() == 0U)
        throw CExcecao(g_NinguemParaDescer);
    
    this->m_passageiros.pop_back();
}

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
