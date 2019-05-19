//
//  linear.h
//  hashing
//
//  Created by Jingchen Cao on 5/19/19.
//  Copyright © 2019 cjc. All rights reserved.
//

#ifndef linear_h
#define linear_h

#include "defs.h"

class linearHash
{
private:
    char **hashTable;
    int size;
    int used;
    int cHash(char *);
    
public:
    linearHash(int s) : size(s)
    {
        used = 0;
        hashTable = new char *[s]();
    };
    void set(char *);
    bool get(char *);
    void del(char *);
    void show();
};

#endif /* linear_h */
