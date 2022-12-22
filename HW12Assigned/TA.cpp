#include <iostream>
#include "Teacher.h"
#include "Student.h"
#include "TA.h"

TA::TA(long _SSN, long _phone, double _contactHours, int _coursesTaught, double credits,
       int coursesTaken) : Teacher(_SSN, _phone, _contactHours, _coursesTaught), Student(_SSN, _phone, credits, coursesTaken) { 
   std::cout << "TA" << std::endl;
} 
                      
