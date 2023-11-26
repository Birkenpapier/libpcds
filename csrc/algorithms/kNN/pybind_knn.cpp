#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "knn.cpp"

namespace py = pybind11;

PYBIND11_MODULE(knn_module, m) {
    py::class_<KNN>(m, "KNN")
        .def(py::init<int>())
        .def("fit", &KNN::fit)
        .def("predict", &KNN::predict);
}
