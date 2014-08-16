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
#include "CircularQueue.h"

int main(int argc, const char * argv[])
{
    // insert code here...
    std::ostringstream oss;
//    oss << sizeof(bool);
//    std::cout << "bool:" << oss.str() << std::endl;
//    oss.str("");
//    oss << sizeof(unsigned long);
//    std::cout << "unsigned long:" << oss.str() << std::endl;
    
//    std::string s1 = "123";
//    std::string &s2 = s1;
//    s2 = "1";
//    std::cout << s1 << std::endl;
//    
//    s8 buf[1024];
//    CStreamSP cstream;
//    cstream->setBuffer(buf);
//    int data1 = 1;
//    unsigned data2 = 2;
//    int data3 = 3;
//    cstream->WriteInt32(data1);
//    cstream->WriteUInt32(data2);
//    cstream->WriteInt32(data3);
//    
//    int intData;
//    u32 uintData;
//    
//    
//    cstream->setBuffer(buf);
//    cstream->ReadInt32(&intData);
//    oss << intData;
//    std::cout << oss.str() << std::endl;
//    oss.str("");
//    
//    cstream->ReadUInt32(&uintData);
//    oss << uintData;
//    std::cout << oss.str() << std::endl;
//    oss.str("");
//    
//    cstream->ReadInt32(&intData);
//    oss << intData;
//    std::cout << oss.str() << std::endl;
//    
//    std::cout << sizeof(unsigned long) << std::endl;
    
    typedef struct _Queue_data {
        int data1;
        int data2[100];
    } Queue_data;
    
    CircularQueue<Queue_data> Queue;
    
    Queue_data pushData;
    Queue_data popData;
    pushData.data1 = 1;
    memset(pushData.data2, 0, sizeof(pushData.data2));
    
    Queue.Push(pushData);
    
    pushData.data1 = 2;
    
    Queue.Push(pushData);
    
    pushData.data1 = 3;
    
    Queue.Push(pushData);
    
    while(Queue.Pop(popData)) {
        std::cout << popData.data1 << std::endl;
    }
    
    
    
    return 0;
    
}

