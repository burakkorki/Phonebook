//
//  SimplePerson.cpp
//  Homework 3
//
//  Created by Burak Korkmaz on 13.12.2018.
//  Copyright © 2018 Burak Korkmaz. All rights reserved.
//

#include "SimplePerson.h"

Person::Person(string name){
    this->name = name;
}

Person::~Person(){
    this->name = "";
}

Person::Person( const Person &personToCopy ){
    this->name = personToCopy.name;
}

void Person::operator=(const Person &right){
    this->name = right.name;
}

string Person::getName(){
    return name;
}
