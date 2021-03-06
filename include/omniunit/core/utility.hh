//utility.hh

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



#ifndef OMNIUNIT_UTILITY_HH_
#define OMNIUNIT_UTILITY_HH_


#include <cmath>
#include <limits>
#include <ratio>
#include <string>



namespace omni
{



//=============================================================================
//=============================================================================
//=============================================================================
//=== INTERNAL EPSILON ========================================================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename T>
struct InternEpsilon
{
  static_assert(std::is_integral<T>::value, "Type is not arithmetic.");
  inline static constexpr T value =  std::numeric_limits<T>::epsilon();
};


template <>
struct InternEpsilon<float>
{
  inline static constexpr float value = (OMNI_USE_STD_EPSILON ? std::numeric_limits<float>::epsilon() : OMNI_FLT_EPSILON);
};


template <>
struct InternEpsilon<double>
{
  inline static constexpr double value = (OMNI_USE_STD_EPSILON ? std::numeric_limits<double>::epsilon() : OMNI_DBL_EPSILON);
};


template <>
struct InternEpsilon<long double>
{
  inline static constexpr long double value = (OMNI_USE_STD_EPSILON ? std::numeric_limits<long double>::epsilon() : OMNI_LDBL_EPSILON);
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== COMPARISON EPSILON ========================================================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename T>
struct Epsilon
{
  static_assert(std::is_integral<T>::value, "Type is not arithmetic.");
  inline static constexpr T value =  std::numeric_limits<T>::epsilon();
};


template <>
struct Epsilon<float>
{
  inline static constexpr float value = (OMNI_COMPARISON_USE_STD_EPSILON ? std::numeric_limits<float>::epsilon() : OMNI_COMPARISON_FLT_EPSILON);
};


template <>
struct Epsilon<double>
{
  inline static constexpr double value = (OMNI_COMPARISON_USE_STD_EPSILON ? std::numeric_limits<double>::epsilon() : OMNI_COMPARISON_DBL_EPSILON);
};


template <>
struct Epsilon<long double>
{
  inline static constexpr long double value = (OMNI_COMPARISON_USE_STD_EPSILON ? std::numeric_limits<long double>::epsilon() : OMNI_COMPARISON_LDBL_EPSILON);
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== UTILITY FUNCTIONS =======================================================
//=============================================================================
//=============================================================================
//=============================================================================



//modulo at compile time (if parameters are constexpr) which can handle floating points.
template <typename T, typename U>
constexpr typename std::common_type<T, U>::type
modulo(T const& a, U const& b)
{
  static_assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value, "Arguments should be arithmetic values.");
  typedef typename std::common_type<T, U>::type common;
  common a2 = static_cast<common>(a);
  common b2 = static_cast<common>(b);
  return a2 - (static_cast<common>(std::floor(a2/b2)) * b2);
}


//there is a standard gcd in c++17, but it handles only integers.
template <typename T, typename U>
constexpr typename std::common_type<T, U>::type
gcd(T const& a, U const& b)
{
  static_assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value, "Arguments should be arithmetic values.");

  typedef typename std::common_type<T, U>::type common;
  common a2 = static_cast<common>(a);
  common b2 = static_cast<common>(b);

