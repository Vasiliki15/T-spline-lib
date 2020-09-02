/*!
  @file demo.cpp
  @brief A demo file.

  Demos for T-spline, etc.
*/

#include "mesh.h"

#ifdef use_namespace
using namespace TSPLINE;
#endif

extern std::vector<std::string>& operator<<(std::vector<std::string> &container, const std::string &value);

Mesh::Mesh()
{
	_factory = makePtr<TFactory>();
	createMesh();
}

void Mesh::createMesh()
{
	createTSpline();
	createTImage();
	createTConnect();
	createTPointset();
	createTVertices();
	createTEdges();
 	createTLinks();
	createTEdgeConditions();
	createTFaces();
	createTNodes();
	createTPoints();

	patchTSpline();
	patchTImage();
	patchTConnect();
	patchTPointset();
	patchTEdges();
	patchTLinks();
	patchTEdgeConditions();
	patchTFaces();
	patchTVertices();
	patchTNodes();
	patchTPoints();

	prepareTObjects();
}

void Mesh::createTSpline()
{
	_factory->createTSpline("mesh");
}

void Mesh::createTImage()
{
	_factory->createTImage("image");
}

void Mesh::createTConnect()
{
	_factory->createTConnect("nodes");
}

void Mesh::createTPointset()
{
	_factory->createTPointset("points");
}

void Mesh::createTVertices()
{
	_factory->createTVertex("v0", 0.0, 0.0); // v
	_factory->createTVertex("v1", 0.2, 0.0); // v
	_factory->createTVertex("v2", 0.4, 0.0); // v
	_factory->createTVertex("v3", 0.6, 0); // v
	_factory->createTVertex("v4", 1.0, 0.0); // v
	_factory->createTVertex("v5", 0.2, 0.2); // v
	_factory->createTVertex("v6", 0.4, 0.2); // v
	_factory->createTVertex("v7", 0.6, 0.2); // v
	_factory->createTVertex("v8", 0.7, 0.2); // v
	_factory->createTVertex("v9", 1.0, 0.2); // v
	_factory->createTVertex("v10", 0.2, 0.5); // v
	_factory->createTVertex("v11", 0.4, 0.5); // v
	_factory->createTVertex("v12", 0.5, 0.5); // v
	_factory->createTVertex("v13", 0.7, 0.5); // v
	_factory->createTVertex("v14", 1.0, 0.5); // v
	_factory->createTVertex("v15", 0.0, 0.65); // v
	_factory->createTVertex("v16", 0.2, 0.65); // v
	_factory->createTVertex("v17", 0.5, 0.7); // v
	_factory->createTVertex("v18", 1.0, 0.7); // v
	_factory->createTVertex("v19", 0.2, 0.8); // v
	_factory->createTVertex("v20", 0.5, 0.8); // v
	_factory->createTVertex("v21", 0.0, 1.0); // v
	_factory->createTVertex("v22", 0.2, 1.0); // v
	_factory->createTVertex("v23", 0.5, 1.0); // v
	_factory->createTVertex("v24", 1.0, 1.0); // v
}

void Mesh::createTEdges() // v
{
	_factory->createTEdge("e0");
	_factory->createTEdge("e1");
	_factory->createTEdge("e2");
	_factory->createTEdge("e3");
	_factory->createTEdge("e4");
	_factory->createTEdge("e5");
	_factory->createTEdge("e6");
	_factory->createTEdge("e7");
	_factory->createTEdge("e8");
	_factory->createTEdge("e9");
	_factory->createTEdge("e10");
  _factory->createTEdge("e11");
	_factory->createTEdge("e12");
	_factory->createTEdge("e13");
	_factory->createTEdge("e14");
	_factory->createTEdge("e15");
  _factory->createTEdge("e16");
	_factory->createTEdge("e17");
	_factory->createTEdge("e18");
	_factory->createTEdge("e19");
	_factory->createTEdge("e20");
	_factory->createTEdge("e21");
	_factory->createTEdge("e22");
	_factory->createTEdge("e23");
	_factory->createTEdge("e24");
	_factory->createTEdge("e25");
	_factory->createTEdge("e26");
	_factory->createTEdge("e27");
  _factory->createTEdge("e28");
	_factory->createTEdge("e29");
	_factory->createTEdge("e30");
	_factory->createTEdge("e31");
	_factory->createTEdge("e32");
	_factory->createTEdge("e33");
	_factory->createTEdge("e34");
	_factory->createTEdge("e35");
}

