//Mark Hentges 5814125

//
// Created by markh on 4/16/2023.
//

#ifndef PROJECT7_NOTFOUNDEXCEPTION_H
#define PROJECT7_NOTFOUNDEXCEPTION_H

#include <stdexcept>
#include <string>

class NotFoundException : public std::logic_error{
public:
    /**constructs the exception message
     * @param message that we print
     */
    explicit NotFoundException(const std::string& message = "");

    virtual ~NotFoundException() noexcept = default;
};


#endif //PROJECT7_NOTFOUNDEXCEPTION_H
