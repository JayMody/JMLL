// Libraries
#include <chrono>
#include <string>

// Headers
#include "Timer.hpp"

using namespace chrono;
using namespace std;

static auto start = high_resolution_clock::now();
static auto stop = high_resolution_clock::now();

void start_time()
{
    start = high_resolution_clock::now();
}

void stop_time()
{
    stop = high_resolution_clock::now();
}

/// Diff Time ///
/**
 * Returns the time that has passed between start_time() and stop_time() in milliseconds
 *
 * @return String of the time passed in milliseconds
 */
string diff_time()
{
    return to_string(duration_cast<microseconds>(stop - start).count() / 1000.0);
}