void Mesh::createTLinks() // v
{
	_factory->createTLink("l0");
	_factory->createTLink("l2");
	_factory->createTLink("l3");
	_factory->createTLink("l1");
	_factory->createTLink("l4");
	_factory->createTLink("l5");
	_factory->createTLink("l6");
	_factory->createTLink("l7");
	_factory->createTLink("l8");
	_factory->createTLink("l9");
  _factory->createTLink("l10");
	_factory->createTLink("l11");
	_factory->createTLink("l12");
	_factory->createTLink("l13");
	_factory->createTLink("l14");
	_factory->createTLink("l15");
	_factory->createTLink("l16");
	_factory->createTLink("l17");
	_factory->createTLink("l18");
	_factory->createTLink("l19");
	_factory->createTLink("l20");
	_factory->createTLink("l21");
  _factory->createTLink("l22");
	_factory->createTLink("l23");
	_factory->createTLink("l24");
	_factory->createTLink("l25");
	_factory->createTLink("l26");
	_factory->createTLink("l27");
	_factory->createTLink("l28");
	_factory->createTLink("l29");
	_factory->createTLink("l30");
	_factory->createTLink("l31");
  _factory->createTLink("l32");
  _factory->createTLink("l33");
	_factory->createTLink("l34");
	_factory->createTLink("l35");
	_factory->createTLink("l36");
	_factory->createTLink("l37");
	_factory->createTLink("l38");
	_factory->createTLink("l39");
	_factory->createTLink("l40");
	_factory->createTLink("l41");
	_factory->createTLink("l42");
	_factory->createTLink("l43");
  _factory->createTLink("l44");
	_factory->createTLink("l45");
	_factory->createTLink("l46");
	_factory->createTLink("l47");
	_factory->createTLink("l48");
	_factory->createTLink("l49");
	_factory->createTLink("l50");
	_factory->createTLink("l51");
	_factory->createTLink("l52");
	_factory->createTLink("l53");
	_factory->createTLink("l54");
	_factory->createTLink("l55");
	_factory->createTLink("l56");
	_factory->createTLink("l57");
  _factory->createTLink("l58");
  _factory->createTLink("l59");
	_factory->createTLink("l60");
	_factory->createTLink("l61");
	_factory->createTLink("l62");
	_factory->createTLink("l63");
	_factory->createTLink("l64");
	_factory->createTLink("l65");
	_factory->createTLink("l66");
	_factory->createTLink("l67");
	_factory->createTLink("l68");
	_factory->createTLink("l69");
	_factory->createTLink("l70");
	_factory->createTLink("l71");
}

void Mesh::createTEdgeConditions() // v
{
	_factory->createTEdgeCondition("ec0");
	_factory->createTEdgeCondition("ec1");
	_factory->createTEdgeCondition("ec2");
	_factory->createTEdgeCondition("ec3");
	_factory->createTEdgeCondition("ec4");
	_factory->createTEdgeCondition("ec5");
	_factory->createTEdgeCondition("ec6");
	_factory->createTEdgeCondition("ec7");
	_factory->createTEdgeCondition("ec8");
	_factory->createTEdgeCondition("ec9");
	_factory->createTEdgeCondition("ec10");
	_factory->createTEdgeCondition("ec11");
	_factory->createTEdgeCondition("ec12");
}

void Mesh::createTFaces() // v
{
	_factory->createTFace("f0");
	_factory->createTFace("f1");
	_factory->createTFace("f2");
	_factory->createTFace("f3");
	_factory->createTFace("f4");
	_factory->createTFace("f5");
	_factory->createTFace("f6");
	_factory->createTFace("f7");
	_factory->createTFace("f8");
	_factory->createTFace("f9");
	_factory->createTFace("f10");
	_factory->createTFace("f11");
}

