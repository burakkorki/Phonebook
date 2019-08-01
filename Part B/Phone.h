//
//  Phone.hpp
//  Homework-3-PartB
//
//  Created by Burak Korkmaz on 13.12.2018.
//  Copyright © 2018 Burak Korkmaz. All rights reserved.
//

#ifndef __PHONE_H
#define __PHONE_H

#include <string>
using namespace std;

class Phone{
public:
    Phone();
    Phone( const int areaCode, const int number );
    int getAreaCode();
    int getNumber();
    
private:
    int areaCode;
    int number; };
#endif
