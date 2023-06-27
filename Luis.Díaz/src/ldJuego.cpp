#include <iostream>
#include <array>
#include <algorithm>
#include <unistd.h>

using namespace std;

// Constantes
const int NUM_SUJETOS = 3;
const int MAX_PESO_BARCA = 2;

// Enumeración para representar a los sujetos
enum Sujeto { LOBO, LECHUGA, OVEJA };

// Nombres de los sujetos
const array<string, NUM_SUJETOS> nombreSujeto = {"lobo", "lechuga", "oveja"};

// Función para mostrar el estado actual del juego
void mostrarEstado(const array<int, NUM_SUJETOS>& orilla, bool barcaEnOrillaInicial) {
    string barcaPosicion = barcaEnOrillaInicial ? "orilla" : "barca";
    string otraOrilla = barcaEnOrillaInicial ? "barca" : "orilla";

    cout << "Estado actual:" << endl;
    cout << "Orilla: ";
    for (int i = 0; i < NUM_SUJETOS; i++) {
        if (orilla[i] == 1) {
            cout << nombreSujeto[i] << " ";
        }
    }
    cout << endl;

    cout << "Barca: ";
    for (int i = 0; i < NUM_SUJETOS; i++) {
        if (orilla[i] == 2) {
            cout << nombreSujeto[i] << " ";
        }
    }
    cout << endl;

    cout << "_______________" << barcaPosicion << "_____" << otraOrilla << "_______________" << endl;

    usleep(500000); // Retardo de 500 ms (0.5 segundos)
}

// Función para verificar si el juego ha terminado
bool juegoTerminado(const array<int, NUM_SUJETOS>& orilla) {
    // El lobo se come la oveja
    if (orilla[LOBO] == orilla[OVEJA] && orilla[LOBO] != orilla[LECHUGA])
        return true;

    // La oveja se come la lechuga
    if (orilla[OVEJA] == orilla[LECHUGA] && orilla[OVEJA] != orilla[LOBO])
        return true;

    return false;
}

int main() {
    array<int, NUM_SUJETOS> orilla = {1, 1, 1};  // Todos los sujetos en la orilla inicial
    bool barcaEnOrillaInicial = true;  // La barca se encuentra en la orilla inicial
    int viajes = 0;

    cout << "Escenario de partida:" << endl;
    mostrarEstado(orilla, barcaEnOrillaInicial);

    // Menú
    while (!juegoTerminado(orilla)) {
        int opcion;
        cout << endl;
        cout << "0: solo" << endl;
        cout << "1: lobo" << endl;
        cout << "2: lechuga" << endl;
        cout << "3: oveja" << endl;
        cout << "4: cambiar posición de la barca" << endl;
        cout << "Elige una opción: ";
        cin >> opcion;

        if (opcion < 0 || opcion > NUM_SUJETOS + 1) {
            cout << "Opción inválida. Inténtalo nuevamente." << endl;
            continue;
        }

        // Mover el sujeto seleccionado a la barca
        if (opcion >= 1 && opcion <= NUM_SUJETOS) {
            int sujetoSeleccionado = opcion - 1;
            if (orilla[sujetoSeleccionado] != barcaEnOrillaInicial) {
                cout << "El sujeto seleccionado no está en la orilla actual. Inténtalo nuevamente." << endl;
                continue;
            }

            if (count(orilla.begin(), orilla.end(), 2) >= MAX_PESO_BARCA) {
                cout << "La barca ya está llena. Debes cambiar la posición de la barca primero." << endl;
                continue;
            }

            orilla[sujetoSeleccionado] = 2;
            mostrarEstado(orilla, barcaEnOrillaInicial);
        }

        // Cambiar posición de la barca
        if (opcion == NUM_SUJETOS + 1) {
            barcaEnOrillaInicial = !barcaEnOrillaInicial;
            mostrarEstado(orilla, barcaEnOrillaInicial);
        }

        viajes++;
    }

    cout << "¡Juego terminado!" << endl;
    cout << "Total de viajes realizados: " << viajes << endl;

    return 0;
}














