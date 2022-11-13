/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2021-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** sep_imple.cxx : implementation file for explicitly instantiated template classes
 ****
 ****************************************************************/

#include "sep_head.h"

template< typename T >
void sep<T>::f() {}
template class sep<int>;
template class sep<double>;
template class sep<char>;
