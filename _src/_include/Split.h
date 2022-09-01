/* 
* split function from https ://www.javatpoint.com/how-to-split-strings-in-cpp 
*/
#pragma once
#include <iostream>
#include <string>

#define MAX 8 // define the max string
std::string strings[MAX];

 
int split(std::string str, char seperator, int return_location)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= str.length())
    {
        if (str[i] == seperator || i == str.length())
        {
            endIndex = i;
            std::string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
    return std::stoi(strings[return_location - 1]);
}

float split(bool return_float, std::string str, char seperator, int return_location)
{
    if (return_float) {
        int currIndex = 0, i = 0;
        int startIndex = 0, endIndex = 0;
        while (i <= str.length())
        {
            if (str[i] == seperator || i == str.length())
            {
                endIndex = i;
                std::string subStr = "";
                subStr.append(str, startIndex, endIndex - startIndex);
                strings[currIndex] = subStr;
                currIndex += 1;
                startIndex = endIndex + 1;
            }
            i++;
        }
        return std::stof(strings[return_location - 1]);
    }
    return 0.0;
}

std::string split(std::string str, char seperator, int return_location, bool return_string)
{
    if (return_string) {
        int currIndex = 0, i = 0;
        int startIndex = 0, endIndex = 0;
        std::string subStr;
        while (i <= str.length())
        {
            if (str[i] == seperator || i == str.length())
            {
                endIndex = i;
                subStr = "";
                subStr.append(str, startIndex, endIndex - startIndex);
                strings[currIndex] = subStr;
                currIndex += 1;
                startIndex = endIndex + 1;
            }
            i++;
        }
        std::string s = strings[return_location - 1];
        
        if (!s.empty() && s[s.length()-1] == '\n') {
            s.erase(s.length()-1);
}
        return s;
    }
    return "";
}