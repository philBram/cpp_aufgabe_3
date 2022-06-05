#include "abstractlogging.h"
#include <QString>

template <typename T>
AbstractLogging<T>::AbstractLogging(T &&initalMsg, T &&filePath):
    initalMsg{initalMsg}, filePath{filePath}
{
}

template class AbstractLogging<QString>;
template class AbstractLogging<std::string>;
