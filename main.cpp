#include "enrutador.h"
#include "red.h"
#include "archivo.h"

int main()
{
    /*
    enrutador router;
    int a;
    char name;
    while (true) {
        cout << "1 Agregar enlace" << endl;
        cout << "2 Eliminar enlace" << endl;
        cout << "3 Modificar enlace" << endl;
        cout << "4 Imprimir todo" << endl;
        cout << "Ingrese una opcion: "; cin >> a;

        switch (a)
        {
            case 1:
                cout << "Ingrese nombre y costo del enlace: ";
                cin >> name >> a;
                if (!router.agregar_enlace(name,a))
                {
                    cout << "Error al agragar el enlace, el enlace ya existe." << endl;
                }
            break;

            case 2:
                cout<< "Ingrese nombre del enlace para eliminar: ";
                cin >>name;
                if (!router.eliminar_enlace(name))
                {
                    cout << "Error al eliminar el enlace, el enlace no existe." << endl;
                }
            break;

            case 3:
                cout<< "Ingrese nombre del enlace y costro para modificarlo: ";
                cin >> name >> a;
                if (!router.modificar_enlace(name,a))
                {
                    cout << "Error al modificar el enlace, el enlace no existe." << endl;
                }
            break;

            case 4:
                router.imprimir();
            break;

            default:

                cout<<" opcion incorrecta";
        }
    }
    */

    red net;
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
        cout<<"7 leer archivo para red topografica "<<endl;
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

            case 7:
                net.leer_archivo();
            break;

            default:

            break;
        }
    }
    return 0;
}
