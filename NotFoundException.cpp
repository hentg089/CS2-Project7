//Mark Hentges 5814125

//
// Created by markh on 4/16/2023.
//

#include "NotFoundException.h"

NotFoundException::NotFoundException(const std::string &message) : std::logic_error(message){

}