#ifndef DTUSUARIO_HPP
#define DTUSUARIO_HPP

#include <string>

class DTUsuario {
    private:
        std::string nickname;
        std::string nombre;
        std::string pass;
        std::string desc;
    public:
        DTUsuario();
        DTUsuario(std::string nickname, std::string nombre, std::string pass, std::string desc);
        virtual ~DTUsuario();
        //Getters
        std::string getNickname();
        std::string getNombre();
        std::string getPass();
        std::string getDesc();
        
};

#endif