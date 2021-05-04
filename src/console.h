#pragma once

#ifndef CONSOLE_H
#define CONSOLE_H

#include <vector>
#include "tokens.h"
#include "references.h"
#include "value.h"

reference_apartment* print(std::vector<value*> arguments, garbage_collector* gc);
reference_apartment* print_line(std::vector<value*> arguments, garbage_collector* gc);
reference_apartment* get_input(std::vector<value*> arguments, garbage_collector* gc);

void handle_syntax_err(int syntax_error, unsigned int pos, const char* source);
void handle_runtime_err(int runtime_error, token* err_tok);

#endif // !IO_H