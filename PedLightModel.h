//
//  PedLightModel.h
//  hw4
//
//  Created by Aakrit Prasad on 5/26/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __hw4__PedLightModel__
#define __hw4__PedLightModel__

#include <iostream>

class Observer;
class PedLightView;
class Controller;

class PedLightModel
{
    std::string walk;
    std::string dont_walk;
    
    PedLightView* view;
    Controller* controller;
    
public:
    
    PedLightModel();
    void attach(Observer*);
    void detach(Observer*);
    
    virtual void notify() const;
    
    std::string getData();
    void service();
};

#endif /* defined(__hw4__PedLightModel__) */
