#include "test_link.h"
#include "test_btree.h"
#include "test_alg.h"
#include "test_jump.h"
#include "test_pq.h"

#include "sorter.h"
#include "perm.h"
#include "util.h"
#include "node.h"

#include <glog/logging.h>

using namespace nemo;

void test_perm() {
  std::string str = "cbcb";
  perm(str);
}

int main(int argc, char *argv[])
{	
	FLAGS_log_dir = "/home/nemo/project/service/code_program/log/";
	// initialize google's logging library
	google::InitGoogleLogging(argv[0]);
  // test_perm();
  // test_struct();
 	// test_link();
  test_alg();
  // test_jump();
  // test_pq();
	LOG(INFO) << "test main " << "is ok";
  return 0;
}
