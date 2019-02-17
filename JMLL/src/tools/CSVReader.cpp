#include <fstream>

#include "CSVReader.hpp"
#include "Matrix.hpp"

using namespace std;

token1d readRow(string &row)
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

token2d readCSV(ifstream &in)
{
    token2d table;
    string row;
    
    while (!in.eof())
    {
        getline(in, row);
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
        
        for (string num : line)
        {
            mat[i].push_back(stoi(num));
        }
        
        i++;
    }
    
    return mat;
}
