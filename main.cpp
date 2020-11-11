#include "enrutador.h"
#include "red.h"
#include "archivo.h"

int main()
{

    red net;
    leer_archivo(net);
    int a;
    char name;
    while(true)
    {
        cout<<"1 Crear enrutador (permite enlaces) "<<endl;
        cout<<"2 Eliminar enrutador"<<endl;
        cout<<"3 Eliminar enlace"<<endl;
        cout<<"4 Modificar enlace"<<endl;
        cout<<"5 Imprimir enrutador "<<endl;
        cout<<"6 Imprimir red completa "<<endl;
        cin>>a;
        switch(a)
        {
            case 1:
                cout<<"Ingrese el nombre del nuevo enlace: ";
                cin>>name;
                net.agregar_enrutador(name);
            break;

            case 2:
                cout<< "Ingrese nombre del enrutador para eliminar: ";
                cin>>name;
                net.eliminar_enrutador(name);

            break;

            case 3:
                cout<< "Ingrese nombre de algun nodo para ver sus enlace: ";
                cin>>name;
                if(net.imprimir_enrutador(name))
                {
                     net.eliminar_enlace_red(name);
                }

            break;

            case 4:
                cout<< "Ingrese nombre de algun nodo para ver sus enlace: ";
                cin>>name;
                if(net.imprimir_enrutador(name))
                {
                     net.modificar_enlace_red(name);
                }

            break;

            case 5:
                cout<<"Ingrese nombre del enrutador a motrar: ";
                cin>>name;
                net.imprimir_enrutador(name);
            break;

            case 6:
                net.imprimir_todo();
            break;

            default:
                cout<<"Opcion incorrecta"<<endl;
            break;
        }
    }
    return 0;
}
