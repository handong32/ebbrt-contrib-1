//          Copyright Boston University SESA Group 2013 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <ebbrt/Debug.h>
#include "../Counter.h"
#include "Printer.h"

void AppMain() { 
  
    auto c = ebbrt::EbbRef<Counter>(321);
    c->Up();
    kprintf("Sum: %d/n", c->Get());
  
  printer->Print("CRTP BACKEND UP.\n"); 

}
