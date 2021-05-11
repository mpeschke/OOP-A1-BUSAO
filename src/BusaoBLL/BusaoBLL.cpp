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
static const char* const g_PassageirosFaltando("Não há passageiros suficientes para descer no ponto.");

unsigned int Onibus::get_pontos() const
{ return this->m_pontos; }

unsigned int Onibus::get_bancos() const
{ return this->m_bancos; }

unsigned int Onibus::get_empe() const
{ return this->m_empe; }

unsigned int Onibus::get_voltas() const
{ return this->m_voltas; }

unsigned int Onibus::get_ponto() const
{ return this->m_ponto; }

const std::vector<Passageiro>& Onibus::get_passageiros() const
{ return this->m_passageiros; }

const std::list<Bilhete>& Onibus::get_bilhetes() const
{ return this->m_bilhetes; }

void Onibus::Pedirparadescer(const unsigned int passageiros)
{ this->m_pedirampradescer = passageiros; }

void Onibus::Passarnoproximoponto()
{
    if(this->m_ponto == this->m_pontos)
    {
        this->m_ponto = 1U;
        this->m_voltas++;
    }
    else
        this->m_ponto++;
    
    this->Sair();
}

unsigned int Onibus::PassageirosEmPe() const
{
    if(this->m_passageiros.size() >= this->m_bancos)
        return this->m_passageiros.size() - this->m_bancos;
    else
        return 0U;
}

unsigned int Onibus::PassageirosSentados() const
{
    return std::min(this->m_bancos, (unsigned int)this->m_passageiros.size());
}

void Onibus::Entrar(const Passageiro& passageiro)
{
    // Lotação atingida.
    if((this->m_bancos + this->m_empe) <= this->m_passageiros.size())
        throw CExcecao(g_LotacaoAtingida);
    
    this->m_passageiros.push_back(passageiro);
    this->m_bilhetes.push_back(passageiro.get_bilhete());
}

void Onibus::Sair()
{
    // Realmente não importa quais passageiros desceram. Remover os últimos do vetor.
    if(this->m_passageiros.size() < this->m_pedirampradescer)
        throw CExcecao(g_PassageirosFaltando);
    
    unsigned int desceram = this->m_pedirampradescer;
    while(desceram)
    {
        this->m_passageiros.pop_back();
        desceram--;
    }
}

// C++ possui oferece a std library, que fornece um conjunto de algoritmos
// comuns para operações de computação. Nesse caso uma função que conta objetos baseado numa condição definida num lambda.
unsigned int Onibus::ContarTipoBilhetes(const Bilhete& tipo) const
{ return std::count_if(this->m_bilhetes.begin(), this->m_bilhetes.end(), [tipo](Bilhete bil){return bil == tipo;}); }

unsigned int Onibus::Numerodeviagens() const
{ return this->get_voltas(); }

Onibus::Onibus()
    : m_pontos(0U), m_bancos(0U), m_empe(0U), m_voltas(0U), m_ponto(0U)
{}

Onibus::Onibus(const unsigned int pontos, const unsigned int bancos, const unsigned int empe)
    : m_pontos(pontos), m_bancos(bancos), m_empe(empe), m_voltas(0U), m_ponto(1U), m_pedirampradescer(0U)
{
    if(this->m_pontos < 2U)
        throw CExcecao(g_InvalidParameters);
    if(this->m_bancos < 1U)
        throw CExcecao(g_InvalidParameters);
    if(this->m_empe < 1U)
        throw CExcecao(g_InvalidParameters);
}

Onibus::~Onibus()
{}

Onibus Onibus::Inicializar(const unsigned int pontos, const unsigned int bancos, const unsigned int empe)
{ return Onibus(pontos, bancos, empe); }

} /* namespace BLL */
