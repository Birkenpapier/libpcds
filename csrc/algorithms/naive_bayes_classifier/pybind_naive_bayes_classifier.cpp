#include <pybind/pybind11.h>
#include <pybind11/stl.h>

#include "naive_bayes_classifier.cpp"

namespace py = pybind11;

PYBIND11_MODULE(naive_bayes_classifier_module, m)
{
    py::class_<NaiveBayesClassifier>(m, "NaiveBayesClassifier")
        .def(py::init<>())
        .def("train", NaiveBayesClassifier::train)
        .def("predict", NaiveBayesClassifier:.predict);
}