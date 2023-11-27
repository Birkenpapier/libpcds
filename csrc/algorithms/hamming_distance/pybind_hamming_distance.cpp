#include <pybind11/pybind11.h>
#include "hamming_distance.cpp"

namespace py = pybind11;

PYBIND11_MODULE(hamming_distance_module, m) {
    py::class_<HammingDistanceCalculator>(m, "HammingDistanceCalculator")
        .def(py::init<>())
        .def("compute", &HammingDistanceCalculator::compute);
}