  double temp = 0;
  while (std::abs(b2) > InternEpsilon<common>::value)
  {
    temp = modulo(a2, b2);
    a2 = b2;
    b2 = temp;
  }
  return a2;
}


//test if a double has no decimals and is positive
template <typename T>
constexpr bool is_positive_integer(T const& number)
{
  static_assert(std::is_arithmetic<T>::value, "Arguments should be arithmetic values.");
  T res = number - static_cast<T>(std::floor(number));
  return (std::abs(res) <= InternEpsilon<T>::value && number >= 0);
}


template <typename T>
constexpr long long unsigned factorial(T const& n)
{
  static_assert(std::is_integral<T>::value && std::is_unsigned<T>::value, "Factorial argument must be a unsigned integer type");
  return ((n == 1 || n == 0) ? 1 : factorial(n-1) * n);
}


constexpr long long unsigned operator"" _fact(unsigned long long n) {return factorial(n);}



//=============================================================================
//=============================================================================
//=============================================================================
//=== STATIC CONSTEXPR POWER OF TEN DEFINITION ================================
//=============================================================================
//=============================================================================
//=============================================================================



inline constexpr double zero = 0.;

inline constexpr double E0  = 1.;
inline constexpr double E1  = 10.;
inline constexpr double E2  = 100.;
inline constexpr double E3  = 1000.;
inline constexpr double E4  = 10000.;
inline constexpr double E5  = 100000.;
inline constexpr double E6  = 1000000.;
inline constexpr double E7  = 10000000.;
inline constexpr double E8  = 100000000.;
inline constexpr double E9  = 1000000000.;
inline constexpr double E10 = 10000000000.;
inline constexpr double E11 = 100000000000.;
inline constexpr double E12 = 1000000000000.;
inline constexpr double E13 = 10000000000000.;
inline constexpr double E14 = 100000000000000.;
inline constexpr double E15 = 1000000000000000.;
inline constexpr double E16 = 10000000000000000.;
inline constexpr double E17 = 100000000000000000.;
inline constexpr double E18 = 1000000000000000000.;
inline constexpr double E19 = 10000000000000000000.;
inline constexpr double E20 = 100000000000000000000.;
inline constexpr double E21 = 1000000000000000000000.;
inline constexpr double E22 = 10000000000000000000000.;
inline constexpr double E23 = 100000000000000000000000.;
inline constexpr double E24 = 1000000000000000000000000.;
inline constexpr double E25 = 10000000000000000000000000.;
inline constexpr double E26 = 100000000000000000000000000.;
inline constexpr double E27 = 1000000000000000000000000000.;
inline constexpr double E28 = 10000000000000000000000000000.;
inline constexpr double E29 = 100000000000000000000000000000.;
inline constexpr double E30 = 1000000000000000000000000000000.;
inline constexpr double E31 = 10000000000000000000000000000000.;
inline constexpr double E32 = 100000000000000000000000000000000.;
inline constexpr double E33 = 1000000000000000000000000000000000.;
inline constexpr double E34 = 10000000000000000000000000000000000.;
inline constexpr double E35 = 100000000000000000000000000000000000.;
inline constexpr double E36 = 1000000000000000000000000000000000000.;
inline constexpr double E37 = 10000000000000000000000000000000000000.;
inline constexpr double E38 = 100000000000000000000000000000000000000.;
inline constexpr double E39 = 1000000000000000000000000000000000000000.;
inline constexpr double E40 = 10000000000000000000000000000000000000000.;
inline constexpr double E41 = 100000000000000000000000000000000000000000.;
inline constexpr double E42 = 1000000000000000000000000000000000000000000.;
inline constexpr double E43 = 10000000000000000000000000000000000000000000.;
inline constexpr double E44 = 100000000000000000000000000000000000000000000.;
inline constexpr double E45 = 1000000000000000000000000000000000000000000000.;
inline constexpr double E46 = 10000000000000000000000000000000000000000000000.;
inline constexpr double E47 = 100000000000000000000000000000000000000000000000.;
inline constexpr double E48 = 1000000000000000000000000000000000000000000000000.;
inline constexpr double E49 = 10000000000000000000000000000000000000000000000000.;
inline constexpr double E50 = 100000000000000000000000000000000000000000000000000.;
inline constexpr double E51 = 1000000000000000000000000000000000000000000000000000.;
inline constexpr double E52 = 10000000000000000000000000000000000000000000000000000.;
inline constexpr double E53 = 100000000000000000000000000000000000000000000000000000.;
inline constexpr double E54 = 1000000000000000000000000000000000000000000000000000000.;
inline constexpr double E55 = 10000000000000000000000000000000000000000000000000000000.;
inline constexpr double E56 = 100000000000000000000000000000000000000000000000000000000.;
inline constexpr double E57 = 1000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E58 = 10000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E59 = 100000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E60 = 1000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E61 = 10000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E62 = 100000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E63 = 1000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E64 = 10000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E65 = 100000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E66 = 1000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E67 = 10000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E68 = 100000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E69 = 1000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E70 = 10000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E71 = 100000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E72 = 1000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E73 = 10000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E74 = 100000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E75 = 1000000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E76 = 10000000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E77 = 100000000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E78 = 1000000000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E79 = 10000000000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E80 = 100000000000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E81 = 1000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E82 = 10000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E83 = 100000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E84 = 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E85 = 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E86 = 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E87 = 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E88 = 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E89 = 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.;
inline constexpr double E90 = 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.;



//=============================================================================
//=============================================================================
//=============================================================================
//=== RATIO DEFINITION ========================================================
//=============================================================================
//=============================================================================
//=============================================================================



template<double const& _Num, double const& _Den>
struct Ratio
{
  static_assert(is_positive_integer(_Num), "Numerator may not have decimals and may be positive.");
  static_assert(is_positive_integer(_Den), "Denominator may not have decimals and may be positive.");
  static_assert(_Den > InternEpsilon<double>::value, "Denominator cannot be zero.");

