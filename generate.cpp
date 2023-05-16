// Copyright (c) Tyler Swann 2023
// Made in partnership with Monash DeepNeuron
// for Monash DeepNeuron's HPC Training.

// Details
// This program will generate the input files
// containing the random list of numbers used
// by in some of the challenges.
//
// Build
// $ g++ -std=c++20 -o bin/generate generate.cpp
//
// Run
// $ bin/generate

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <ranges>
#include <string>
#include <string_view>
#include <tuple>
#include <utility>
#include <vector>

using namespace std::literals;
namespace fs = std::filesystem;

using result_t = std::pair<std::vector<double>, std::vector<double>>;

constexpr std::size_t problem_size = 1'000'000uL;

fs::path main_path = fs::current_path() / "challenges" / "distributed-computing";
fs::path sum_path = main_path / "sum";
fs::path partial_sum_path = main_path / "partial-sum";
fs::path mergesort_path = main_path / "mergesort";

auto gen = std::mt19937 { std::random_device {}() };
auto distrib = std::uniform_real_distribution { -1.0e5, 1.0e5 };
auto generate = [](auto& container) { std::ranges::generate(container, [&]() -> double { return distrib(gen); }); };

auto write(const fs::path& filename, const std::vector<double>& data) -> void
{
    auto file = std::fstream { filename, std::ios::in | std::ios::out | std::ios::trunc };

    if (file.is_open()) {
        std::ranges::copy(data, std::ostream_iterator<double>(file, "\n"));
    } else
        std::clog << "Failed to open file" << filename << std::endl;
}

namespace make {

auto sum() noexcept -> void
{
    auto input = std::vector<double>(problem_size, 0.0);

    generate(input);

    auto sum = std::accumulate(input.cbegin(), input.cend(), double {});
    auto output = std::vector<double> {};
    output.push_back(sum);

    write(sum_path / "input.txt", input);
    write(sum_path / "output.txt", output);
}

auto partial_sum() noexcept -> void
{
    auto input = std::vector<double>(problem_size, 0.0);
    generate(input);

    auto output = std::vector<double> {};
    std::partial_sum(input.cbegin(), input.cend(), std::back_inserter(output));

    write(partial_sum_path / "input.txt", input);
    write(partial_sum_path / "check.txt", output);
}

auto mergesort() noexcept -> void
{
    auto input = std::vector<double>(problem_size, 0.0);
    generate(input);
    write(mergesort_path / "unsorted.txt", input);

    std::ranges::sort(input);

    if (!std::ranges::is_sorted(input)) {
        std::clog << "Didn't sort input" << std::endl;
        return;
    }

    write(mergesort_path / "sorted.txt", input);
}

} // make

int main()
{
    make::sum();
    make::partial_sum();
    make::mergesort();

    return 0;
}
