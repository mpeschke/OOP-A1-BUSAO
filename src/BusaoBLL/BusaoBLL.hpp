/**
    BusaoBLL.hpp
    Purpose: Busao Onibus class

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#pragma once

#include <string>
#include <vector>
#include <list>
#include "Passageiro.hpp"

namespace BLL {

class Onibus {
protected:
    unsigned int m_pontos;
    unsigned int m_bancos;
    unsigned int m_empe;
    unsigned int m_voltas;
    unsigned int m_ponto;
    unsigned int m_pedirampradescer;
    std::vector<Passageiro> m_passageiros;
    std::list<Bilhete> m_bilhetes;
    Onibus();
    Onibus(const unsigned int pontos, const unsigned int bancos, const unsigned int empe);
public:
    unsigned int get_pontos() const;
    unsigned int get_bancos() const;
    unsigned int get_empe() const;
    unsigned int get_voltas() const;
    unsigned int get_ponto() const;
    const std::vector<Passageiro>& get_passageiros() const;
    const std::list<Bilhete>& get_bilhetes() const;
    void Entrar(const Passageiro& passageiro);
    void Sair();
    unsigned int ContarTipoBilhetes(const Bilhete& tipo) const;
    void Pedirparadescer(const unsigned int passageiros);
    unsigned int Numerodeviagens() const;
    void Passarnoproximoponto();
    unsigned int PassageirosEmPe() const;
    unsigned int PassageirosSentados() const;
    
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
