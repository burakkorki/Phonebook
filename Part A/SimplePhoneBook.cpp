//
//  SimplePhoneBook.cpp
//  Homework 3
//
//  Created by Burak Korkmaz on 13.12.2018.
//  Copyright © 2018 Burak Korkmaz. All rights reserved.
//

#include "SimplePhoneBook.h"
#include <string>
#include <iostream>
#include <algorithm>

PhoneBook::PhoneBook(){
    head = NULL;
    numberOfPeople = 0;
}

PhoneBook::~PhoneBook(){
    while(head != NULL){
        PersonNode *cur = head;
        head = head ->next;
        cur->next = NULL;
        delete cur;
        cur = NULL;
    }
}

PhoneBook::PhoneBook (const PhoneBook& phoneBookToCopy){
    numberOfPeople = phoneBookToCopy.numberOfPeople;
    
    if(phoneBookToCopy.head == NULL)
        head = NULL;
    else{
        head = new PersonNode;
        head->t = phoneBookToCopy.head->t;
        
        PersonNode *temp = head;
        
        for(PersonNode *cur = phoneBookToCopy.head->next; cur != NULL; cur = cur->next){
            temp->next = new PersonNode;
            temp = temp->next;
            temp->t = cur->t;
        }
        temp->next = NULL;
    }
}

void PhoneBook::operator=(const PhoneBook &right){
    if(&right != this){
        numberOfPeople = right.numberOfPeople;
        
        if(right.head == NULL)
            head = NULL;
        else{
            head = new PersonNode;
            head->t = right.head->t;
            
            PersonNode *temp = head;
            
            for(PersonNode *cur = right.head->next; cur != NULL; cur = cur->next){
                temp->next = new PersonNode;
                temp = temp->next;
                temp->t = cur->t;
            }
            temp->next = NULL;
        }
    }
}

bool PhoneBook::addPerson(const string name){
    PersonNode *cur = head;
    string tempname = name;
    std::transform(tempname.begin(),tempname.end(),tempname.begin(),::tolower);
    if(head == NULL){
        head = new PersonNode;
        head->t = Person(name);
        head->next = NULL;
        numberOfPeople++;
        return true;
    }
    while (cur->next != NULL){
        string temp = cur->t.getName();
        std::transform(temp.begin(),temp.end(),temp.begin(),::tolower);
        if(temp == tempname)
            return false;
        cur = cur->next;
    }

    cur->next = new PersonNode;
    cur = cur->next;
    cur->t = Person(name);
    numberOfPeople++;
    cur->next = NULL;
    return true;
}

bool PhoneBook::removePerson(const string name){
    PersonNode *cur = head, *prev = NULL;
    string tempname = name;
    std::transform(tempname.begin(),tempname.end(),tempname.begin(),::tolower);
    
    while(cur != NULL){
        string temp = cur->t.getName();
        std::transform(temp.begin(),temp.end(),temp.begin(),::tolower);
        if(temp== tempname){
            numberOfPeople--;
            
            if(cur == head){
                head= head->next;
                return true;
            }
            else
                prev->next=cur->next;
            
            cur->next = NULL;
            delete cur;
            cur = NULL;
            
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
    
}

void PhoneBook::displayPeople(){
    PersonNode *temp = head;
    
    if(temp == NULL){
        cout << "--EMPTY--" << endl;
        return;
    }
    while(temp!= NULL){
        cout << "Person " << temp->t.getName() << endl;
        temp = temp->next;
    }
    
}

PhoneBook::PersonNode* PhoneBook::findPerson(string name){
    PersonNode *temp = head;
    std::transform(name.begin(),name.end(),name.begin(),::tolower);

    while(temp!= NULL){
        string tempname = temp->t.getName();
        std::transform(tempname.begin(),tempname.end(),tempname.begin(),::tolower);
        if(tempname==name)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
