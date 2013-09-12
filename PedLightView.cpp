//
//  PedLightView.cpp
//  hw4
//
//  Created by Aakrit Prasad on 5/26/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "PedLightView.h"
#include "PedLightModel.h"
#include "Controller.h"
using namespace std;

PedLightView::PedLightView(PedLightModel* plm)
{
    plmodel = plm;
    //The view subscribes to the change-propagation mechanism of the model by calling the attach procedure
    plm->attach(this);
    //The view continues initialization by creating its controller. It passes references both to the model and to itself to the controller's initialization procedure.
    
    Controller *c = new Controller(plm, this);
    cv = c;
}
Controller* PedLightView::getController()
{
    return cv;
}
void PedLightView::update()
{
    display();
}
void PedLightView::display() const
{
    //Each view requests the changed data from the model and re- displays itself on the screen
    string output = plmodel->getData();
    cout << output << endl << endl;
}
void PedLightView::deleteControllerObject()
{
    delete cv;
}