  static constexpr double num = _Num / gcd(_Num, _Den);
  static constexpr double den = _Den / gcd(_Num, _Den);
  inline static constexpr double value = num / den;
  typedef Ratio<num, den> type;
};


template<typename falseType>
struct is_stb_Ratio : std::false_type
{
};


template<double const& Num, double const& Den>
struct is_stb_Ratio<Ratio<Num, Den>> : public std::true_type
{
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== RATIO ARITHMETIC ========================================================
//=============================================================================
//=============================================================================
//=============================================================================



template <typename ratio>
class Ratio_invert
{
  static_assert(std::abs(ratio::num) > InternEpsilon<double>::value, "Denominator cannot be zero.");
  static_assert(is_stb_Ratio<ratio>::value , "Template parameter should be an OmniUnit ratio.");
public:
  typedef Ratio<ratio::den, ratio::num> type;
};


template <typename ratio1, typename ratio2>
class Ratio_times_Ratio
{
  static_assert(is_stb_Ratio<ratio1>::value && is_stb_Ratio<ratio2>::value, "Template parameters should be OmniUnit ratios.");

  static constexpr double _gcd = gcd(ratio1::num * ratio2::num, ratio1::den * ratio2::den);
  static constexpr double num = (ratio1::num * ratio2::num) / _gcd;
  static constexpr double den = (ratio1::den * ratio2::den) / _gcd;
public:
  typedef Ratio<num, den> type;
};


template <typename ratio, double const& val>
class Ratio_times_value
{
  static_assert(is_stb_Ratio<ratio>::value, "First template parameter should be an OmniUnit ratio.");
  static_assert(is_positive_integer(val), "Second template parameter may not have decimals and may be positive.");

  static constexpr double _gcd = gcd(ratio::num * val, ratio::den);
  static constexpr double num = (ratio::num * val) / _gcd;
  static constexpr double den = ratio::den / _gcd;
public:
  typedef Ratio<num, den> type;
};


template <double const& val, typename ratio>
class value_times_Ratio
{
  static_assert(is_stb_Ratio<ratio>::value, "Second template parameter should be an OmniUnit ratio.");
  static_assert(is_positive_integer(val), "First template parameter may not have decimals and may be positive.");
public:
  typedef typename Ratio_times_value<ratio, val>::type type;
};


template <typename ratio1, typename ratio2>
class Ratio_over_Ratio
{
  static_assert(std::abs(ratio2::num) > InternEpsilon<double>::value, "Denominator cannot be zero.");
  static_assert(is_stb_Ratio<ratio1>::value && is_stb_Ratio<ratio2>::value, "Template parameters should be OmniUnit ratios.");

  static constexpr double _gcd = gcd(ratio1::num * ratio2::den, ratio1::den * ratio2::num);
  static constexpr double num = (ratio1::num * ratio2::den) / _gcd;
  static constexpr double den = (ratio1::den * ratio2::num) /_gcd;
public:
  typedef Ratio<num, den> type;
};


template <typename ratio, double const& val>
class Ratio_over_value
{
  static_assert(std::abs(val) > InternEpsilon<double>::value, "Denominator cannot be zero.");
  static_assert(is_stb_Ratio<ratio>::value, "First template parameter should be an OmniUnit ratio.");
  static_assert(is_positive_integer(val), "Second template parameter may not have decimals and may be positive.");

