#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
{
    total_contacts = 0;
    oldest_index = 0;
}

void PhoneBook::add_contact() 
{
    Contact new_contact;
    std::string input;

    std::cout << "Please enter your first name : ";
    if (!std::getline(std::cin, input))
        std::exit(0);
    while (input.length() <= 0)
    {
        std::cout << "Please enter a valid first name (not an empty field) : ";
        if (!std::getline(std::cin, input))
            std::exit(0);
    }
    new_contact.set_first_name(input);

    std::cout << "Please enter your last name : ";
    if (!std::getline(std::cin, input))
        std::exit(0);
    while (input.length() <= 0)
    {
        std::cout << "Please enter a valid last name (not an empty field) : ";
        if (!std::getline(std::cin, input))
            std::exit(0);
    }
    new_contact.set_last_name(input);

    std::cout << "Please enter your nickname : ";
    if (!std::getline(std::cin, input))
        std::exit(0);
    while (input.length() <= 0)
    {
        std::cout << "Please enter a valid nickname (not an empty field) : ";
        if (!std::getline(std::cin, input))
            std::exit(0);
    }
    new_contact.set_nickname(input);

    std::cout << "Please enter your phone number : ";
    if (!std::getline(std::cin, input))
        std::exit(0);
    while (input.length() <= 0)
    {
        std::cout << "Please enter a valid phone number (not an empty field) : ";
        if (!std::getline(std::cin, input))
            std::exit(0);
    }
    new_contact.set_phone_number(input);

    std::cout << "Please enter your darkest secret : ";
    if (!std::getline(std::cin, input))
        std::exit(0);
    while (input.length() <= 0)
    {
        std::cout << "Please enter a valid darkest secret (not an empty field) : ";
        if (!std::getline(std::cin, input))
            std::exit(0);
    }
    new_contact.set_darkest_secret(input);
    
    this->Contacts[oldest_index] = new_contact;
    this->oldest_index = (this->oldest_index + 1) % 8;
    if (total_contacts < 8)
        total_contacts++;
}

std::string PhoneBook::format_column(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void PhoneBook::search_contact() {

    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname"
              << "|" << std::endl;
    
    for (int i = 0; i < this->total_contacts; i++)
    {
        std::cout   << "|" << std::setw(10) << i
                    << "|" << std::setw(10) << format_column(this->Contacts[i].get_first_name())
                    << "|" << std::setw(10) << format_column(this->Contacts[i].get_last_name())
                    << "|" << std::setw(10) << format_column(this->Contacts[i].get_nickname())
                    << "|" << std::endl;
    }
    std::cout << "Please write an index between 0 and 7 to see more information about this contact : " << std::endl;
    std::string input;
    if (!std::getline(std::cin, input))
        std::exit(0);
    int index;
    if (input.length() == 1 && input[0] >= '0' && input[0] < '0' + this->total_contacts)
    {
        index = input[0] - 48;
        std::cout << "Contact index : " << index << std::endl;
        std::cout << "first name : " << this->Contacts[index].get_first_name() << std::endl;
        std::cout << "last name : " << this->Contacts[index].get_last_name() << std::endl;
        std::cout << "nickname : " << this->Contacts[index].get_nickname() << std::endl;
        std::cout << "Phone number : " << this->Contacts[index].get_phone_number() << std::endl;
        std::cout << "Darkest secret : " << this->Contacts[index].get_darkest_secret() << std::endl;
    }
    else
        std::cout << "Index is invalid (choose between 0 to 7 max)" << std::endl;
}