void Mesh::createTNodes() // v
{
	_factory->createTNodeV4("n0"); // v
	_factory->createTNodeV4("n1"); // v
	_factory->createTNodeV4("n2"); // v
	_factory->createTNodeV4("n3"); // v
	_factory->createTNodeV4("n4"); // v
	_factory->createTNodeV4("n5"); // v
	_factory->createTNodeV4("n6"); // v
	_factory->createTNodeV4("n7"); // v
	_factory->createTNodeV4("n8"); // v
	_factory->createTNodeV4("n9"); // v
	_factory->createTNodeV4("n10"); // v
  _factory->createTNodeV4("n11"); // v
	_factory->createTNodeV4("n12"); // v
	_factory->createTNodeV4("n13"); // v
	_factory->createTNodeV4("n14"); // v
	_factory->createTNodeV4("n15"); // v
	_factory->createTNodeV4("n16"); // v
	_factory->createTNodeV4("n17"); // v
	_factory->createTNodeV4("n18"); // v
	_factory->createTNodeV4("n19"); // v
	_factory->createTNodeV4("n20"); // v
	_factory->createTNodeV4("n21"); // v
	_factory->createTNodeV4("n22"); // v
	_factory->createTNodeV4("n23"); // v
  _factory->createTNodeV4("n24"); // v
}

void Mesh::createTPoints()
{
	_factory->createTPoint("p0", 0.0, 0.0, 1.0, 1.0); // v
	_factory->createTPoint("p1", 0.2, 0.0, 1.3, 1.0); // v
	_factory->createTPoint("p2", 0.4, 0.0, 1.6, 1.0); // v
	_factory->createTPoint("p3", 0.6, 0.0, 1.1, 1.0); // v
	_factory->createTPoint("p4", 1.0, 0.0, 1.0, 1.0); // v
	_factory->createTPoint("p5", 0.2, 0.2, 1.2, 1.0); // v
	_factory->createTPoint("p6", 0.4, 0.2, 1.2, 1.0); // v
	_factory->createTPoint("p7", 0.6, 0.2, 1.5, 1.0); // v
	_factory->createTPoint("p8", 0.7, 0.2, 1.1, 1.0); // v
	_factory->createTPoint("p9", 1.0, 0.2, 1.3, 1.0); // v
	_factory->createTPoint("p10", 0.2, 0.5, 1.2, 1.0); // v
  _factory->createTPoint("p11", 0.4, 0.5, 1.3, 1.0); // v
	_factory->createTPoint("p12", 0.5, 0.5, 1.5, 1.0); // v
	_factory->createTPoint("p13", 0.7, 0.5, 1.5, 1.0); // v
	_factory->createTPoint("p14", 1, 0.5, 1.1, 1.0); // v
	_factory->createTPoint("p15", 0, 0.65, 1.5, 1.0); // v
	_factory->createTPoint("p16", 0.2, 0.65, 1.5, 1.0); // v
	_factory->createTPoint("p17", 0.5, 0.7, 1.3, 1.0); // v
	_factory->createTPoint("p18",  1.0, 0.7, 1.1, 1.0); // v
	_factory->createTPoint("p19", 0.2, 0.8, 1.3, 1.0); // v
	_factory->createTPoint("p20", 0.5, 0.8, 1.1, 1.0); // v
	_factory->createTPoint("p21", 0.0, 1.0, 1.5, 1.0); // v
	_factory->createTPoint("p22", 0.2, 1.0, 1.6, 1.0); // v
	_factory->createTPoint("p23", 0.5, 1.0, 1.2, 1.0); // v
  _factory->createTPoint("p24", 1.0, 1.0, 1.1, 1.0); // v
}

