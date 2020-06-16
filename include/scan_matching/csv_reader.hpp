#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include <vector>
#include <string>

void readPointsFromCsv(std::string file, Eigen::MatrixX3d &input_points) 
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
            input_points.conservativeResize(pt_size+1, 3);
            input_points.row(pt_size) << read_row[0], read_row[1], 1;
        }
        in.close();
    }
}

void writePointsToCsv(std::string file_name, Eigen::MatrixXd &points)
{
    std::ofstream srcdata;
    srcdata.open(file_name, std::ios::out);
    for (int i = 0; i < points.rows(); i++) {
        for (int j = 0; j < points.cols()-1; j++) {
            std::string str = std::to_string(points(i, j));
            if (j + 1 == points.cols()) {
                srcdata << str;
            }
            else {
                srcdata << str << ',';
            }
        }
        srcdata << '\n';
    }
    std::cout << "SAVE SUSS" << std::endl;
    srcdata.close();
}
