#ifndef FUNCTION_H
#define FUNCTION_H

#include <memory>
#include <string>
#include <vector>

#include "expression.h"

class Function final {
    std::string identifier;
    std::vector<char> arguments;
    std::unique_ptr<Expression> expr;
public:
    Function(std::string &identifier, std::vector<char> &arguments, Expression &expr);
     &calculate(std::vector<> )
};

#endif //FUNCTION_H
