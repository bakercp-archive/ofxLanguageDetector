//
//  ofxLanguageDetector.cpp
//  cldExample
//
//  Created by Christopher Baker on 6/1/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "ofxLanguageDetector.h"


string ofxLanguageDetector::detect(const string& input) {
    
    bool is_plain_text = true;
    bool do_allow_extended_languages = true;
    bool do_pick_summary_language = false;
    bool do_remove_weak_matches = false;
    bool is_reliable;
    Language plus_one = UNKNOWN_LANGUAGE;
    const char* tld_hint = NULL;
    int encoding_hint = UNKNOWN_ENCODING;
    Language language_hint = UNKNOWN_LANGUAGE;
    
    double normalized_score3[3];
    Language language3[3];
    int percent3[3];
    int text_bytes;
    
    Language lang;
    lang = CompactLangDet::DetectLanguage(0,
                                          input.c_str(), input.length(),
                                          is_plain_text,
                                          do_allow_extended_languages,
                                          do_pick_summary_language,
                                          do_remove_weak_matches,
                                          tld_hint,
                                          encoding_hint,
                                          language_hint,
                                          language3,
                                          percent3,
                                          normalized_score3,
                                          &text_bytes,
                                          &is_reliable);
    if(!is_reliable) {
        ofLog(OF_LOG_WARNING,"ofxLanguageDetector::detect: result not reliable.");
    }
    
    return LanguageName(lang);
}