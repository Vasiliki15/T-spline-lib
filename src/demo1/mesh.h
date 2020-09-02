#ifndef MESH_H
#define MESH_H

#include <factory.h>

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
private:
	std::shared_ptr<TFactory> _factory;
};

DECLARE_SMARTPTR(Mesh);

#endif
