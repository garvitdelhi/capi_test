/*  Example of wrapping cos function from math.h with the Python-C-API. */

#include <Python.h>

/*  wrapped cosine function */
static PyObject* count_custom(PyObject* self, PyObject* args)
{
    long long int value;

    /*  parse the input, from python float to c double */
    if (!PyArg_ParseTuple(args, "L", &value))
        return NULL;
    /* if the above function returns -1, an appropriate Python exception will
     * have been set, and the function simply returns NULL
     */

    /* call cos from libm */
    Py_BEGIN_ALLOW_THREADS
    sleep(1);
    for (long long int i = 0; i < value; ++i) {}
    Py_END_ALLOW_THREADS

    /*  construct the output from cos, from c double to python float */
    return Py_BuildValue("i", 1);
}

/*  define functions in module */
static PyMethodDef myModule[] =
{
     {"count_custom", count_custom, METH_VARARGS, "evaluate the cosine"}
};

/* module initialization */
PyMODINIT_FUNC initmy_module(void)
{
     (void) Py_InitModule("my_module", myModule);
}
