#pragma once 
#ifndef MX_RAIN_H
#define MX_RAIN_H

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <locale.h>

int mx_strlen(const char *s);
void mx_printerr(const char *str);

void mx_rain();
void mx_initcolor();

#endif

