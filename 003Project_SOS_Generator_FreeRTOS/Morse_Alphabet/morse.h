/*
 * morse.h
 *
 *  Created on: Aug 9, 2024
 *      Author: ILKER KESER
 */

#ifndef MORSE_H_
#define MORSE_H_


#include <stdbool.h>

void char_to_morse(char letter, char* result);
void string_to_morse(char* string, char* result);
char morse_to_char(const char* morse);
void morse_to_string(const char* morse, char* result);


#endif /* MORSE_H_ */
