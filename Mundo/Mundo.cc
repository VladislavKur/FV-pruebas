#include "Mundo.h"

Mundo* pinstancia=NULL;

Mundo* Mundo::instancia(){
    if(pinstancia==NULL){
        pinstancia = new Mundo;
    }
    return pinstancia;
}

Mundo::Mundo(){
    
}