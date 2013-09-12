//
//  PedLightView.h
//  hw4
//
//  Created by Aakrit Prasad on 5/26/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __hw4__PedLightView__
#define __hw4__PedLightView__

#include <iostream>
#include "Observer.h"

class Controller;
class PedLightModel;

class PedLightView: public Observer
{
    Controller* cv;
    PedLightModel* plmodel;
    
public:
    
    PedLightView(PedLightModel*);
    
    void activate();
    virtual void display() const;
    virtual void update();
    
    Controller* getController();
    void deleteControllerObject();

};


#endif /* defined(__hw4__PedLightView__) */
