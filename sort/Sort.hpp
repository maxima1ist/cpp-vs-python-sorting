#ifndef SORT_HPP
#define SORT_HPP

namespace boost
{
    namespace python
    {
        class list;
    }
}

namespace py = boost::python;

py::list sort(py::list& arr);

#endif // SORT_HPP