  static constexpr double _gcd = gcd(ratio::num, ratio::den * val);
  static constexpr double num = ratio::num / _gcd;
  static constexpr double den = (ratio::den * val) /_gcd;
public:
  typedef Ratio<num, den> type;
};


template <double const& val, typename ratio>
class value_over_Ratio
{
  static_assert(std::abs(ratio::num) > InternEpsilon<double>::value, "Denominator cannot be zero.");
  static_assert(is_stb_Ratio<ratio>::value, "Second template parameter should be an OmniUnit ratio.");
  static_assert(is_positive_integer(val), "First template parameter may not have decimals and may be positive.");

  static constexpr double _gcd = gcd(val * ratio::den, ratio::num);
  static constexpr double num = (val * ratio::den) / _gcd;
  static constexpr double den = (ratio::den * val) /_gcd;
public:
  typedef Ratio<num, den> type;
};


template <typename ratio, int exponent>
class Ratio_power
{
  static_assert(is_stb_Ratio<ratio>::value, "First template parameter should be an OmniUnit ratio.");

  static constexpr double _gcd = gcd(std::pow(ratio::num, exponent), std::pow(ratio::den, exponent));
  static constexpr double num = std::pow(ratio::num, exponent) / _gcd;
  static constexpr double den = std::pow(ratio::den, exponent) /_gcd;
public:
  typedef Ratio<num, den> type;
};


template <typename ratio, int basis>
class Ratio_root
{
  static_assert(is_stb_Ratio<ratio>::value, "First template parameter should be an OmniUnit ratio.");
  static_assert(basis != 0, "Basis must not be 0.");

  static constexpr double _gcd = gcd(std::pow(ratio::num, 1.0/basis), std::pow(ratio::den, 1.0/basis));
  static constexpr double num = std::pow(ratio::num, 1.0/basis) / _gcd;
  static constexpr double den = std::pow(ratio::den, 1.0/basis) /_gcd;
public:
  typedef Ratio<num, den> type;
};


//=============================================================================
//=============================================================================
//=============================================================================
//=== RATIO CONVERTER STD/OMNI =================================================
//=============================================================================
//=============================================================================
//=============================================================================



template<typename falseType>
struct is_std_Ratio : std::false_type
{
};


template<intmax_t Num, intmax_t Den>
struct is_std_Ratio<std::ratio<Num, Den>> : public std::true_type
{
};


template<typename _stdRatio>
class Ratio_std_to_omni
{
  static_assert(is_std_Ratio<_stdRatio>::value, "Template parameter should be a standard ratio.");

  static constexpr double num = static_cast<double>(_stdRatio::num);
  static constexpr double den = static_cast<double>(_stdRatio::den);
public:
  typedef Ratio<num, den> type;
};


template<typename _stbRatio>
class Ratio_omni_to_std
{
  static_assert(is_stb_Ratio<_stbRatio>::value, "Template parameter should be an OmniUnit ratio.");
  static_assert(_stbRatio::num < std::numeric_limits<intmax_t>::max(), "Too high numerator.");
  static_assert(_stbRatio::den < std::numeric_limits<intmax_t>::max(), "Too high denominator.");
public:
  typedef std::ratio<static_cast<intmax_t>(_stbRatio::num), static_cast<intmax_t>(_stbRatio::den)> type;
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== RATIO TYPEDEF ===========================================================
//=============================================================================
//=============================================================================
//=============================================================================



typedef Ratio<E0, E24> yocto;
typedef Ratio<E0, E21> zepto;
typedef Ratio<E0, E18> atto;
typedef Ratio<E0, E15> femto;
typedef Ratio<E0, E12> pico;
typedef Ratio<E0, E9> nano;
typedef Ratio<E0, E6> micro;
typedef Ratio<E0, E3> milli;
typedef Ratio<E0, E2> centi;
typedef Ratio<E0, E1> deci;
typedef Ratio<E0, E0> base;
typedef Ratio<E1, E0> deca;
typedef Ratio<E2, E0> hecto;
typedef Ratio<E3, E0> kilo;
typedef Ratio<E6, E0> mega;
typedef Ratio<E9, E0> giga;
typedef Ratio<E12, E0> tera;
typedef Ratio<E15, E0> peta;
typedef Ratio<E18, E0> exa;
typedef Ratio<E21, E0> zetta;
typedef Ratio<E24, E0> yotta;



//=============================================================================
//=============================================================================
//=============================================================================
//=== DIMENSION DEFINITION ====================================================
//=============================================================================
//=============================================================================
//=============================================================================



template<int _length, int _mass, int _time, int _current,
int _temperature, int _quantity, int _luminous_intensity>
struct Dimension
{
  inline static constexpr int length = _length;
  inline static constexpr int mass = _mass;
  inline static constexpr int time = _time;
  inline static constexpr int current = _current;
  inline static constexpr int temperature = _temperature;
  inline static constexpr int quantity = _quantity;
  inline static constexpr int luminous_intensity = _luminous_intensity;
};


typedef Dimension<0,0,0,0,0,0,0> Dimensionless;


template<typename falseType>
struct is_Dimension : std::false_type
{
};


template<int length, int mass, int time, int current,
int temperature, int quantity, int luminous_intensity>
struct is_Dimension<Dimension<length, mass, time, current,
temperature, quantity, luminous_intensity>> : public std::true_type
{
};


template <typename dim1, typename dim2>
struct Dimension_multiply
{
  static_assert(is_Dimension<dim1>::value && is_Dimension<dim2>::value,
  "Template parameters should be dimensions.");