void Mesh::patchTVertices()
{
	_factory->patchTVertexByVertices("v0", "v15", "", "", "v1"); // v
	_factory->patchTVertexByVertices("v1", "v5", "v0", "", "v2"); // v
	_factory->patchTVertexByVertices("v2", "v6", "v1", "", "v3"); // v
	_factory->patchTVertexByVertices("v3", "v7", "v2", "", "v4"); // v
	_factory->patchTVertexByVertices("v4", "v9", "v3", "", ""); // v
	_factory->patchTVertexByVertices("v5", "v10", "", "v1", "v6"); // v
	_factory->patchTVertexByVertices("v6", "v11", "v5", "v2", "v7"); // v
	_factory->patchTVertexByVertices("v7", "", "v6", "v3", "v8"); // v
	_factory->patchTVertexByVertices("v8", "v13", "v7", "", "v9"); // v
	_factory->patchTVertexByVertices("v9", "v14", "v8", "v4", ""); // v
	_factory->patchTVertexByVertices("v10", "v16", "", "v5", "v11"); // v
	_factory->patchTVertexByVertices("v11", "", "v10", "v6", "v12"); // v
	_factory->patchTVertexByVertices("v12", "v17", "v11", "", "v13"); // v
	_factory->patchTVertexByVertices("v13", "", "v12", "v8", "v14"); // v
	_factory->patchTVertexByVertices("v14", "v18", "v13", "v9", ""); // v
	_factory->patchTVertexByVertices("v15", "v21", "", "v0", "v16"); // v
	_factory->patchTVertexByVertices("v16", "v19", "v15", "v10", ""); // v
	_factory->patchTVertexByVertices("v17", "v20", "", "v12", "v18"); // v
	_factory->patchTVertexByVertices("v18", "v24", "v17", "v14", ""); // v
	_factory->patchTVertexByVertices("v19", "v22", "", "v16", "v20"); // v
	_factory->patchTVertexByVertices("v20", "v23", "v19", "v17", ""); // v
	_factory->patchTVertexByVertices("v21", "", "", "v15", "v22"); // v
	_factory->patchTVertexByVertices("v22", "", "v21", "v19", "v23"); // v
	_factory->patchTVertexByVertices("v23", "", "v22", "v20", "v24"); // v
	_factory->patchTVertexByVertices("v24", "", "v23", "v18", ""); // v
}

void Mesh::patchTEdges()
{
	_factory->patchTEdge("e0", "v0", "v1", "f0", ""); // v
	_factory->patchTEdge("e1", "v1", "v2", "f1", ""); // v
	_factory->patchTEdge("e2", "v2", "v3", "f2", ""); // v
	_factory->patchTEdge("e3", "v3", "v4", "f3", ""); // v
	_factory->patchTEdge("e4", "v9", "v4", "", "f3"); // v
	_factory->patchTEdge("e5", "v14", "v9", "", "f6"); // v
	_factory->patchTEdge("e6", "v18", "v14", "", "f8"); // v
	_factory->patchTEdge("e7", "v24", "v18", "", "f11"); // v
	_factory->patchTEdge("e8", "v23", "v24", "", "f11"); // v
	_factory->patchTEdge("e9", "v22", "v23", "", "f10"); // v
	_factory->patchTEdge("e10", "v21", "v22", "", "f9"); // v
	_factory->patchTEdge("e11", "v21", "v15", "f9", ""); // v
	_factory->patchTEdge("e12", "v15", "v0", "f0", ""); // v
	_factory->patchTEdge("e13", "v5", "v6", "f4", "f1"); // v
	_factory->patchTEdge("e14", "v6", "v7", "f5", "f2"); // v
	_factory->patchTEdge("e15", "v8", "v9", "f6", "f3"); // v
	_factory->patchTEdge("e16", "v10", "v11", "f7", "f4"); // v
	_factory->patchTEdge("e17", "v11", "v12", "f7", "f5"); // v
	_factory->patchTEdge("e18", "v12", "v13", "f8", "f5"); // v
	_factory->patchTEdge("e19", "v13", "v14", "f8", "f6"); // v
	_factory->patchTEdge("e20", "v15", "v16", "f9", "f0"); // v
	_factory->patchTEdge("e21", "v17", "v18", "f11", "f8"); // v
	_factory->patchTEdge("e22", "v19", "v20", "f10", "f7"); // v
	_factory->patchTEdge("e23", "v5", "v1", "f1", "f0"); // v
	_factory->patchTEdge("e24", "v6", "v2", "f2", "f1"); // v
	_factory->patchTEdge("e25", "v7", "v3", "f3", "f2"); // v
	_factory->patchTEdge("e26", "v10", "v5", "f4", "f0"); // v
	_factory->patchTEdge("e27", "v11", "v6", "f5", "f4"); // v
	_factory->patchTEdge("e28", "v13", "v8", "f6", "f5"); // v
	_factory->patchTEdge("e29", "v16", "v10", "f7", "f0"); // v
	_factory->patchTEdge("e30", "v17", "v12", "f8", "f7"); // v
	_factory->patchTEdge("e31", "v19", "v16", "f7", "f9"); // v
	_factory->patchTEdge("e32", "v20", "v17", "f11", "f7"); // v
	_factory->patchTEdge("e33", "v22", "v19", "f10", "f9"); // v
	_factory->patchTEdge("e34", "v23", "v20", "f11", "f10"); // v
	_factory->patchTEdge("e35", "v7", "v8", "f5", "f3"); // v
}

