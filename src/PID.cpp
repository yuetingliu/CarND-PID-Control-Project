#include "PID.h"

/**
 * Complete the PID class.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * Initialize PID coefficients (and errors, if needed)
   */
    this->Kp = Kp_;
    this->Ki = Ki_;
    this->Kd = Kd_;
    this->p_error = 0;
    this->i_error = 0;
}

void PID::UpdateError(double cte) {
  /**
   * Update PID errors based on cte.
   */
  this->i_error += cte;
  this->d_error = cte - this->p_error;
  this->p_error = cte;
}

double PID::TotalError() {
  /**
   * Calculate and return the total error
   */
  return -this->Kp*this->p_error - this->Ki*this->i_error - this->Kd*this->d_error;

}
