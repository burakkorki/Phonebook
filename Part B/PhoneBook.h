//
//  PhoneBook.hpp
//  Homework-3-PartB
//
//  Created by Burak Korkmaz on 13.12.2018.
//  Copyright © 2018 Burak Korkmaz. All rights reserved.
//

#ifndef __PHONEBOOK_H
#define __PHONEBOOK_H

#include <string>
using namespace std;
#include "Person.h"

class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();
    PhoneBook( const PhoneBook& systemToCopy );
    void operator=( const PhoneBook &right );
    bool addPerson( string name );
    bool removePerson( string name );
    bool addPhone( string personName, int areaCode, int number );
    bool removePhone( string personName, int areaCode, int number );
    void displayPerson( string name );
    void displayAreaCode( int areaCode );
    void displayPeople();
    
private:
    struct Node {
        Person t;
        Node* next;
    };
    Node *head;
    int numberOfPeople;
    Node* findPerson( string name );
};
#endif
