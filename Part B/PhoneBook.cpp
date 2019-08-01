//
//  PhoneBook.cpp
//  Homework-3-PartB
//
//  Created by Burak Korkmaz on 13.12.2018.
//  Copyright © 2018 Burak Korkmaz. All rights reserved.
//

#include "PhoneBook.h"
#include <string>
#include <iostream>
#include <algorithm>

PhoneBook::PhoneBook(){
    head = NULL;
    numberOfPeople = 0;
}

PhoneBook::~PhoneBook(){
    while(head != NULL){
        Node *cur = head;
        head = head ->next;
        cur->next = NULL;
        delete cur;
        cur = NULL;
    }
}

PhoneBook::PhoneBook(const PhoneBook &systemToCopy){
    numberOfPeople = systemToCopy.numberOfPeople;
    
    if(systemToCopy.head == NULL)
        head = NULL;
    else{
        head = new Node;
        head->t = systemToCopy.head->t;
        
        Node *temp = head;
        
        for(Node *cur = systemToCopy.head->next; cur != NULL; cur = cur->next){
            temp->next = new Node;
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
            head = new Node;
            head->t = right.head->t;
            
            Node *temp = head;
            
            for(Node *cur = right.head->next; cur != NULL; cur = cur->next){
                temp->next = new Node;
                temp = temp->next;
                temp->t = cur->t;
            }
            temp->next = NULL;
        }
    }
}

bool PhoneBook::addPerson(string name){
    Node *cur = head, *prev = NULL;
    string tempname;
    std::transform(tempname.begin(),tempname.end(),tempname.begin(),::tolower);
    
    while(cur != NULL){
        string temp = cur->t.getName();
        std::transform(temp.begin(),temp.end(),temp.begin(),::tolower);
        if(temp == tempname){
            cout << name  << " is added before." << endl;
            return false;
        }
        prev = cur;
        cur = cur->next;
    }
    
    Node *newPtr = new Node;
    newPtr->t = Person(name);
    
    
    if(head == NULL){
        newPtr->next = head;
        head = newPtr;
    }
    else{
        newPtr->next = cur;
        prev->next = newPtr;
    }
    
    numberOfPeople++;
    return true;
}

bool PhoneBook::removePerson(string name){
    Node *cur = head, *prev = NULL;
    string tempname = name;
    std::transform(tempname.begin(),tempname.end(),tempname.begin(),::tolower);
    
    while(cur != NULL){
        string temp = cur->t.getName();
        std::transform(temp.begin(),temp.end(),temp.begin(),::tolower);
        if(temp == tempname){
            if(cur == head)
                head = head->next;
            else
                prev->next = cur->next;
            
            cur->next = NULL;
            delete cur;
            cur = NULL;
            
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << "There is any person such as " << name << endl;
    return false;
}

bool PhoneBook::addPhone(string personName, int areaCode, int number){
    Node *temp = findPerson(personName);
    if(temp!= NULL){
        if(temp->t.addPhone( areaCode, number))
            return true;
        else{
            cout << "Number is already added" << endl;
            return false;
        }
    }
    else
        return false;
}

bool PhoneBook::removePhone(string personName, int areaCode, int number){
    Node *temp = findPerson(personName);
    if(temp!= NULL){
        if(temp->t.removePhone( areaCode, number))
            return true;
        else{
            cout << "There is no phone such as "<< areaCode << " " << number << endl;
            return false;
        }
    }
    else
        return false;
}

void PhoneBook::displayPerson(string name){
    Node *cur = head;
    std::transform(name.begin(),name.end(),name.begin(),::tolower);
    
    while(cur != NULL){
        string temp = cur->t.getName();
        std::transform(temp.begin(),temp.end(),temp.begin(),::tolower);
        if(temp == name){
            cout << cur->t.getName() << endl;
            cur->t.displayPhoneNumbers();
            return;
        }
        cur = cur->next;
    }
}

void PhoneBook::displayAreaCode(int areaCode){
    cout << areaCode << endl;
    Node *cur = head;
    int count = 0;
    while(cur != NULL){
        if(cur->t.displayPhoneArea(areaCode,cur->t.getName()))
            count++;
        cur = cur->next;
    }
    if(count == 0)
        cout << "--EMPTY--" << endl;
}

void PhoneBook::displayPeople(){
    Node *cur = head;
    
    if(head == NULL){
        cout << "--EMPTY--" << endl;
        return;
    }
    
    while(cur != NULL){
        cout <<  cur->t.getName() << ", " << cur->t.numberOfPhone() << " has" << endl;
        cur = cur->next;
    }
}

PhoneBook::Node* PhoneBook::findPerson(const string name){
    Node *cur = head;
    string tempname = name;
    std::transform(tempname.begin(),tempname.end(),tempname.begin(),::tolower);
    while(cur != NULL){
        string temp = cur->t.getName();
        std::transform(temp.begin(),temp.end(),temp.begin(),::tolower);
        if(temp == tempname)
            return cur;
        cur = cur->next;
    }
    cout<< "There is not such a person" << endl;
    return NULL;;
}


