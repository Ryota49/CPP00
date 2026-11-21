#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Please enter a command (ADD, SEARCH, EXIT) : " << std::endl;
        if (!std::getline(std::cin, command))
            std::exit(0);
        if (command == "ADD")
            phonebook.add_contact();
        if (command == "SEARCH")
            phonebook.search_contact();
        if (command == "EXIT")
            break;
    }
    return (0);
}
