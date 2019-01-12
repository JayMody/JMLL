#include <chrono>
#include <string>
using namespace std::chrono;

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

std::string diff_time()
{
    return std::to_string(duration_cast<microseconds>(stop - start).count());
}
