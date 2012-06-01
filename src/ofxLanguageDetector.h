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
    ofxLanguageDetector();
    virtual ~ofxLanguageDetector();
    
    static string detect(const string& input);
    
};
