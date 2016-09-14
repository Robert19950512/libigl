#include <igl/avg_edge_length.h>
#include <igl/barycenter.h>
#include <igl/jet.h>
#include <igl/local_basis.h>
#include <igl/n_polyvector.h>
#include <igl/readDMAT.h>
#include <igl/readOBJ.h>
#include <igl/viewer/Viewer.h>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "tutorial_shared_path.h"

// Input mesh
Eigen::MatrixXd V;
Eigen::MatrixXi F;

// Per face bases
Eigen::MatrixXd B1,B2,B3;






  

int main(int argc, char *argv[])
{
	using namespace Eigen;
	using namespace std;
	VectorXi b(2);
	b << 1,3;

	MatrixXd bc(b.size(), 3);
	
  
  // Load a mesh in OBJ format
  igl::readOBJ(TUTORIAL_SHARED_PATH "/test2.obj", V, F);
  igl::local_basis(V, F, B1, B2, B3);
 // for (unsigned i = 0; i<b.size(); ++i)
  //{
	  bc.row(0) << 1, 2, 0;
	  bc.row(1) << 1, 3, 0;
 // }
  Eigen::MatrixXd pvf;
  igl::n_polyvector(V, F, b, bc, pvf);
  std::cout << pvf << std::endl;
  system("PAUSE");
 

  
}
