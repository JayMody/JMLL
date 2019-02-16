#include <fstream>

#include "CSVReader.hpp"
#include "Matrix.hpp"

token1d readRow(std::string &row)
{
    token1d fields = {""};
    int i = 0;
    
    for (char c : row)
    {
        if (c == ',')
        {
            fields.push_back("");
            i++;
        }
        else
        {
            fields[i].push_back(c);
        }
    }
    
    return fields;
}


#include <iostream>

token2d readCSV(std::ifstream &in)
{
    token2d table;
    std::string row;
    
    while (!in.eof())
    {
        std::getline(in, row);
        if (!in.good())
        {
            break;
        }
        token1d fields = readRow(row);
        table.push_back(fields);
    }
    
    return table;
}

vec2d convert_to_double(token2d text)
{
    vec2d mat;
    
    int i = 0;
    for (token1d line : text)
    {
        mat.push_back({});
        
        for (std::string num : line)
        {
            mat[i].push_back(std::stoi(num));
        }
        
        i++;
    }
    
    return mat;
}
