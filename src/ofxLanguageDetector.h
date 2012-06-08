//
//  ofxLanguageDetector.h
//  cldExample
//
//  Created by Christopher Baker on 6/1/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"

#include "compact_lang_det.h"
#include "ext_lang_enc.h"
#include "encodings/proto/encodings.pb.h"


class ofxLanguageDetector {
public:
    struct Settings;
    struct Results;
    
    ofxLanguageDetector();
    virtual ~ofxLanguageDetector();
    
    // full control
    static string detect(const string& input, const Settings& settings, Results& results);

    // default control
    static string detect(const string& input);


    struct Results {
        string      languageName;
        Language    lang;
        bool        isReliable;
        Language    languages[3];
        string      languageNames[3];
        double      normalizedScores[3];
        int         percents[3];
        int         textBytes;
        
        Results();
    };
    
    struct Settings {
        bool        isPlainText;
        bool        allowExtendedLanguages;
        bool        pickSummaryLanguage;
        bool        removeWeakMatches;
        Language    plusOne;
        const char* tldHint;
        int         encodingHint;
        Language    languageHint;

        Settings();
	};

};
