//
//  main.cpp
//  hw4
//
//  Created by Aakrit Prasad on 5/25/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include <iostream>
#include "TrafficLightModel.h"
#include "PedLightModel.h"
#include "TrafficLightView.h"
#include "PedLightView.h"
#include "Controller.h"

using namespace std;


int main(int argc, const char * argv[])
{    
    //create both model objects
    TrafficLightModel *tlm = new TrafficLightModel();
    PedLightModel *plm = new PedLightModel();
    
    //create both view objects taking in the respective model object as parameter
    TrafficLightView *tlv = new TrafficLightView(tlm);
    PedLightView *plv = new PedLightView(plm);
    
    //unit testing code initialized
    string red = "ON";
    string yellow = "OFF";
    string green = "OFF";
    
    string walk = "OFF";
    string dont_walk = "ON";
    
    while (1)
    {
        cout << "Press any letter to change the light... OR '1' to QUIT <enter>" << endl;
        string input;
        cin >> input;
        if (input == "1")
        {
            break;
        }
        else
        {
            //call the eventhandle procedure of the controller for tlv
            tlv->getController()->handleEventTraffic(input);
            
            //Unit testing: basicially wanting the lights to switch 'on' and 'off' as expected
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
            cout << "UNIT TEST RESULT for Traffic Light: " << endl;
            cout << "Red Light: " << red << " , Yellow Light: " << yellow + " , Green Light: " << green << endl << endl << endl;
            
            //call the eventhandle procedure of controller for plv
            plv->getController()->handleEventPed(input);
            
            //Unit testing: basicially wanting the lights to switch 'on' and 'off' as expected
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
            cout << "UNIT TEST RESULT for Pedestrian Light: " << endl;
            cout << "Pedestrian Light: Walk Light: " << walk << " , Don't Walk Light: " << dont_walk << endl << endl;
            
            cout << "The Lights have changed " << tlv->getController()->getCallCount() << " times" << endl << endl;
        }

    }
    //first lets delete controller objects in the view
    tlv->deleteControllerObject();
    plv->deleteControllerObject();
    delete tlm;
    delete plm;
    delete tlv;
    delete plv;
    
    
    cout << "Exiting Program ... " << endl;
    
    return 0;
}

