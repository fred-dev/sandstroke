#pragma once

#include "ofMain.h"
#include "Crack.h"
#include "SandPainter.h"


#define maxpal 128
#define dimension 1080
#define maxnum 200

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void takecolor(string fn);
    ofColor somecolor();
    void begin();
    
 
    int num;
   // int maxnum = 200;
    ofColor goodcolor[maxpal];

    // grid of cracks
    int cgrid[dimension*dimension];
    std::vector<Crack> cracks;

    // color parameters
    int numpal;
    
    //std::vector<SandPainter> sands;
    
    void move(int iter);
    void regionColor(int iter);
    void findStart(int iter);
    void startCrack(int X, int Y, int T, int iter);
    void makeCrack();
    
    
    bool startDelay, hasStarted;



};
