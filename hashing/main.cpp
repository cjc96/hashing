//
//  main.cpp
//  hashing
//
//  Created by Jingchen Cao on 5/19/19.
//  Copyright © 2019 cjc. All rights reserved.
//

#include "defs.h"
#include "linear.hpp"

int main()
{
    linearHash obj(10);
    
    obj.show();
    obj.set((char *)"ab");
    obj.set((char *)"abc");
    obj.show();
    
    return 0;
}
