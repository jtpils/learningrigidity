/**
 * Copyright (C) 2018 NVIDIA Corporation.  All rights reserved.
 * Licensed under the CC BY-NC-SA 4.0 license 
 * (https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode).
 * 
 * Author: Zhaoyang Lv 
 */

#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>
#include <gtsam/geometry/Point3.h>
#include <gtsam/geometry/Pose3.h>
#include <gtsam/geometry/Cal3_S2.h>
#include <gtsam/linear/NoiseModel.h>
#include <gtsam/nonlinear/ExpressionFactorGraph.h>

#include <opencv2/core/core.hpp>

struct Putative {
  gtsam::Point3 pt1;
  gtsam::Point3 pt2;

  Putative(const gtsam::Point3 p1, const gtsam::Point3 p2)
  : pt1(p1), pt2(p2) {
  }
};

struct Flow2Pose {

enum {
  Gauss_Newton,
  Levenberg_Marquardt
};

double huber_threshold = 1;
double ransacConfidence =0.999;
double ransacIteration = 1000;
int solver_type = Gauss_Newton;

gtsam::SharedNoiseModel huber_measurement_model;
gtsam::SharedNoiseModel measurement_noise_model;

Flow2Pose();

/* Solve Camera pose */
gtsam::Pose3 solve(const std::vector<gtsam::Point3>& pts1,
  const std::vector<gtsam::Point3>& pts2, const gtsam::Pose3& initial_pose, const std::vector<bool>& inliers = std::vector<bool>());

gtsam::Pose3 calculate_transform(const cv::Mat& v_map0, const cv::Mat& v_map1,
const cv::Mat& flow, const cv::Mat& foreground_S0, const cv::Mat& foreground_S1, const cv::Mat& occlusion, const gtsam::Pose3& initial_pose);

};
