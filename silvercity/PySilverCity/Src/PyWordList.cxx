// Copyright 2002 by Brian Quinlan <brian@sweetapp.com>
// The License.txt file describes the conditions under which this 
// software may be distributed.

#include <stdio.h>  // For NULL, for WordList.h
#include <ctype.h> // For ctypes..., for WordList.h
#include <assert.h>

#include "ILexer.h"
#include "Scintilla.h"
#include <SciLexer.h>
#include "WordList.h"
#include <LexAccessor.h>
#include <Accessor.h>

#include "PyWordList.h"

PyObject*
PyWordList_new(PyObject *, PyObject* args)
{
    PyWordList*     pyWordList;
    char*           wordStr = NULL;

    if (!PyArg_ParseTuple(args, "|s", &wordStr))
        return NULL;

    pyWordList = PyObject_New(PyWordList, &PyWordListType);
    if (wordStr) {
        pyWordList->wordListAsString = PyUnicode_FromString(wordStr);
        Py_INCREF(pyWordList->wordListAsString);
    } else {
        pyWordList->wordListAsString = NULL;
    }

    return (PyObject*) pyWordList;
}

static PyMethodDef PyWordList_methods[] = 
{
    { NULL, NULL }
};


static PyObject *
PyWordList_getattr(PyWordList *self, char *name)
{
    if (strcmp(name, "words") == 0)
        return self->wordListAsString;

    return PyObject_GenericGetAttr((PyObject*)self, PyUnicode_FromString(name));
}

static void
PyWordList_dealloc(PyWordList* self)
{
    Py_XDECREF(self->wordListAsString);
    PyObject_Del(self);
}


PyTypeObject PyWordListType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "WordList",
    sizeof(PyWordList),
    0,
    (destructor) PyWordList_dealloc,        /*tp_dealloc*/
    0,                                      /*tp_print*/
    (getattrfunc) PyWordList_getattr,       /*tp_getattr*/
    0,                                      /*tp_setattr*/
    0,                                      /*tp_compare*/
    0,                                      /*tp_repr*/
    0,                                      /*tp_as_number*/
    0,                                      /*tp_as_sequence*/
    0,                                      /*tp_as_mapping*/
    0,                                      /*tp_hash */
    0,                                      /*tp_call*/
    0,                                      /*tp_str */
    0,                                      /*tp_getattro*/
    0,                                      /*tp_setattro*/
    0,                                      /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,                     /*tp_flags*/
    0,                                      /*tp_doc*/
    0,                                      /*tp_traverse*/
    0,                                      /*tp_clear*/
    0,                                      /*tp_richcompare*/
    0,                                      /*tp_weaklistoffset*/
    0,                                      /*tp_iter*/
    0,                                      /*tp_iternext*/
    PyWordList_methods,                     /*tp_methods*/
};

void
initPyWordList(void)
{
    /* Initialize object types */
    if (PyType_Ready(&PyWordListType) < 0)
        return;
}
