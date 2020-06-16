#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/Core>
#include <scan_matching/csv_reader.hpp>

int main(int argc, char const *argv[])
{
    Eigen::MatrixX3d input_points;
    readPointsFromCsv("../data/rectangle_points10.csv", input_points);

    std::cout << input_points << std::endl;

    double theta = 1.57;
    double tx = 2.0;
    double ty = 3.0;

    double cos_th = cos(theta);
    double sin_th = sin(theta);

    Eigen::MatrixX3d rot(3, 3);
    rot << cos_th, -sin_th, tx,
           sin_th, cos_th,  ty,
           0,      0,        1;

    std::cout << rot << std::endl;

    Eigen::MatrixXd rot_points = (rot * input_points.transpose());
    std::cout << rot_points << std::endl;

    Eigen::MatrixXd Result = rot_points.transpose();
    std::cout << Result << std::endl;

    writePointsToCsv("../data/rectangle_points10_retated.csv", Result);
    return 0;
}