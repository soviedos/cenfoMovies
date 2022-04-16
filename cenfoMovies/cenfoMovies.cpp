// cenfoMovies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>

using namespace std;

#include "pelicula.h"
#include "listaPeliculas.h"
#include "listaCategorias.h"
#include "logica.h"

void menuMantenimientoPeliculas(listaPeliculas*& LP, listaCategorias*& LC) {
    int opc = 0;
    do {
        cout << "OPERACIONES DE PELICULAS " << endl;
        cout << endl;
        cout << "(1)  Agregar a la lista " << endl;
        cout << "(2)  Retirar de la lista " << endl;
        cout << "(3)  Consultar la lista " << endl;
        cout << "(4)  Modificar la lista " << endl;
        cout << "(5)  Listado catalogo completo en forma ascendente (descendente) por codigo " << endl;
        cout << "(6)  Listado catalogo completo en forma ascendente (descendente) por nombre " << endl;
        cout << "(7)  Listar peliculas cuyo nombre contenga una hilera especifica " << endl;
        cout << "(8)  Listado de catalogo de peliculas de un rango de año especifico " << endl;
        cout << "(9)  Listar peliculas cuya solicitud sean inferior a un limite dado " << endl;
        cout << "(10) Eliminar de la lista las peliculas cuya solicitud sea inferior a un limite dado " << endl;
        cout << "(11) Listado de peliculas sin categoria asignada " << endl;
        cout << "(0) Terminar" << endl;
        cout << endl;
        cout << "OPCION SELECCIONADA-> "; cin >> opc;
        cout << endl << endl;
        cout << "_____________________________________________________________________";
        cout << endl << endl;

        switch (opc) {
            case 1: {
                cout << "Agregar a la lista " << endl;
                int id;
                cout << "Por favor ingresar el número identificador de la película: " << endl;
                cin >> id;
                string nombre;
                cout << "Por favor ingresar el nombre de la película: " << endl;
                cin.ignore() >> nombre;
                int anio;
                cout << "Por favor ingresar el año en que se filmó la película: " << endl;
                cin >> anio;
                string director;
                cout << "Por favor ingresar el nombre del director de la película: " << endl;
                cin.ignore() >> director;
                int cantSolicitudes = 0;
                int cantCategorias = 0;
                bool agregado = LP->agregarPelicula(id, nombre, anio, director, cantSolicitudes, cantCategorias);
                if (agregado) {
                    cout << "La pelicula ha sido ingresada con exito al catalogo";
                }
                else {
                    cout << "La pelicula no se ha podido ingresar, por favor revisar los datos proporcionados";
                }
                break;
            }

            case 2: {
                cout << "Retirar de la lista " << endl << endl;
                int id;
                cout << "Ingrese el codigo de la pelicula a eliminar: ";
                cin >> id;
                bool eliminada = LP->retirarPelicula(id);
                if (eliminada) {
                    cout << "La pelicula " << id << " ha sido eliminada del catalogo" << endl;
                }
                else {
                    cout << "No se ha podido eliminar la pelicula";
                }

                break;
            }
            case 3: {
                cout << "Consultar la lista " << endl;
                int id;
                cout << "Ingrese el codigo de la pelicula a consultar: ";
                cin >> id;
                cout << endl;
                LP->consultarPelicula(id);
                break;
            }
            case 4: {
                cout << "Modificar la lista " << endl;

                break;
            }
            case 5: {
                cout << "Listado catalogo completo en forma ascendente por codigo " << endl << endl;
                LP->listarCatalogoPorCodigo();
                break;
            }
            case 6: {
                cout << "Listado catalogo completo en forma ascendente por nombre " << endl;

                break;
            }
            case 7: {
                cout << "Listar peliculas cuyo nombre contenga una hilera especifica " << endl;

                break;
            }
            case 8: {
                cout << "Listado de catalogo de peliculas de un rango de año especifico " << endl;

                break;
            }
            case 9: {
                cout << "Listar peliculas cuya solicitud sean inferior a un limite dado " << endl;

                break;
            }
            case 10: {
                cout << "Eliminar de la lista las peliculas cuya solicitud sea inferior a un limite dado " << endl;

                break;
            }
            case 11: {
                cout << "Listado de peliculas sin categoria asignada " << endl;

                break;
            }
            case 0: {
                cout << "Finalizando aplicacion.... Adios.... " << endl;
                break;
            }
            default:
                cout << "Opcion digitada no es valida " << endl;
                break;
            }

        cout << endl << endl;

    } while (opc != 0);
}

