//
//  CircularQueue.h
//  GameServerProgramming
//
//  Created by signorinotang on 14-8-12.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#ifndef GameServerProgramming_CircularQueue_h
#define GameServerProgramming_CircularQueue_h

#include <string.h>

#define MAX_QUEUE_LENGTH 5


template <class T>
class CircularQueue {
public:
    CircularQueue() {
        memset(m_Queue, 0, sizeof(m_Queue));
        m_QueueHead = m_QueueTail = 0;
    }
    
    ~CircularQueue() {
        
    }
public:
    bool Begin() {
        memset(m_Queue, 0, sizeof(m_Queue));
         m_QueueHead = m_QueueTail = 0;
        return true;
    }
    
    bool End() {
        return true;
    }
    
    bool Push(T data) {
        u32 tempTail = (m_QueueTail + 1) % MAX_QUEUE_LENGTH;
        if(tempTail == m_QueueHead)
            return false;
        memcpy(&m_Queue[tempTail], &data, sizeof(T));
        m_QueueTail = tempTail;
        return true;
    }
    
    bool Pop(T &data) {
        if(m_QueueHead == m_QueueTail)
            return false;
        u32 tempHead = (m_QueueHead + 1) % MAX_QUEUE_LENGTH;
        memcpy(&data, &m_Queue[tempHead], sizeof(T));
        m_QueueHead = tempHead;
        return true;
    }
    
    bool IsEmpty() {
        if(m_QueueHead == m_QueueTail)
            return true;
        return false;
    }
    
private:
    T m_Queue[MAX_QUEUE_LENGTH];
    u32 m_QueueHead;
    u32 m_QueueTail;
};


#endif
