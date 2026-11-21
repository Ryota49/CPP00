# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

    public:
        PhoneBook();
        void add_contact();
        void search_contact();
        std::string format_column(std::string str);

    private:
        Contact Contacts[8];
        int total_contacts;
        int oldest_index;
};

# endif