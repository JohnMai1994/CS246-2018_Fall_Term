/*
 * MVC example of GTKmm program
 *
 * Subject class.  Abstract class for Observer Pattern
 *
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Updated to GTKmm 3.0 (version 3.10.1) from 2.4 on February 13, 2017.
 *  Copyright 2009, 2017 UW. All rights reserved.
 *
 */

#include <set>
#include "subject.h"
#include "observer.h"

void Subject::subscribe ( Observer *newView ) {
    observers_.insert( newView );
}


void Subject::unsubscribe ( Observer *formerView ) {
    observers_.erase( formerView );
}


void Subject::notify () {
    for ( auto i : observers_ ) i->update();
}
