#include <iomanip>
#include <unistd.h>
#include <iostream>
#include <cstdlib> 
#include <chrono>
#include <C:\Users\luisd\Desktop\Examen\lib\ldColor.h>

using namespace std;

//limpia la terminal
void ldLimpiarTerminal() {
    system("cls");
}

// Muestra barra de carga
void ldMostrarBarraCarga(int porcentaje) 
{
    std::cout << "[";
    int barraLlena = porcentaje / 5;
    for (int i = 0; i < 20; ++i) {
        if (i < barraLlena)
            std::cout << "*";
        else
            std::cout << " ";
    }
    std::cout << "] " << porcentaje << "%";
}
int ldPorcentaje() 
{
    int porcentaje = 0;
    int direccion = 1;

    while (true) {
        ldMostrarBarraCarga(porcentaje);
        std::cout << "\r";
        std::cout.flush();

        if (porcentaje == 100 && direccion == 1) {
        //     direccion = -1;
        // } else if (porcentaje == 0 && direccion == -1) {
            break;  // Salir del bucle cuando regrese a 0
        }

        porcentaje += direccion;
        usleep(1000);  // Retraso de 100 milisegundos (0.1 segundos)
    }

    std::cout << std::endl;
    std::cout << "Carga completa." << std::endl;

    return 0;
}

//muestra el menu
void ldMostrarMenu() 
{
    // ldLimpiarTerminal();
    ldSetTextColor(textColorRed);
    cout << "\n1. COMIENZA EL JUEGO" << endl;
    cout << "2. SALIR" << endl;
}


// Funcion para validar el inicio de sesion
bool login(string correo, string contrasena) {
    // Correos y contrasenas válidas
    string correos_validos[] = {"luis.diaz04@epn.edu.ec", "profe"};
    string contrasenas_validas[] = {"1752153807", "1234"};

    // Comprobar si el correo y la contrasena coinciden
    for (int i = 0; i < 2; i++) {
        if (correo == correos_validos[i] && contrasena == contrasenas_validas[i]) {
            return true;  // Inicio de sesion exitoso
        }
    }

    return false;  // Inicio de sesion fallido
}

//
// Inicia el programa
int main() {
    ldLimpiarTerminal();
    ldSetTextColor(textColorBlue);
    ldMostrarBarraCarga(ldPorcentaje());
    string correo, contrasena;
    bool inicio_sesion_exitoso = false;
    int intentos = 0;
    string nombreUsuario = "";

    ldLimpiarTerminal();
    ldSetTextColor(textColorGreen);
    cout << "\nCarga exitosa. Continua con el login :D" << endl;
    ldSetTextColor(textColorRed);
    cout << "\nSolo tienes 3 intentos" << endl;
    ldSetTextColor(textColorYellow);
    
    while (intentos < 3 && !inicio_sesion_exitoso) {
        cout << "\nInicio de sesion" << endl;
        cout << "Correo: ";
        cin >> correo;
        cout << "Contrasena: ";
        cin >> contrasena;

        if (login(correo, contrasena)) {
            ldSetTextColor(textColorGreen);
            cout << "\nInicio de sesion exitoso." << endl;
            inicio_sesion_exitoso = true;

            // Asignar el nombre de usuario según el correo electronico
            if (correo == "luis.diaz04@epn.edu.ec") {
                nombreUsuario = "LUIS";
            } else if (correo == "profe") {
                nombreUsuario = "PROFE";
            }
        } else {
            ldSetTextColor(textColorRed);
            cout << "Inicio de sesion fallido. Correo o contrasena incorrectos." << endl;
            intentos++;
        }
    }

    if (!inicio_sesion_exitoso) {
        ldSetTextColor(textColorRed);
        cout << "Demasiados intentos. Cerrando el programa..." << endl;
        return 0;
    }

    ldSetTextColor(textColorCyan);
    cout << "\nBienvenido, " << nombreUsuario << "!" << endl;

    ldSetTextColor(textColorWhite);
    cout << "\nCEDULA: 1752153807"<< endl;
    cout << "CORREO: LUIS.DIAZ04@EPN.EDU.EC"<< endl;
    cout << "NOMBRE: LUIS ALEXANDER DIAZ BENALCAZAR"<< endl;

    ldMostrarMenu();

    int opcion;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Hubo problemas al implemetar el juego al menu, el juego esta en src/ldJuego.cpp :(" << endl;
            break;
        case 2:
            cout << "Saliendo del programa..." << endl;
            return 0;
        default:
            cout << "Opcion invalida." << endl;
            break;
    }

    return 0;
}



