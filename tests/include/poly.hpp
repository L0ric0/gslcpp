#pragma once

#include <gtest/gtest.h>

// stllib
#include <complex>
#include <iostream>
#include <vector>

template <typename T>
concept EvalStruct = requires(T p)
{
    p.c;
    p.x;
    p.result;
};

template <EvalStruct T>
void PrintTo(const T& pto, std::ostream* os)
{
    *os << "{";
    *os << "c: [";
    for (const auto elem : pto.c) {
        *os << elem << ", ";
    }
    *os << "], ";
    *os << "x: " << pto.x << ", ";
    *os << "result: " << pto.result;
    *os << "}";
}

template <typename T>
concept SolveStruct = requires(T p)
{
    p.a;
    p.b;
    p.c;
    p.result;
};

template <SolveStruct T>
void PrintTo(const T& pto, std::ostream* os)
{
    *os << "{";
    *os << "a: " << pto.a << ", ";
    *os << "b: " << pto.b << ", ";
    *os << "c: " << pto.c << ", ";
    *os << "result: [";
    for (const auto elem : pto.result) {
        *os << elem << ", ";
    }
    *os << "]";
    *os << "}";
}

struct EvalParam {
    std::vector<double> c;
    double x;
    double result;
};

class PolyEval : public testing::TestWithParam<EvalParam>
{
};

struct EvalComplexParam {
    std::vector<double> c;
    std::complex<double> x;
    std::complex<double> result;
};

class PolyEvalComplex : public testing::TestWithParam<EvalComplexParam>
{
};

struct ComplexEvalComplexParam {
    std::vector<std::complex<double>> c;
    std::complex<double> x;
    std::complex<double> result;
};

class PolyComplexEvalComplex : public testing::TestWithParam<ComplexEvalComplexParam>
{
};

struct SolveParam {
    double a;
    double b;
    double c;
    std::vector<double> result;
};

class PolySolveQuadratic : public testing::TestWithParam<SolveParam>
{
};

class PolySolveCubic : public testing::TestWithParam<SolveParam>
{
};

struct SolveComplexParam {
    std::complex<double> a;
    std::complex<double> b;
    std::complex<double> c;
    std::vector<std::complex<double>> result;
};

class PolySolveQuadraticComplex : public testing::TestWithParam<SolveComplexParam>
{
};

class PolySolveCubicComplex : public testing::TestWithParam<SolveComplexParam>
{
};
