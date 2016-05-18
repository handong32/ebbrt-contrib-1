//          Copyright Boston University SESA Group 2013 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "Printer.h"
#include "Poly.h"

void AppMain() { 
  printer->Print("POLY BACKEND UP.\n"); 

  auto fooby = ebbrt::PolyFoo::Create();
  fooby->Foo();
  fooby->Bar();

  printer->Print("POLY BACKEND FINISHED.\n"); 
}