void menuMantenimientoCategorias(listaPeliculas*& LP, listaCategorias*& LC) {
    int opc = 0;
    do {
        cout << "OPERACIONES DE CATEGORIAS " << endl;
        cout << endl;
        cout << "(1)  Agregar a la categoria " << endl;
        cout << "(2)  Cerrar una categoria " << endl;
        cout << "(3)  Modificar la categoria " << endl;
        cout << "(4)  Consultar las categorias " << endl;
        cout << "(5)  Catalogo de categorias (nombre y cantidad de peliculas asociadas) " << endl;
        cout << "(6)  Agregar pelicula a una categoria " << endl;
        cout << "(7)  Retirar pelicula de una categoria " << endl;
        cout << "(8)  Consultar peliculas de una categoria en especifica " << endl;
        cout << "(9)  Catalogo de categorias con codigos y nombre de peliculas " << endl;
        cout << "(10) Catalogo de categorias con detalle completo de sus peliculas " << endl;
        cout << "(0) Terminar" << endl;
        cout << endl;
        cout << "OPCION SELECCIONADA-> "; cin >> opc;
        cout << endl << endl;
        cout << "_____________________________________________________________________";
        cout << endl << endl;

        switch (opc) {
        case 1: {
            cout << "Agregar a la categoria " << endl;
            break;
        }

        case 2: {
            cout << "Cerrar una categoria " << endl;

            break;
        }
        case 3: {
            cout << "Modificar la categoria " << endl;

            break;
        }
        case 4: {
            cout << "Consultar las categorias " << endl;

            break;
        }
        case 5: {
            cout << "Catalogo de categorias (nombre y cantidad de peliculas asociadas) " << endl;

            break;
        }
        case 6: {
            cout << "Agregar pelicula a una categoria " << endl;

            break;
        }
        case 7: {
            cout << "Retirar pelicula de una categoria " << endl;

            break;
        }
        case 8: {
            cout << "Consultar peliculas de una categoria en especifica " << endl;

            break;
        }
        case 9: {
            cout << "Catalogo de categorias con codigos y nombre de peliculas " << endl;

            break;
        }
        case 10: {
            cout << "Catalogo de categorias con detalle completo de sus peliculas " << endl;

            break;
        }
        case 0: {
            cout << "Finalizando aplicacion.... Adios.... " << endl;
            break;
        }
        default:
            cout << "Opcion digitada no es valida " << endl;
            break;
        }

        cout << endl << endl;

    } while (opc != 0);
}

void menuAdministrador() {
    string usuario;
    string password;
    int tipo = 1;
    char sp = '*';

    cout << "Ingrese el nombre de usuario: ";
    cin >> usuario;
    cout << "Ingrese su password: ";
    password = passwordDelUsuario(sp);
    bool valido = validarCredenciales(usuario, password, tipo);

    if (valido) {
        int opc = 0;
        do {
            cout << "OPERACIONES DE MANTENIMIENTO " << endl;
            cout << endl;
            cout << "(1)  Mantenimiento a peliculas " << endl;
            cout << "(2)  Mantenimiento a categorias " << endl;
            cout << "(0)  Terminar" << endl;
            cout << endl;
            cout << "OPCION SELECCIONADA-> "; cin >> opc;
            cout << endl << endl;
            cout << "_____________________________________________________________________";
            cout << endl << endl;

            switch (opc) {
            case 1: {
                listaPeliculas* LP = new listaPeliculas();
                listaCategorias* LC = new listaCategorias();
                menuMantenimientoPeliculas(LP, LC);
                break;
            }

            case 2: {
                listaPeliculas* LP = new listaPeliculas();
                listaCategorias* LC = new listaCategorias();
                menuMantenimientoCategorias(LP, LC);
                break;
            }
            case 0: {
                cout << "Finalizando aplicacion.... Adios.... " << endl;
                break;
            }
            default:
                cout << "Opcion digitada no es valida " << endl;
                break;
            }

            cout << endl << endl;

        } while (opc != 0);
    }
    else {
        cout << "Los credenciales no son validos" << endl;
    }
}

void menuCliente() {
    string usuario;
    string password;
    int tipo = 2;
    char sp = '*';

    cout << "Ingrese el nombre de usuario: ";
    cin >> usuario;
    cout << "Ingrese su password: ";
    password = passwordDelUsuario(sp);
    bool valido = validarCredenciales(usuario, password, tipo);

    if (valido) {
        int opc = 0;
        do {
            cout << "OPERACIONES DE CONSULTA " << endl;
            cout << endl;
            cout << "(1)  Consulta de peliculas " << endl;
            cout << "(2)  Consulta de categorias " << endl;
            cout << "(0)  Terminar" << endl;
            cout << endl;
            cout << "OPCION SELECCIONADA-> "; cin >> opc;
            cout << endl << endl;
            cout << "_____________________________________________________________________";
            cout << endl << endl;

            switch (opc) {
            case 1: {
                cout << "Consulta de peliculas " << endl;
                break;
            }

            case 2: {
                cout << "Consulta de categorias " << endl;
                break;
            }
            case 0: {
                cout << "Finalizando aplicacion.... Adios.... " << endl;
                break;
            }
            default:
                cout << "Opcion digitada no es valida " << endl;
                break;
            }

            cout << endl << endl;

        } while (opc != 0);
    }
    else {
        cout << "Los credenciales no son validos" << endl;
    }
}

void menuPrincipal() {
    int opc = 0;
    do {
        cout << " UNIVERSIDAD CENFOTEC" << endl;
        cout << "ESTRUCTURAS DE DATOS 1\n" << endl;
        cout << "CenfoMovies Streaming\n" << endl;
        cout << "*****INTERFACE MANEJO DE PROGRAMA*****\n" << endl;
        cout << "ESCOGER TIPO DE USUARIO" << endl;
        cout << endl;
        cout << "(1) Administrador " << endl;
        cout << "(2) Cliente " << endl;
        cout << endl;
        cout << "(0) Finalizar Programa" << endl;
        cout << endl;
        cout << "OPCION SELECCIONADA-> "; cin >> opc;
        cout << endl << endl;
        cout << "_____________________________________________________________________";
        cout << endl << endl;

        switch (opc) {
            case 1: {
                menuAdministrador();
                break;
            }
            case 2: {
                menuCliente();
                break;
            }
            case 0: {
                cout << "Finalizando aplicacion.... Adios.... " << endl;
                break;
            }
            default:
                cout << "Opcion digitada no es valida " << endl;
                break;
        }
        cout << endl << endl;

     } while (opc != 0);
}

int main()
{
    menuPrincipal();
    return 0;
}

