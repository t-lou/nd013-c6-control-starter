/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini)
 {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
   param_p_ = Kpi;
   param_i_ = Kii;
   param_d_ = Kdi;
   max_ = output_lim_maxi;
   min_ = output_lim_mini;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
   sum_cte_ += cte * dt_;
   last_cte_ = curr_cte_;
   curr_cte_ = cte;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
   const double delta = dt_ < 1E-4 ? 0.0 : ((curr_cte_ - last_cte_) / dt_);
   const double control = -(param_p_ + param_i_ * sum_cte_ + param_d_ * delta);
   return std::max(std::min(control, max_), min_);
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
   dt_ =  = new_delta_time;
   return dt_;
}