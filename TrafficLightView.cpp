//
//  TrafficLightView.cpp
//  hw4
//
//  Created by Aakrit Prasad on 5/26/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "TrafficLightView.h"
#include "TrafficLightModel.h"
#include "Controller.h"

using namespace std;

TrafficLightView::TrafficLightView(TrafficLightModel* tlm)
{
    this->tlmodel = tlm;
    //The view subscribes to the change-propagation mechanism of the model by calling the attach procedure
    tlm->attach(this);
    
    
    //The view continues initialization by creating its controller. It passes references both to the model and to itself to the controller's initialization procedure.
    
    Controller *c = new Controller(tlm, this);
    cv = c;
    
}
Controller* TrafficLightView::getController()
{
    return cv;
}
void TrafficLightView::update()
{
    display();
}
void TrafficLightView::display() const
{
    //Each view requests the changed data from the model and re- displays itself on the screen
    cout << "Status: " << endl;
    cout << "Traffic Light 1: " << endl;
    string output = tlmodel->getData();
    cout << output << endl << endl;
}

void TrafficLightView::deleteControllerObject()
{
    delete cv;
}