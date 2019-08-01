//
//  Person.hpp
//  Homework-3-PartB
//
//  Created by Burak Korkmaz on 13.12.2018.
//  Copyright © 2018 Burak Korkmaz. All rights reserved.
//

#ifndef __PERSON_H
#define __PERSON_H

#include <string>
using namespace std;
#include "Phone.h"

class Person{ public:
    Person();
    Person( const string name  );
    ~Person();
    Person( const Person& personToCopy );
    void operator=( const Person &right );
    string getName();
    bool addPhone( const int areaCode, const int number );
    bool removePhone( const int areaCode, const int number );
    void displayPhoneNumbers();
    
    int numberOfPhone();
    bool displayPhoneArea(int area, string name);
private:
    struct PhoneNode {
        Phone p;
        PhoneNode* next;
    };
    PhoneNode *head;
    string name;
    int totalPhones;
    PhoneNode* findPhone( const int areaCode, const int number );
};
#endif
