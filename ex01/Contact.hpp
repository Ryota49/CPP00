# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include <cstdlib>

class Contact {

    public:
        // constructeur par default
        Contact();

        // Enregistre la donnée dans la private string adapter pour ce contact (this)
        void set_first_name(const std::string& str);
        void set_last_name(const std::string& str);
        void set_nickname(const std::string& str);
        void set_phone_number(const std::string& str);
        void set_darkest_secret(const std::string& str);

        // fonctions pour recuperer les infos du contact en question (avec return this)
        std::string get_first_name();
        std::string get_last_name();
        std::string get_nickname();
        std::string get_phone_number();
        std::string get_darkest_secret();
    
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};

# endif