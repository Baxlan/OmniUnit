# OmniUnit overview #

## About ##

OmniUnit is a HEADER ONLY library for modern C++.

In C++, in order to avoid ambiguities and hidden bugs, it is heavily recommended to handle values with strongly typed classes.<br/>
C++ stantard has taken this recommendation into account by implementing std::chrono::duration to represent durations.<br/>
It is not enough.

* The main purpose of OmniUnit is to provide strong types to represent all physical units ;
* Implicit conversions are performed when operating on units : Millimeter = meter + inches is absolutely legal ;
* Compile-time dimensional analysis are performed when operating on units : Length/time returns a speed. Computing this as a Mass causes a compilation error, so there cannot be any homogeneity error ;
* Units from all systems are representable : metric, imperial, microscopic, astronomic... ;
* Units representing a time are fully, implicitly and reciprocally convertible to a std::chrono::duration :
* If a unit is not defined in OmniUnit, users can define their own easily through typedefs ;
* Units can handle uncertainties and propagate them through operators, taking covariances into account ; **(comming soon)**
* Suffixes are available for some predefined units through litteral operator, making OmniUnit a user friendly library ;
* More than the five basic operations (+-*/%), Mathematic tools are provided to use units (exponential, power, trigonometric, hyperbolic and rounding functions) ;
* Units can be handled by matrices from the "Eigen" header only library ; **(to be tested)**
* Although this is not the main purpose of OmniUnit, a Timer and a Countdown are available. They can take relativistic effects into account. They provide scalable time flow as well. **comming soon**

## Prerequisites ##

OmniUnit requires fully supported **C++17** (at least gcc/g++ 7.2 or Visual Studio 2017 with the option /constexpr).

## Documentation ##

Open __omniunit/doc/html/index.html__.

## Basic example ##

    #include "omniunit/omniunit.hh"
    #include <iostream>

    int main()
    {
        // a and b represent 3000 meters in different ways
        omni::Millimeter a(3000000);
        omni::Kilometer b(3);

        omni::CentimeterPerSecond c = a / stb::second(3); //OK, LENGTH/DURATION returns a SPEED.
        std::cout << c.count() << '\n';   //prints 100000

        omni::Gram d = c; //ERROR, this doesn't compile because the dimension of "d" is MASS and the dimension of "c" is SPEED

        omni::Inch e = omni::MilliMeter(5.2) + omni::Angstrom(124.347); //OK, all conversions are done implicitly

        omni::Joule kineticEnergy = 0.5 * omni::Ton(10) * omni::pow<2>(c); //OK

    return 0;
    }

## License ##

BSD 3-Clause License

Copyright (c) 2021, Denis Tosetto alias Baxlan
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
