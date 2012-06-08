#include "testApp.h"

#include "test_text.h" // a lot of test text in here

//--------------------------------------------------------------
void testApp::setup(){
    defaultControlDemo();
    fullControlDemo();
    webPageDemo();
}

//--------------------------------------------------------------
void testApp::draw() {
    ofBackground(0);
    ofSetColor(255);
    ofDrawBitmapString("This is a console based demo.",16,16);    
}

//--------------------------------------------------------------
void testApp::defaultControlDemo() {
    // default control
    string lang0 = ofxLanguageDetector::detect(english);
    string lang1 = ofxLanguageDetector::detect(hindi);
    string lang2 = ofxLanguageDetector::detect(chinese);
    string lang3 = ofxLanguageDetector::detect(chinese_s);
    string lang4 = ofxLanguageDetector::detect(greek);
    string lang5 = ofxLanguageDetector::detect(swahili);
    string lang6 = ofxLanguageDetector::detect(vietnamese);
    string lang7 = ofxLanguageDetector::detect(tamil);
    string lang8 = ofxLanguageDetector::detect(japanese);
    
    // etc.
    
    cout << "the first one is probably " << lang0 << endl;
    cout << "the first one is probably " << lang1 << endl;
    cout << "the first one is probably " << lang2 << endl;
    cout << "the first one is probably " << lang3 << endl;
    cout << "the first one is probably " << lang4 << endl;
    cout << "the first one is probably " << lang5 << endl;
    cout << "the first one is probably " << lang6 << endl;
    cout << "the first one is probably " << lang7 << endl;
    cout << "the first one is probably " << lang8 << endl;
}

//--------------------------------------------------------------
void testApp::fullControlDemo() {
    // default control
    
    ofxLanguageDetector::Settings settings;
    // settings could be changed here    
    settings.isPlainText = true;
    
    
    ofxLanguageDetector::Results  results;
    
    string lang0 = ofxLanguageDetector::detect(english,settings,results);
    printResults(results);

    string lang1 = ofxLanguageDetector::detect(hindi,settings,results);
    printResults(results);
    
    string lang2 = ofxLanguageDetector::detect(chinese,settings,results);
    printResults(results);
    
    string lang3 = ofxLanguageDetector::detect(chinese_s,settings,results);
    printResults(results);
    
    string lang4 = ofxLanguageDetector::detect(greek,settings,results);
    printResults(results);
    
    string lang5 = ofxLanguageDetector::detect(swahili,settings,results);
    printResults(results);
    
    string lang6 = ofxLanguageDetector::detect(vietnamese,settings,results);
    printResults(results);
    
    string lang7 = ofxLanguageDetector::detect(tamil,settings,results);
    printResults(results);
    
    string lang8 = ofxLanguageDetector::detect(japanese,settings,results);
    printResults(results);
    
    // etc.
}

//--------------------------------------------------------------
void testApp::webPageDemo() {
    // prepare the settings and results structures
    
    ofxLanguageDetector::Results  results;
    ofxLanguageDetector::Settings settings;
    settings.isPlainText = false;  // set false for html text.
    // will automatically ignore tags

    // try spanish
    ofURLFileLoader html;
    ofHttpResponse response = html.get("http://elpais.com/"); // get a spanish page
    
    string lang0 = ofxLanguageDetector::detect(response.data.getText(),settings,results);
    printResults(results);

    // try german
    response = html.get("http://www.spiegel.de/"); // get a spanish page
    
    string lang1 = ofxLanguageDetector::detect(response.data.getText(),settings,results);
    printResults(results);

    
    
}

//--------------------------------------------------------------
void testApp::printResults(const ofxLanguageDetector::Results& results) {
    cout << "------------------------------------------------" << endl;
    cout << "       Language Name: " << results.languageName << endl;
    cout << "       Language Code: " << results.lang << endl;
    cout << " Is Result Reliable?: " << (results.isReliable ? "YES" : "NO") << endl; 
    cout << "# of non-tag letters: " << results.textBytes << endl; 
    cout << "   Language Guesses: " << endl;
    
    for(int i = 0; i < 3; i++) {
        cout << "                  " << ofToString(i) << ": (";
        cout << ofToString(results.languages[i]) << ") " << results.languageNames[i] << endl;
        cout << "\t\tNormalized Score: " << results.normalizedScores[i] << endl; 
        cout << "\t\tPercent: " << results.percents[i] << endl; 
    }
}

