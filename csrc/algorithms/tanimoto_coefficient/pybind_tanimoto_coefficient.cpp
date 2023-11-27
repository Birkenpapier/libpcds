// c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) pybind_tanimoto_coefficient.cpp -o tanimoto_coefficient_module$(python3-config --extension-suffix)

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "tanimoto_coefficient.cpp"

namespace py = pybind11;

PYBIND11_MODULE(tanimoto_coefficient_module, m) {
    py::class_<TanimotoCoefficientCalculator>(m, "TanimotoCoefficientCalculator")
        .def(py::init<>())
        .def("compute", &TanimotoCoefficientCalculator::compute);
}
