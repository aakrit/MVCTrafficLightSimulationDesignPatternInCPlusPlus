//  TrafficLightModel.cpp
//  hw4
//
//  Created by Aakrit Prasad on 5/26/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
#include "TrafficLightModel.h"
#include "Observer.h"
#include "TrafficLightView.h"
#include "Controller.h"

using namespace std;

TrafficLightModel::TrafficLightModel()
{
    red = "ON";
    yellow = "OFF";
    green = "OFF";
}
void TrafficLightModel::attach(Observer* os)
{
    if(dynamic_cast<TrafficLightView*>(os))
    {
        TrafficLightView *t = dynamic_cast<TrafficLightView*>(os);
        view = t;
    }
    else if(dynamic_cast<Controller*>(os))
    {
        Controller *c = dynamic_cast<Controller*>(os);
        controller = c;
    }
}
void TrafficLightModel::detach(Observer* os)
{
    if(dynamic_cast<TrafficLightView*>(os))
    {
        view = NULL;
    }
    else if(dynamic_cast<Controller*>(os))
    {
        controller = NULL;
    }
}
void TrafficLightModel::notify() const
{
    //iterator over all the Observer references and call their update method
    view->update();
    controller->update();
}
string TrafficLightModel::getData()
{
    string state = "Red Light: " + red + " , Yellow Light: " + yellow + " , Green Light: " + green;
    return state;
}
void TrafficLightModel::service()
{
    //change all lights to other position
    //at red light, lets change to green
    if (red == "ON" && yellow == "OFF" && green == "OFF")
    {
        red = "OFF";
        yellow = "OFF";
        green = "ON";
    }
    //at green light, lets change to yellow
    else if (red == "OFF" && yellow == "OFF" && green == "ON")
    {
        red = "OFF";
        yellow = "ON";
        green = "OFF";
    }
    //at yellow light, lets change to red
    else if (red == "OFF" && yellow == "ON" && green == "OFF")
    {
        red = "ON";
        yellow = "OFF";
        green = "OFF";
    }
    //call update procedures of the views and controllers
    notify();
}
