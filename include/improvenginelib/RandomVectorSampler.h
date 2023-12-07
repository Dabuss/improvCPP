#pragma once

#include <random>
#include <vector>

template <typename T>
class RandomVectorSampler {
public:
    RandomVectorSampler();

    T sample(std::vector<T> const &data) const;

private:
    mutable std::mt19937 m_generator;
};

#include "../src/improvenginelib/RandomVectorSampler.inl"
