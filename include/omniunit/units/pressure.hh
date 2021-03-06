//pressure.hh

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

#ifndef OMNIUNIT_PRESSURE_HH_
#define OMNIUNIT_PRESSURE_HH_

#include "../omniunit.hh"
#include "constants_for_units.hh"


namespace omni
{



typedef Dimension<-1,1,-2,0,0,0,0> Pressure;



template <typename Rep = OMNI_DEFAULT_TYPE>
using yoctopascal = Unit<Pressure, Rep, yocto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zeptopascal = Unit<Pressure, Rep, zepto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using attopascal = Unit<Pressure, Rep, atto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using femtopascal = Unit<Pressure, Rep, femto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using picopascal = Unit<Pressure, Rep, pico, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using nanopascal = Unit<Pressure, Rep, nano, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using micropascal = Unit<Pressure, Rep, micro, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millipascal = Unit<Pressure, Rep, milli, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centipascal = Unit<Pressure, Rep, centi, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decipascal = Unit<Pressure, Rep, deci, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using pascal_t = Unit<Pressure, Rep, base, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decapascal = Unit<Pressure, Rep, deca, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using hectopascal = Unit<Pressure, Rep, hecto, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilopascal = Unit<Pressure, Rep, kilo, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using megapascal = Unit<Pressure, Rep, mega, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gigapascal = Unit<Pressure, Rep, giga, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using terapascal = Unit<Pressure, Rep, tera, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using petapascal = Unit<Pressure, Rep, peta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using exapascal = Unit<Pressure, Rep, exa, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using zettapascal = Unit<Pressure, Rep, zetta, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using yottapascal = Unit<Pressure, Rep, yotta, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using millibar = Unit<Pressure, Rep, Ratio<E5, E3>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using decibar = Unit<Pressure, Rep, Ratio<E5, E1>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using bar = Unit<Pressure, Rep, Ratio<E5, E0>, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using atmosphere = Unit<Pressure, Rep, Ratio<atmDef, E0>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using technicalatmosphere = Unit<Pressure, Rep, Ratio<gE5, E1>, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using poundforcePerInch2 = Unit<Pressure, Rep, typename Ratio_over_Ratio<Ratio<poundforceE13, E13>, typename Ratio_power<Ratio<inchE2, E2>, 2>::type>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using shorttonforcePerInch2 = Unit<Pressure, Rep, typename Ratio_times_value<typename poundforcePerInch2<Rep>::period, twoThousand>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using longtonforcePerInch2 = Unit<Pressure, Rep, typename Ratio_times_value<typename poundforcePerInch2<Rep>::period, longtonforceDef>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gramforcePerCentimeter2 = Unit<Pressure, Rep, Ratio<gE5, E4>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using gramforcePerMeter2 = Unit<Pressure, Rep, Ratio<gE5, E8>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilogramforcePerCentimeter2 = technicalatmosphere<Rep>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using kilogramforcePerMeter2 = Unit<Pressure, Rep, Ratio<gE5, E5>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using tonforcePerCentimeter2 = Unit<Pressure, Rep, typename Ratio_times_value<Ratio<gE5, E2>, E4>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using tonforcePerMeter2 = Unit<Pressure, Rep, Ratio<gE5, E2>, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using torr = Unit<Pressure, Rep, Ratio<atmDef, torrDenominator>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millitorr = Unit<Pressure, Rep, typename Ratio_over_value<typename torr<Rep>::period, E3>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millimetermercury = Unit<Pressure, Rep, Ratio<atmDef, torrDenominator>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centimetermercury = Unit<Pressure, Rep, typename Ratio_times_value<typename millimetermercury<Rep>::period, E1>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using micrometermercury = Unit<Pressure, Rep, typename Ratio_over_value<typename millimetermercury<Rep>::period, E3>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using inchmercury = Unit<Pressure, Rep, Ratio<inchmercuryE3, E3>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using centimeterwater = Unit<Pressure, Rep, Ratio<gE5, E4>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using millimeterwater = Unit<Pressure, Rep, Ratio<gE5, E5>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using meterwater = Unit<Pressure, Rep, Ratio<gE5, E2>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using inchwater = Unit<Pressure, Rep, typename Ratio_times_Ratio<Ratio<gE5, E2>, Ratio<inchE2, E4>>::type, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using footwater = Unit<Pressure, Rep, typename Ratio_times_Ratio<Ratio<gE5, E2>, Ratio<footE2, E4>>::type, zero>;



template <typename Rep = OMNI_DEFAULT_TYPE>
using barye = Unit<Pressure, Rep, Ratio<E0, E1>, zero>;

template <typename Rep = OMNI_DEFAULT_TYPE>
using meterseawater = Unit<Pressure, Rep, Ratio<E4, E0>, zero>;


typedef yoctopascal<> Yoctopascal;
typedef zeptopascal<> Zeptopascal;
typedef attopascal<> Attopascal;
typedef femtopascal<>  Femtopascal;
typedef picopascal<> Picopascal;
typedef nanopascal<> Nanopascal;
typedef micropascal<> Micropascal;
typedef millipascal<> Millipascal;
typedef centipascal<> Centipascal;
typedef decipascal<> Decipascal;
typedef pascal_t<> Pascal;
typedef decapascal<> Decapascal;
typedef hectopascal<> Hectopascal;
typedef kilopascal<> Kilopascal;
typedef megapascal<> Megapascal;
typedef gigapascal<> Gigapascal;
typedef terapascal<> Terapascal;
typedef petapascal<> Petapascal;
typedef exapascal<> Exapascal;
typedef zettapascal<> Zettapascal;
typedef yottapascal<> Yottapascal;

typedef millibar<> Millibar;
typedef decibar<> Decibar;
typedef bar<> Bar;
typedef atmosphere<> Atmosphere;
typedef technicalatmosphere<> Technicalatmosphere;
typedef poundforcePerInch2<> PoundforcePerInch2;
typedef shorttonforcePerInch2<> ShorttonforcePerInch2;
typedef longtonforcePerInch2<> LongtonforcePerInch2;
typedef gramforcePerCentimeter2<> GramforcePerCentimeter2;
typedef kilogramforcePerCentimeter2<> KilogramforcePerCentimeter2;
typedef kilogramforcePerMeter2<> KilogramforcePerMeter2;
typedef tonforcePerCentimeter2<> TonforcePerCentimeter2;
typedef tonforcePerMeter2<> TonforcePerMeter2;
typedef torr<> Torr;
typedef millitorr<> Millitorr;
typedef millimetermercury<> Millimetermercury;
typedef centimetermercury<> Centimetermercury;
typedef micrometermercury<> Micrometermercury;
typedef inchmercury<> Inchmercury;
typedef centimeterwater<> Centimeterwater;
typedef millimeterwater<> Millimeterwater;
typedef meterwater<> Meterwater;
typedef inchwater<> Inchwater;
typedef footwater<> Footwater;
typedef barye<> Barye;
typedef meterseawater<> Meterseawater;



namespace suffixes
{



constexpr yoctopascal<OMNI_LITTERAL_FLOATING> operator"" _yPa(long double val){return val;}
constexpr zeptopascal<OMNI_LITTERAL_FLOATING> operator"" _zPa(long double val){return val;}
constexpr attopascal<OMNI_LITTERAL_FLOATING> operator"" _aPa(long double val){return val;}
constexpr femtopascal<OMNI_LITTERAL_FLOATING> operator"" _fPa(long double val){return val;}
constexpr nanopascal<OMNI_LITTERAL_FLOATING> operator"" _nPa(long double val){return val;}
constexpr micropascal<OMNI_LITTERAL_FLOATING> operator"" _uPa(long double val){return val;}
constexpr millipascal<OMNI_LITTERAL_FLOATING> operator"" _mPa(long double val){return val;}
constexpr centipascal<OMNI_LITTERAL_FLOATING> operator"" _cPa(long double val){return val;}
constexpr decipascal<OMNI_LITTERAL_FLOATING> operator"" _dPa(long double val){return val;}
constexpr pascal_t<OMNI_LITTERAL_FLOATING> operator"" _Pa(long double val){return val;}
constexpr decapascal<OMNI_LITTERAL_FLOATING> operator"" _daPa(long double val){return val;}
constexpr hectopascal<OMNI_LITTERAL_FLOATING> operator"" _hPa(long double val){return val;}
constexpr kilopascal<OMNI_LITTERAL_FLOATING> operator"" _kPa(long double val){return val;}
constexpr megapascal<OMNI_LITTERAL_FLOATING> operator"" _MPa(long double val){return val;}
constexpr gigapascal<OMNI_LITTERAL_FLOATING> operator"" _GPa(long double val){return val;}
constexpr terapascal<OMNI_LITTERAL_FLOATING> operator"" _TPa(long double val){return val;}
constexpr petapascal<OMNI_LITTERAL_FLOATING> operator"" _PPa(long double val){return val;}
constexpr exapascal<OMNI_LITTERAL_FLOATING> operator"" _EPa(long double val){return val;}
constexpr zettapascal<OMNI_LITTERAL_FLOATING> operator"" _ZPa(long double val){return val;}
constexpr yottapascal<OMNI_LITTERAL_FLOATING> operator"" _YPa(long double val){return val;}

constexpr millibar<OMNI_LITTERAL_FLOATING> operator"" _mbar(long double val){return val;}
constexpr decibar<OMNI_LITTERAL_FLOATING> operator"" _dbar(long double val){return val;}
constexpr bar<OMNI_LITTERAL_FLOATING> operator"" _bar(long double val){return val;}
constexpr atmosphere<OMNI_LITTERAL_FLOATING> operator"" _atm(long double val){return val;}
constexpr technicalatmosphere<OMNI_LITTERAL_FLOATING> operator"" _at(long double val){return val;}
constexpr torr<OMNI_LITTERAL_FLOATING> operator"" _torr(long double val){return val;}
constexpr millitorr<OMNI_LITTERAL_FLOATING> operator"" _mtorr(long double val){return val;}
constexpr millimetermercury<OMNI_LITTERAL_FLOATING> operator"" _mmHg(long double val){return val;}
constexpr centimetermercury<OMNI_LITTERAL_FLOATING> operator"" _cmHg(long double val){return val;}
constexpr micrometermercury<OMNI_LITTERAL_FLOATING> operator"" _umHg(long double val){return val;}
constexpr inchmercury<OMNI_LITTERAL_FLOATING> operator"" _inHg(long double val){return val;}
constexpr centimeterwater<OMNI_LITTERAL_FLOATING> operator"" _cmH2O(long double val){return val;}
constexpr millimeterwater<OMNI_LITTERAL_FLOATING> operator"" _mmH2O(long double val){return val;}
constexpr meterwater<OMNI_LITTERAL_FLOATING> operator"" _mH2O(long double val){return val;}
constexpr inchwater<OMNI_LITTERAL_FLOATING> operator"" _inH2O(long double val){return val;}
constexpr footwater<OMNI_LITTERAL_FLOATING> operator"" _fH2O(long double val){return val;}
constexpr barye<OMNI_LITTERAL_FLOATING> operator"" _bary(long double val){return val;}
constexpr meterseawater<OMNI_LITTERAL_FLOATING> operator"" _msw(long double val){return val;}



constexpr yoctopascal<OMNI_LITTERAL_INTEGER> operator"" _yPa(unsigned long long int val){return val;}
constexpr zeptopascal<OMNI_LITTERAL_INTEGER> operator"" _zPa(unsigned long long int val){return val;}
constexpr attopascal<OMNI_LITTERAL_INTEGER> operator"" _aPa(unsigned long long int val){return val;}
constexpr femtopascal<OMNI_LITTERAL_INTEGER> operator"" _fPa(unsigned long long int val){return val;}
constexpr nanopascal<OMNI_LITTERAL_INTEGER> operator"" _nPa(unsigned long long int val){return val;}
constexpr micropascal<OMNI_LITTERAL_INTEGER> operator"" _uPa(unsigned long long int val){return val;}
constexpr millipascal<OMNI_LITTERAL_INTEGER> operator"" _mPa(unsigned long long int val){return val;}
constexpr centipascal<OMNI_LITTERAL_INTEGER> operator"" _cPa(unsigned long long int val){return val;}
constexpr decipascal<OMNI_LITTERAL_INTEGER> operator"" _dPa(unsigned long long int val){return val;}
constexpr pascal_t<OMNI_LITTERAL_INTEGER> operator"" _Pa(unsigned long long int val){return val;}
constexpr decapascal<OMNI_LITTERAL_INTEGER> operator"" _daPa(unsigned long long int val){return val;}
constexpr hectopascal<OMNI_LITTERAL_INTEGER> operator"" _hPa(unsigned long long int val){return val;}
constexpr kilopascal<OMNI_LITTERAL_INTEGER> operator"" _kPa(unsigned long long int val){return val;}
constexpr megapascal<OMNI_LITTERAL_INTEGER> operator"" _MPa(unsigned long long int val){return val;}
constexpr gigapascal<OMNI_LITTERAL_INTEGER> operator"" _GPa(unsigned long long int val){return val;}
constexpr terapascal<OMNI_LITTERAL_INTEGER> operator"" _TPa(unsigned long long int val){return val;}
constexpr petapascal<OMNI_LITTERAL_INTEGER> operator"" _PPa(unsigned long long int val){return val;}
constexpr exapascal<OMNI_LITTERAL_INTEGER> operator"" _EPa(unsigned long long int val){return val;}
constexpr zettapascal<OMNI_LITTERAL_INTEGER> operator"" _ZPa(unsigned long long int val){return val;}
constexpr yottapascal<OMNI_LITTERAL_INTEGER> operator"" _YPa(unsigned long long int val){return val;}

constexpr millibar<OMNI_LITTERAL_INTEGER> operator"" _mbar(unsigned long long int val){return val;}
constexpr decibar<OMNI_LITTERAL_INTEGER> operator"" _dbar(unsigned long long int val){return val;}
constexpr bar<OMNI_LITTERAL_INTEGER> operator"" _bar(unsigned long long int val){return val;}
constexpr atmosphere<OMNI_LITTERAL_INTEGER> operator"" _atm(unsigned long long int val){return val;}
constexpr technicalatmosphere<OMNI_LITTERAL_INTEGER> operator"" _at(unsigned long long int val){return val;}
constexpr torr<OMNI_LITTERAL_INTEGER> operator"" _torr(unsigned long long int val){return val;}
constexpr millitorr<OMNI_LITTERAL_INTEGER> operator"" _mtorr(unsigned long long int val){return val;}
constexpr millimetermercury<OMNI_LITTERAL_INTEGER> operator"" _mmHg(unsigned long long int val){return val;}
constexpr centimetermercury<OMNI_LITTERAL_INTEGER> operator"" _cmHg(unsigned long long int val){return val;}
constexpr micrometermercury<OMNI_LITTERAL_INTEGER> operator"" _umHg(unsigned long long int val){return val;}
constexpr inchmercury<OMNI_LITTERAL_INTEGER> operator"" _inHg(unsigned long long int val){return val;}
constexpr centimeterwater<OMNI_LITTERAL_INTEGER> operator"" _cmH2O(unsigned long long int val){return val;}
constexpr millimeterwater<OMNI_LITTERAL_INTEGER> operator"" _mmH2O(unsigned long long int val){return val;}
constexpr meterwater<OMNI_LITTERAL_INTEGER> operator"" _mH2O(unsigned long long int val){return val;}
constexpr inchwater<OMNI_LITTERAL_INTEGER> operator"" _inH2O(unsigned long long int val){return val;}
constexpr footwater<OMNI_LITTERAL_INTEGER> operator"" _fH2O(unsigned long long int val){return val;}
constexpr barye<OMNI_LITTERAL_INTEGER> operator"" _bary(unsigned long long int val){return val;}
constexpr meterseawater<OMNI_LITTERAL_INTEGER> operator"" _msw(unsigned long long int val){return val;}



} //namespace suffixes



} //namespace omni



#endif //OMNIUNIT_PRESSURE_HH_
