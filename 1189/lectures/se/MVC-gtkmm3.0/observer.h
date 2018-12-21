/*
 * Observer class.  Abstract class for Observer Pattern
 *
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Updated to GTKmm 3.0 (version 3.10.1) from 2.4 on February 13, 2017.
 *  Copyright 2009, 2017 UW. All rights reserved.
 *
 */


#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;


class Observer {
  public:
    virtual void update () = 0;
};


#endif
