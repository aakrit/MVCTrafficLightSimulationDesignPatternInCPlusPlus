//
//  Controller.h
//  hw4
//
//  Created by Aakrit Prasad on 5/25/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __hw4__Controller__
#define __hw4__Controller__

#include <iostream>
#include "Observer.h"

class TrafficLightView;
class TrafficLightModel;
class PedLightModel;
class PedLightView;

class Controller: public Observer
{
    TrafficLightModel* tlm;
    TrafficLightView* tlv;
    PedLightModel* plm;
    PedLightView* plv;
    
    int callCount = 0;
    
public:
    //overloaded contructors for traffic and ped light
    
    Controller(TrafficLightModel*, TrafficLightView*);
    Controller(PedLightModel*, PedLightView*);

    void handleEventTraffic(std::string const&);
    void handleEventPed(std::string const&);

    virtual void update();
    
    int getCallCount() const;
    
    virtual ~Controller();
};


#endif /* defined(__hw4__Controller__) */
