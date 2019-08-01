//
//  Person.cpp
//  Homework-3-PartB
//
//  Created by Burak Korkmaz on 13.12.2018.
//  Copyright © 2018 Burak Korkmaz. All rights reserved.
//

#include "Person.h"
#include <string>
#include <iostream>

Person::Person(){
    head = NULL;
    name = "";
    totalPhones = 0;
}

Person::Person(const string name){
    head = NULL;
    this->name = name;
    this->totalPhones = 0;
}

Person::~Person(){
    while(head != NULL){
        PhoneNode *cur = head;
        head = head ->next;
        cur->next = NULL;
        delete cur;
        cur = NULL;
    }
    
    totalPhones = 0;
}

Person::Person(const Person &personToCopy){
    name = personToCopy.name;
    totalPhones = personToCopy.totalPhones;
    
    if(personToCopy.head == NULL)
        head = NULL;
    else{
        head = new PhoneNode;
        head->p = personToCopy.head->p;
        
        PhoneNode *temp = head;
        
        for(PhoneNode *cur = personToCopy.head->next; cur != NULL; cur = cur->next){
            temp->next = new PhoneNode;
            temp = temp->next;
            temp->p = cur->p;
        }
        temp->next = NULL;
    }
}

void Person::operator=(const Person &right){
    if(&right != this){
        name = right.name;
        totalPhones = right.totalPhones;
        
        if(right.head == NULL)
            head = NULL;
        else{
            head = new PhoneNode;
            head->p = right.head->p;
            
            PhoneNode *temp = head;
            
            for(PhoneNode *cur = right.head->next; cur != NULL; cur = cur->next){
                temp->next = new PhoneNode;
                temp = temp->next;
                temp->p = cur->p;
            }
            temp->next = NULL;
        }
    }
}

string Person::getName(){
    return name;
}

bool Person::addPhone( const int areaCode, const int number ){
    PhoneNode *cur = head, *prev = NULL;
    
    while(cur != NULL){
        if(cur->p.getAreaCode() == areaCode && cur->p.getNumber() == number){
            cout<< "The number is already added" <<endl;
            return false;
        }
        prev = cur;
        cur = cur->next;
    }
    
    PhoneNode *newPtr = new PhoneNode;
    newPtr->p = Phone(areaCode,number);
    
    
    if(cur == NULL){
        newPtr->next = head;
        head = newPtr;
    }
    else{
        newPtr->next = cur;
        prev->next = newPtr;
    }
    totalPhones++;
    return true;
}

bool Person::removePhone( const int areaCode, const int number ){
    PhoneNode *cur = head, *prev = NULL;
    
    while(cur != NULL){
        if(cur->p.getAreaCode() == areaCode && cur->p.getNumber() == number){
            if(cur == head)
                head = head->next;
            else
                prev->next = cur->next;
            
            cur->next = NULL;
            delete cur;
            cur = NULL;
            
            totalPhones--;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << "There is not such a phone number. area code: " << areaCode << " number: " << number << endl;
    return false;
}

void Person::displayPhoneNumbers(){
    PhoneNode *cur = head;
    
    if(head == NULL){
        cout << "--EMPTY--" << endl;
        return;
    }
    
    while(cur != NULL){
        cout << "Phone Number: "<<  cur->p.getAreaCode() << "," << cur->p.getNumber() <<endl;
        cur = cur->next;
    }
    
}

Person::PhoneNode* Person::findPhone(const int areaCode, const int number){
    PhoneNode *cur = head;
    
    while(cur != NULL){
        if(cur->p.getAreaCode() == areaCode || cur->p.getNumber() == number)
            return cur;
        cur = cur->next;
    }
    return NULL;;
}


bool Person::displayPhoneArea(int area,string name){
    PhoneNode *cur = head;
    int count = 0;
    
    while(cur != NULL){
        if(cur->p.getAreaCode() == area){
            if(count==0)
                cout<< name << endl;
            cout << "Phone Number: "<<  cur->p.getAreaCode() << ", " << cur->p.getNumber() <<endl;
            count++;
        }
        cur = cur->next;
    }
    if(count != 0){
        cout << endl;
        return true;
    }
    else
        return false;
}

int Person::numberOfPhone(){
    return totalPhones;
}
