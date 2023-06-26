#ifndef DTFECHA
#define DTFECHA

#include <iostream>

class DTFecha{
private:
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;

    int comparacion(DTFecha f);
public:
    //C&D
    DTFecha();
    DTFecha(int dia, int mes, int anio, int hora, int minuto);
    ~DTFecha();

    // Getters
    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();

    //Comparadores
    bool operator==(DTFecha f);
    bool operator!=(DTFecha f);
    bool operator<(DTFecha f);
    bool operator>(DTFecha f);
    bool operator<=(DTFecha f);
    bool operator>=(DTFecha f);

    //output
    friend std::ostream& operator<<(std::ostream& os, DTFecha f);
};
#endif