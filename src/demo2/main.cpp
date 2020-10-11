#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <cerrno>
#include <cstring>
#include "square.h"
#include <tspline.h>
#include <factory.h>
#include <tessellator.h>
#include <writer.h>
#include <splbase.h>


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


	CirclePtr demo = makePtr<Circle>();
	TSplinePtr spline = demo->findTSpline();
	std::string splinename = spline->getName();

	auto m=spline->getTImage();
	TLinkLoopPtr l;
	TNodVIterator n;
	std::cout<<m->sizeLinks()<<endl;
	for (auto i=m->faceIteratorBegin(); i!=m->faceIteratorEnd(); i++){
	  std::cout<<"face is:"<< (*i)->getName()<<endl;
		std::cout<<"long is: "<< (*i)->sizeBlendingNodes()<<endl;
	  l=(*i)->getLinkLoop();
	  for (auto j=l->linkIteratorBegin(); j!= l->linkIteratorEnd(); j++){
	    std::cout<<"\t"<<(*j)->getName()<<":"<<(*j)->getTEdge()->getName()<<" "<<(*j)->getTEdge()->getStartVertex()->getName()<<","<<(*j)->getTEdge()->getEndVertex()->getName()<<endl;
	  }
		for(auto j=(*i)->blendingNodeIteratorBegin(); j!= (*i)->blendingNodeIteratorEnd(); j++){
			std::cout<<"\t"<<(*j)->getName()<<endl;
		}
	}

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

	StlWriter stlwriter(dirname + "/" + splinename, trimesh);
	stlwriter.writeStlAcii();
	cout << "STL file: " << stlwriter.fileName() << " is written!" << endl;

	ObjWriter objwriter(dirname + "/" + splinename, 0);
	std::vector<std::string> faces;
	demo->findTFaceNames(faces);
	for (unsigned int i = 0; i<faces.size(); i++)
	{
		TriMeshPtr trimesh = tessellator.interpolateFace(faces[i]);
		objwriter.addMesh(trimesh);
		StlWriter stlwriter(dirname + "/" + splinename + "-" + faces[i], trimesh);
		stlwriter.writeStlBinary();
		cout << "STL file: " << stlwriter.fileName() << " is written!" << endl;
	}
	objwriter.writeObj();
	cout << "OBJ file: " << objwriter.fileName() << " is written!" << endl;

	DxfWriter dxfwriter(dirname + "/" + splinename, spline);
	dxfwriter.writeDxfTPointset();
	dxfwriter.writeDxfTConnect();
	dxfwriter.writeDxfTImage();
	cout << "DXF file: " << dxfwriter.fileName() << " is written!" << endl;

	StepWriter stepwriter(dirname + "/" + splinename, demo->findTGroup());
	stepwriter.writeStep();
	cout << "STEP file: " << stepwriter.fileName() << " is written!" << endl;

	return(0);
}

std::vector<std::string>& operator<<(std::vector<std::string> &container, const std::string &value)
{
	container.push_back(value);
	return container;
}
