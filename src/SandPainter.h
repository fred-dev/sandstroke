#pragma once

#include "ofMain.h"

class SandPainter{
    
public:
    
    float g;
    ofColor inColour;
    ofMesh sandMesh;
    
    void initSandPainter(ofColor someColor) {
        
        inColour = someColor;
        g = ofRandom(0.01,0.1);
        sandMesh.setMode(OF_PRIMITIVE_POINTS);
        sandMesh.clear();
       // cout<<"Initing sand painter " + ofToString(inColour) << endl;

    }
    
    
    void render(float x, float y, float ox, float oy) {
      //  cout<<"Rendering crack " + ofToString(inColour) << endl;

        // draw painting sweeps
        g+=ofRandom(-0.050,0.050);
           float maxg = 1.0;
           if (g<0) g=0;
           if (g>maxg) g=maxg;
           
           // calculate grains by distance
           //int grains = int(sqrt((ox-x)*(ox-x)+(oy-y)*(oy-y)));
           int grains = 64;

           // lay down grains of sand (transparent pixels)
           float w = g/(grains-1);
           for (int i=0;i<grains;i++) {
             float a = 0.1-i/(grains*10.0);
               //cout << ofToString(inColour) << endl;

               
               sandMesh.addVertex(glm::vec3(ox+(x-ox)*sin(sin(i*w)),oy+(y-oy)*sin(sin(i*w)),0));
               sandMesh.addColor(ofColor(inColour.r, inColour.g, inColour.b, 256*a));
               //cout << "added vertex " + ofToString(glm::vec3(ox+(x-ox)*sin(sin(i*w)),oy+(y-oy)*sin(sin(i*w)),0)) + " " + ofToString(ofColor(inColour.r, inColour.g, inColour.b, 256*a)) << endl;
               

           }
         }
};