void Mesh::patchTLinks()
{
	_factory->patchTLink("l0", "e0", true); // v
	_factory->patchTLink("l59", "e0", false); // v
	_factory->patchTLink("l6", "e1", true); // v
	_factory->patchTLink("l60", "e1", false); // v
	_factory->patchTLink("l10", "e2", true); // v
	_factory->patchTLink("l61", "e2", false); // v
	_factory->patchTLink("l14", "e3", true); // v
	_factory->patchTLink("l62", "e3", false); // v
	_factory->patchTLink("l15", "e4", true); // v
	_factory->patchTLink("l63", "e4", false); // v
	_factory->patchTLink("l20", "e5", true); // v
	_factory->patchTLink("l64", "e5", false); // v
	_factory->patchTLink("l32", "e6", true); // v
	_factory->patchTLink("l65", "e6", false); // v
	_factory->patchTLink("l53", "e7", true); // v
	_factory->patchTLink("l66", "e7", false); // v
	_factory->patchTLink("l54", "e8", false); // v
	_factory->patchTLink("l67", "e8", true); // v
	_factory->patchTLink("l50", "e9", false); // v
	_factory->patchTLink("l68", "e9", true); // v
	_factory->patchTLink("l46", "e10", false); // v
	_factory->patchTLink("l69", "e10", true); // v
	_factory->patchTLink("l47", "e11", false); // v
	_factory->patchTLink("l70", "e11", true); // v
	_factory->patchTLink("l5", "e12", false); // v
	_factory->patchTLink("l71", "e12", true); // v
	_factory->patchTLink("l27", "e13", true); // v
	_factory->patchTLink("l8", "e13", false); // v
	_factory->patchTLink("l23", "e14", true); // v
	_factory->patchTLink("l12", "e14", false); // v
	_factory->patchTLink("l19", "e15", true); // v
	_factory->patchTLink("l16", "e15", false); // v
	_factory->patchTLink("l42", "e16", true); // v
	_factory->patchTLink("l29", "e16", false); // v
	_factory->patchTLink("l36", "e17", true); // v
	_factory->patchTLink("l58", "e17", false); // v
	_factory->patchTLink("l35", "e18", true); // v
	_factory->patchTLink("l25", "e18", false); // v
	_factory->patchTLink("l31", "e19", true); // v
	_factory->patchTLink("l21", "e19", false); // v
	_factory->patchTLink("l43", "e20", true); // v
	_factory->patchTLink("l4", "e20", false); // v
	_factory->patchTLink("l52", "e21", true); // v
	_factory->patchTLink("l33", "e21", false); // v
	_factory->patchTLink("l48", "e22", true); // v
	_factory->patchTLink("l39", "e22", false); // v
	_factory->patchTLink("l1", "e23", true); // v
	_factory->patchTLink("l9", "e23", false); // v
	_factory->patchTLink("l7", "e24", true); // v
	_factory->patchTLink("l13", "e24", false); // v
	_factory->patchTLink("l11", "e25", true); // v
	_factory->patchTLink("l18", "e25", false); // v
	_factory->patchTLink("l2", "e26", true); // v
	_factory->patchTLink("l30", "e26", false); // v
	_factory->patchTLink("l28", "e27", true); // v
	_factory->patchTLink("l26", "e27", false); // v
	_factory->patchTLink("l24", "e28", true); // v
	_factory->patchTLink("l22", "e28", false); // v
  _factory->patchTLink("l3", "e29", true); // v
	_factory->patchTLink("l41", "e29", false); // v
  _factory->patchTLink("l37", "e30", true); // v
  _factory->patchTLink("l34", "e30", false); // v
	_factory->patchTLink("l44", "e31", true); // v
	_factory->patchTLink("l40", "e31", false); // v
	_factory->patchTLink("l38", "e32", true); // v
	_factory->patchTLink("l56", "e32", false); // v
	_factory->patchTLink("l45", "e33", true); // v
	_factory->patchTLink("l51", "e33", false); // v
	_factory->patchTLink("l49", "e34", true); // v
	_factory->patchTLink("l55", "e34", false); // v
	_factory->patchTLink("l57", "e35", true); // v
  _factory->patchTLink("l17", "e35", false); // v
}

