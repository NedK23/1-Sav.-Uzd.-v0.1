#pragma once

#include "mylib.h"
#include <sstream>
#include <fstream>

void SkaitytiIsFailo(std::string failoVardas, std::list<Studentas>& grupe, std::chrono::duration<double>& SortingTime, std::chrono::duration<double>& FileEnterTime);
