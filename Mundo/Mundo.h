#pragma once
#include <SFML/Graphics.hpp>

class Mundo
{
protected:
    static Mundo* pinstancia;

    Mundo();
    Mundo(const Mundo&);
    Mundo* operator=(Mundo*);
    ~Mundo() {}
public:
    Mundo* instancia();
};