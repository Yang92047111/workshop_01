#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include <vector>
#include <string>

void readPointsFromCsv(std::string file, Eigen::MatrixX2d &input_points) 
{
    std::ifstream in(file);
    std::string line;

    if (in.is_open()) {
        std::getline(in, line);
        while (std::getline(in, line)) {

            std::stringstream lineStream(line);
            std::string cell;
            std::vector<double> read_row;

            while(std::getline(lineStream, cell, ','))
            {
                read_row.push_back(std::stod(cell));
            }

            int pt_size = input_points.rows();
            input_points.conservativeResize(pt_size+1, 2);
            input_points.row(pt_size) << read_row[0], read_row[1];
        }
        in.close();
    }
}
