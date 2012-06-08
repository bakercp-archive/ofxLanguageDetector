//
//  ofxLanguageDetector.cpp
//  cldExample
//
//  Created by Christopher Baker on 6/1/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "ofxLanguageDetector.h"

//--------------------------------------------------------------
ofxLanguageDetector::Results::Results() {
    languageName        = "";
    lang                = ENGLISH;
    isReliable          = false;
    textBytes           = -1;

    for(int i = 0; i < 3; i++) {
        languages[i]        = ENGLISH;
        languageNames[i]    = LanguageName(languages[i]);
        normalizedScores[i] = -1;
        percents[i]         = -1;
    }
};

//--------------------------------------------------------------
ofxLanguageDetector::Settings::Settings() {
    bool        isPlainText             = true;
    bool        allowExtendedLanguages  = true;
    bool        pickSummaryLanguage     = false;
    bool        removeWeakMatches       = false;
    Language    plusOne                 = UNKNOWN_LANGUAGE;
    const char* tldHint                 = NULL;
    int         encodingHint            = UNKNOWN_ENCODING;
    Language    languageHint            = UNKNOWN_LANGUAGE;
}

//--------------------------------------------------------------
string ofxLanguageDetector::detect(const string& buffer, const Settings& settings, Results& results) {
    
    results.lang = CompactLangDet::DetectLanguage(0,
                                            buffer.c_str(),
                                            buffer.length(),
                                          settings.isPlainText,
                                          settings.allowExtendedLanguages,
                                          settings.pickSummaryLanguage,
                                          settings.removeWeakMatches,
                                          settings.tldHint,
                                          settings.encodingHint,
                                          settings.languageHint,
                                           results.languages,
                                           results.percents,
                                           results.normalizedScores,
                                          &results.textBytes,
                                          &results.isReliable);
    
    results.languageNames[0] = LanguageName(results.languages[0]);
    results.languageNames[1] = LanguageName(results.languages[1]);
    results.languageNames[2] = LanguageName(results.languages[2]);
    
    results.languageName     = LanguageName(results.lang);
    
    return results.languageName;
}

//--------------------------------------------------------------
string ofxLanguageDetector::detect(const string& input) {
    Settings settings = Settings();
    Results  results  = Results();
    
    string lang = detect(input,settings,results);
    
    if(!results.isReliable) {
        ofLog(OF_LOG_WARNING,"ofxLanguageDetector::detect results not reliable.");
    }
    
    return lang;
}