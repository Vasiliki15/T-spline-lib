#ifndef MESH_H
#define MESH_H

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
class Mesh
{
public:
	Mesh();
public:
	/** Create the mouse surface. */
	void createMesh();
	/** Finds the local knot vectors */
	void findLocalVecs();
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

private:
	std::shared_ptr<TFactory> _factory;
	std::shared_ptr<TExtractor> _textractor;
};

DECLARE_SMARTPTR(Mesh);

#endif