  typedef Dimension<
  dim1::length + dim2::length,
  dim1::mass + dim2::mass,
  dim1::time + dim2::time,
  dim1::current + dim2::current,
  dim1::temperature + dim2::temperature,
  dim1::quantity + dim2::quantity,
  dim1::luminous_intensity + dim2::luminous_intensity
  > type;
};


template <typename dim1, typename dim2>
struct Dimension_divide
{
  static_assert(is_Dimension<dim1>::value && is_Dimension<dim2>::value,
  "Template parameters should be dimensions.");

  typedef Dimension<
  dim1::length - dim2::length,
  dim1::mass - dim2::mass,
  dim1::time - dim2::time,
  dim1::current - dim2::current,
  dim1::temperature - dim2::temperature,
  dim1::quantity - dim2::quantity,
  dim1::luminous_intensity - dim2::luminous_intensity
  > type;
};


template <typename dim, int exponent>
struct Dimension_power
{
  static_assert(is_Dimension<dim>::value, "Template parameter should be dimension.");

  typedef Dimension<
  dim::length * exponent,
  dim::mass * exponent,
  dim::time * exponent,
  dim::current * exponent,
  dim::temperature * exponent,
  dim::quantity * exponent,
  dim::luminous_intensity * exponent
  > type;
};


template <typename dim, int basis>
struct Dimension_root
{
  static_assert(is_Dimension<dim>::value, "Template parameter should be dimension.");
  static_assert(basis != 0, "Basis must not be 0.");

  static_assert(
  std::abs(modulo(static_cast<double>(dim::length) / static_cast<double>(basis), 1)) <= InternEpsilon<double>::value &&
  std::abs(modulo(static_cast<double>(dim::mass) / static_cast<double>(basis), 1)) <= InternEpsilon<double>::value &&
  std::abs(modulo(static_cast<double>(dim::time) / static_cast<double>(basis), 1)) <= InternEpsilon<double>::value &&
  std::abs(modulo(static_cast<double>(dim::current) / static_cast<double>(basis), 1)) <= InternEpsilon<double>::value &&
  std::abs(modulo(static_cast<double>(dim::temperature) / static_cast<double>(basis), 1)) <= InternEpsilon<double>::value &&
  std::abs(modulo(static_cast<double>(dim::quantity) / static_cast<double>(basis), 1)) <= InternEpsilon<double>::value &&
  std::abs(modulo(static_cast<double>(dim::luminous_intensity) / static_cast<double>(basis), 1)) <= InternEpsilon<double>::value,
  "Cannot root this dimension with this basis (some values may not be integers).");

