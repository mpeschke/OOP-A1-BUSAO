/**
    Passageiro.hpp
    Purpose: Busao Passageiro class

    @author Matheus Peschke
    @version 1.0.0 2021-05-10
*/
#pragma once

namespace BLL {

enum Bilhete {
    Indefinido,
    Normal,
    Idoso,
    Estudante
};

class Passageiro {
protected:
    Bilhete m_bilhete;
    Passageiro();
    Passageiro(Bilhete bilhete);
public:
    const Bilhete& get_bilhete() const;
    void set_bilhete(const Bilhete& bilhete);
/**
    Instancia um objeto da classe Passageiro.

    @return Objeto da classe Passageiro.
    @param bilhete tipo do bilhete apresentado pelo passageiro ao embarcar.
*/
    static Passageiro instantiate(Bilhete bilhete);
public:
    virtual ~Passageiro();
};

} /* namespace BLL */
