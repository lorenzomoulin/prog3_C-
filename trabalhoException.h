//exceptionTrabalho

#ifndef EXCEPTIONTRABALHO_H_
#define EXCEPTIONTRABALHO_H_

#include <iostream>

using namespace std;

namespace trabalho{
class trabalhoException : exception {
    string e;
public:
    trabalhoException(string e);

    virtual ~trabalhoException() throw () {
    }

    virtual const char* what() const throw () {
        return (e).c_str();
    }
};
}
#endif