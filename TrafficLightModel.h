//
//  TrafficLightModel.h
//  hw4
//
//  Created by Aakrit Prasad on 5/26/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __hw4__TrafficLightModel__
#define __hw4__TrafficLightModel__

#include <iostream>

class Observer;
class Controller;
class TrafficLightView;

class TrafficLightModel
{
    std::string red;
    std::string yellow;
    std::string green;
    
    TrafficLightView* view;
    Controller* controller;
    
public:
    TrafficLightModel();
    void attach(Observer*);
    void detach(Observer*);
    void attachController(Observer*);

    
    virtual void notify() const;
    
    void service();
    std::string getData();

};

#endif /* defined(__hw4__TrafficLightModel__) */
