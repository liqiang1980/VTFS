#pragma once

#include <iostream>
#include <deque>
#include <time.h> //for program running test(cpu consuming time)
#include <sys/time.h>//for program running test(realtime consuming test)
#include <Eigen/Dense>
#include <kdl/frames.hpp>
#include <utility>
#include <fstream>      // std::ifstream
#include <unsupported/Eigen/MatrixFunctions>   //the computation of matrix exponential, be careful, all related function can be updated in future

extern Eigen::Vector3d euler2axisangle(Eigen::Vector3d la,Eigen::Matrix3d tm);
extern Eigen::Vector3d g_euler2axisangle(Eigen::Vector3d la,Eigen::Matrix3d tm);
extern Eigen::Vector3d tm2axisangle(Eigen::Matrix3d tm);
extern std::pair<Eigen::Vector3d,double>  tm2axisangle_4(Eigen::Matrix3d,bool&);
extern Eigen::Matrix3d g_euler2tm(Eigen::Vector3d la,Eigen::Matrix3d tm);
extern Eigen::Matrix3d euler2tm(Eigen::Vector3d la,Eigen::Matrix3d tm);
extern double _smooth_filter(std::deque<double> t);
extern Eigen::Matrix3d GetSkrewFromVector(Eigen::Vector3d vec);
extern long long timeval_diff(struct timeval *difference, struct timeval *end_time, struct timeval *start_time);
extern Eigen::Matrix3d AlignVec(Eigen::Vector3d cur, Eigen::Vector3d des);
extern Eigen::Vector3d kdl2eigen_position(const KDL::Frame& f);
extern Eigen::Matrix3d kdl2eigen_orien(const KDL::Frame& f);
extern void global2local(Eigen::Vector3d g, Eigen::Matrix3d M, Eigen::Vector3d &l);
extern void local2global(Eigen::Vector3d l, Eigen::Matrix3d M, Eigen::Vector3d &g);
extern std::pair<Eigen::Vector3d,double> omega_transform(std::pair<Eigen::Vector3d,Eigen::Vector3d>,Eigen::Matrix3d);
extern void gen_hm(Eigen::Matrix3d m,Eigen::Vector3d v,Eigen::MatrixXd& hm);
extern Eigen::Vector3d skewtovector(Eigen::Matrix3d m);
extern Eigen::Matrix3d vectortoskew(Eigen::Vector3d v);
extern bool is_file_exist(const char *fileName);
extern Eigen::MatrixXd readMatrix(std::fstream &infile);
//this function will generate a transform matrix to compute the current homogeneous matrix
//from the previous HM given by the rotation direction, linear velocity
//always in one reference frame
extern Eigen::Matrix4d gen_transform(Eigen::Vector3d omega, Eigen::Vector3d vel, double theta);
//generate orthogonal basis from one vector
extern Eigen::Matrix3d gen_ort_basis(Eigen::Vector3d v);
extern double dis_2_vec(double x1,double y1,double x2,double y2);

//extern Eigen::VectorXd MatrixtoQuaternion(Eigen::Matrix3d);
