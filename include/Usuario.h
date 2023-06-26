#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <vector>

#include "Notificacion.h"
#include "IObserver.h"

class Usuario: public IObserver {
private:
    std::string nickname;
    std::string nombre;
    std::string pass;
    std::string desc;
    std::vector<Notificacion*> notificaciones;
public:

    Usuario(std::string nickname, std::string nombre, std::string pass, std::string desc);
    virtual ~Usuario() = 0;

    //getters
    std::string getNickname();
    std::string getNombre();
    std::string getPass();
    std::string getDesc();


    //setters
    void setNickname(std::string nickname);
    void setNombre(std::string nombre);
    void setPass(std::string pass);
    void setDesc(std::string desc);

    void notificar(Notificacion* notificacion);
    vector<DTNotificaciones> consultarNotificaciones();
};

#endif

