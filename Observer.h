//
//  Observer.h
//  hw4
//
//  Created by Aakrit Prasad on 5/25/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __hw4__Observer__
#define __hw4__Observer__

#include <iostream>

class Observer
{
    
public:
    Observer();
    virtual ~Observer();
    virtual void update() = 0;
    
};


#endif /* defined(__hw4__Observer__) */
