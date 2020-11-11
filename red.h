#ifndef RED_H
#define RED_H

#include "enrutador.h"

class red
{
public:
    void agregar_enrutador(char nombre);
    void modificar_enlace_red(char nombre);
    void eliminar_enrutador(char nombre);
    void eliminar_enlace_red(char nombre);
    void agregar_ruta(char nombre, char ruta, int costo);
    void imprimir_todo();
    bool imprimir_enrutador(char nombre);
    void leer_archivo();
private:
    map<char,enrutador> net;
    map<char,enrutador>::iterator it;
};

#endif // RED_H
