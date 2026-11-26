#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
{
    total_contacts = 0;
    oldest_index = 0;
}

std::string PhoneBook::ask_field(std::string ask_message, std::string error_message)
{
    std::string input;

    std::cout << ask_message;
    if (!std::getline(std::cin, input))
        std::exit(0);
    while (input.length() <= 0)
    {
        std::cout << error_message;
        if (!std::getline(std::cin, input))
            std::exit(0);
    }
    return input;
}

void PhoneBook::add_contact() 
{
    Contact new_contact;
    
    new_contact.set_first_name(ask_field("Please enter your first name : ", "Please enter a valid first name (not an empty field) : "));
    new_contact.set_last_name(ask_field("Please enter your last name : ", "Please enter a valid last name (not an empty field) : "));
    new_contact.set_nickname(ask_field("Please enter your nickname : ", "Please enter a valid nickname (not an empty field) : "));
    new_contact.set_phone_number(ask_field("Please enter your phone number : ", "Please enter a valid phone number (not an empty field) : "));
    new_contact.set_darkest_secret(ask_field("Please enter your darkest secret : ", "Please enter a valid darkest secret (not an empty field) : "));
    
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
        std::cout << "No Contact at this index" << std::endl;
}
