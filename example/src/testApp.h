#pragma once

#include "ofMain.h"
#include "ofxLanguageDetector.h"

class testApp : public ofBaseApp{

	public:
		void setup();
        void draw();
		
    
    void defaultControlDemo();
    void fullControlDemo();
    void webPageDemo();
    
    
    static void printResults(const ofxLanguageDetector::Results& results);
    
};
