//
//  main.cpp
//  GameServerProgramming
//
//  Created by signorinotang on 14-8-12.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "type.h"
#include "Stream.h"

int main(int argc, const char * argv[])
{
    // insert code here...
    std::ostringstream oss;
//    oss << sizeof(bool);
//    std::cout << "bool:" << oss.str() << std::endl;
//    oss.str("");
//    oss << sizeof(unsigned long);
//    std::cout << "unsigned long:" << oss.str() << std::endl;
    
    s8 buf[1024];
    CStreamSP cstream;
    cstream->setBuffer(buf);
    int data1 = 1;
    unsigned data2 = 2;
    int data3 = 3;
    cstream->WriteInt32(data1);
    cstream->WriteUInt32(data2);
    cstream->WriteInt32(data3);
    
    int intData;
    u32 uintData;
    
    
    cstream->setBuffer(buf);
    cstream->ReadInt32(&intData);
    oss << intData;
    std::cout << oss.str() << std::endl;
    oss.str("");
    
    cstream->ReadUInt32(&uintData);
    oss << uintData;
    std::cout << oss.str() << std::endl;
    oss.str("");
    
    cstream->ReadInt32(&intData);
    oss << intData;
    std::cout << oss.str() << std::endl;
    
    return 0;
    
}

