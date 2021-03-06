#ifndef ABSTRACTLOGGING_H
#define ABSTRACTLOGGING_H

template <typename T>
class AbstractLogging
{
protected:
    T initalMsg;
    T filePath;

    virtual void logOut(T &&) const = 0;
    virtual void logOut(T &&, T &&) const = 0;
    virtual T logOut() const = 0;

public:
    explicit AbstractLogging(T &&, T &&);
    virtual ~AbstractLogging() = default;
};

#endif // ABSTRACTLOGGING_H
