//
//  Controller.cpp
//  hw4
//
//  Created by Aakrit Prasad on 5/25/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Controller.h"
#include "TrafficLightModel.h"
#include "TrafficLightView.h"
#include "PedLightModel.h"
#include "PedLightView.h"

using namespace std;

Controller::Controller(TrafficLightModel* tm, TrafficLightView* tv)
{
    //The controller also subscribes to the change-propagation mechanism by calling the attach procedure.
    tlm = tm;
    tlv = tv;
    //pass Controller object reference to model
    tm->attach(this);
}
Controller::Controller(PedLightModel* pm, PedLightView* pv)
{
    //The controller also subscribes to the change-propagation mechanism by calling the attach procedure.
    plm = pm;
    plv = pv;
    //pass Controller object reference to model
    pm->attach(this);
}
void Controller::handleEventTraffic(std::string const& s)
{
    //not doing anything with the user input here
    //increment a controller variable to track the times its been called
    callCount++;
    //The controller activates the service procedure of the model
    tlm->service();
    //plm->service();
}
void Controller::handleEventPed(std::string const& s)
{
    //not doing anything with the user input here
    //increment a controller variable to track the times its been called
    callCount++;
    //The controller activates the service procedure of the model
    plm->service();
    //tlm->service();
}
void Controller::update()
{
    //Each registered controller retrieves data from the model to enable or disable certain user functions
//    cout << "The lights have changed " << getCallCount() << " times" << endl;
}

int Controller::getCallCount() const
{
    return callCount;
}
Controller::~Controller()
{
//    cout << "Terminating Program! " << endl;
//    cout << "The lights has changed " << getCallCount() << " times" << endl;
}