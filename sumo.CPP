float myVariable;

bool Target;

// "when started" hat block
int whenStarted1() {
  Color6.setLight(100, percent);
  Target = false;
  RightMotor.setMaxTorque(90.0, percent);
  LeftMotor.setMaxTorque(90.0, percent);
  while (true) {
    while ((!Target)) {
      if (Distance1.distance(mm) < 300.0) {
        Target = true;
      }
      else {
        LeftMotor.setVelocity(-100.0, percent);
        RightMotor.setVelocity(100.0, percent);
        RightMotor.spin(forward);
        LeftMotor.spin(forward);
      }
    wait(20, msec);
    }
    while (Target) {
      if (static_cast<float>(Color6.brightness()) < 25.0) {
        LeftMotor.setVelocity(90.0, percent);
        RightMotor.setVelocity(90.0, percent);
        RightMotor.spin(forward);
        LeftMotor.spin(forward);
      } else if (static_cast<float>(Color6.brightness()) > 24.9) {
        LeftMotor.setVelocity(-100.0, percent);
        RightMotor.setVelocity(-30.0, percent);
        RightMotor.spin(forward);
        LeftMotor.spin(forward);
        wait(2.0, seconds);
        LeftMotor.setVelocity(100.0, percent);
        RightMotor.setVelocity(100.0, percent);
        RightMotor.spin(forward);
        LeftMotor.spin(forward);
        wait(0.5, seconds);
        Target = false;
      } else {
      }
    wait(20, msec);
    }
  wait(20, msec);
  }
  return 0;
}


int main() {
  whenStarted1();
}
