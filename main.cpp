#include <cmath>  // std::exp, std::cos

#include <pybind11/embed.h>  // py::scoped_interpreter
#include <pybind11/stl.h>    // bindings from C++ STL containers to Python types

namespace py = pybind11;

int main() {
    // Create an exponentially decaying sinusoidal signal as an example
    std::vector<double> signal(1024);
    for (size_t i = 0; i < signal.size(); ++i)
        signal[i] = std::exp(i / -256.0) * std::cos(2 * M_PI * 8 * i / 1024.0);

    // Start the Python interpreter
    py::scoped_interpreter guard{};
    using namespace py::literals;

    // Save the necessary local variables in a Python dict
    py::dict locals = py::dict{
        "signal"_a = signal,
    };

    // Execute Python code, using the local C++ variables
    py::exec(R"(
    
    import matplotlib.pyplot as plt

    plt.plot(signal)
    plt.show()
    
    )",
             py::globals(), locals);
}