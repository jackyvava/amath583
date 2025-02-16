#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>  // For writing data to file

int main () {
  double pi = std::acos(-1.0);  // C++ does not mandate a value for pi

  std::vector<double> x(1024);  // Create two vectors
  std::vector<double> y(1024);

  // Fill in x with values from 0 to 4*pi (equally spaced)
  for (int i = 0; i < 1024; ++i) {
    x[i] = i * (4 * pi / 1024);
  }

  // Fill in y with sin of x
  for (int i = 0; i < 1024; ++i) {
    y[i] = std::sin(x[i]);
  }

  // Check that the last value of y has the right value
  if (std::abs(x[1023] - 4.0 * pi) < 1.0e-12) {
    std::cout << "Pass" << std::endl;
  } else {
    std::cout << "Fail" << " " << std::abs(x[1023] - 4.0 * pi) << std::endl;
  }

  // Write data to a file that gnuplot can read
  std::ofstream data_file("sin_data.txt");
  for (int i = 0; i < 1024; ++i) {
    data_file << x[i] << " " << y[i] << std::endl;
  }
  data_file.close();

  // Plot with gnuplot
  // Here, we are using a system call to call gnuplot directly
  system("gnuplot -e \"plot 'sin_data.txt' with lines title 'sin(x)'; pause -1\"");

  return 0;
}

