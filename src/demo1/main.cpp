#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <cerrno>
#include <cstring>
#include "mesh.h"
#include <tspline.h>
#include <factory.h>
#include <tessellator.h>
#include <writer.h>


#ifdef use_namespace
using namespace TSPLINE;
#endif

int main(void)
{
	cout << "=====================================================\n";
	cout << " TSPLINE -- A T-spline object oriented package in C++ \n";
	cout << " DEMO program \n";
	cout << "=====================================================\n";
	cout << "\n";


	MeshPtr demo = makePtr<Mesh>();
	TSplinePtr spline = demo->findTSpline();
	std::string splinename = spline->getName();

	TTessellator tessellator(spline);
	tessellator.setResolution(0.1);

	TriMeshPtr trimesh = tessellator.interpolateAll();

	std::string dirname = "../export/" + splinename;

#ifdef _WIN32
	_mkdir(dirname.c_str());
#elif __linux__
	int dir_err=mkdir("./export", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	dirname = "./export/" + splinename;
	dir_err = mkdir(dirname.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	cout<< dirname<<endl;
	if  (dir_err==-1){
		cout << " mkdir: " << strerror(errno) << '\n';
	}
#elif defined __APPLE__
	dirname = "./export/" + splinename;
	mkdir(dirname.c_str(), 0744);
#endif

	GnuplotWriter gplwriter(dirname + "/" + splinename, trimesh, spline);
	gplwriter.writeGnuplMesh();
	gplwriter.writeGnuplTImage();
	gplwriter.writeGnuplTConnect();
	gplwriter.writeGnuplTPointset();
	cout << "GNUpl files: " << gplwriter.fileName() << " is written!" << endl;

	return(0);
}

std::vector<std::string>& operator<<(std::vector<std::string> &container, const std::string &value)
{
	container.push_back(value);
	return container;
}
