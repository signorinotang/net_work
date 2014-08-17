//
//  Log.h
//  GameServerProgramming
//
//  Created by signorinotang on 14-8-17.
//  Copyright (c) 2014 signorinotang. All rights reserved.
//

#ifndef GameServerProgramming_Log_h
#define GameServerProgramming_Log_h


class Log {
public:
    enum Level {
        kDebug = 0;
        kInformation,
        kWarning,
        kError,
        kFatalError
    };
    
    class Stream {
        friend class Log;
        
        
    };
    
    
    
};

#endif
