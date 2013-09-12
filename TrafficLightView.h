//
//  TrafficLightView.h
//  hw4
//
//  Created by Aakrit Prasad on 5/26/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __hw4__TrafficLightView__
#define __hw4__TrafficLightView__

#include <iostream>
#include "Observer.h"

class Controller;
class TrafficLightModel;

class TrafficLightView: public Observer
{
    Controller* cv;
    TrafficLightModel* tlmodel;
public:
    TrafficLightView(TrafficLightModel*);
    
    void activate();
    virtual void display() const;
    virtual void update();
    
    Controller* getController();
    void deleteControllerObject();
};

#endif /* defined(__hw4__TrafficLightView__) */
