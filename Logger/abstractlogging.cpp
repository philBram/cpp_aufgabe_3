#include "abstractlogging.h"
#include <QString>

template <typename T>
AbstractLogging<T>::AbstractLogging(T &&initalMsg): initalMsg{initalMsg}
{
}

template class AbstractLogging<QString>;
template class AbstractLogging<std::string>;