void Mesh::patchTEdgeConditions() // v
{
	_factory->patchTEdgeCondition("ec0", "e0", true);
	_factory->patchTEdgeCondition("ec1", "e1", true);
	_factory->patchTEdgeCondition("ec2", "e2", true);
	_factory->patchTEdgeCondition("ec3", "e3", true);
	_factory->patchTEdgeCondition("ec4", "e4", true);
	_factory->patchTEdgeCondition("ec5", "e5", true);
	_factory->patchTEdgeCondition("ec6", "e6", true);
	_factory->patchTEdgeCondition("ec7", "e7", true);
	_factory->patchTEdgeCondition("ec8", "e8", true);
	_factory->patchTEdgeCondition("ec9", "e9", true);
	_factory->patchTEdgeCondition("ec10", "e10", true);
	_factory->patchTEdgeCondition("ec11", "e11", true);
  _factory->patchTEdgeCondition("ec12", "e12", true);
}

void Mesh::patchTFaces()
{
	std::vector<std::string> link_loop;
	std::vector<std::string> nodes;

	link_loop << "l0" << "l9" << "l30" << "l41" << "l4" << "l71";
	_factory->patchTFace("f0", link_loop, nodes); // v
	link_loop.clear();

	link_loop << "l6" << "l13" << "l8" << "l1";
	_factory->patchTFace("f1", link_loop, nodes); // v
	link_loop.clear();

	link_loop << "l10" << "l18" << "l12" << "l7";
	_factory->patchTFace("f2", link_loop, nodes); // v
	link_loop.clear();

	link_loop << "l14" << "l63" << "l16" << "l17" << "l11";
	_factory->patchTFace("f3", link_loop, nodes); // v
	link_loop.clear();

	link_loop << "l27" << "l26" << "l29" << "l2";
	_factory->patchTFace("f4", link_loop, nodes); // v
	link_loop.clear();

	link_loop << "l23" << "l57" << "l22" << "l25" << "l58"<< "l28";
	_factory->patchTFace("f5", link_loop, nodes); // v
	link_loop.clear();

	link_loop << "l19" << "l64" << "l21" << "l24";
	_factory->patchTFace("f6", link_loop, nodes); // v
	link_loop.clear();

	link_loop << "l42" << "l36" << "l34" << "l56" << "l39"<< "l3"<< "l44";
	_factory->patchTFace("f7", link_loop, nodes); // v
	link_loop.clear();

	link_loop << "l35" << "l31" << "l65" << "l33" << "l37";
	_factory->patchTFace("f8", link_loop, nodes); // v
	link_loop.clear();

	link_loop << "l43" << "l40" << "l51" << "l46" << "l70";
	_factory->patchTFace("f9", link_loop, nodes); // v
	link_loop.clear();

	link_loop << "l48" << "l55" << "l50" << "l45";
	_factory->patchTFace("f10", link_loop, nodes); // v
	link_loop.clear();

	link_loop << "l52" << "l66" << "l54" << "l38" << "l49";
	_factory->patchTFace("f11", link_loop, nodes); // v
	link_loop.clear();

	nodes.clear();
}

