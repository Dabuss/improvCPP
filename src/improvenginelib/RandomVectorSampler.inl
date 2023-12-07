template <typename T>
RandomVectorSampler<T>::RandomVectorSampler() : m_generator(std::random_device()())
    {}

template <typename T>
T RandomVectorSampler<T>::sample(const std::vector<T>& data)
{
    if (data.empty())
    {
        throw std::out_of_range("Cannot sample from an empty vector");
    }

    std::uniform_int_distribution<std::size_t> distribution(0, data.size() - 1);
    size_t index = distribution(m_generator);
    return data[index];
}
