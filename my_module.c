#include <Python.h>

static PyObject* count_custom(PyObject* self, PyObject* args)
{
    long long int value, i;

    /*  parse the input, from python integer to c long long int */
    if (!PyArg_ParseTuple(args, "L", &value))
        return NULL;
    /* if the above function returns -1, an appropriate Python exception will
     * have been set, and the function simply returns NULL
     */

    Py_BEGIN_ALLOW_THREADS
//    sleep(1);
    for (i = 0; i < value; ++i) {
    }
    Py_END_ALLOW_THREADS

    return Py_BuildValue("i", 1);
}

/*  define functions in module */
static PyMethodDef myModule[] =
{
     {"count_custom", count_custom, METH_VARARGS, "evaluate the count"}
};

/* module initialization */
PyMODINIT_FUNC initmy_module(void)
{
     (void) Py_InitModule("my_module", myModule);
}
