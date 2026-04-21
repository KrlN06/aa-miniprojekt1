//
// Created by Karol Nalepa on 20/04/2026.
//

#include "Timer.h"


Timer::Timer() {}

Timer::~Timer() {}

void Timer::start() {
    startTime = std::chrono::high_resolution_clock::now();
}

void Timer::stop() {
    endTime = std::chrono::high_resolution_clock::now();
}

long long Timer::getElapsedTime() const {
    auto elapsed = endTime - startTime;

    return std::chrono::duration_cast<std::chrono::microseconds>(
        elapsed
    ).count();
}