  typedef Dimension<
  dim::length / basis,
  dim::mass / basis,
  dim::time / basis,
  dim::current / basis,
  dim::temperature / basis,
  dim::quantity / basis,
  dim::luminous_intensity / basis
  > type;
};


//it is useless to make this function part of the class Dimension (static constexpr)
//because std::string is not a litteral : the function cannot be interpreted at
//compile time, so class Dimension could neither (i guess...).
template<typename dimension>
constexpr std::string dimension_str()
{
  static_assert(is_Dimension<dimension>::value, "Template parameter should be dimension.");

  std::string dim = "";

  if(dimension::length != 0)
    dim += ("[L" + std::to_string(dimension::length) + "]");
  if(dimension::mass != 0)
    dim += ("[M" + std::to_string(dimension::mass) + "]");
  if(dimension::time != 0)
    dim += ("[Tm" + std::to_string(dimension::time) + "]");
  if(dimension::current != 0)
    dim += ("[I" + std::to_string(dimension::current) + "]");
  if(dimension::temperature != 0)
    dim += ("[Tp" + std::to_string(dimension::temperature) + "]");
  if(dimension::quantity != 0)
    dim += ("[N" + std::to_string(dimension::quantity) + "]");
  if(dimension::luminous_intensity != 0)
    dim += ("[J" + std::to_string(dimension::luminous_intensity) + "]");
  if(dim.length() == 0)
    dim = "[1]";

  return dim;
}



//=============================================================================
//=============================================================================
//=============================================================================
//=== ORIGIN MANAGEMENT =======================================================
//=============================================================================
//=============================================================================
//=============================================================================



template<double const& a, double const& b>
struct origin_product
{
  inline static constexpr double value = OMNI_TRUE_ZERO ? zero : a*b;
};


template<double const& a, double const& b>
struct origin_division
{
  //static_assert(std::abs(b) > InternEpsilon<double>::value, "Dividing Origin by 0.");
  inline static constexpr double value = (OMNI_TRUE_ZERO || std::abs(b) <= InternEpsilon<double>::value) ? zero : a/b;
};


template<double const& origin, int exponent>
struct origin_power
{
  inline static constexpr double value = std::pow(origin, exponent);
};


template<double const& origin, int basis>
struct origin_root
{
  static_assert(basis != 0, "Basis must not be 0.");
  inline static constexpr double value = std::pow(origin, 1.0/basis);
};



//=============================================================================
//=============================================================================
//=============================================================================
//=== UNCERTAINTY UTILITIES ===================================================
//=============================================================================
//=============================================================================
//=============================================================================



enum class Law {None, Uniform, Triangular, Asymetric, Normal, Arcsinus, Uniform_gap};

constexpr double getDeviation(double variation, Law law)
{
  if(law == Law::None || law == Law::Normal)
    return variation;
  else if(law == Law::Uniform)
    return variation / std::sqrt(3.);
  else if(law == Law::Triangular)
    return variation / std::sqrt(6.);
  else if(law == Law::Asymetric)
    return variation / (3. * std::sqrt(2.));
  else if(law == Law::Arcsinus)
    return variation / std::sqrt(2.);
  else if(law == Law::Uniform_gap)
    return variation / (2. * std::sqrt(3.));
}


template <typename container_t, typename systContainer_t>
constexpr std::initializer_list<double> getMeanAndDeviation(container_t const& Obj, systContainer_t systErr)
{
  static_assert(Obj.size > 1, "Cannot calculate uncertainty with a single value");

  double mean = 0.;
  double deviation = 0.;

  if(Obj.size() > 0)
  {
    for(unsigned count = 0; count < Obj.size(); count++)
      mean += static_cast<double>(Obj[count]);
    mean /= static_cast<double>(Obj.size());

    // non-biased variance
    for(unsigned count = 0; count < Obj.size(); count++)
      deviation += std::pow(static_cast<double>(Obj[count]) - mean, 2);

    if(Obj.size() > 1)
      deviation /= static_cast<double>(Obj.size()-1);
    deviation = std::sqrt(deviation/static_cast<double>(Obj.size()))* quantile(Obj.size() - 1);
  }

  // systematic error
  double syst = 0.;

  if(systErr.size() <= OMNI_NUMBER_OF_SYSTEM_ERROR_BEFORE_QUAD_SUM || OMNI_NUMBER_OF_SYSTEM_ERROR_BEFORE_QUAD_SUM == 0)
    for(unsigned count = 0; count < systErr.size(); count++)
      syst += static_cast<double>(systErr[count]);
  else
  {
    for(unsigned count = 0; count < systErr.size(); count++)
      syst += std::pow(static_cast<double>(systErr[count]), 2);
    syst = std::sqrt(syst);
  }

  //return the mean and the absolute confidence interval at 1 sigma
  return {std::sqrt(std::pow(mean, 2) + std::pow(syst, 2)), deviation};
}



} // namespace omni

#endif //OMNIUNIT_UTILITY_HH_