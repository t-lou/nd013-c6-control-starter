/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PID {
private:
   /**
   * TODO: Create the PID class
   **/

    /*
    * Errors
    */
    double curr_cte_{0.0};
    double last_cte_{0.0};
    double sum_cte_{0.0};

    /*
    * Coefficients
    */
    double param_p_{0.0};
    double param_i_{0.0};
    double param_d_{0.0};

    /*
    * Output limits
    */
    double max_{0.0};
    double min_{0.0};
  
    /*
    * Delta time
    */
    double dt_{0.0};

public:
    /*
    * Constructor
    */
    PID();

    /*
    * Destructor.
    */
    virtual ~PID();

    /*
    * Initialize PID.
    */
    void Init(double Kp, double Ki, double Kd, double output_lim_max, double output_lim_min);

    /*
    * Update the PID error variables given cross track error.
    */
    void UpdateError(double cte);

    /*
    * Calculate the total PID error.
    */
    double TotalError();
  
    /*
    * Update the delta time.
    */
    double UpdateDeltaTime(double new_delta_time);
};

#endif //PID_CONTROLLER_H


