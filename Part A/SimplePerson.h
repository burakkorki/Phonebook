//
//  SimplePerson.hpp
//  Homework 3
//
//  Created by Burak Korkmaz on 13.12.2018.
//  Copyright © 2018 Burak Korkmaz. All rights reserved.
//

#ifndef __SIMPLE_PERSON_H
#define __SIMPLE_PERSON_H

#include <string>
using namespace std;

class Person { public:
    Person( const string name = "" );
    ~Person();
    Person ( const Person &personToCopy );
    void operator=( const Person &right );
    string getName();
    
private:
    string name;
};
#endif
