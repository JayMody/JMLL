//
//  Timer.h
//  JMLL
//
//  Created by Jay Mody on 2019-01-15.
//  Copyright © 2019 Jay Mody. All rights reserved.
//

#include <chrono>
#include <string>

using namespace std::chrono;

#ifndef Timer_h
#define Timer_h

void start_time();
void stop_time();
std::string diff_time();

#endif /* Timer_h */
