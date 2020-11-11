#include "red.h"

void red::agregar_enrutador(char nombre)
{
    enrutador router;
    char name;
    int valor=0;
    if (net.find(nombre)==net.end())//SI NO EXISTE
    {
        router.agregar_enlace(nombre,0);//se une consigo mismo
        for (it=net.begin();it!=net.end();it++)
        {
            router.agregar_enlace(it->first,-1);
            it->second.agregar_enlace(nombre,-1);
        }
        do
        {
            cout<<"Ingrese el nombre del nodo con el que se va a enlazar el nodo "<<nombre<<endl;
            cin>>name;
            if(name==nombre)
            {
                cout<<"No se puede enlazar a si mismo"<<endl;
            }
            else if(name!='+')
            {

                if(!router.modificar_enlace(name,valor))
                {
                    cout<<"El nodo ingresado no existe"<<endl;
                }
                else
                {
                    cout<<"Ingrese el costo del enlace: ";
                    cin>>valor;
                    net[name].modificar_enlace(nombre,valor);
                    router.modificar_enlace(name,valor);
                }
            }
        }
        while(name!='+');
        net.insert(pair<char,enrutador>(nombre,router));
        system("CLS");
    }
    else
    {
        cout<<"El enrutador ya existe"<<endl;
    }
    system("CLS");
}

void red::modificar_enlace_red(char nombre)
{
    char name;
    int valor;
    cout<< "Enlace que desea modificar : "<<endl;
    cin>>name;
    if(name==nombre)
    {
        cout<<"No se puede modificar el enlace consigo mismo"<<endl;
    }
    else
    {
        for (it=net.begin();it!=net.end();it++)
        {
            if (it->first==nombre)
            {
                cout<<"Ingrese el nuevo valor del enlace: ";
                cin>>valor;
                if(!it->second.modificar_enlace(name,valor))
                {
                    cout<<"El nodo ingresado no existe"<<endl;
                }
                else
                {
                    it->second.modificar_enlace(name,valor);
                    net[name].modificar_enlace(nombre,valor);
                    cout<<"Enlace modificado correctamente"<<endl;
                }
            }
        }
    }
}

void red::eliminar_enrutador(char nombre)
{
    if (net.find(nombre)!=net.end())//SI ESTA EN EL MAPA
    {
        net.erase(nombre);
        for(it=net.begin();it!=net.end();it++)
        {
            it->second.eliminar_enlace(nombre);
        }
    }
    else
    {
        cout<<"Nodo no encontrado"<<endl;
    }
}

void red::eliminar_enlace_red(char nombre)
{
    char name;
    cout<< "Enlace que desea eliminar : "<<endl;
    cin>>name;
    if(name==nombre)
    {
        cout<<"No se puede eliminar el enlace consigo mismo"<<endl;
    }
    else
    {
        for (it=net.begin();it!=net.end();it++)
        {
            if (it->first==nombre)
            {
                if(!it->second.modificar_enlace(name,-1))
                {
                    cout<<"El nodo ingresado no existe"<<endl;
                }
                else
                {
                    it->second.modificar_enlace(name,-1);
                    net[name].modificar_enlace(nombre,-1);
                    cout<<"Enlace eliminado correctamente"<<endl;
                }
            }
        }
    }
}

void red::imprimir_todo()
{
    for (it=net.begin();it!=net.end();it++)
    {
        cout <<"Precio de "<< it->first<<" con:\n";
        it->second.imprimir();
    }
}

bool red::imprimir_enrutador(char nombre)
{
    bool ver=true;
    if(net.find(nombre)!=net.end())
    {
        for (it=net.begin();it!=net.end();it++)
        {
            if (it->first==nombre)
            {
                cout << "El nodo " << it->first<< " tiene enlaces con: " << endl;
                it->second.imprimir();
            }
        }
    }
    else
    {
        cout<<"El enrutador no existe"<<endl;
        ver=false;
    }
    return ver;
}

void red::leer_archivo()
{
    ifstream archivo("red.txt");
    if(!archivo.is_open())
    {
        cout<<"El archivo no existe "<<endl;
    }
    else
    {
        char letra;
        while(!archivo.eof())
        {
            letra=archivo.get();
            cout<<letra;
        }
    }
    archivo.close();
    cout<<endl;
}




