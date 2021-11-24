#include "Sort.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

#include <boost/python.hpp>

using std::cout;
using std::vector;

py::list sort(py::list& arr)
{
    auto cppArr = vector<int>(py::stl_input_iterator<int>(arr), py::stl_input_iterator<int>());
    
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(cppArr.begin(), cppArr.end());
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "cpp\n" << duration.count() << " microsec\n\n";

    py::list pyList;
    for (auto item : cppArr)
    {
        pyList.append(item);
    }
    return pyList;
}

BOOST_PYTHON_MODULE(cppsort)
{
    py::def("sort", sort);
}