void Mesh::patchTNodes()
{
	//////////////////////////////////////////////////////////////////////////
	// ???
	_factory->patchTNodeV4("n0", "v0", "p0",  "n15", "", "", "n1"); // v
	_factory->patchTNodeV4("n1", "v1", "p1", "n5", "n0", "", "n2"); // v
	_factory->patchTNodeV4("n2", "v2", "p2", "n6", "n1", "", "n3"); // v
	_factory->patchTNodeV4("n3", "v3", "p3", "n7", "n2", "", "n4"); // v
	_factory->patchTNodeV4("n4", "v4", "p4", "n9", "n3", "", ""); // v
	_factory->patchTNodeV4("n5", "v5", "p5", "n10", "", "n1", "n6"); // v
	_factory->patchTNodeV4("n6", "v6", "p6", "n11", "n5", "n2", "n7"); // v
	_factory->patchTNodeV4("n7", "v7", "p7", "", "n6", "n3", "n8"); // v
	_factory->patchTNodeV4("n8", "v8", "p8", "n13", "n7", "", "n9"); // v
	_factory->patchTNodeV4("n9", "v9", "p9", "n14", "n8", "n4", ""); // v
	_factory->patchTNodeV4("n10", "v10", "p10", "n16", "", "n5", "n11"); // v
	_factory->patchTNodeV4("n11", "v11", "p11", "", "n10", "n6", "n12"); // v
	_factory->patchTNodeV4("n12", "v12", "p12", "n17", "n11", "", "n13"); // v
	_factory->patchTNodeV4("n13", "v13", "p13", "", "n12", "n8", "n14"); // v
	_factory->patchTNodeV4("n14", "v14", "p14", "n18", "n13", "n9", ""); // v
	_factory->patchTNodeV4("n15", "v15", "p15", "n21", "", "n0", "n16"); // v
	_factory->patchTNodeV4("n16", "v16", "p16", "n19", "n15", "n10", ""); // v
	_factory->patchTNodeV4("n17", "v17", "p17", "n20", "", "n12", "n18"); // v
	_factory->patchTNodeV4("n18", "v18", "p18", "n24", "n17", "n14", ""); // v
	_factory->patchTNodeV4("n19", "v19", "p19", "n22", "", "n16", "n20"); // v
	_factory->patchTNodeV4("n20", "v20", "p20", "n23", "n19", "n17", ""); // v
	_factory->patchTNodeV4("n21", "v21", "p21", "", "", "n15", "n22"); // v
	_factory->patchTNodeV4("n22", "v22", "p22", "", "n21", "n19", "n23"); // v
	_factory->patchTNodeV4("n23", "v23", "p23", "", "n22", "n20", "n24"); // v
  _factory->patchTNodeV4("n24", "v24", "p24", "", "n23", "n18", ""); // v
}

void Mesh::patchTPoints() // v
{
	_factory->patchTPoint("p0", "n0");
	_factory->patchTPoint("p1", "n1");
	_factory->patchTPoint("p2", "n2");
	_factory->patchTPoint("p3", "n3");
	_factory->patchTPoint("p4", "n4");
	_factory->patchTPoint("p5", "n5");
	_factory->patchTPoint("p6", "n6");
	_factory->patchTPoint("p7", "n7");
	_factory->patchTPoint("p8", "n8");
	_factory->patchTPoint("p9", "n9");
	_factory->patchTPoint("p10", "n10");
  _factory->patchTPoint("p11", "n11");
	_factory->patchTPoint("p12", "n12");
	_factory->patchTPoint("p13", "n13");
	_factory->patchTPoint("p14", "n14");
	_factory->patchTPoint("p15", "n15");
	_factory->patchTPoint("p16", "n16");
	_factory->patchTPoint("p17", "n17");
	_factory->patchTPoint("p18", "n18");
	_factory->patchTPoint("p19", "n19");
	_factory->patchTPoint("p20", "n20");
	_factory->patchTPoint("p21", "n21");
	_factory->patchTPoint("p22", "n22");
	_factory->patchTPoint("p23", "n23");
  _factory->patchTPoint("p24", "n24");
}

void Mesh::patchTSpline() // v
{
	_factory->patchTSpline("mesh", "image", "nodes", "points");
}

void Mesh::patchTImage()
{
	std::vector<std::string> faces, links, edges, vertices;
	_factory->findTObjectNames(faces, TSPLINE::E_TFACE);
	_factory->findTObjectNames(links, TSPLINE::E_TLINK);
	_factory->findTObjectNames(edges, TSPLINE::E_TEDGE);
	_factory->findTObjectNames(vertices, TSPLINE::E_TVERTEX);
	_factory->patchTImage("image", faces, links, edges, vertices);
}

void Mesh::patchTConnect()
{
	std::vector<std::string> nodes;
	_factory->findTObjectNames(nodes, TSPLINE::E_TNODE);
	_factory->patchTConnect("nodes", nodes);
}

void Mesh::patchTPointset()
{
	std::vector<std::string> points;
	_factory->findTObjectNames(points, TSPLINE::E_TPOINT);
	_factory->patchTPointset("points", points);
}

void Mesh::prepareTObjects()
{
	_factory->prepareTNodeHalfLinkages();
	_factory->prepareTJunctions();
	_factory->prepareImageConnect();
}

TSplinePtr Mesh::findTSpline()
{
	return _factory->findTSpline();
}

TGroupPtr Mesh::findTGroup()
{
	return _factory->findTGroup();
}

void Mesh::findTFaceNames( std::vector<std::string> &faces )
{
	_factory->findTObjectNames(faces, TSPLINE::E_TFACE);
}
