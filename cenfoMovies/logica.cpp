//
//

#include "logica.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

bool validarCredenciales(string _usuario, string _password, int _tipo) {
	bool valido = false;
    string userAdmin = "Sergio";
    string passAdmin = "1234";
    string userCliente = "Sergio";
    string passCliente = "123";

    if (_tipo == 1) {
        if (_usuario == userAdmin && _password == passAdmin) {
            valido = true;
        }
    }
    else {
        if (_usuario == userCliente && _password == passCliente) {
            valido = true;
        }
    }
    
	return valido;
}

enum IN {

    // 13 is ASCII for carriage
    // return
    IN_BACK = 8,
    IN_RET = 13

};

string passwordDelUsuario(char sp = '*')
{
    // Stores the password
    string passwd = "";
    char ch_ipt;

    // Until condition is true
    while (true) {

        ch_ipt = _getch();

        // if the ch_ipt
        if (ch_ipt == IN::IN_RET) {
            cout << endl;
            return passwd;
        }
        else if (ch_ipt == IN::IN_BACK
            && passwd.length() != 0) {
            passwd.pop_back();

            // Cout statement is very
            // important as it will erase
            // previously printed character
            cout << "\b \b";

            continue;
        }

        // Without using this, program
        // will crash as \b can't be
        // print in beginning of line
        else if (ch_ipt == IN::IN_BACK
            && passwd.length() == 0) {
            continue;
        }

        passwd.push_back(ch_ipt);
        cout << sp;
    }
}