#pragma once

#include "ofMain.h"
#include "SandPainter.h"

class Crack{
    
public:
    
    float x, y;
      float t;    // direction of travel in degrees
      // sand painter
      SandPainter sp;
    ofMesh crackMesh;
    ofColor inColour;
      void initCrack(ofColor someColour) {
          inColour = someColour;
        // find placement along existing crack
          //cout<<"initing crack " + ofToString(someColour) <<endl;
          //findStart(cgrid);
          //cout<<"Initing crack " + ofToString(inColour) << endl;

          sp.initSandPainter(inColour);
          crackMesh.clear();
          
      }
       
      void startCrack(int X, int Y, int T) {
        x=X;
        y=Y;
        t=T;//%360;
        x+=0.61*cos(t*PI/180);
        y+=0.61*sin(t*PI/180);
         // cout<<"Starting crack x= " + ofToString(x) + " y= " + ofToString(y)<< endl;

      }
                 
    
};
