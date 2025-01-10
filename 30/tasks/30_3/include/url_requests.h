#pragma once
#include <iostream>
#include <vector>
#include <cpr/cpr.h>


void UrlRequestGet(std::string& site, std::vector<cpr::Pair> &v);

void UrlRequestPost(std::string& site, std::vector<cpr::Pair> &v);


