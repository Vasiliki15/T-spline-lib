#ifndef SQUARE_H
#define SQUARE_H

#include <factory.h>
#include <cross.h>
#include <multiplicity.h>
#include <tspline.h>
#include <extractor.h>

#ifdef use_namespace
using namespace TSPLINE;
#endif

/**
  *  @class  <Mesh>
  *  @brief Mesh class
  *  @note
  *  The MouseDemo creates a surface using T-spline.
*/
class Circle
{
public:
	Circle();
public:
	/** Create the mouse surface. */
	void createMesh();
	/** Finds the local knot vectors */
	void findLocalVecs();
	/*Calls a series of functions to insert a new node */
	void addNode();
	/*Computes the T matrix needed for the new contro point*/
	Real** computeTMatrix(Real s_new,int np, std::vector<Real> &u_knot);
	/*Creates a new node*/
	void createNewNode(const Real s_new,const Real tau_new,unsigned int* index);
	/** Cpmputes the new control points **/
	void computeNewControlPoint();
	/** Inserts a new node given by the user in parametric space*/
	void insertNewNode(unsigned int index);
	/** Find the T-spline object. */
	TSplinePtr findTSpline();
	/** Find the T-group object. */
	TGroupPtr findTGroup();
	/** Find all the T-face names. */
	void findTFaceNames(std::vector<std::string> &faces);
protected:
	void createTSpline();
	void createTImage();
	void createTConnect();
	void createTPointset();
	void createTVertices();
	void createTEdges();
	void createTLinks();
	void createTEdgeConditions();
	void createTFaces();
	void createTNodes();
	void createTPoints();

	void patchTSpline();
	void patchTImage();
	void patchTConnect();
	void patchTPointset();
	void patchTVertices();
	void patchTEdges();
	void patchTLinks();
	void patchTEdgeConditions();
	void patchTFaces();
	void patchTNodes();
	void patchTPoints();

	void prepareTObjects();

	void extractUVKnotsFromTNodeV4();


	void getS();
	void getT();
	void setST();

private:
	std::shared_ptr<TFactory> _factory;
	std::shared_ptr<TExtractor> _textractor;
	std::shared_ptr<TVertex> _tvertex;
};

DECLARE_SMARTPTR(Circle);

#endif
