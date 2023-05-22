// Copyright (c) Tyler Swann 2023
// Made in partnership with Monash DeepNeuron
// for Monash DeepNeuron's HPC Training.

// Details
// This program will generate the input files
// containing the random list of numbers used
// by in some of the challenges.
//
// Build
// $ g++ -std=c++20 -o bin/generate-lazy generate-lazy.cpp
//
// Run
// $ bin/generate-lazy

#include <algorithm>
#include <chrono>
#include <concepts>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <ranges>
#include <string_view>
#include <vector>

namespace fs = std::filesystem;

using clock = std::chrono::high_resolution_clock;

constexpr std::size_t default_problem_size = 1'000'000uL;

fs::path main_path = fs::current_path() / "challenges" / "distributed-computing";
fs::path sum_path = main_path / "sum";
fs::path mergesort_path = main_path / "mergesort";

auto gen = std::mt19937 { std::random_device {}() };
auto distrib = std::uniform_real_distribution { -1.0e5, 1.0e5 };
auto generate = std::views::transform([]([[maybe_unused]] auto x) -> double { return distrib(gen); });

template <std::ranges::range Range>
auto write(const fs::path& filename, Range&& data) -> void
{
    auto file = std::fstream { filename, std::ios::in | std::ios::out | std::ios::trunc };

    if (file.is_open()) {
        std::ranges::copy(data, std::ostream_iterator<double>(file, "\n"));
    } else
        std::clog << "Failed to open file" << filename << std::endl;

    file.close();
}

auto write(const fs::path& filename, const double& data) -> void
{
    auto file = std::fstream { filename, std::ios::in | std::ios::out | std::ios::trunc };

    if (file.is_open()) {
        file << data << std::endl;
    } else
        std::clog << "Failed to open file" << filename << std::endl;
}

namespace make {

auto sum(std::size_t problem_size) -> void
{
    auto auto nums = std::views::iota(0)
        | generate
        | std::views::take(problem_size)
        | std::views::common;

    auto sum = std::accumulate(nums.begin(), nums.end(), double {});

    write(sum_path / "input.txt", nums);
    write(sum_path / "output.txt", sum);
}

auto mergesort(std::size_t problem_size) -> void
{
    auto nums = std::views::iota(0) | generate | std::views::take(problem_size);
    write(mergesort_path / "unsorted.txt", nums);

    std::ranges::sort(nums);

    if (!std::ranges::is_sorted(nums)) {
        std::clog << "Didn't sort input" << std::endl;
        return;
    }

    write(mergesort_path / "sorted.txt", nums);
}

} // namespace make

int main(int argc, char* argv[])
{
    std::size_t problem_size = default_problem_size;

    if (argc > 1) {
        problem_size = std::atoll(argv[1]);
        problem_size = std::ranges::clamp(problem_size, default_problem_size, std::vector<double> {}.max_size());
    }

    make::sum(problem_size);
    make::mergesort(problem_size);

    return 0;
}
