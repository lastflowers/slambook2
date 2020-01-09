#include <iostream>
#include <chrono>

using namespace std;


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char **argv) {
  // Read the image specified by argv [1]
  cv::Mat image;
   image = cv::imread(argv[1]); //cv:: imread function reads the image in the specified path
  //image = cv::imread("/home/nesl/JJH/slambook2/ch5/imageBasics/ubuntu.png");
  // Determine if the image file is read correctly
  cout << argv[1] << endl;
  if (image.data == nullptr) { // The data does not exist, it may be that the file does not exist
    cerr << "file" << argv[1] << "does not exist." << endl;
    return 0;
  }

  // The file is successfully read, first output some basic information
  cout << "width" << image.cols << ", height" << image.rows << ",# of channels" << image.channels() << endl;
  cv::imshow("image", image);      // Display image with cv :: imshow
  cv::waitKey(0);                  // Pause the program and wait for a key input

  // Determine the type of image
  if (image.type() != CV_8UC1 && image.type() != CV_8UC3) {
    // Image type does not meet requirements
    cout << "Please enter a color or grayscale image." << endl;
    return 0;
  }

  // Traverse the image, please note that the following traversal methods can also be used for random pixel access
  // Use std :: chrono to time the algorithm
  chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
  for (size_t y = 0; y < image.rows; y++) {
    // Get line pointer of image with cv :: Mat :: ptr
    unsigned char *row_ptr = image.ptr<unsigned char>(y);  // row_ptr is the head pointer of the y-th row
    for (size_t x = 0; x < image.cols; x++) {
      // Access the pixel at x, y
      unsigned char *data_ptr = &row_ptr[x * image.channels()]; // data_ptr points to the pixel data to be accessed
      // Output each channel of the pixel, if it is a grayscale image, there is only one channel
      for (int c = 0; c != image.channels(); c++) {
        unsigned char data = data_ptr[c]; // data is the value of the c-th channel of I (x, y)
      }
    }
  }
  chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
  chrono::duration<double> time_used = chrono::duration_cast < chrono::duration < double >> (t2 - t1);
  cout << "Time to traverse the image:" << time_used.count() << " sec" << endl;

  // About copy of cv :: Mat
  // Direct assignment does not copy data
  cv::Mat image_another = image;
  // Modifying image_another will cause the image to change
  image_another(cv::Rect(0, 0, 100, 100)).setTo(0); // Zero the 100 * 100 block in the upper left corner
  cv::imshow("image", image);
  cv::waitKey(0);

  // Use clone function to copy data
  cv::Mat image_clone = image.clone();
  image_clone(cv::Rect(0, 0, 100, 100)).setTo(255);
  cv::imshow("image", image);
  cv::imshow("image_clone", image_clone);
  cv::waitKey(0);

  // There are many basic operations for images, such as cropping, rotating, scaling, etc., 
  // which are not introduced one by one due to space, please refer to the OpenCV official 
  // document to query the calling method of each function.
  cv::destroyAllWindows();
  return 0;
}
