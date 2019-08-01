//
//  Phone.cpp
//  Homework-3-PartB
//
//  Created by Burak Korkmaz on 13.12.2018.
//  Copyright © 2018 Burak Korkmaz. All rights reserved.
//

#include "Phone.h"

Phone::Phone(){
    areaCode = 0;
    number = 0;
}

Phone::Phone(const int areaCode, const int number){
    this->areaCode = areaCode;
    this->number = number;
}

int Phone::getAreaCode(){
    return areaCode;
}

int Phone::getNumber(){
    return number;
}
