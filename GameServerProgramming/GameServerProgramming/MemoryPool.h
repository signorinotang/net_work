//
//  MemoryPool.h
//  GameServerProgramming
//
//  Created by signorinotang on 14-8-17.
//  Copyright (c) 2014年 signorinotang. All rights reserved.
//

#ifndef GameServerProgramming_MemoryPool_h
#define GameServerProgramming_MemoryPool_h

#include <assert.h>
#include "type.h"

template <class T, int ALLOC_BLOCK_SIZE = 50>
class MemoryPool {
public:
    static void *operator new(size_t alloclength) {
        //when use new will be called
        assert(sizeof(T) == alloclength);
        assert(sizeof(T) >= sizeof(u8*));
        if(!m_FreePointer)
            _allocBlock();
        u8 *retrunPointer = m_FreePointer;
        m_FreePointer = *reinterpret_cast<u8 **>(retrunPointer);
        return retrunPointer;
    }
    
    
    static void operator delete(void *deletePointer) {
        //when delete will be called
        *reinterpret_cast<u8**>(deletePointer) = m_FreePointer;
        m_FreePointer = static_cast<u8*>(deletePointer);
    }
    
    
protected:
    ~MemoryPool() {
        
    }
    
    
private:
    static u8 *m_FreePointer;
    
    static void _allocBlock() {
        m_FreePointer = new u8[sizeof(T) * ALLOC_BLOCK_SIZE];
        u8 **current = reinterpret_cast<u8 **>(m_FreePointer);
        u8 *next = m_FreePointer;
        
        for(int i = 0; i < ALLOC_BLOCK_SIZE - 1; ++i) {
            next += sizeof(T); 
            *current = next;
            current = reinterpret_cast<u8**>(next);
        }
        *current = 0;
        
    }
};

template <class T, int ALLOC_BLOCK_SIZE>
u8 * MemoryPool<T, ALLOC_BLOCK_SIZE>::m_FreePointer;


#endif
