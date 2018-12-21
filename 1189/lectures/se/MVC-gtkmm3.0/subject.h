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


#ifndef MVC_SUBJECT_H
#define MVC_SUBJECT_H

#include <set>


class Observer;

class Subject {
  public:
    void subscribe( Observer* );
    void unsubscribe( Observer* );

  protected:
    void notify();

  private:
    typedef std::set< Observer* > Observers;
    Observers observers_;
}; // Subject


#endif
