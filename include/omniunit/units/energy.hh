//energy.hh

/*
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
*/

#ifndef OMNIUNIT_ENERGY_HH_
#define OMNIUNIT_ENERGY_HH_

#include "../omniunit.hh"
#include "constants_for_units.hh"

namespace omni
{



typedef Dimension<2,1,-2,0,0,0,0> Energy;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctojoule = Unit<Energy, Rep, yocto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptojoule = Unit<Energy, Rep, zepto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attojoule = Unit<Energy, Rep, atto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtojoule = Unit<Energy, Rep, femto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picojoule = Unit<Energy, Rep, pico, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanojoule = Unit<Energy, Rep, nano, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microjoule = Unit<Energy, Rep, micro, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millijoule = Unit<Energy, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centijoule = Unit<Energy, Rep, centi, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decijoule = Unit<Energy, Rep, deci, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using joule = Unit<Energy, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decajoule = Unit<Energy, Rep, deca, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectojoule = Unit<Energy, Rep, hecto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilojoule = Unit<Energy, Rep, kilo, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megajoule = Unit<Energy, Rep, mega, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigajoule = Unit<Energy, Rep, giga, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using terajoule = Unit<Energy, Rep, tera, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petajoule = Unit<Energy, Rep, peta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exajoule = Unit<Energy, Rep, exa, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettajoule = Unit<Energy, Rep, zetta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottajoule = Unit<Energy, Rep, yotta, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using ev = Unit<Energy, Rep, typename Ratio_over_value<Ratio<CoulombE9, E9>, E19>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using microev = Unit<Energy, Rep, typename Ratio_times_Ratio<ev<OMNI_DEFAULT_TYPE>::period, micro>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using milliev = Unit<Energy, Rep, typename Ratio_times_Ratio<ev<OMNI_DEFAULT_TYPE>::period, milli>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kiloev = Unit<Energy, Rep, typename Ratio_times_Ratio<ev<OMNI_DEFAULT_TYPE>::period, kilo>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megaev = Unit<Energy, Rep, typename Ratio_times_Ratio<ev<OMNI_DEFAULT_TYPE>::period, mega>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigaev = Unit<Energy, Rep, typename Ratio_times_Ratio<ev<OMNI_DEFAULT_TYPE>::period, giga>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using teraev = Unit<Energy, Rep, typename Ratio_times_Ratio<ev<OMNI_DEFAULT_TYPE>::period, tera>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petaev = Unit<Energy, Rep, typename Ratio_times_Ratio<ev<OMNI_DEFAULT_TYPE>::period, peta>::type, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using erg = Unit<Energy, Rep, Ratio<E0, E7>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using calorie = Unit<Energy, Rep, Ratio<calorieE4, E4>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilocalorie = Unit<Energy, Rep, Ratio<calorieE4, E1>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using btu = Unit<Energy, Rep, Ratio<btuDef, E0>, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using wattHour = Unit<Energy, Rep, Ratio<secondsPerHour, E0>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilowattHour = Unit<Energy, Rep, typename Ratio_times_Ratio<wattHour<OMNI_DEFAULT_TYPE>::period, kilo>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megawattHour = Unit<Energy, Rep, typename Ratio_times_Ratio<wattHour<OMNI_DEFAULT_TYPE>::period, mega>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigawattHour = Unit<Energy, Rep, typename Ratio_times_Ratio<wattHour<OMNI_DEFAULT_TYPE>::period, giga>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using terawattHour = Unit<Energy, Rep, typename Ratio_times_Ratio<wattHour<OMNI_DEFAULT_TYPE>::period, tera>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petawattHour = Unit<Energy, Rep, typename Ratio_times_Ratio<wattHour<OMNI_DEFAULT_TYPE>::period, peta>::type, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using tonTNT = Unit<Energy, Rep, typename Ratio_times_value<Ratio<tonTNTE3, E3>, E9>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using boe = Unit<Energy, Rep, typename Ratio_times_value<Ratio<boeE7, E7>, E9>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kiloboe = Unit<Energy, Rep, typename Ratio_times_Ratio<boe<OMNI_DEFAULT_TYPE>::period, kilo>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megaboe = Unit<Energy, Rep, typename Ratio_times_Ratio<boe<OMNI_DEFAULT_TYPE>::period, mega>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigaboe = Unit<Energy, Rep, typename Ratio_times_Ratio<boe<OMNI_DEFAULT_TYPE>::period, giga>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using tec = Unit<Energy, Rep, typename Ratio_times_value<Ratio<tecE5, E5>, E9>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilotec = Unit<Energy, Rep, typename Ratio_times_Ratio<tec<OMNI_DEFAULT_TYPE>::period, kilo>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megatec = Unit<Energy, Rep, typename Ratio_times_Ratio<tec<OMNI_DEFAULT_TYPE>::period, mega>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using tep = Unit<Energy, Rep, typename Ratio_times_value<Ratio<tepE3, E3>, E9>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilotep = Unit<Energy, Rep, typename Ratio_times_Ratio<tep<OMNI_DEFAULT_TYPE>::period, kilo>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megatep = Unit<Energy, Rep, typename Ratio_times_Ratio<tep<OMNI_DEFAULT_TYPE>::period, mega>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigatep = Unit<Energy, Rep, typename Ratio_times_Ratio<tep<OMNI_DEFAULT_TYPE>::period, giga>::type, zero>;



typedef yoctojoule<> Yoctojoule;
typedef zeptojoule<> Zeptojoule;
typedef attojoule<> Attojoule;
typedef femtojoule<>  Femtojoule;
typedef picojoule<> Picojoule;
typedef nanojoule<> Nanojoule;
typedef microjoule<> Microjoule;
typedef millijoule<> Millijoule;
typedef centijoule<> Centijoule;
typedef decijoule<> Decijoule;
typedef joule<> Joule;
typedef decajoule<> Decajoule;
typedef hectojoule<> Hectojoule;
typedef kilojoule<> Kilojoule;
typedef megajoule<> Megajoule;
typedef gigajoule<> Gigajoule;
typedef terajoule<> Terajoule;
typedef petajoule<> Petajoule;
typedef exajoule<> Exajoule;
typedef zettajoule<> Zettajoule;
typedef yottajoule<> Yottajoule;

typedef ev<> Ev;
typedef microev<> Microev;
typedef milliev<> Milliev;
typedef kiloev<> Kiloev;
typedef megaev<> Megaev;
typedef gigaev<> Gigaev;
typedef teraev<> Teraev;
typedef petaev<> Petaev;

typedef erg<> Erg;
typedef calorie<> Calorie;
typedef kilocalorie<> Kilocalorie;
typedef btu<> Btu;

typedef wattHour<> WattHour;
typedef kilowattHour<> KilowattHour;
typedef megawattHour<> MegawattHour;
typedef gigawattHour<> GigawattHour;
typedef terawattHour<> TerawattHour;
typedef petawattHour<> PetawattHour;

typedef tonTNT<> TonTNT;
typedef boe<> Boe;
typedef kiloboe<> Kiloboe;
typedef megaboe<> Megaboe;
typedef gigaboe<> Gigaboe;
typedef tec<> Tec;
typedef kilotec<> Kilotec;
typedef megatec<> Megatec;
typedef tep<> Tep;
typedef kilotep<> Kilotep;
typedef megatep<> Megatep;
typedef gigatep<> Gigatep;



namespace suffixes
{



constexpr yoctojoule<OMNI_LITTERAL_FLOATING> operator"" _yJ(long double val){return val;}
constexpr zeptojoule<OMNI_LITTERAL_FLOATING> operator"" _zJ(long double val){return val;}
constexpr attojoule<OMNI_LITTERAL_FLOATING> operator"" _aJ(long double val){return val;}
constexpr femtojoule<OMNI_LITTERAL_FLOATING> operator"" _fJ(long double val){return val;}
constexpr nanojoule<OMNI_LITTERAL_FLOATING> operator"" _nJ(long double val){return val;}
constexpr microjoule<OMNI_LITTERAL_FLOATING> operator"" _uJ(long double val){return val;}
constexpr millijoule<OMNI_LITTERAL_FLOATING> operator"" _mJ(long double val){return val;}
constexpr centijoule<OMNI_LITTERAL_FLOATING> operator"" _cJ(long double val){return val;}
constexpr decijoule<OMNI_LITTERAL_FLOATING> operator"" _dJ(long double val){return val;}
constexpr joule<OMNI_LITTERAL_FLOATING> operator"" _J(long double val){return val;}
constexpr decajoule<OMNI_LITTERAL_FLOATING> operator"" _daJ(long double val){return val;}
constexpr hectojoule<OMNI_LITTERAL_FLOATING> operator"" _hJ(long double val){return val;}
constexpr kilojoule<OMNI_LITTERAL_FLOATING> operator"" _kJ(long double val){return val;}
constexpr megajoule<OMNI_LITTERAL_FLOATING> operator"" _MJ(long double val){return val;}
constexpr gigajoule<OMNI_LITTERAL_FLOATING> operator"" _GJ(long double val){return val;}
constexpr terajoule<OMNI_LITTERAL_FLOATING> operator"" _TJ(long double val){return val;}
constexpr petajoule<OMNI_LITTERAL_FLOATING> operator"" _PJ(long double val){return val;}
constexpr exajoule<OMNI_LITTERAL_FLOATING> operator"" _EJ(long double val){return val;}
constexpr zettajoule<OMNI_LITTERAL_FLOATING> operator"" _ZJ(long double val){return val;}
constexpr yottajoule<OMNI_LITTERAL_FLOATING> operator"" _YJ(long double val){return val;}

constexpr ev<OMNI_LITTERAL_FLOATING> operator"" _eV(long double val){return val;}
constexpr microev<OMNI_LITTERAL_FLOATING> operator"" _ueV(long double val){return val;}
constexpr milliev<OMNI_LITTERAL_FLOATING> operator"" _meV(long double val){return val;}
constexpr kiloev<OMNI_LITTERAL_FLOATING> operator"" _keV(long double val){return val;}
constexpr megaev<OMNI_LITTERAL_FLOATING> operator"" _MeV(long double val){return val;}
constexpr gigaev<OMNI_LITTERAL_FLOATING> operator"" _GeV(long double val){return val;}
constexpr teraev<OMNI_LITTERAL_FLOATING> operator"" _TeV(long double val){return val;}
constexpr petaev<OMNI_LITTERAL_FLOATING> operator"" _PeV(long double val){return val;}

constexpr erg<OMNI_LITTERAL_FLOATING> operator"" _erg(long double val){return val;}
constexpr calorie<OMNI_LITTERAL_FLOATING> operator"" _cal(long double val){return val;}
constexpr kilocalorie<OMNI_LITTERAL_FLOATING> operator"" _kcal(long double val){return val;}
constexpr btu<OMNI_LITTERAL_FLOATING> operator"" _btu(long double val){return val;}

constexpr wattHour<OMNI_LITTERAL_FLOATING> operator"" _Wh(long double val){return val;}
constexpr kilowattHour<OMNI_LITTERAL_FLOATING> operator"" _kWh(long double val){return val;}
constexpr megawattHour<OMNI_LITTERAL_FLOATING> operator"" _MWh(long double val){return val;}
constexpr gigawattHour<OMNI_LITTERAL_FLOATING> operator"" _GWh(long double val){return val;}
constexpr terawattHour<OMNI_LITTERAL_FLOATING> operator"" _TWh(long double val){return val;}
constexpr petawattHour<OMNI_LITTERAL_FLOATING> operator"" _PWh(long double val){return val;}

constexpr tonTNT<OMNI_LITTERAL_FLOATING> operator"" _tTNT(long double val){return val;}
constexpr boe<OMNI_LITTERAL_FLOATING> operator"" _boe(long double val){return val;}
constexpr kiloboe<OMNI_LITTERAL_FLOATING> operator"" _kboe(long double val){return val;}
constexpr megaboe<OMNI_LITTERAL_FLOATING> operator"" _Mboe(long double val){return val;}
constexpr gigaboe<OMNI_LITTERAL_FLOATING> operator"" _Gboe(long double val){return val;}
constexpr tec<OMNI_LITTERAL_FLOATING> operator"" _tec(long double val){return val;}
constexpr kilotec<OMNI_LITTERAL_FLOATING> operator"" _ktec(long double val){return val;}
constexpr megatec<OMNI_LITTERAL_FLOATING> operator"" _Mtec(long double val){return val;}
constexpr tep<OMNI_LITTERAL_FLOATING> operator"" _tep(long double val){return val;}
constexpr kilotep<OMNI_LITTERAL_FLOATING> operator"" _ktep(long double val){return val;}
constexpr megatep<OMNI_LITTERAL_FLOATING> operator"" _Mtep(long double val){return val;}
constexpr gigatep<OMNI_LITTERAL_FLOATING> operator"" _Gtep(long double val){return val;}



constexpr yoctojoule<OMNI_LITTERAL_INTEGER> operator"" _yJ(unsigned long long int val){return val;}
constexpr zeptojoule<OMNI_LITTERAL_INTEGER> operator"" _zJ(unsigned long long int val){return val;}
constexpr attojoule<OMNI_LITTERAL_INTEGER> operator"" _aJ(unsigned long long int val){return val;}
constexpr femtojoule<OMNI_LITTERAL_INTEGER> operator"" _fJ(unsigned long long int val){return val;}
constexpr nanojoule<OMNI_LITTERAL_INTEGER> operator"" _nJ(unsigned long long int val){return val;}
constexpr microjoule<OMNI_LITTERAL_INTEGER> operator"" _uJ(unsigned long long int val){return val;}
constexpr millijoule<OMNI_LITTERAL_INTEGER> operator"" _mJ(unsigned long long int val){return val;}
constexpr centijoule<OMNI_LITTERAL_INTEGER> operator"" _cJ(unsigned long long int val){return val;}
constexpr decijoule<OMNI_LITTERAL_INTEGER> operator"" _dJ(unsigned long long int val){return val;}
constexpr joule<OMNI_LITTERAL_INTEGER> operator"" _J(unsigned long long int val){return val;}
constexpr decajoule<OMNI_LITTERAL_INTEGER> operator"" _daJ(unsigned long long int val){return val;}
constexpr hectojoule<OMNI_LITTERAL_INTEGER> operator"" _hJ(unsigned long long int val){return val;}
constexpr kilojoule<OMNI_LITTERAL_INTEGER> operator"" _kJ(unsigned long long int val){return val;}
constexpr megajoule<OMNI_LITTERAL_INTEGER> operator"" _MJ(unsigned long long int val){return val;}
constexpr gigajoule<OMNI_LITTERAL_INTEGER> operator"" _GJ(unsigned long long int val){return val;}
constexpr terajoule<OMNI_LITTERAL_INTEGER> operator"" _TJ(unsigned long long int val){return val;}
constexpr petajoule<OMNI_LITTERAL_INTEGER> operator"" _PJ(unsigned long long int val){return val;}
constexpr exajoule<OMNI_LITTERAL_INTEGER> operator"" _EJ(unsigned long long int val){return val;}
constexpr zettajoule<OMNI_LITTERAL_INTEGER> operator"" _ZJ(unsigned long long int val){return val;}
constexpr yottajoule<OMNI_LITTERAL_INTEGER> operator"" _YJ(unsigned long long int val){return val;}

constexpr ev<OMNI_LITTERAL_INTEGER> operator"" _eV(unsigned long long int val){return val;}
constexpr microev<OMNI_LITTERAL_INTEGER> operator"" _ueV(unsigned long long int val){return val;}
constexpr milliev<OMNI_LITTERAL_INTEGER> operator"" _meV(unsigned long long int val){return val;}
constexpr kiloev<OMNI_LITTERAL_INTEGER> operator"" _keV(unsigned long long int val){return val;}
constexpr megaev<OMNI_LITTERAL_INTEGER> operator"" _MeV(unsigned long long int val){return val;}
constexpr gigaev<OMNI_LITTERAL_INTEGER> operator"" _GeV(unsigned long long int val){return val;}
constexpr teraev<OMNI_LITTERAL_INTEGER> operator"" _TeV(unsigned long long int val){return val;}
constexpr petaev<OMNI_LITTERAL_INTEGER> operator"" _PeV(unsigned long long int val){return val;}

constexpr erg<OMNI_LITTERAL_INTEGER> operator"" _erg(unsigned long long int val){return val;}
constexpr calorie<OMNI_LITTERAL_INTEGER> operator"" _cal(unsigned long long int val){return val;}
constexpr kilocalorie<OMNI_LITTERAL_INTEGER> operator"" _kcal(unsigned long long int val){return val;}
constexpr btu<OMNI_LITTERAL_INTEGER> operator"" _btu(unsigned long long int val){return val;}

constexpr wattHour<OMNI_LITTERAL_INTEGER> operator"" _Wh(unsigned long long int val){return val;}
constexpr kilowattHour<OMNI_LITTERAL_INTEGER> operator"" _kWh(unsigned long long int val){return val;}
constexpr megawattHour<OMNI_LITTERAL_INTEGER> operator"" _MWh(unsigned long long int val){return val;}
constexpr gigawattHour<OMNI_LITTERAL_INTEGER> operator"" _GWh(unsigned long long int val){return val;}
constexpr terawattHour<OMNI_LITTERAL_INTEGER> operator"" _TWh(unsigned long long int val){return val;}
constexpr petawattHour<OMNI_LITTERAL_INTEGER> operator"" _PWh(unsigned long long int val){return val;}

constexpr tonTNT<OMNI_LITTERAL_INTEGER> operator"" _tTNT(unsigned long long int val){return val;}
constexpr boe<OMNI_LITTERAL_INTEGER> operator"" _boe(unsigned long long int val){return val;}
constexpr kiloboe<OMNI_LITTERAL_INTEGER> operator"" _kboe(unsigned long long int val){return val;}
constexpr megaboe<OMNI_LITTERAL_INTEGER> operator"" _Mboe(unsigned long long int val){return val;}
constexpr gigaboe<OMNI_LITTERAL_INTEGER> operator"" _Gboe(unsigned long long int val){return val;}
constexpr tec<OMNI_LITTERAL_INTEGER> operator"" _tec(unsigned long long int val){return val;}
constexpr kilotec<OMNI_LITTERAL_INTEGER> operator"" _ktec(unsigned long long int val){return val;}
constexpr megatec<OMNI_LITTERAL_INTEGER> operator"" _Mtec(unsigned long long int val){return val;}
constexpr tep<OMNI_LITTERAL_INTEGER> operator"" _tep(unsigned long long int val){return val;}
constexpr kilotep<OMNI_LITTERAL_INTEGER> operator"" _ktep(unsigned long long int val){return val;}
constexpr megatep<OMNI_LITTERAL_INTEGER> operator"" _Mtep(unsigned long long int val){return val;}
constexpr gigatep<OMNI_LITTERAL_INTEGER> operator"" _Gtep(unsigned long long int val){return val;}



} //namespace suffixes



} //namespace omni

#endif //OMNIUNIT_ENERGY_HH_