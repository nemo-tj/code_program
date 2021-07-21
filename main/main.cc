#include <gflags/gflags.h>
#include <glog/logging.h>
#include <glog/stl_logging.h>

#include "work/worker.h"


using namespace nemo::leetcode;

int main(int argc, char* argv[]) {
  FLAGS_log_dir = "log"; 
  // Initialize Google's logging library.
  google::InitGoogleLogging(argv[0]);

  // Optional: parse command line flags
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  LOG(INFO) << "Hello, world!";

  Runner::GetInstance().run_link_list();
  Runner::GetInstance().run_bi_tree();

  Runner::GetInstance().run_func();
  /*
  Runner::GetInstance().run_sorter();
  */
  // Shutdown Google's logging library
  google::ShutdownGoogleLogging();

  return 0;
}
