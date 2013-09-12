//
//  PedLightModel.cpp
//  hw4
//
//  Created by Aakrit Prasad on 5/26/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "PedLightModel.h"
#include "Observer.h"
#include "Controller.h"
#include "PedLightView.h"
using namespace std;

PedLightModel::PedLightModel()
{
    walk = "OFF";
    dont_walk = "ON";
}
void PedLightModel::attach(Observer* os)
{
    if(dynamic_cast<PedLightView*>(os))
    {
       PedLightView *t = dynamic_cast<PedLightView*>(os);
        view = t;
    }
    else if(dynamic_cast<Controller*>(os))
    {
        Controller *c = dynamic_cast<Controller*>(os);
        controller = c;
    }
}
void PedLightModel::detach(Observer* os)
{
    if(dynamic_cast<PedLightView*>(os))
    {
        view = NULL;
    }
    else if(dynamic_cast<Controller*>(os))
    {
        controller = NULL;
    }
}
void PedLightModel::service()
{
    //change all lights to other position
    //this is when traffic light is Red
    if (walk == "OFF" && dont_walk == "ON")
    {
        walk = "ON";
        dont_walk = "OFF";
    }
    //this is when traffic light is Yellow
    else if (walk == "ON" && dont_walk == "OFF")
    {
        walk = "OFF";
        dont_walk = "Flashing";
    }
    //this is when traffice light is Green
    else if (walk == "OFF" && dont_walk == "Flashing")
    {
        walk = "OFF";
        dont_walk = "ON";
    }
    //call update procedures of the views and controllers
    notify();
}
void PedLightModel::notify() const
{
    //iterator over all the Observer references and call their update method
    view->update();
    controller->update();
}
string PedLightModel::getData()
{
    string state = "Pedestrian Light: Walk Light: " + walk + " , Don't Walk Light: " + dont_walk;
    return state;
}