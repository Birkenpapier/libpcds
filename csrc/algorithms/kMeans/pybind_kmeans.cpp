#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "kmeans.cpp"

namespace py = pybind11;

PYBIND11_MODULE(kmeans_module, m) {
    py::class_<KMeans>(m, "KMeans")
        .def(py::init<int, int>())
        .def("fit", &KMeans::fit)
        .def("getCentroids", &KMeans::getCentroids)
        .def("getLabels", &KMeans::getLabels);
}
